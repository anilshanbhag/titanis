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

#ifndef DOCINDEX_H_
#define DOCINDEX_H_

#include <map>
#include <string>
#include <list>
using namespace std;

class DocIndex {
	private:
		map<string, int> index;
		map<int, string> rIndex;
		int cur;
	public:
		DocIndex();
		int Put(string& url);
		int Exists(string& url);
		int Get(string& url);
		string& Get(int docId);
		list<int>& BatchConvert(list<string>& urls);
};

#endif
