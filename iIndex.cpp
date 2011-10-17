/*
 * =====================================================================================
 *
 *       Filename:  iIndex.cpp
 *
 *    Description:  Inverted Index : Mapping from words to list of urls
 *
 *        Version:  1.0
 *        Created:  10/17/2011 05:01:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include "iIndex.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InvertedIndex::InvertedIndex
 *  Description:  Constructor
 * =====================================================================================
 */
	
InvertedIndex::InvertedIndex ( )
{
	
}		/* -----  end of function InvertedIndex::InvertedIndex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InvertedIndex::AddToIndex
 *  Description:  Add from fIndex into this
 * =====================================================================================
 */
	void
InvertedIndex::AddToIndex ( int docId, map<string,int> words)
{
	for(map<string,int>::iterator it = words.begin(); it != words.end(); it++)
	{
		index[it->first].push_back(docId);
	}
	
	return;
}		/* -----  end of function InvertedIndex::AddToIndex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InvertedIndex::Put
 *  Description:  Put a list of documents
 * =====================================================================================
 */
	void
InvertedIndex::Put ( string word, list<int> urls )
{
	index[word] = urls;
	return;
}		/* -----  end of function InvertedIndex::Put  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InvertedIndex::Get
 *  Description:  Get the list of documents
 * =====================================================================================
 */
	list<int>&
InvertedIndex::Get ( string word )
{
	return index[word];
}		/* -----  end of function InvertedIndex::Get  ----- */

