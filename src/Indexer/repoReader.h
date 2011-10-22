/*
 * =====================================================================================
 *
 *       Filename:  repoReader.h
 *
 *    Description:  Repository Reader
 *
 *        Version:  1.0
 *        Created:  10/13/2011 04:04:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */

#ifndef REPO_READER_H_
#define REPO_READER_H_

#include <fstream>
#include <queue>
#include <string>
#include <cstdlib>
#include <dirent.h>
#include <errno.h>
#include <iostream>
using namespace std;

class RepoReader {
	private:
		string startPt;
		queue<string> fileQueue;
	public:
		RepoReader(string start = "../../Repository/");
		int GetDir (string dir);
		bool Empty();
		int Size();
		void GetNext( string& content );
		void GetNextURL( string& url );
};

#endif
