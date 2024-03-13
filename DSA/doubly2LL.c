#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
struct Node* prev;

};

void reversetraversal(struct Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* q = head;  // Initialize q with the current head

    // Move q to the last node
    while (q->next != NULL) {
        q = q->next;
    }

    struct Node* ptr = q;  // Initialize ptr with the last node

    // Traverse in reverse order
    while (ptr != NULL) {
        printf("The data at node is %d\n", ptr->data);
        ptr = ptr->prev;
    }
}




void forwardtraversal(struct Node* head){

 struct Node* ptr = head;
    while (ptr->next!=NULL)
    {
        printf("The data at node is %d\n",ptr -> data);

        ptr = ptr -> next;
        
    }

    
        printf("The data at node is %d\n",ptr -> data);
    
    }


//AddToEmpty Function to add create first node
struct Node* AddToEmpty(struct Node* head,int data){

struct Node* ptr;

   ptr = malloc(sizeof(struct Node));
    ptr ->next = NULL;
    ptr->data = data;
    ptr ->prev = NULL;
    head = ptr;

    return head;

}



//Add to end function to add node to end 
struct Node* AddToEnd(struct Node* head,int data){

struct Node* p;
p = head;

struct Node* ptr;
   ptr = malloc(sizeof(struct Node));
    ptr ->next = NULL;
    ptr->data = data;
    ptr ->prev = NULL;
    

   while (p->next!=NULL)
{
    p = p->next;

}

p->next = ptr;
ptr -> prev = p;

return head;
}



struct Node* CreateList(struct Node* head){
int nodes,data; 

    printf("enter no. of nodes:");
    scanf("%d",&nodes);

    if (nodes==0)
    {
        return head;
    }
    
    printf("enter data for 1st node:");
    scanf("%d",&data);

    head = AddToEmpty(head,data);


for (size_t i = 1; i < nodes; i++)
{
     printf("enter data for %d node:",i+1);
     scanf("%d",&data);
     head = AddToEnd(head,data);
}

   return head;
}


int main(){

struct Node* head = NULL;

head = CreateList(head);

int choice;

do
{
    printf("1.forwardtraversal\n2.reverse traversal\n3.exit\nenter your choice:");
scanf("%d",&choice);

switch (choice)
{
case 1:
    forwardtraversal(head);
    break;

case 2:
    reversetraversal(head);
    break;




default:printf("invalid option no.");
    break;
}



} while (choice!=3);

   

}






