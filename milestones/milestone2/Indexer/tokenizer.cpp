
#include "tokenizer.h"
using namespace std;

Tokenizer::Tokenizer()
{
	result = "";
	url = "";
}

void Tokenizer::Tokenize(string text)
{	
	int i = 0;
	l.erase(l.begin(),l.end());
	size_t found = text.find("<body");
	if(found == string::npos)
		{
		found = text.find("< body");
		if (found == string::npos ) {
			vector<string>* x = new vector<string>();
			//return *x;
		}
	}
	
	i = found;
	
	while (i < text.size())
	 
	{
		if(text[i] == '<')
			{
				while(text[i] != '>')
					{
						tokens += text [i];
					
						i++;
					}
			}
		else if(text[i] == '>')
			{
				tokens += text [i];
				l.push_back(tokens);
				tokens.erase(tokens.begin(),tokens.end());
				i++;
			}
		else
			{
				while(text[i] != '<')
					{
						tokens += text[i];
						i++;
					}
				l.push_back(tokens);
				tokens.erase(tokens.begin(),tokens.end());
			}
		}

}

void Tokenizer::Debug()
{
	for(itr = l.begin();itr != l.end();itr++)
	{
		cout<<(*itr)<<endl;
	}
}

void Tokenizer::PrintURL()
{
	for(iter = lst.begin();iter != lst.end();iter++)
	{
		cout<<(*iter)<<endl;
	}
}

string Tokenizer::GetText()
{
    itr = l.begin();
    while(itr != l.end())
    {
        if (((*itr).find("<style") != string::npos) || (((*itr).find("<script")) != string::npos))
            itr = itr + 3;
        else if((*itr).at(0) == '<')
            itr++;
        else
        {
         result += (*itr);
         itr++;
         }
    }
    cout<<result<<endl;
    return result;
}

list<string>& Tokenizer::GetURL()
{	
	size_t n;
	string token;
    itr = l.begin();
    while(itr != l.end())
    {
    	if((*itr).find("<a href") != string::npos)
    	{
    		token = (*itr);
    		if((*itr).find('"') != string::npos)
    		{
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
    		
    		
    			
    		
