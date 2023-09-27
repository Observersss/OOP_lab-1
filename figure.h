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
#include <map>
struct Point {
    double x;
    double y;
};

class Shape {
protected:
    std::vector<Point> points;
public:
    Shape(const std::vector<Point>& pts) : points(pts) {}
    // Статичний метод для обчислення відстані між двома точками
    static double distanceBetweenPoints(const Point& p1, const Point& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
    virtual bool isSpecial() const = 0;
    double perimeter() const
    {
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
    double gaussArea() const{
        double totalArea = 0.0;
        int numVertices =points.size();

        for (int i = 0; i < numVertices; ++i) {
            const Point& currentPoint = points[i];
            const Point& nextPoint = points[(i + 1) % numVertices];

            totalArea += (currentPoint.x * nextPoint.y - nextPoint.x * currentPoint.y);
        }

        return std::abs(totalArea) / 2.0;
    }
    virtual ~Shape() {}
};

class Triangle : public Shape {
protected:
    enum TriangleType {
        Invalid,
        Equilateral,
        Isosceles,
        Right,
        Scalene

    };

public:
    static std::unordered_map<TriangleType, std::string> triangleMessages;
    Triangle(const std::vector<Point>& pts) : Shape(pts) {}
    void tria() const {
        triangleMessages.insert(make_pair(Invalid,"Данний трикутник не може існувати"));
        triangleMessages.insert(make_pair(Equilateral, "Трикутник рівносторонній"));
        triangleMessages.insert(make_pair(Isosceles, "Трикутник рівнобедрений"));
        triangleMessages.insert(make_pair(Right, "Трикутник є прямокутним"));
        triangleMessages.insert(make_pair(Scalene, "Данний трикутник не є спеціальним"));
    }
    bool isSpecial() const override {
        tria();
        // Перевірка чи є трикутник рівностороннім, рівнобедреним або прямокутним
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        double c = distanceBetweenPoints(points[2], points[0]);
        if (a + b <= c || b + c <= a || a + c <= b) {
            std::cout << triangleMessages[Invalid] << std::endl;
            return Invalid;
        }
        if (a == b && b == c)
            return Equilateral;

        if (a == b || b == c || a == c)
            return Isosceles;

        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
            return Right;

        return Scalene;
    }
//    void printTriangleType() const {
//        TriangleType type = isSpecial();
//        if (triangleMessages.find(type) != triangleMessages.end()) {
//            std::cout << triangleMessages[type] << std::endl;
//        } else {
//            std::cout << "Невідомий тип трикутника" << std::endl;
//        }
//    }
};
/*
class Quadrangle : public Shape {
private:
    std::vector<Point> points;

public:
    Quadrangle(const std::vector<Point>& pts) : points(pts) {}

    // Функція для обчислення периметра багатокутника
    double perimeter() const override {
        double perimeter = 0.0;
        int numVertices = points.size();

        for (int i = 0; i < numVertices; ++i) {
            perimeter += distanceBetweenPoints(points[i], points[(i + 1) % numVertices]);
        }

        return perimeter;
    }
    double area() const override {
        // Обчислення площі прямокутника за формулою Гаусса
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        return a * b;
    }

    bool isSpecial() const override {
        // Перевірка на спеціальний чотирикутник (наприклад, квадрат або ромб)
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        double c = distanceBetweenPoints(points[2], points[3]);
        double d = distanceBetweenPoints(points[3], points[0]);

        // Перевірка на квадрат
        if (a == b && b == c && c == d) {
            cout<<"Данний чотирикутник є квадратом\n";
            return true;
        }

        // Перевірка на ромб
        double diagonal1 = distanceBetweenPoints(points[0], points[2]);
        double diagonal2 = distanceBetweenPoints(points[1], points[3]);

        if (diagonal1 == diagonal2) {
            cout<<"Данний чотирикутник є ромбом\n";
            return true;
        }
        cout<<"Данний чотирикутник не є спеціальним\n";
        return false;
    }
};

class Pentagon : public Shape{
private:
    std::vector<Point> points;
public:
    Pentagon(const std::vector<Point>& pts) : points(pts) {}

    // Функція для обчислення периметра багатокутника
    double perimeter() const override {
        double perimeter = 0.0;
        int numVertices = points.size();

        for (int i = 0; i < numVertices; ++i) {
            perimeter += distanceBetweenPoints(points[i], points[(i + 1) % numVertices]);
        }

        return perimeter;
    }

    double area() const override {
        // Обчислення площі прямокутника за формулою Гаусса
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        return a * b;
    }
    bool isSpecial() const override {
        // Перевірка, чи є п'ятикутник ромбом
        double sideLength = distanceBetweenPoints(points[0], points[1]);
        for (int i = 1; i < 5; ++i) {
            if (std::abs(distanceBetweenPoints(points[i], points[(i + 1) % 5]) - sideLength) > 1e-6) {
                cout<<"Данний п'ятикутник не є ромбом\n";
                return false; // Якщо хоча б одна сторона не рівна іншим, то не ромб
            }
        }
        cout<<"Данний п'ятикутник є ромбом\n";
        return true; // Усі сторони рівні, це ромб
    }
};

class Polygon: public Shape{
private:
    std::vector<Point> points;
public:
    Polygon(const std::vector<Point>& pts) : points(pts) {}

    // Функція для обчислення периметра багатокутника
    double perimeter() const override {
        double perimeter = 0.0;
        int numVertices = points.size();

        for (int i = 0; i < numVertices; ++i) {
            perimeter += distanceBetweenPoints(points[i], points[(i + 1) % numVertices]);
        }

        return perimeter;
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
*/