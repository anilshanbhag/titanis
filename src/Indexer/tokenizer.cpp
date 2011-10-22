/*
 * =====================================================================================
 *
 *       Filename:  tokenizer.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/17/2011 08:24:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: 	Rahee Borade (), rahee11@iitb.ac.in
 *
 * =====================================================================================
 */
 
#include "tokenizer.h"
using namespace std;

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Tokenizer::Tokenizer
 *  Description:  Constructor
 * =====================================================================================
 */

Tokenizer::Tokenizer()
{
	result = "";
	url = "";
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Tokenizer::Tokenize
 *  Description:  Tokenize the text and store locally
 * =====================================================================================
 */

void Tokenizer::Tokenize(string text)
{
	cout<<endl<<endl<<text<<endl<<endl;
	int i = 0;
	l.erase(l.begin(),l.end());
	cout<<endl<<endl<<l.size()<<endl<<endl;
	size_t found = text.find("<body");
	if(found == string::npos)
	{
		found = text.find("< body");
		if(found == string::npos) return;
	}
	
	i = found;
	
	while (i < text.size())
	{
		if(text[i] == '<'){
			while(text[i] != '>'){
				tokens += text [i];
				i++;
			}
		} else if(text[i] == '>') {
			tokens += text [i];
			l.push_back(tokens);
			tokens = "";
			i++;
		} else 	{
			while (text[i] != '<') {
				tokens += text[i];
				i++;
			}
			l.push_back(tokens);
			tokens = "";
		}
	}
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Tokenizer::Debug
 *  Description:  Debug code
 * =====================================================================================
 */

void Tokenizer::Debug()
{
	for (itr = l.begin();itr != l.end();itr++) {
		cout<<(*itr)<<endl;
	}
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Tokenizer::PrintURL
 *  Description:  Debug URL list
 * =====================================================================================
 */

void Tokenizer::PrintURL()
{
	for (iter = lst.begin();iter != lst.end();iter++) {
		cout<<(*iter)<<endl;
	}
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Tokenizer::GetText
 *  Description:  Get plain text from previously constructed tokens
 * =====================================================================================
 */

string Tokenizer::GetText()
{
    itr = l.begin();
    while (itr != l.end()) {
        if (((*itr).find("<style") != string::npos) || (((*itr).find("<script")) != string::npos))
            itr = itr + 3;
        else if((*itr).at(0) == '<')
            itr++;
        else {
        	result += (*itr) + " ";
        	itr++;
        }
    }
    cout<<result<<endl;
    return result;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Tokenizer::GetURL
 *  Description:  Get urls from previously constructed tokens
 * =====================================================================================
 */

list<string>& Tokenizer::GetURL()
{	
	size_t n;
	string token;
    itr = l.begin();
    while (itr != l.end()) {
    	if ((*itr).find("<a href") != string::npos) {
    		token = (*itr);
    		if ((*itr).find('"') != string::npos) {
    			n = (*itr).find('"') + 1;
    			while (token[n] != ('"'))
    			{
    				url += token[n];
    				n++;
    			}
    			lst.push_back(url);
    			url.erase(url.begin(),url.end());
    		}
    		else if((*itr).find("'") != string::npos)
    		{
				n = (*itr).find("'") + 1;
					while (token[n] != '\'')
					{
						url += token[n];
						n++;
					}
				lst.push_back(url);
				url.erase(url.begin(),url.end());
    		}
    		itr++;
    	}
    	else
    		itr++;
    }
    return lst;
}
