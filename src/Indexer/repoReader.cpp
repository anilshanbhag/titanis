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
 *        Company:  
 *
 * =====================================================================================
 */

#include <fstream>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

class RepoReader {
	private:
		string startPt;
		queue<string> fileQueue;
	public:
		RepoReader();
		int GetDir (string dir);
		bool Empty();
		string GetNext();
};
