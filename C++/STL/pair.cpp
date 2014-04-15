#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<double,double>point;

void setPoint(point&,int,int);

main()
{
    point p1;
    setPoint(p1,5,6);

    cout << "P1 is ("<< p1.first <<" , "<<p1.second <<")"<<endl;
    cout<<endl;

    point p2;
    setPoint(p2,5,6);
    cout << "P1 is ("<< p1.first <<" , "<<p1.second <<")"<<endl;
    cout << "P2 is ("<< p2.first <<" , "<<p2.second <<")"<<endl;
    cout << "Are p1 and p2 the same? " << ( (p1==p2) ? "yes":"no") <<endl;
    cout<<endl;

    point p3;
    setPoint(p3,4,6);
    point p4;
    setPoint(p4,6,5);
    point p5;
    setPoint(p5,5,4);

    cout<<"P3 < P4 "<< ((p1==p2)? "yes":"no")<<endl;

    point p[5];
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;

    sort(p,p+5);
    for (int i = 0; i < 5; i++)
        cout<<p[i].first<<"\t"<<p[i].second<<endl;
}

void setPoint(point&p , int x, int y) {
    p.first = x;
    p.second = y;
}
