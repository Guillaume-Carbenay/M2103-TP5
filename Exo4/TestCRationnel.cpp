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
#include "Rationnel.h"
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
        int num1, denom1, num2, denom2;
        cout << "Premier rationnel : " << endl << "Entrez le numerateur : " << endl;
        cin >> num1;
        cout << "Entrez le denominateur : " << endl;
        cin >> denom1;
        nsMath::Rationnel dividende(num1, denom1);
        cout << "Deuxieme rationnel : " << endl << "Entrez le numerateur : " << endl;
        cin >> num2;
        cout << "Entrez le denominateur : " << endl;
        cin >> denom2;
        nsMath::Rationnel diviseur(num2, denom2);
        nsMath::Rationnel result = dividende / diviseur;
        result.display();
        cout << endl;
    } // testDivisionParZero ()
} // namespace

int main (void)
{
    while(true)
    {
        try
        {
            testDivisionParZero ();
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
    }
    return KNoExc;
} // main()
