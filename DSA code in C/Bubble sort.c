//Bubble sort in c
//Time complexity O(n*n)
//Space complexity O(1)

#include<stdio.h>
int main()
{
    int arr[]= {2,34,3,4,45,6,7,8,9};
    int swap,count =0;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Size is %d\n",size);
    for(int i=0; i<size-1; i++)
    {
        swap=0;
        for(int j=0; j<size-1-i; j++)
        {
            count ++;//to observe how many times loop rounded
            if(arr[j]>arr[j+1])      // use arr[j]<arr[j+1] for descending order
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap++;
            }
        }
        if(swap==0)
           break;// To control useless loop rounding
    }
    printf("Loop rounded %d times \n",count);
    printf("Sorted array in ascending order : ");
    for(int i=0; i<size; i++)
    {
        printf("%d  ",arr[i]);

    }
}
