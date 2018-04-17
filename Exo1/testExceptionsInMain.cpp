#include "testExceptionsInMain.h"
#include <iostream>
#include <exception>
#include <string>
#include "CExceptions.h"

using namespace std;

namespace {
    void testExceptionsInMain()
    {
        unsigned except;
        cout << " Exceptions : " << endl << "0 : exception" << endl << "1 : runtime_error" << endl << "2 : CException" << endl << "3 : unsigned" << endl << "4 : int" << endl << "5 : out_of_range" << endl;
        cin >> except;
        switch(except)
        {
        case 0:
            throw exception();
        break;
        case 1:
            throw runtime_error("erreur runtime");
        break;
        case 2:
            throw nsUtil::CException("Erreur Cexception", nsUtil::KExcStd);
        break;
        case 3:
            throw unsigned(5);
        break;
        case 4:
            throw -5;
        break;
        case 5:
            {
                string str =" toto";
                str.at(6);
            }
        }

    }
}
int main(int argc, char *argv[])
{
    try
    {
        testExceptionsInMain();
    }
    catch(nsUtil::CException const& e)
    {
        cout << "CException : " << endl;
        e.display();
    }
    catch(out_of_range const& e)
    {
        cout << "out_of_range : " << endl;
        cout<<e.what()<<endl;
    }
    catch(runtime_error const & e)
    {
        cout << "runtime_error : " << endl;
        cout << e.what()<<endl;
    }
    catch(exception const & e)
    {
        cout << "exception : " << endl;
        cout << e.what()<<endl;
    }
    catch(unsigned const & u)
    {
        cout << "unsigned" << endl;
    }
    catch(...)
    {
        cout << "Autre erreur" << endl;
    }
    return 0;
}
