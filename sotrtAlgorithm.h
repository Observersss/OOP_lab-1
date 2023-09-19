void insertion_sort(int *mas,int size=0)
{
    //Створення додаткових змінних та виконання алгоритму
    int buf=0;
    int i,j;
    
    for(i=1;i<size;i+=1)
    {
        buf=mas[i];
        j=i-1;
        while(j>=0&&mas[j]>buf)
        {
             mas[j + 1] = mas[j];
            j--;
        }
        mas[j+1]=buf;
    }

}