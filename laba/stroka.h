#ifndef LABA_STROKA_H
#define LABA_STROKA_H


class stroka{
protected :
    int len;
    char *pCh;
public:
    stroka (int=0);
    stroka (char ch);               //stroka obj('z');
    stroka (const char *);          //stroka obj1("itmo");
    stroka (const stroka &);        //stroka obj2=obj1;
    ~stroka();
    char *getstr(void)const
    {
        return pCh;
    }
    int getlen(void)const
    {
        return len;
    }
    void show(void);
};


#endif //LABA_STROKA_H
