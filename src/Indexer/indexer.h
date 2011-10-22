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

#ifndef INDEXER_H_
#define INDEXER_H_

#include "docIndex.h"
#include "fIndex.h"
#include "iIndex.h"
#include "pageRank.h"
#include "tokenizer.h"
#include "URLResolver.h"
#include "repoReader.h"
using namespace std;

class Indexer {
	private:
		ForwardIndex fIndex;
		InvertedIndex iIndex;
		DocIndex docIn;
		RepoReader rr;
		Tokenizer tk;
		URLResolver ur;
		PageRank pr;
	public:
		Indexer();
		void BuildFIndex();
		void BuildIIndex();
		void Debug();
};

#endif
