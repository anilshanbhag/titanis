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
 *        Company:  
 *
 * =====================================================================================
 */


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
	index[docId] = docIds;
	return;
}		/* -----  end of function PageRank::Put  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PageRank::Get
 *  Description:  Get the pagerank of a particular doc
 * =====================================================================================
 */
	void
PageRank::Get ( )
{
	return;
}		/* -----  end of function PageRank::Get  ----- */
