 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include "sotrtAlgorithm.h"
#include "figure3.h"
int main()
{
    class algorithm algo;
    int mas[10]={4,98,2,4,0,124,5,8,32,140};
    cout<<sizeof(mas)/sizeof(mas[0])<<'\n';
    int size =sizeof(mas)/sizeof(mas[0]);

    algo.print_mas(mas,sizeof(mas)/sizeof(mas[0]));
    int algorithm=0;
    cout<<"write algorithm fo start sort\n";
    cout<<"1 - insertion sort'\n"<<"2 - quick sort\n"<<"3 - merge sort\n";
    cin>>algorithm;
    if(algorithm==1){
        algo.insertion_sort(mas,sizeof(mas)/sizeof(mas[0]));
    }else if (algorithm==2)
    {
        algo.quicksort(mas,0,size-1);
    }else if(algorithm ==3)
    {
        int N=15;
    int arr[N], aux[N];
    srand(time(NULL));
 
    // генерируем случайный ввод целых чисел
    for (int i = 0; i < N; i++) {
        aux[i] = arr[i] = (rand() % 100) - 50;
    }
 
    // сортируем массив `arr`, используя вспомогательный массив `aux`
    algo.mergesort(arr, aux, 0, N - 1);
 
    if (algo.isSorted(arr))
    {
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
    }
    }
    algo.print_mas(mas,sizeof(mas)/sizeof(mas[0]));
    
    return 0;
}
