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

#ifndef PAGERANK_H_
#define PAGERANK_H_

#include <map>
#include <list>
#include <iostream>
using namespace std;

class PageRank {
	private:
		// Map from doc to all links outbound
		map<int, list<int> > out;
		// Map from doc to all links inbound
		map<int, list<int> > in;
		// Final computed pagerank
		map<int, double> pr;
		void BuildInbound();

	public:
		PageRank();
		void Put(int docId, list<int>& docIds );
		void Compute();
		double Get(int docId);
};

#endif

