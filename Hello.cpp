#include <iostream>
#include <algorithm>
#include "sotrtAlgorithm.h"
#include "figure.h"

/*
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
}*/
int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Triangle(/* координати вершин трикутника */));
    shapes.push_back(new Rectangle(/* координати вершин прямокутника */));

    for (Shape* shape : shapes) {
        std::cout << "Периметр: " << shape->perimeter() << std::endl;
        std::cout << "Площа: " << shape->area() << std::endl;

        if (shape->isSpecial()) {
            std::cout << "Це спеціальна фігура." << std::endl;
        } else {
            std::cout << "Це не спеціальна фігура." << std::endl;
        }

        delete shape;
    }

    return 0;
}
