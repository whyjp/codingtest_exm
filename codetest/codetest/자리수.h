#pragma once

#include <math.h>

//
//int dLen(int a)
//{
//    if (a == 0)
//        return 1;
//    return static_cast<int>(log10(a)) + 1;
//}
//bool compare(int a, int b)
//{
//    int aL = dLen(a);
//    int bL = dLen(b);
//
//    int ab = a * pow(10, bL) + b;
//    int ba = b * pow(10, aL) + a;
//    return ab > ba;
//}
int dLen(int a)
{
    if (a == 0)
        return 1;
    return static_cast<int>(log10(a)) + 1;
}