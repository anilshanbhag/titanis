/*
 * =====================================================================================
 *
 *       Filename:  stopwords.cpp
 *
 *    Description:  Stop Words Class
 *
 *        Version:  1.0
 *        Created:  10/06/2011 12:47:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anil Shanbhag (), anilashanbhag@gmail.com
 *
 * =====================================================================================
 */


#include <map>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class StopWords {
    private:
        map<string,bool> stops;
    public:
        StopWords ( string filename = "../stop_words.txt" );
        bool IsStopWord ( string inp );
};
