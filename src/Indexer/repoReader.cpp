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
	string
RepoReader::GetNext ( )
{
	string filepath = startPt + fileQueue.front();
	ifstream file;
	file.open(filepath.c_str(),ifstream::in);
	string output, line;
	while(file){
		getline(file, line); output += line;
	}
	fileQueue.pop();
	return output;
}		/* -----  end of function RepoReader::GetNext  ----- */

