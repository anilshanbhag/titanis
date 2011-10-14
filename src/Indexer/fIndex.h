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

#ifndef FINDEX
#define FINDEX
#endif

#include <map>
#include <vector>
using namespace std;

class ForwardIndex {
	private:
		map<int, vector<string> > index;
	public:
		ForwardIndex();
		void AddToIndex (int docId, string text);
		void Insert( int  docId, vector<string>& tokens);
};
