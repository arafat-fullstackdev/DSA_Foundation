#include <bits/stdc++.h>
using namespace std;

union Variant
{
    char myString[11];
    int myInteger;
    double myDouble;
};
int main()
{
    Variant v;
    v.myInteger = 32;
    printf("My Union Integer: %d\n", v.myInteger);

    v.myDouble = 4.4564235;
    printf("My Union Double: %f\n", v.myDouble);

    printf("My Union Integer 2: %d\n", v.myInteger);

    return 0;
}