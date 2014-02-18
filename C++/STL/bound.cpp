#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

main()
{
    vector<int> v;
    v.reserve(10);

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);

    cout << "Index : " <<endl;
    for (int i = 0; i < v.size(); i++)
        cout << i + 1 <<"\t";
    cout << "\nContent:" <<endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] <<"\t";
    cout << endl;

    cout<<"Since the bound is count through difference between begin, it's can be thought as 1-based"<<endl;
    vector<int>::iterator it;
    it = lower_bound(v.begin(), v.end(), 2);
    cout << "lower bound of 2 is " << it - v.begin() << endl;
    it = upper_bound(v.begin(), v.end(), 2);
    cout << "upper bound of 2 is " << it - v.begin() << endl;

    it = upper_bound(v.begin(), v.end(), 3);
    cout << "upper bound of 3 is " << it - v.begin() << endl;

    it = lower_bound(v.begin(), v.end(), 4);
    cout << "lower bound of 4 is " << it - v.begin() << endl;
    it = upper_bound(v.begin(), v.end(), 4);
    cout << "upper bound of 4 is " << it - v.begin() << endl;

}
