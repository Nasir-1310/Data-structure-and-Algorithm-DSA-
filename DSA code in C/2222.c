#include<stdio.h>
#include<stdlib.h>

struct Nodeop
{
  char name[100];
  int Account_number;
  char Account_Type[10];
  int Total_Balance;
  struct Node* parent;
  struct Node *left,*right;
};

struct Node* getNode(char name[],int Account_number,char Account_Type[],int Total_Balance)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->name[100]=name;
    newnode->Account_number=Account_number;
    newnode->Account_Type[10]=Account_Type;
    newnode->Total_Balance=Total_Balance;

    return newnode;
}
struct Node* Insert(struct Node* root,char name[],int Account_number,char Account_Type[],int Total_Balance)
{
    if(root==NULL)
     return getNode(name,Account_number,Account_Type,Total_Balance);

    if(Account_number<=root->Account_number)
    {
        struct Node* temp;
        temp=Insert(root->left,name,Account_number,Account_Type,Total_Balance);
        root->left=temp;
        temp->parent=root;

    }

    else
    {
     struct Node* temp;
        temp=Insert(root->right,name,Account_number,Account_Type,Total_Balance);
        root->right=temp;
        temp->parent=root;
    }

    return root;
}
struct Node* tree_search(struct Node* root,int Account_number)
{
    if(root==NULL || root->Account_number==Account_number)
     return root;

    if(Account_number<=root->Account_number)
      return tree_search(root->left,Account_number);
     else
      return tree_search(root->right,Account_number);

}
void InorderTraverse(struct Node *root)
{
    if(root==NULL)
     return;

     InorderTraverse(root->left);
     printf("%s\t%d",root->name,root->Account_number);


     InorderTraverse(root->right);


}
void Add_Account(struct Node **root,char name[],int Account_number,char Account_Type[],int Total_Balance)
{

}
void Show_Balance(struct Node **root)
{  int Account_number;
   printf("Give the accoount_number to know balance-\n");
    scanf("%d",&Account_number);
    struct Node* temp=tree_search((*root),Account_number);
    printf("Balance is %d\n",temp->Total_Balance);
}

void WithDraw_Money(struct Node **root)
{
     int withdraw_amount,Account_number;
    printf("Give the accoount_number and amount of money to withdraw\n");
    scanf("%d%d",&Account_number,&withdraw_amount);
     struct Node* temp=tree_search((*root),Account_number);
    if(temp->Total_Balance<withdraw_amount)
    {
        printf("Amount of money to be withdrawn  from Account%d exceeds existing balance\n ");
 }
    else
    {
        temp->Total_Balance=temp->Total_Balance-withdraw_amount;

    }
}

void Deposite_money(struct Node **root)
{
    int deposite,Account_number;
   printf("Give the accoount_number and amount of money to deposite\n");
    scanf("%d%d",&Account_number,&deposite);
    struct Node* temp=tree_search(root,Account_number);
    temp->Total_Balance=temp->Total_Balance+deposite;
}


int main()
{
    struct Node* root=NULL;
    int num;
    char name[100];
    int Account_number;
    char Account_Type[10];
    int Total_Balance;
    printf("How many Accounts do you want to insert?\n");
    scanf("%d",&num);

    for(int i=1;i<=num;i++)
    {
        scanf("%s",name);
        scanf("%d",&Account_number);
        scanf("%s",Account_Type);
        scanf("%d",&Total_Balance);

      root=Insert(&root,name,Account_number,Account_Type,Total_Balance);

    }

    Show_Balance(&root);
    WithDraw_Money(&root);
    Deposite_money(&root);



}
