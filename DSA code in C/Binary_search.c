//Binary search in C
//Time complexity O(log n)
//Space complexity O(1)

#include<stdio.h>
int main()
{
    int arr[]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int left,right,middle,search_value;
    printf("Enter value that you want to Search\n");
    scanf("%d",&search_value);
    left=0;
    right=size-1;
    while(right>=left)
    {
        middle=right-(right-left)/2;

        if(arr[middle]==search_value)
        {
            printf("Value %d is found in %d th index\n",search_value,middle);
            return 0;
        }
        else if (arr[middle]>search_value)
        {
            right=middle-1;
        }
        else if(arr[middle]<search_value)
        {
            left=middle+1;
        }

    }
    printf("Value %d is not found \n",search_value);
    return 0;
}
