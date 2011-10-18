/*
 * =====================================================================================
 *
 *       Filename:  pageRank.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2011 07:24:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */

#include "pageRank.h"

typedef map<int,list<int> >::iterator milit;
typedef list<int>::iterator listit;
typedef map<int,double>::iterator midit;

#define d 0.15
#define ITERC 1

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PageRank::PageRank
 *  Description:  Constructor
 * =====================================================================================
 */

PageRank::PageRank ( )
{
	
}		/* -----  end of function PageRank::PageRank  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PageRank::Put
 *  Description:  Adds an entry into index of pagerank
 * =====================================================================================
 */
	void
PageRank::Put (int docId, list<int>& docIds )
{
	out[docId] = docIds;
	return;
}		/* -----  end of function PageRank::Put  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PageRank::Get
 *  Description:  Get the pagerank of a particular doc
 * =====================================================================================
 */
	double
PageRank::Get ( int docId )
{
	return pr[docId];
}		/* -----  end of function PageRank::Get  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PageRank::BuildInbound
 *  Description:  Create `in` using `out`
 * =====================================================================================
 */
	void
PageRank::BuildInbound ( )
{
	for( milit it = out.begin(); it != out.end(); it++)
	{
		for(listit ix = (it->second).begin(); ix != (it->second).end(); ix++)
		{
			in[*ix].push_back(it->first);
		}
	}
}		/* -----  end of function PageRank::BuildInbound  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PageRank::Compute
 *  Description:  Build the page rank index 
 * =====================================================================================
 */
	void
PageRank::Compute ( )
{
	BuildInbound();

	map<int,double>* previous = new map<int,double>();
	map<int,double>* current = new map<int,double>();
	
	int iter = ITERC;
	
	// Initialize all to 1
	for(milit it = in.begin(); it != in.end(); it++)
	{
		(*previous)[it->first] = 1.0;
	}

	// Do 10 iterations -- will stabilize by then
	while (iter--) 
	{
		for(midit it = (*previous).begin(); it != (*previous).end(); it++)
		{
			double sum = 0.0;
			for (listit is = in[it->first].begin(); is != in[it->first].end(); is++) 
			{
				sum += (*previous)[*is] / out[*is].size();
			}
			(*current)[it->first] = d + (1-d) * sum;
		}

		delete previous;
		previous = current;
		current = new map<int,double>();
	}

	pr = *previous;
	delete previous;
	delete current;

	return;
}		/* -----  end of function PageRank::Compute  ----- */

int main () 
{
	PageRank pr;
	list<int> x[3];
	x[0].push_back(2); x[0].push_back(3);
	x[1].push_back(1);
	x[2].push_back(1); x[1].push_back(2);
	pr.Put(1,x[0]); pr.Put(2,x[1]); pr.Put(3,x[2]);
	pr.Compute();
	cout<<pr.Get(1)<<" "<<pr.Get(2)<<" "<<pr.Get(3)<<endl;
	return 0;
}
