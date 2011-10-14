/*
 * =====================================================================================
 *
 *       Filename:  URLResolver.cpp
 *
 *    Description:  URLResolver :: Resolves the urls 
 *
 *        Version:  1.0
 *        Created:  10/10/2011 05:41:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include "URLResolver.h"

URLResolver::URLResolver (string& l, list<string>& lst) 
{
	link = l;
	links = lst;
}

int countSlash (string& x)
{
	int t = 0;
	for(int i=0;i<x.size();i++)
		if (x[i] == '/') t++;

	return t;
}

int findRootPos (string& url) 
{
	int count = 0,pos = 0;
	for(int i=0;i<url.size();i++){
		if(url[i] == '/') count++;
		if(count == 3) {
			pos = i; break;
		}
	}

	return pos;
}

int findHostPos (string& url) 
{
	int pos = 0;
	for(int i = url.size(); i >=0; i--)
		if(url[i] == '/') return i;
	return 0;
}

list<string>& URLResolver::Resolve()
{
	string host,root;
	// sample urls
	// http://abc.com
	// http://abc.com/
	// http://abc.com/acv
	// http://avc.com/acd/
	// http://asd.com/asd/index.html
	
	int slashCount = countSlash(link);
	if (slashCount == 2) {
		// This is easier since root will be same as host
		host = root = link;	
	} else if(slashCount >= 3) {
		// First find root
		int pos = findRootPos( link );
		root = link.substr(0,pos);
		
		// Now find host
		pos = findHostPos( link ); 
		host = link.substr(0,pos);
	} else {
		// We got an error here
	}

	for(list<string>::iterator it = links.begin(); it != links.end();it++)
	{
		if ((*it).find("http://") == 0) {
			// This is full link 
			continue;
		} else if ((*it)[0] == '/') {
			// This is root link
			*it = root + *it;
		} else {
			// This is a relative link
			*it = host + *it;
		}
	}

}

