#include <iostream>
#include <algorithm>
#include "sotrtAlgorithm.h"
#include "figure.h"
#include <cmath>
int main() {
    class Shape shape;
    long x, y,x1,y1,x2,y2;
    cin >> x >> y;
    cin>>x1>>y1;
    cin>>x2>>y2;
    shape.push_back(x, y);
    shape.push_back(x1,y1);
    shape.push_back(x2,y2);
    cout<<'\n';
    cout<<shape.perimeter();
    cout<<'\n';
    cout<<shape.triangArea();
    cout<<'\n';
    shape.print();
    return 0;
}