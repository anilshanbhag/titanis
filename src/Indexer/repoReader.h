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
		fileQueue.push(string(dirp->d_name));
	}
	
	closedir(dp);
	return 0;
}

RepoReader::RepoReader( string start = "../Repository/" ) 
{
	GetDir(start);
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  RepoReader::GetNext
 *  Description:  
 * =====================================================================================
 */
	string
RepoReader::GetNext ( )
{
	return "";
}		/* -----  end of function RepoReader::GetNext  ----- */
