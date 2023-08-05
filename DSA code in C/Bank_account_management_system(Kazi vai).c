//Bank account management system
#include<stdio.h>
int a[10]= {0,0,0,0,0};


void Account(int acc_num,int value)
{


    if(value==1)
    {
        printf("Your account Balance  %d tk\n\n",a[acc_num]);

    }
    else if (value==2)
    {
        printf("Enter amount of Money\n");
        int amount ;
        scanf("%d",&amount);
        a[acc_num]+=amount;
        printf("Successfully added!\n\n");
    }


    else if (value==3)
    {
        printf("Enter amount of Money\n");
        int amount ;
        scanf("%d",&amount);
        if(a[acc_num]<amount)
        {
            printf("Insufficient Balance! please Try again!!\n");
        }
        else
        {
            a[acc_num]-=amount;
            printf("Successfully Withdraw!\n\n");
        }
    }

    else if (value==4)
    {
        printf("Enter Recipient Account Number\n");
        int account_number;
        scanf("%d",&account_number);
        printf("Enter Amount\n");
        int amount ;
        scanf("%d",&amount);
        if(a[acc_num]<amount)
        {
            printf("Insufficient Balance! please Try again!!\n");
        }
        else
        {
            a[acc_num]-=amount;
            a[account_number]+=amount;
            printf("Send Successfully \n\n");
        }

    }
}


int main()
{
    int acc_num,value=1;
    while(value)
    {
        printf("Enter Your account number 1000000, 2000000, 3000000, 4000000, 5000000, 600000, 7000000\n");
        scanf("%d",&acc_num);
        acc_num=acc_num/1000000;
        printf("Enter any key\n1.Check Balance\n2.Add Money\n3. Withdraw Money\n4.Send Money\nPress 0 for Exit\n\n");
        scanf("%d",&value);
        Account(acc_num,value);
    }
}


