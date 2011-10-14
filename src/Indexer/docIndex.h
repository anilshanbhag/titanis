/*
 * =====================================================================================
 *
 *       Filename:  docIndex.h
 *
 *    Description:  Document Index
 *
 *        Version:  1.0
 *        Created:  10/13/2011 02:54:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */

#ifndef DOCINDEX
#define DOCINDEX
#endif

#include <map>
#include <string>
using namespace std;

class DocIndex {
	private:
		map<string, int> index;
		int cur;
	public:
		DocIndex();
		int Put(string url);
		int Exists(string url);
		int Get(string url);
};
