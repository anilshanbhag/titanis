#include "stopwords.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  StopWords
 *  Description:  Constructor
 * =====================================================================================
 */
void
    StopWords::StopWords ( string filename )
    {
        ifstream fil(filename);
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


