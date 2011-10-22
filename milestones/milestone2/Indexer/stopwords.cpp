#include "stopwords.h"
using namespace std;

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  StopWords
 *  Description:  Constructor
 * =====================================================================================
 */
StopWords::StopWords ( string filename  )
    {
		std::ifstream fil;
		fil.open( filename.c_str() , ifstream::in);
        string inp;

        while(fil>>inp)
        {
            stops[inp] = 1;
        }
    }		/* -----  end of function StopWords  ----- */


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  IsStopword
 *  Description:  stopword? true : false
 * =====================================================================================
 */
bool
    StopWords::IsStopWord ( string inp )
    {
        return stops[inp];
    }		/* -----  end of function IsStopword  ----- */

