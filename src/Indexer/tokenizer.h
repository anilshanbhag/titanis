#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include<iostream>
#include<list>
#include<vector>
#include<cstring>
using namespace std;

class Tokenizer
{	
	private:
		string text;
		string tokens;
		vector<string> l;
		list<string> lst;
		list<string>::iterator iter;
		vector<string>::iterator itr;
		string result;
		string url;
	
	public:
		Tokenizer();
		void Tokenize(string);
		void Debug();
		string GetText();
		list<string>& GetURL();
		void PrintURL();
};

#endif
