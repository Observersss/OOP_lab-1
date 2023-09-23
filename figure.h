#include <vector>

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
long perimeter(/*std::vector<std::pair<long, long> > points*/)
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