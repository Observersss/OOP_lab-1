

class Shape
{
private:

protected:
struct point
{
    double x;
    double y;
};

public:

    virtual double calculatePerimeter()const=0;
    virtual double calculateArea() const = 0;
    virtual bool isSpecial() const = 0;
};

class Triangle:public Shape
{
private:
    point a,b,c;
public:
    Triangle(point p1,point p2, point p3):a(p1),b(p2),c(c)
    {}

    double calculatePerimeter() const override 
    {
        double sideAB = distance(a, b);
        double sideBC = distance(b, c);
        double sideCA = distance(c, a);
        return sideAB + sideBC + sideCA;
    }
}