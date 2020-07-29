//
// Created by Никита Лычаный on 2019-04-05.
//

#ifndef LABA_DECSTR__H
#define LABA_DECSTR__H
#include "stroka.h"

class decstr: public stroka
{
public:
    decstr (int=0);
    decstr (const char *);
    decstr (const decstr &);
    ~decstr();
    decstr & operator = (const decstr &);
    friend decstr operator + (const decstr &, const decstr &);
    friend decstr operator - (const decstr &, const decstr &);
    friend decstr operator + (const decstr &, int);
    friend decstr operator + (int, const decstr &);
    friend decstr operator + (const decstr &, const char*);
    friend decstr operator + (const char*, const decstr &);
};

#endif //LABA_DECSTR__H
