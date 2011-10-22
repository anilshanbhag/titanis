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
ForwardIndex::AddToIndex ( int docId, string text )
{
	istringstream ss(text);	
	string t;
	map<string,int> in;
	while(ss>>t){
		if( stopWords.IsStopWord(t) ) continue;
		if(in[t] ) in[t] += 1;
		else in[t] = 1;
	}
	index[docId] = in;
	return;
}		/* -----  end of function ForwardIndex::AddToIndex  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ForwardIndex::Insert
 *  Description:  Add an entry into the forward index
 * =====================================================================================
 */
	void
ForwardIndex::Insert ( int docId, map<string,int>& tokens )
{
	index[docId] = tokens;
	return;
}		/* -----  end of function ForwardIndex::Insert  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ForwardIndex::Get
 *  Description:  Get the index   
 * =====================================================================================
 */
	map<string,int>&
ForwardIndex::Get ( int docId )
{
    return index[docId];
}		/* -----  end of function ForwardIndex::Get  ----- */

/* 
int main()
{
	ForwardIndex fw;
	map<string,int> n;
	fw.AddToIndex(1, string("asd asdas asd"));
	fw.Get( 1, n);
	cout<<n["asd"]<<endl;
	cout<<n["2"]<<endl;
	return 0;
}
*/
