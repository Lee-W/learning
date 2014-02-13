#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void initialVector(int&);
template<typename T> void printElement(T elem, string s);

void printMapElement(pair<const int,char>);

main ()
{
    vector<int>v(10);
    for_each(v.begin(), v.end(), initialVector);        //without parameter
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(printElement<int>), "parameter"));     //with one parameter and using template

    map<int,char>m;
    m[5] = 'a';
    m[20] = 'c';
    m[100] = '5';
    m[2] = 'w';
    m[8] = '@';
    for_each(m.begin(), m.end(),printMapElement);   //for_each for map

}

void initialVector(int& e) {
    e = 5;
}

template<typename T> void printElement(T elem, string s) {
    cout<<elem<<"\t"<<s<<endl;
}

void printMapElement(pair<const int,char> e) {
    cout<<e.first<<"\t"<<e.second<<endl;
}
