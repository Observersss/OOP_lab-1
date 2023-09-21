#include <vector>

class Shape
{
private:
std::vector<std::pair<long, long>> points{};
public:
Shape()
{}
void push_back(long x,long y){
    points.push_back(std::pair<long, long>{x, y});
}

void push_back(std::pair<long, long> point){
    points.push_back(point);
}
    friend void perimeter(std::vector<std::pair<long, long>> points){};
~Shape(){points.clear();};
};
long distanceBetweenPoints(std::pair<long, long> point1,std::pair<long, long> point2){
    long distance =sqrt(square((point2.first-point1.first))+(square(point2.second-point1.second)));
};
void perimeter(std::vector<std::pair<long, long>> points){

};
long square(long x)
{
return (x * x);
};