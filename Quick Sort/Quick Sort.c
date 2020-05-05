#include<stdio.h>
void quick_sort(int array[],int low,int high)
{
    if(low>=high)
    {
        return ;
    }
    else
    {
        int p;
        p=partition(array,low,high);

        quick_sort(array,low,p-1);
        quick_sort(array,p+1,high);
    }
}

int partition(int array[],int low,int high)
{
    int i=low-1,j,t,pivot;
    pivot=array[high];
    for(j=low;j<high;j++)
    {
        if(array[j]<pivot)
        {
            i=i+1;
            t=array[j];
            array[j]=array[i];
            array[i]=t;
        }
    }

    t=array[high];
    array[high]=array[i+1];
    array[i+1]=t;
    return i+1;
}

int main()
{
    int array[5]={10,5,3,12,2};
    quick_sort(array,0,4);
    printf("Sorted array= ");
    for(int i=0;i<5;i++)
    {
        printf("%d ",array[i]);
    }
}
