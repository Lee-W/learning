#include <iostream>
#include <cmath>
using namespace std;

#define maxPower 31

int powerOf2[maxPower+1];

string toBin(int n) {
    string result = "";
    int tmpResult;
    for (int i = maxPower; i >= 0; i--) {
        tmpResult = floor(n / powerOf2[i]);
        n -= tmpResult * powerOf2[i];
        result += tmpResult + '0';
    }
    return result;
}

main()
{
    for (int i = 0; i < maxPower+1; i++)
        powerOf2[i] = (int)pow(2,i);
    cout << toBin(4) << endl;
    cout << toBin(8) << endl;
    cout << toBin(21) << endl;
}
