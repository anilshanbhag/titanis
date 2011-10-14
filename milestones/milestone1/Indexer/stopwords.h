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
#include <istream>
#include <iostream>
using namespace std;

class StopWords {
    private:
        map<string,bool> stops;
    public:
        void StopWords ( string filename );
        bool IsStopWord ( string inp );
};
