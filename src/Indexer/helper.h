/*
 * =====================================================================================
 *
 *       Filename:  helper.h
 *
 *    Description:  Helper Functions
 *
 *        Version:  1.0
 *        Created:  10/13/2011 04:49:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

template<typename t,typename s>
void pprint (t<s> x)
{
	t<s>::iterator it;

	for(it = x.begin();it != x.end();it++)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;
}
