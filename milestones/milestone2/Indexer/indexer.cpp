/*
 * =====================================================================================
 *
 *       Filename:  indexer.cpp
 *
 *    Description:  Indexer Class
 *
 *        Version:  1.0
 *        Created:  10/17/2011 05:57:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */

#include "indexer.h"

typedef map<int,map<string,int> >::iterator mimit;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Indexer::Indexer
 *  Description:  Constructor
 * =====================================================================================
 */
	
Indexer::Indexer ( )
{
	BuildFIndex();
	BuildIIndex();
	pr.Compute();
}		/* -----  end of function Indexer::Indexer  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Indexer::BuildFIndex
 *  Description:  Builds the forward index
 * =====================================================================================
 */
	void
Indexer::BuildFIndex (  )
{
	string html,plain,url;
	int docId;

	// Read a file from the RepoReader 
	// Then add it to the forward index
	while (!rr.Empty())
	{
		url = rr.GetNextURL();
		html = rr.GetNext();
		docId = docIn.Put(url); 
		tk.Tokenize(html);
		plain = tk.GetText();

		// Get the list of urls from tokenizer
		// Resolve the urls 
		// Add them into pagerank	
		pr.Put(docId, docIn.BatchConvert(ur.( tk.GetURL())));

		fIndex.AddToIndex(docId, plain);		
	}

	return;
}		/* -----  end of function Indexer::BuildFIndex  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  RepoReader::BuildIIndex
 *  Description:  Build the inverted index
 * =====================================================================================
 */
	void
Indexer::BuildIIndex (  )
{
	for(mimit it = fIndex.index.begin(); it != fIndex.index.end(); it++)
	{
		iIndex.AddToIndex(it->first, it->second);
	} 
	return;
}		/* -----  end of function RepoReader::BuildIIndex  ----- */

