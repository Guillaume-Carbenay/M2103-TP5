/**
 *
 * \file   : SqueletteMain.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>

#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{
    void testFailure (void)
    {
        cin.exceptions (ios_base::failbit | ios_base::eofbit);
        try
        {

            while(true)
            {
                cout << "Entrez un entier" << endl;
                int i;
                cin >> i;
                cout << i << endl;
                cout << endl;
            }
        }
        catch (exception const & e)
        {
            cout << "testFailure::exception standard : " ;
            cout << e.what() << endl;
            if (cin.eof())
            {
                cout << "cin.eof()" << endl;
            }
            else if (cin.fail())
            {
                cout << "cin.fail()" << endl;
            }
            throw e;
        }

    } // TestFailure  ()

} // namespace

int main (void)
{
    try
    {
        testFailure ();

        return KNoExc;
    }
    catch (const CException & e)
    {
        cerr << "Erreur        : " << e.getLibelle () << '\n'
             << "Code d'erreur = " << e.getCodErr ()  << '\n';
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()
