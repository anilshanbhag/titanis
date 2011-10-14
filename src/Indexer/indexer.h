/*
 * =====================================================================================
 *
 *       Filename:  Indexer.h
 *
 *    Description:  Indexer Class
 *
 *        Version:  1.0
 *        Created:  10/13/2011 03:21:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */

#include "docIndex.h"
#include "fIndex.h"
#include "rIndex.h"
using namespace std;

class Indexer {
	private:
		ForwardIndex fIndex;
		InvertedIndex iIndex;
	public:
		Indexer();
};
