#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main()
{
    vector<int> a;
    a.push_back(5);
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);

    vector<int>::iterator it = find(a.begin(), a.end(), 5);
    if (it != a.end())
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;

    it = find(a.begin(), a.end(), 6);
    if (it != a.end())
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;
}
