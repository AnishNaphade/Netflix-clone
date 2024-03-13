
#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node* next;

};



void LLtraversal(struct Node* ptr){
    while(ptr!=NULL){
        
            printf("The data at node is %d\n",ptr->data);
            ptr = ptr->next;
        
    }
}


//Case:1 deleting the node at the beginning

 struct Node* deletefirst(struct Node* head){
    

    struct Node* ptr = head;

    head = head -> next;
    free(ptr);

    return head;

}


//Case:2 deleting a node at an index

 void deleteinbetween(struct Node* head,int index){
    
struct Node* p = head;

for (size_t i = 0; i < index-1 ; i++)
{
    p = p->next;
}


struct Node* ptr = p->next;
p -> next = ptr ->next;
free(ptr);


}


//Case:3 deleting the last node

void deletelastnode(struct Node* head){
    
struct Node* p = head;
struct Node* q = head->next;

while (q->next!=NULL)
{
    q = q->next;
    p = p->next;
}

p -> next = NULL;
free(q);


}



//Case:3 deleting the node with value

void deletevalue(struct Node* head,int value){
    
struct Node* p = head;
struct Node* q = head->next;

while (q->data != value && q -> next != NULL)
{
    q = q->next;
    p = p->next;
}

if(q->data=value){

    p->next = q->next;
    free(q);

}



}












int  main()
{


struct Node* head;
struct Node* second;
struct Node* third;



head = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));



head->data = 7;
head->next = second;


second->data = 8;
   second->next = third; 

   third->data = 9;
   third->next = NULL;

printf("The Linked list before deletion is:\n");
LLtraversal(head);

//head = deletefirst(head);

//deleteinbetween(head,0);

//deletelastnode(head);

deletevalue(head,9);//doesnt work for 1st node

printf("The Linked list after deletion is:\n");
LLtraversal(head);


    return 0;
}
