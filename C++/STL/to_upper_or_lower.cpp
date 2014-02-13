#include <cstdio>
#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;


main () {
    string str = "ABcDEfghiJkLmnOpQrStUVwXyZ";
    printf("original : %s\n",str.c_str());


    transform(str.begin(), str.end(), str.begin(), ::tolower);
    printf("lower : %s\n",str.c_str());

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    printf("upper : %s\n",str.c_str());
}
