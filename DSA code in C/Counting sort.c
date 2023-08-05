//Uses -> there are similar integers with multiple count/ Linear complexity is needed
//Time complexity O(n+r)
//Space complexity O(max)
//Stability Yes
#include<stdio.h>
print_array(int final_arr[],int size)
{
    printf("Sorted array is :");
    for(int i=0; i<size; i++)
    {
        printf("%d ",final_arr[i]);
    }
}

void counting_sort(int arr[],int final_arr[],int size)
{
    //int final_arr[size];
    int max=-100;
    for(int i=0; i<size; i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    int count[max+1];
    for(int i=0; i<max+1; i++)
    {
        count[i]=0;
    }
    for(int i=0; i<size; i++)
    {

        count[arr[i]]++;
    }
    printf("\n");

    for(int i=1; i<max+1; i++)
    {
        count[i]=count[i-1]+count[i];
    }
    for(int i=0; i<size; i++)
    {
        printf("-- count ->arr i %d\n ",--count[arr[i]]);
        final_arr[- -count[arr[i]]]=arr[i];
    }

}
int  main()
{

    int arr[]= {1,2,4,3,0,2,1,7,1,4,3,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    int final_arr[size];
    counting_sort(arr,final_arr,size);

    print_array(final_arr,size);
    return 0;

}
