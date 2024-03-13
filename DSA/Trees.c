#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * right;
    struct node * left;
};

struct node * newnode(int x){

    struct node * node=(struct node*)malloc(sizeof(struct node));
    node->data=x;
    node->right=NULL;
    node->left=NULL;
    return(node);

}



void postorder(struct node *root)  
{  
    if(root == NULL) 
    
        return;  
  
     
    postorder(root->left);  
  
      postorder(root->right); 
    printf("%d ",root->data);  
  
      
     
} 



void inorder(struct node *root)  
{  
    if(root == NULL) 
    
        return;  
  
     
    inorder(root->left);  
  
      
    printf("%d ",root->data);  
  
      
    inorder(root->right);  
} 



void preorder(struct node *root)  
{  
    if(root == NULL)  
        return;  
  
     printf("%d ",root->data);
    preorder(root->left);          
    preorder(root->right);  
} 



void main()
{
struct node * root=newnode(5);



  root->left=newnode(6);
  root->right=newnode(7);  

  

  root->left->left=newnode(8);
  root->left->right=newnode(9);
  root->right->left=newnode(10);
  root->right->right=newnode(11);


  int operation;
  int choice;


  do{
    
printf(" 1.inorder\n 2.preorder\n 3.postorder\n 4.insert\n enter your choice:");
scanf("%d",&operation);

  switch (operation)
  {

  case 1:
  printf("inorder traversal:\t");
    inorder(root);
printf("\n");
    break;

     case 2:
  printf("preorder traversal:\t");
    preorder(root);
printf("\n");
    break;

     case 3:
  printf("postorder traversal:\t");
    postorder(root);
printf("\n");
    break;

    case 4:
  printf("insert element:\t");


  break;
  
  default:
  printf("enter a valid choice\n");
    break;
    
  }printf("continue operation press 1 else press 0=");
    scanf("%d",&choice);}
  while (choice);
}














