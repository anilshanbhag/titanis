/*
 * =====================================================================================
 *
 *       Filename:  iIndex.h
 *
 *    Description:  Inverted Index : Mapping from words to list of urls 
 *
 *        Version:  1.0
 *        Created:  10/17/2011 05:01:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef IINDEX_H_
#define IINDEX_H_

#include <string>
#include <map>
#include <list>
using namespace std;

class InvertedIndex {
	private:
		map<string,list<int> > index;
	public:
		InvertedIndex();
		void AddToIndex(int docId, map<string,int> words);
		void Put(string word, list<int> urls);
		list<int>& Get(string word);
};

#endif
