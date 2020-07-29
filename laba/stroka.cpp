#include "iostream"
#include "stroka.h"
using namespace std;

stroka::stroka(int val):len(val),pCh(new char[len+1])
/*{
 * len= val;
 * pCh= new char [len+1]};          //др вид записи
 * }*/
{
    if(val==0)pCh[0]='0';
    cout << "stroka::stroka (int val)" << endl;
}

stroka::stroka(char ch):len(1),pCh(new char[len+1])
{
    pCh[0]=ch;
    pCh[1]='\0';
    cout << "stroka::stroka(char ch)" << endl;
}

stroka::stroka(const char *s):len(strlen(s)),pCh(new char[len+1])
{
    strcpy(pCh,s);          //strcy_s(pCh,len+1,s);
    cout << "stroka::stroka(const char* s)" << endl;
}

stroka::stroka(const stroka &from):len(strlen(from.pCh)),pCh(new char[from.len+1])
{
    strcpy(pCh,from.pCh);
    //strcy_s(pCh,from.len+1,from.pCh);
    cout << "stroka::stroka(const stroka & from)" << endl;
}
stroka::~stroka()
{
    if (pCh)
        delete[] pCh;
    cout << "stroka::~stroka()" << endl;
}
void stroka::show (void)
{
    cout << "len = " << len << endl;
    cout << "pCh = " << pCh << endl;
}