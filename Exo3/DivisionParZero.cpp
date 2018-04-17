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
#include <vector>
#include "CstCodErr.h"
#include "CException.h"

using namespace std;
using namespace nsUtil;

namespace
{
    int divisionEntiere (const int & e1, const int & e2) throw (CException)
    {
        if (e2 == 0) throw nsUtil::CException("Erreur Division par zero", nsUtil::KExcDivZero);
        return e1/e2;
    }

    void testDivisionParZero (void)
    {
        vector <int> Entier1(4);
        Entier1[0] = 3;
        Entier1[1] = 32;
        Entier1[2] = 4;
        Entier1[3] = 0;
        vector <int> Entier2(4);
        Entier2[0] = 1;
        Entier2[1] = 2;
        Entier2[2] = 0;
        Entier2[3] = 8;
        for (unsigned i=0; i < 3; ++i)
        {
            cout << divisionEntiere(Entier1[i], Entier2[i]) << endl;
        }

    } // testDivisionParZero ()

} // namespace

int main (void)
{
    try
    {
        testDivisionParZero ();

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
