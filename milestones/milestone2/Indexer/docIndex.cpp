/*
 * =====================================================================================
 *
 *       Filename:  docIndex.cpp
 *
 *    Description:  Document Index
 *
 *        Version:  1.0
 *        Created:  10/13/2011 02:53:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */

#include "docIndex.h"
using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DocIndex::DocIndex
 *  Description:  Constructor
 * =====================================================================================
 */

DocIndex::DocIndex ( )
{
	cur = 0;
}		/* -----  end of function DocIndex::DocIndex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DocIndex::Put
 *  Description:  Adds the url into the index , returns the index
 * =====================================================================================
 */
	int
DocIndex::Put ( string& url )
{
	int exists = Exists(url);
	if (!exists) {
		cur += 1;
		index[url] = cur;
		rIndex[cur] = url;
		return cur;
	}
	return exists;
}		/* -----  end of function DocIndex::Put  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DocIndex::Exists
 *  Description:  Bool (int) whether the url is already there in the index
 * =====================================================================================
 */
	int
DocIndex::Exists ( string& url )
{
	return index[url];
}		/* -----  end of function DocIndex::Exists  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DocIndex::Put
 *  Description:  Get gets the doc index
 * =====================================================================================
 */
	int
DocIndex::Get ( string& url )
{
	return index[url];
}		/* -----  end of function DocIndex::Put  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DocIndex::Get
 *  Description:  Return the url of string 
 * =====================================================================================
 */
	string&
DocIndex::Get ( int docId )
{
	return rIndex[docId];
}		/* -----  end of function DocIndex::Get  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DocIndex::BatchConvert
 *  Description:  Convert a list of urls into ids
 * =====================================================================================
 */
	list<int>&
DocIndex::BatchConvert ( list<string>& urls )
{
	list<int> docIds;
	while(!urls.empty())
	{
		docIds.push_back(Put(urls.front()));
		urls.pop_front();
	}
	return docIds;
}		/* -----  end of function DocIndex::BatchConvert  ----- */
