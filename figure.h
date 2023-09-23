#include <vector>
/*
class Shape
{
private:
std::vector<std::pair<long, long> > points;
public:
//Базовий конструктор ініціалізації
Shape()
{}
//Вивід всіх точок у форматі (x;y)
void print()
{
    for (const auto& point : points) {
        std::cout << '(' << point.first << ';' << point.second << ")\n";
    }
}
//Додавання нової точки до вектору за допомогою make_pair
void push_back(long x,long y)
{
    points.push_back(std::make_pair(x, y));
}
//Функція відстані між двома точками
static long distanceBetweenPoints(std::pair<long, long> point1,std::pair<long, long> point2)
{
        //Математичний запис √( (Bx-Ay)^2 +(By-Ay)^2)
        return sqrt(std::pow(point2.first-point1.first,2)+std::pow(point2.second-point1.second,2));
}
//Функція знаходження периметру яка використовує ітератори
long perimeter()
{
    //Базовий випадок - невистачає точок
    if(points.size()<3)
    {
        cout<<"Неможливо знайти периметер з двох точок\n";
        return 0;
    }
    int i=1;
    long perimeter=0;

    auto prev = points.begin();
    auto curr=prev+1;

    while (curr!=points.end())
    {
        perimeter+= distanceBetweenPoints(*prev,*curr);
        ++prev;
        ++curr;
    }
    perimeter+= distanceBetweenPoints(points.back(),points.front());
    return perimeter;
}
//Функція площі трикутника за Героном
long triangArea()
{
    if(points.size()<3)
    {
        cout<<"Неможливо знайти площу з двох точок\n";
        return 0;
    }
    //Для обчислення площі трикутника використовується формула Герона,яка використовує половину периметру
    // (p) та довжини сторін (a, b, c):
    long p=perimeter();
    long a = distanceBetweenPoints(points[0],points[1]);
    long b = distanceBetweenPoints(points[1],points[2]);
    long c = distanceBetweenPoints(points[2],points[0]);

    long area = sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}
//Деструктор
~Shape(){points.clear();}
};
*/
#include <cmath>

struct Point {
    double x;
    double y;
};

class Shape {
public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual bool isSpecial() const = 0;

    virtual ~Shape() {}

    // Статичний метод для обчислення відстані між двома точками
    static double distanceBetweenPoints(const Point& p1, const Point& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

class Triangle : public Shape {
private:
    std::vector<Point> points;

public:
    Triangle(const std::vector<Point>& pts) : points(pts) {}

    double perimeter() const override {
        // Обчислення периметру трикутника
        double p = 0.0;
        for (int i = 0; i < 3; ++i) {
            p += distanceBetweenPoints(points[i], points[(i + 1) % 3]);
        }
        return p;
    }

    double area() const override {
        // Обчислення площі трикутника за формулою Гаусса
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        double c = distanceBetweenPoints(points[2], points[0]);
        double s = (a + b + c) / 2.0;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    bool isSpecial() const override {
        // Реалізація для перевірки спеціальних трикутників
        // ...
    }
};

class Rectangle : public Shape {
private:
    std::vector<Point> points;

public:
    Rectangle(const std::vector<Point>& pts) : points(pts) {}

    double perimeter() const override {
        // Обчислення периметру прямокутника
        // ...
    }

    double area() const override {
        // Обчислення площі прямокутника за формулою Гаусса
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        return a * b;
    }

    bool isSpecial() const override {
        // Реалізація для перевірки прямокутників
        // ...
    }
};

