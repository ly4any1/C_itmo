#include "iostream"
#include "IdentStr.h"
using namespace std;

IdentStr::IdentStr(int val):stroka(val)
{
    cout << "IdentStr::IdentStr (int val):stroka (val),val=" << val << endl;
}

IdentStr::IdentStr(char ch):stroka(ch)
{
    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (ch >= 'A' && ch <= 'Z')))
    {
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        cout << "bad symbol" << endl;
    }
    cout << "IdentStr::IdentStr(char ch):stroka(ch)" << endl;
}

IdentStr::IdentStr(const char *str):stroka(str)
{
    if ((pCh[0] >= '0' && pCh[0] <= '9') || (pCh[0] == ' '))
    {
        cout << "bad symbol, pCh[0]=" << pCh[0] << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i=1; i<len;i++)
    {
        if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_')))
        {
            cout << "bad symbol, pCh[i]=" << pCh[i] << endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    const char *keywords[] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "asm", "bool", "catch", "class", "const_cast", "delete", "dynamic_cast", "explicit", "export", "false", "friend", "inline", "mutable", "namespace", "new", "operator", "private", "protected", "public", "reinterpret_cast", "static_cast", "template", "this", "throw", "true", "try", "typeid", "typename", "using", "virtual", "wchar_t", "_Bool", "_Complex", "_Imaginary", "restrict" };
    for (int i=0; i<67; i++)
    {
        if (!strcmp(pCh, keywords[i]))
        {
            cout << "Error!!!" << pCh << endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "IdentStr::IdentStr(const char *):stroka(char *)" << endl;
}

IdentStr::IdentStr (const IdentStr &from):stroka(from)
{
    cout << "IdentStr::IdentStr(const IdentStr & from):stroka(from)" << endl;
}
IdentStr::~IdentStr()
{
    cout << "IdentStr::~IdentStr()" << endl;
}

IdentStr & IdentStr:: operator = (const IdentStr &S)
{
    if(&S!=this)
    {
        delete[] pCh;
        len = strlen(S.pCh);
        pCh = new char[len + 1];
        strcpy(pCh,S.pCh);
    }
    cout << "IdentStr & IdentStr::operator=(const IdentStr &S)" << endl;
    return *this;
}

IdentStr IdentStr::operator ~ ()
{
    int i,j;
    char tmp;
    for (i=0,j=len-1;i<len/2;i++,j--)
    {
        tmp = pCh[i];
        pCh[i] = pCh[j];
        pCh[j] = tmp;
    }
    cout << "IdentStr & IdentStr::operator~()" << endl;
    return *this;
}

char & IdentStr::operator [](int index)
{
    if ((index >= 0) && (index < len))
    {
        cout << "char & IdentStr::operator[](int index)" << endl;
        return pCh[index];
    }
    return pCh[0];
}

IdentStr operator + (const IdentStr &obj1, const IdentStr &obj2)
{
    IdentStr tmp(obj1.getlen()+obj2.getlen());
    //strcpy (tmp.pCh,obj1.getstr());
    int i=0,j=0;
    while (tmp.pCh[i++]=obj1.pCh[j++]);
    --i;
    //strcat (tmp.pCh,obj2.getstr());
    //int i = obj1.getlen();
    j=0;
    while (tmp.pCh[i++]=obj2.pCh[j++]);
    cout << "IdentStr operator + (const IdentStr &obj1, const IdentStr &obj2)" << endl;
    return tmp;
}

IdentStr operator + (const IdentStr &obj1, const char *obj2)
{
    IdentStr tmp (obj1.getlen()+(int)strlen(obj2));
    int i=0, j=0;
    while (tmp.pCh[i++]=obj1.pCh[j++]);
    --i;
    j=0;
    while (tmp.pCh[i++]= *obj2++);
    cout << "IdentStr operator + (const IdentStr &obj1, const IdentStr &obj2)" << endl;
    return tmp;
}

IdentStr operator + (const char *obj1,const IdentStr &obj2)
{
    IdentStr tmp ((int)strlen(obj1)+obj2.getlen());
    int i=0, j=0;
    while (tmp.pCh[i++]= *obj1++);
    --i;
    j=0;
    while (tmp.pCh[i++]=obj2.pCh[j++]);
    cout << "IdentStr operator + (const IdentStr &obj1, const IdentStr &obj2)" << endl;
    return tmp;
}
