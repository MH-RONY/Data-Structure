#include<stdio.h>
merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

merge(int arr[],int l,int m,int r)
{
    int i,j,k,n1=m-l+1,n2=r-m;
    int larr[n1],rarr[n2];
    for(i=0;i<n1;i++)
    {
        larr[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        rarr[j]=arr[m+1+j];
    }
    i=0;j=0,k=0;

    while(i<n1 && j<n2)
    {
        if(larr[i]<=rarr[j])
        {
            arr[l+k]=larr[i];
            i++;
        }
        else
        {
            arr[l+k]=rarr[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[l+k]=larr[i];
        i++;k++;
    }
    while(j<n2)
    {
        arr[l+k]=rarr[j];
        j++;k++;
    }
}

void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int arr[]={12,11,13,5,6,7};
    int array_size=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",array_size);
    printf("Given array is= \n");
    print(arr,array_size);

    merge_sort(arr,0,array_size-1);

    printf("\nSorted array is \n");
    print(arr,array_size);
    return 0;
}
