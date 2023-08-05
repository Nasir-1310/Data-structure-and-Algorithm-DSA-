#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*next;

};

struct node*delate_first_node(struct node*head)
{
    if(head==NULL)
    {
        printf("none\n");

    }
    else
    {
        struct node*temp;
        temp=head;
        head=head->next;
        cout<<temp->data<<endl;
        free(temp);
        temp=NULL;
    }
    return head;
};




struct node*delate_node_at_given_position(struct node*head,int position)
{
    if(head==NULL)
    {
        printf("none\n");
        return head;
    }
    else if (position==1)
    {
        head=delate_first_node(head);
        return head;
    }
    else
    {
        struct node*temp,*previous;
        temp=head;
        while(position!=1)
        {
            previous=temp;
            temp=temp->next;
            position--;
        }
        previous->next=temp->next;
        cout<<temp->data;
        free(temp);
        return head;
    }

}

struct node*insert_node_at_end(struct node*head,int item)
{
    struct node*temp,*node;
    node=(struct node*)malloc(sizeof(struct node));

    node->data=item;
    node->next=NULL;
    temp=head;
   if(temp==NULL)
   {
       head=node;
   }
else{
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;
    return head;
}
}

void print_list(struct node*head)
{
    struct node*temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Linked is is empty\n:");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main()
{
    struct node *head;

    head=(struct node*)malloc(sizeof(struct node));
     head=NULL;
    int t,v;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
         for(int j=0;j<n;j++)
         {
             cin>>v;
               head= insert_node_at_end(head,v);
         }

    cout<<"Case"<<" "<<i<<endl;

         for(int j=1;j<=m;j++)
         {

             char ch;
             cin>>ch>>v;
             if(ch=='a')
             {
                 cout<<v<<endl;
                  head= insert_node_at_end(head,v);
             }
             else{
                head=delate_node_at_given_position(head,v);
             }

         }
             print_list(head);

    }
}
