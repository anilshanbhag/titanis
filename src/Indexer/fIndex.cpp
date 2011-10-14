/*
 * =====================================================================================
 *
 *       Filename:  fIndex.cpp
 *
 *    Description: Forward Index 
 *
 *        Version:  1.0
 *        Created:  10/13/2011 02:24:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include "fIndex.h"
using namespace std;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ForwardIndex::ForwardIndex
 *  Description:  Constructor
 * =====================================================================================
 */
	
ForwardIndex::ForwardIndex ( )
{
	
}		/* -----  end of function ForwardIndex::ForwardIndex  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ForwardIndex::AddToIndex
 *  Description:  Adds a text from html page into index after tokenizing
 * =====================================================================================
 */
	void
ForwardIndex::AddToIndex (int docId, string text)
{
	return;
}		/* -----  end of function ForwardIndex::AddToIndex  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ForwardIndex::Insert
 *  Description:  Add an entry into the forward index
 * =====================================================================================
 */
	void
ForwardIndex::Insert ( int docId, vector<string>& tokens )
{
	map[docId] = tokens;
	return;
}		/* -----  end of function ForwardIndex::Insert  ----- */
