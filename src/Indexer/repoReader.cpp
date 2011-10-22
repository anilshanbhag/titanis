/*
 * =====================================================================================
 *
 *       Filename:  repoReader.cpp
 *
 *    Description:  Repository Reader
 *
 *        Version:  1.0
 *        Created:  10/13/2011 04:03:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:
 *
 * =====================================================================================
 */

#include "repoReader.h"
#include <istream>

string urlDecode(string &SRC) 
{
    string ret;
    char ch;
    int i, ii;
    for (i=0; i<SRC.length(); i++) {
        if (int(SRC[i])==37) {
            sscanf(SRC.substr(i+1,2).c_str(), "%x", &ii);
            ch=static_cast<char>(ii);
            ret+=ch;
            i=i+2;
        } else {
            ret+=SRC[i];
        }
    }
    ret.erase(ret.end()-5,ret.end());
    return (ret);
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  RepoReader::GetDir
 *  Description:  Lists files in the directory
 * =====================================================================================
 */
	int
RepoReader::GetDir ( string dir )
{
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}
	while ((dirp = readdir(dp)) != NULL) {
		string filename = string(dirp->d_name);
		if(filename != "." && filename != "..")
			fileQueue.push(filename);
	}
	closedir(dp);
	return 0;
}

RepoReader::RepoReader( string start )
{
	GetDir(start);
	startPt = start;
}



/*
 * ===  FUNCTION  ======================================================================
 *         Name:  RepoReader::Empty
 *  Description:  Checks whether there are any more files in the repository
 * =====================================================================================
 */
	bool
RepoReader::Empty ( )
{
	return fileQueue.size() == 0;
}		/* -----  end of function RepoReader::Empty  ----- */

	int
RepoReader::Size ( )
{
	return fileQueue.size();
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  RepoReader::GetNext
 *  Description:  Get the file contents of next file in the queue
 * =====================================================================================
 */
	void
RepoReader::GetNext ( string& content )
{
	string filepath = startPt + fileQueue.front();
	ifstream file;
	file.open(filepath.c_str(),ifstream::in);
	string output, line;
	while(file){
		getline(file, line); output += line;
	}
	cout<<fileQueue.size()<<endl;
	fileQueue.pop();
	content = output;
	//return output;
}		/* -----  end of function RepoReader::GetNext  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  RepoReader::GetNextFile
 *  Description:  Get the next file in the queue
 * =====================================================================================
 */
	void
RepoReader::GetNextURL ( string& url )
{
	url = urlDecode(fileQueue.front());
	cout<<url<<endl;
}		/* -----  end of function RepoReader::GetNextFile  ----- */
