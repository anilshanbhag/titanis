/*
 * =====================================================================================
 *
 *       Filename:  fIndex.h
 *
 *    Description:  Forward Index -- It is a mapping from the document id to 
 *    				the list of words contained in the document
 *
 *        Version:  1.0
 *        Created:  10/13/2011 02:24:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */

#ifndef FINDEX_H_
#define FINDEX_H_

#include <map>
#include <vector>
#include <sstream>

#include "stopwords.h"
using namespace std;

class ForwardIndex {
	private:
		StopWords stopWords;
	public:
		ForwardIndex();
		map<int, map<string,int> > index;
		void AddToIndex (int docId, string text);
		void Insert( int  docId, map<string,int>& tokens);
		map<string,int>& Get( int docId );
};

#endif
