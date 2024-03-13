#include<stdio.h>
#include<stdlib.h>

//Creating entire doublyLL
//Logic: Creating first node using add to empty function
//creating subsequent nodes using add to end function
//calling them in create list function 

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* AddToEmpty(struct Node* head,int data);
struct Node* AddToEnd(struct Node* head,int data);
struct Node* deletefirst(struct Node* head);








//CREATELIST FUNCTION 
struct Node* CreateList(struct Node* head){

int data,nodes;

printf("Enter number of Nodes:");
scanf("%d",&nodes);

if (nodes==0)
{
    return head;
}

printf("Enter data for 1st Node:");
scanf("%d",&data);

head = AddToEmpty(head,data);

for (size_t i = 1; i < nodes; i++)
{
    printf("Enter data for %d node:",i+1);
    scanf("%d",&data);
    head = AddToEnd(head,data);
}
return head;

}


//FORWARD TRAVERSAL
void forwardtraversal(struct Node* head){
struct Node* p;
p = head;

while (p->next!=NULL)
{
    printf("The data at node is %d\n",p->data);
    p = p->next;

}
printf("The data at node is %d\n",p->data);

}




//MAIN METHOD
int  main(){
    struct Node* head = NULL;
    head = CreateList(head);
    printf("The List before deleting:\n");
forwardtraversal(head);
deletelast(head);
printf("The List after deleting:\n");
forwardtraversal(head);

return 0;

}




//ADD TO EMPTY FUNCTION
struct Node* AddToEmpty(struct Node* head,int data){

struct Node* ptr;
ptr = (struct Node*)malloc(sizeof(struct Node));

ptr->prev = NULL;
ptr->data = data;
ptr->next = NULL;

head = ptr;

return head;

}



//ADD TO END FUNCTION
struct Node* AddToEnd(struct Node* head,int data){

struct Node* q;
q = head;

struct Node* ptr;
ptr = (struct Node*)malloc(sizeof(struct Node));

ptr->prev = NULL;
ptr->data = data;
ptr->next = NULL;

while (q->next!=NULL)
{
    q = q->next;
}

q->next = ptr;
ptr ->prev = q;

return head;

}



//DELETE FIRST
    struct Node* deletefirst(struct Node* head){
    
    struct Node* ptr = head;

    head = head -> next;
    free(ptr);

    return head;

    }

   
   //DELETE LAST 
 void deletelast(struct Node* head){
    
    struct Node* ptr = head;
struct Node* p=head->next;

while (p->next!=NULL)
{
    p = p->next;
    ptr=ptr->next;

}

free(p);

ptr->next=NULL;
 }
    

    


