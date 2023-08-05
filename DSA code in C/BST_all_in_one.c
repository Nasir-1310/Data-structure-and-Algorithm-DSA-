#include<stdio.h>
struct node
{
    int data;
    struct node*parent;
    struct node*left;
    struct node*right;
};

struct node*create_node(int item)
{
    struct node*new_node=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->parent=NULL;
    return new_node;
};

struct node*insert_BST(struct node*root,struct node*node)
{
    struct node*current_node,*parent_node;
    if(root==NULL)
    {
        root=node;
        return root;
    }
    current_node=root;

    while(current_node!=NULL)
    {
        parent_node=current_node;
        if(current_node->data<node->data)
          current_node=current_node->right;
        else
            current_node=current_node->left;

    }
    if(parent_node->data<node->data)
    {
        parent_node->right=node;

        if(node!=NULL)
        node->parent=parent_node;
    }

    else {
        parent_node->left=node;
        if(node!=NULL)
        node->parent=parent_node;
    }
    return root;
};
void print_inorder(struct node*root)
{
    struct node*temp;
    temp=root;
    if(temp->left!=NULL)
      print_inorder(temp->left);
      printf("%d ",temp->data);
    if(temp->right!=NULL)
        print_inorder(temp->right);
}

    struct node*search_item_in_BST(root,item)
    {
        struct node *node;
        node=root;
        while(node!=NULL)
        {
            if(node->data==item)
            {
                return node;
            }
            else if(node->data>item)
                node=node->left;
            else
                node=node->right;
        }
        return node;
    };


    struct node*Max_node(struct node*root)
    {
        struct node*temp;
        temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp;
    };

    struct node*Min_node(struct node*root)
    {
        struct node*temp;
        temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;
    };

   struct node*Successor(struct node*root,int item)
   {
       struct node*temp,*node;
       temp=root;
    node=search_item_in_BST(root,item);
     if(node->right!=NULL)
     {
         node=node->right;
         while(node->left)
         {
             node=node->left;
         }
         return node;
     }

     if(node->parent->left==node)
     {
         node=node->parent;
            return node;
     }

     else
     {
         node=node->parent;
           if(node==node->parent->right)
                 return NULL;
            while(  node->parent!=NULL&&  node->parent->left==node )
            {
                node=node->parent;
            }
            return node;
     }

   };


   struct node*delate_node(struct node*root,int item)
   {
       struct node*node;
       node= search_item_in_BST(root,item);
       if(node->left==NULL && node->right==NULL)
       {
           if(node->parent->left=node)
            node->parent->left=NULL;
           else
            node->parent->right=NULL;
           free(node);
           node=NULL;
       }
       else if(node->left==NULL)
       {
           if(node->parent->left==node)
            node->parent->left=node->right;
           else
            node->parent->right=node->right;
            free(node);
            node=NULL;
       }
       else if(node->right==NULL)
       {
           if(node->parent->left==node)
            node->parent->left=node->left;
           else
            node->parent->right=node->left;
             free(node);
            node=NULL;
       }
       else {
        struct node*min_node=Successor(root,item);
        node->data=min_node->data;
        min_node->data=item;


        struct node*node_=delate_node(root,item);
         free(node);
            node=NULL;

       }
       return root;
   };

int main()
{
    int a[]={5,10,17,12,7,3,19,1,4};
    struct node*root,*node;
    int size=sizeof(a)/sizeof(a[0]);
    root=create_node(a[0]);
    for(int i=1;i<size;i++)
    {
        node=create_node(a[i]);

        root=insert_BST(root,node);
    }
     printf("Inorder traverse :");
    print_inorder(root);
    printf("\nEnter value that you want to search\n");
    int item;
    scanf("%d",&item);
    struct node*search_node=search_item_in_BST(root,item);
    if(search_node!=NULL)
           printf("%d is found in BST\n",search_node->data);
    else {
        printf("Oops! Node not found\n");
    }

    struct node*max;
    max=Max_node(root);
    printf("Max node is :%d\n",max->data);


    struct node*min;
    min=Min_node(root);
    printf("Min node is :%d\n",min->data);
    struct node*successor=NULL;
    printf("Enter value for which you want to find successor\n");
    int suc;
    scanf("%d",&suc);
    successor=Successor(root,suc);
    if(successor)
    printf("Successor is %d\n",successor->data);
    else
        printf("Invalid Information\n");
        printf("Enter value that you want to delate\n");
        int delate;
        scanf("%d",&delate);

        root=delate_node(root,delate);
        print_inorder(root);


    return 0;
}
//1 3 4 5 7 10 12 17 19
