#include<bits/stdc++.h>
using namespace std;
struct node{
             string name;
             int account_number;
             string type;
             int total_balance;
             struct node*next;
              };

    struct node*root=NULL;



struct node*Deposite_balance(struct node*root,int acc_num,int amount)
{

    struct node*node;
          node=root;
          if(node==NULL)
          {
              printf("Sorry Have not any account\n");
              return 0;
          }

          else if(node->account_number==acc_num)
        {

                node->total_balance=node->total_balance+amount;
                return root;

        }
        while(node->next!=NULL)
        {
            if(node->account_number==acc_num)
            {


                node->total_balance=node->total_balance+amount;
                return root;

            }
            node=node->next;
        }
}



struct node*withdraw_money(struct node*root,int acc_num,int amount)
          {
          struct node*node;
          node=root;
          if(node==NULL)
          {
              printf("Sorry Have not any account\n");
              return 0;
          }

          else if(node->account_number==acc_num)
        {
            if(node->total_balance<amount)
            {
                printf("Not enough Balance\n");
            }
            else {
                node->total_balance=node->total_balance-amount;
                return root;
            }
        }
        while(node->next!=NULL)
        {
            if(node->account_number==acc_num)
            {
                if(node->total_balance<amount)
                  {
                printf("Not enough Balance\n");
                  }
            else {
                node->total_balance=node->total_balance-amount;
                return root;
                  }
            }
            node=node->next;
        }
      }



    struct node*create_node(int item)
    {
        struct node*node=(struct node*)malloc(sizeof(struct node));
        node->account_number=item;
        node->total_balance=NULL;
        //node->type=NULL;
        node->next=NULL;
        return node;
    }



    struct node*add_new_account(struct node*root)
    {
        struct node*temp,*node;
        temp=root;
        int acc_num;
        printf("Enter your account number\n ");
        scanf("%d",&acc_num);

        node=create_node(acc_num);
        printf("Enter name:");
        string name;
        cin>>name;

        printf("Enter type");
        string type;

        cin>>type;
        int total_balance=0;
        node->name=name;
        node->total_balance=total_balance;
        node->type=type;
        if(root==NULL)
        {
            root=node;
            return root;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
        printf("Account create Successfully\n");
        return root;

    }


    void print_balance(struct node*root,int acc_num)
    {
        struct node*node;
        node=root;
        if(node->account_number==acc_num)
        {
            printf("Account balance : %d",node->total_balance);
        }
        while(node->next!=NULL)
        {
            if(node->account_number==acc_num)
            {
                printf("%d",node->total_balance);
                break;
            }
            node=node->next;
        }
    }


void Account(int value)
{

    if(value==1)
    {
        root=add_new_account(root);

    }
    else if (value==2)
    {
        printf("Enter Your account number\n");
        int acc_num;
        cin>>acc_num;
        print_balance(root,acc_num);

    }

    else if (value==3)
    {
        int acc_num,amount;
        printf("Enter account number\n");
        cin>>acc_num;
        printf("Enter amount of Money\n");
        scanf("%d",&amount);
        struct node*temp;
        temp=withdraw_money(root,acc_num,amount);

    }

    else if (value==4)
    {
       int acc_num,amount;
        printf("Enter account number\n");
        cin>>acc_num;
        printf("Enter amount of Money\n");
        scanf("%d",&amount);
        struct node*temp;
        temp=Deposite_balance(root,acc_num,amount);

    }
}


int main()
{
     int value=1,choice;

    while(value){
    printf("Enter your choice\n 1. Add new account\n2.Display current balance\n3.Withdraw Balance\n4.Deposit money\nPress 0 to exit\n");
    cin>>value;
    Account(value);

    }


}
