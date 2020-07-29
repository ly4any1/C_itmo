#ifndef LABA_IDENTSTR_H
#define LABA_IDENTSTR_H
#include "stroka.h"

class IdentStr: public stroka {
public:
    IdentStr(int=0);
    IdentStr(char ch);
    IdentStr(const char *);
    IdentStr(const IdentStr &);
    ~IdentStr();
    IdentStr & operator = (const IdentStr &);
    char & operator [] (int);
    IdentStr operator ~ ();
    friend IdentStr operator + (const IdentStr &, const IdentStr &);
    friend IdentStr operator + (const IdentStr &, const char *);
    friend IdentStr operator + (const char *, const IdentStr &);
};


#endif //LABA_IDENTSTR_H
