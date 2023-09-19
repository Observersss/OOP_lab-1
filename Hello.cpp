 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include "sotrtAlgorithm.h"

using namespace std;

void print_mas(int *mas,int size=0)
{
for(int i=0;i<size;i+=1)
    {   
        cout<<"mas["<<i<<"] = ";
        cout<<mas[i]<<endl;
    }
}
int main()
{
    int mas[10]={4,98,2,4,0,124,5,8,32,140};
    cout<<sizeof(mas)/sizeof(mas[0])<<'\n';
    print_mas(mas,sizeof(mas)/sizeof(mas[0]));
    // for(int i=0;i<10;i+=1)
    // {   
    //     cout<<"mas["<<i<<"] = ";
    //     cout<<mas[i]<<endl;
    // }
    insertion_sort(mas,sizeof(mas)/sizeof(mas[0]));
    print_mas(mas,sizeof(mas)/sizeof(mas[0]));
    return 0;
}