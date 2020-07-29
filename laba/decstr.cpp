//
// Created by Никита Лычаный on 2019-04-05.
//
#include "iostream"
#include "decstr.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

decstr:: decstr (int val): stroka (val)
{
    cout << "decstr::decstr(int val): stroka (val)" << val << endl;
}

decstr::decstr (const char *dstr):stroka(dstr)
{
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || (pCh[0] == '-' && pCh[1] >='1' && pCh[1] <='9')) || pCh[0]=='+')
    {
        cout << "bad symbol, pCh[0]=" << pCh[0] << endl;
        if (pCh)
            delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    cout << "decstr::decstr (const char *dstr):stroka(dstr)" << endl;
}

decstr :: decstr (const decstr &from): stroka (from)
{
    cout << "decstr::decstr (const decstr &from): stroka (from)" << endl;
}

decstr :: ~decstr()
{
    cout << "decstr::~decstr()" << endl;
}

decstr & decstr :: operator = (const decstr &dS)
{
    if(&dS!=this)
    {
        delete[] pCh;
        len = strlen(dS.pCh);
        pCh = new char[len + 1];
        strcpy(pCh,dS.pCh);
    }
    cout << "decstr & decstr :: operator = (const decstr &dS)" << endl;
    return *this;
}

decstr operator + (const decstr &pobj1,const decstr &pobj2)
{
    int num1, num2;
    char *pChTmp;
    decstr tmp (pobj1);
    num1 = atoi(tmp.getstr());
    num2 = atoi(pobj2.getstr());
    if (tmp.len >= pobj2.len)
    {

       int A = num1 + num2;
       int count = tmp.len + 1;
       int modul, AS, i = 0;
       AS = A;
       char *pMasCh = new char[count+1];
       pMasCh[count - 1] = '\0';
       while (i < count - 1)
           pMasCh[i++] = ' ';
       if (A < 0)
           A = -A;
       --i;
       while (A)
       {
           modul = A % 10;
           pMasCh[i] = modul + '0';
           A /= 10;
           --i;
       }
       if (AS < 0)
           pMasCh[i] = '-';
       pChTmp = pMasCh;
    }
    else
    {
        int A = num1 + num2;
        int count = pobj2.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);
    cout << pChTmp << endl;
    cout << strlen(pChTmp) << endl;
    cout << "decstr operator + (const decstr &pobj1,const decstr &pobj2)" << endl;
    return tmp;
}

decstr operator - (const decstr &pobj1,const decstr &pobj2)
{
    int num1, num2;
    char *pChTmp;
    decstr tmp (pobj1);
    num1 = atoi(tmp.getstr());
    num2 = atoi(pobj2.getstr());
    if (tmp.len >= pobj2.len)
    {

        int A = num1 - num2;
        int count = tmp.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    else
    {
        int A = num1 - num2;
        int count = pobj2.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);
    cout << pChTmp << endl;
    cout << strlen(pChTmp) << endl;
    cout << "decstr operator - (const decstr &pobj1,const decstr &pobj2)" << endl;
    return tmp;
}

decstr operator + (const decstr &pobj1, int num2)
{
    int num1;
    char *pChTmp;
    decstr tmp (pobj1);
    num1 = atoi(tmp.getstr());
    int numm2=num2;
    int num2size=0;
    while (numm2!=0)
    {
        numm2/=10;
        num2size ++;
    }
    if (tmp.len >= num2size)
    {

        int A = num1 + num2;
        int count = tmp.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    else
    {
        int A = num1 + num2;
        int count = num2size + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);
    cout << pChTmp << endl;
    cout << strlen(pChTmp) << endl;
    cout << "decstr operator + (const decstr &pobj1, int num2)" << endl;
    return tmp;
}

decstr operator + (int num1, const decstr &pobj2)
{
    int num2;
    char *pChTmp;
    decstr tmp (pobj2);
    num2 = atoi(tmp.getstr());
    int numm1=num1;
    int num1size=0;
    while (numm1!=0)
    {
        numm1/=10;
        num1size ++;
    }
    if (tmp.len >= num1size)
    {

        int A = num1 + num2;
        int count = tmp.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    else
    {
        int A = num1 + num2;
        int count = num1size + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);
    cout << pChTmp << endl;
    cout << strlen(pChTmp) << endl;
    cout << "decstr operator + (int num1, const decstr &pobj2)" << endl;
    return tmp;
}

decstr operator + (const decstr &pobj1,const char* pobj2)
{
    int num1,num2;
    char *pChTmp;
    decstr tmp (pobj1);
    num1 = atoi(tmp.getstr());
    num2 = atoi(pobj2);
    if (tmp.len >= strlen(pobj2))
    {

        int A = num1 + num2;
        int count = tmp.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    else
    {
        int A = num1 + num2;
        int count = strlen(pobj2) + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);
    cout << pChTmp << endl;
    cout << strlen(pChTmp) << endl;
    cout << "decstr operator + (const decstr &pobj1,const char* pobj2)" << endl;
    return tmp;
}

decstr operator + (const char* pobj1,const decstr &pobj2)
{
    int num1,num2;
    char *pChTmp;
    decstr tmp (pobj1);
    num1 = atoi(tmp.getstr());
    num2 = atoi(pobj2.getstr());
    if (tmp.len >= pobj2.len)
    {

        int A = num1 + num2;
        int count = tmp.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    else
    {
        int A = num1 + num2;
        int count = pobj2.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);
    cout << pChTmp << endl;
    cout << strlen(pChTmp) << endl;
    cout << "decstr operator + (const char* pobj1,const decstr &pobj2)" << endl;
    return tmp;
}