#include <vector>

class Shape
{
protected:
   static long square(long x)
    {
        return (x * x);
    }
private:
std::vector<std::pair<long, long> > points;
public:
Shape()
{}

void print()
{
    for(int obj=0;obj<points.size();obj++)
        cout<<'('<<points[obj].first<<';'<<points[obj].second<<")\n";
}

void push_back(long x,long y)
{
    points.push_back(std::pair<long, long>(x, y));
}

void push_back(std::pair<long, long> point)
{
    points.push_back(point);
}

long distanceBetweenPoints(std::pair<long, long> point1,std::pair<long, long> point2)
{
        return sqrt(std::pow(point2.first-point1.first,2)+std::pow(point2.second-point1.second,2));
}

long perimeter(std::vector<std::pair<long, long> > points)
{
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
        perimeter+=distanceBetweenPoints(points[i-1],points[i]);
        perimeter+= distanceBetweenPoints(*prev,*curr);
        ++prev;
        ++curr;
    }
    perimeter+= distanceBetweenPoints(points.back(),points.front());
    return perimeter;
}
long perimeter(){
        long perimeter = distanceBetweenPoints(points[0],points[1]);
        return perimeter;
    }

~Shape(){points.clear();}
};