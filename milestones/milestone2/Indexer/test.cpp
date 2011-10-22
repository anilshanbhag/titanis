#include<iostream>
#include<cstring>
#include"tokenizer.h"

using namespace std;

int main()
{
	string text;
	string result;
	Tokenizer T;
	while(getline(cin,text)){ result += text; }
	T.Tokenize(result);
	T.Debug();
	T.GetText();
	T.GetURL();
	T.PrintURL();
	return 0;
}
	
