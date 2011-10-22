/*
 * =====================================================================================
 *
 *       Filename:  URLResolver.h
 *
 *    Description:  URLResolver :: Resolves the urls seen in file
 *
 *        Version:  1.0
 *        Created:  10/10/2011 05:38:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <list>
#include <string>
using namespace std;

class URLResolver {
	private:
		string link;
		list<string> links;
	public:
		URLResolver (string& l, list<string>& lst);
		list<string>& Resolve();
};
