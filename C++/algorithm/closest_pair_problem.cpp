#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

void printPoint(pair<double,double>);
double countDistance(pair<double,double>,pair<double,double>);

main ()
{
    //this can be used only in c++11
    pair<double,double> point[10] = {{3, 3}, {1, 5}, {4, 6}, {2, 8}, {9, 9},{2, 1}, {7, 2}, {6, 5}, {9, 4}, {5, 9}};

    sort(point,point+10);
    for_each(point,point+10,printPoint);

    double minDistance = countDistance(point[0],point[1]);

    for (int i= 0; i < 10-1; i++)
        for (int j = i+1; j < 10; j++)
            if ((point[j].first - point[i].second) > minDistance)
                break;
            else
                minDistance = min(minDistance, countDistance(point[i],point[j]));
    cout<<minDistance<<endl;
}

void printPoint(pair<double,double>p) {
    cout<<p.first<<"\t"<<p.second<<endl;
}

double countDistance(pair<double,double>p1, pair<double,double>p2) {
    return sqrt(pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2));
}
