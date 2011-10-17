/*
 * =====================================================================================
 *
 *       Filename:  pageRank.h
 *
 *    Description:  Maintains the page rank index
 *
 *        Version:  1.0
 *        Created:  10/17/2011 06:04:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef PAGERANK
#define PAGERANK

#include <map>
#include <list>
#include <iostream>

class PageRank {
	private:
		map<int, list<int> > index;
		map<int, double> pr;
	public:
		PageRank();
		void Put(int docId, list<int>& docIds );
		void Compute();
		void Get(int docId);
};

#endif
