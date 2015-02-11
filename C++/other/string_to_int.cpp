#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, const char *argv[])
{
    string five = "5";
    int five_int = atoi(five.c_str());

    cout << (five_int == 5) << endl;
    return 0;
}
