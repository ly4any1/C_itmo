#include <iostream>
#include "stroka.h"
#include "IdentStr.h"
#include "decstr.h"
using namespace std;
extern "C" char* __stdcall fun1(int);

int main()
{
    stroka obj1(0);
    stroka obj2(3);
    obj2.show();
    stroka obj3('s');
    obj3.show();
    stroka obj4("csgo");
    obj4.show();
    stroka obj5=obj1;
    obj5.show();

    IdentStr obj1_(5);
    IdentStr obj2_('c');
    IdentStr obj3_("iTMO");
    IdentStr obj4_(0);
    IdentStr obj5_("auto");
    IdentStr obj6_(" 12");
    IdentStr obj7_("1PBKS");
    IdentStr obj8_("SLOG");
    obj1_=obj2_;
    obj3_[2];
    obj3_=obj3_+obj8_;
    obj3_.show();
    obj8_=obj8_+"HELLO";
    obj8_.show();
    obj7_="GOOD"+obj3_;
    obj7_.show();

    decstr _obj1(2);
    decstr _obj2("a421");
    decstr _obj3("123");
    decstr _obj4(" 1");
    decstr _obj5=_obj3;
    decstr _obj6(0);
    _obj6=_obj2;
    _obj3=_obj3+_obj5;
    _obj4=_obj3-_obj5;
    decstr _obj7("-55");
    _obj6=_obj3-_obj7;
    _obj4=_obj3+_obj7;
    _obj4=_obj4+123;
    _obj6=12+_obj6;
    _obj4="456"+_obj4;
    _obj6=_obj6+"333";

    char* k = fun1(9090);
    cout << k << endl;

    return 0;
}
