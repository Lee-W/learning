#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void uniqueSort(vector<int>& v) {
    sort(v.begin(), v.end());
    vector<int>::iterator it = unique(v.begin(), v.end());
    v.erase(it, v.end());
}

main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);

    uniqueSort(v);
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;
}
