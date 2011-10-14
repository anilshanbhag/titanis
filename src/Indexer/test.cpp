/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  Test fstream
 *
 *        Version:  1.0
 *        Created:  10/13/2011 04:26:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <iostream>
#include <errno.h>
#include <dirent.h>
#include <vector>
//#include "helper.h"
using namespace std;

int getdir (string dir, vector<string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		if (dirp->d_name == "." || dirp->d_name == "..") continue;
		files.push_back(string(dirp->d_name));
	}
	
	closedir(dp);
	return 0;
}

int main ()
{
	vector<string> results;
	getdir( "../Repository/", results);
	cout<<results[0]<<" "<<results[1]<<" "<<results[2]<<"  "<<results.size()<<"  "<<results[5109]<<endl;
	return 0;
}
