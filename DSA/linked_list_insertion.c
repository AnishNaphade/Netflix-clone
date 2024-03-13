#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node* next;

};




struct Node* insertatbeginning(struct Node* head,int data){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));


ptr ->next = head;
ptr ->data = data;

return  ptr;

}



struct Node* insertatindex(struct Node* head, int data, int index){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

struct Node* p = head;

int i = 0;
while(i!=index-1){
    p = p->next;
}

ptr -> data = data;
ptr -> next = p -> next;
p -> next = ptr;

return ptr;
}



struct Node* insertatend(struct Node* head,int data){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

struct Node* p = head;

int i = 0;
while(p->next!=NULL){
    p = p->next;
}

p -> next = ptr;
ptr -> next = NULL;
ptr -> data = data;


return  ptr;
}



struct Node* insertafternode(struct Node* head,struct Node* prevNode,int data){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
ptr -> data = data;

ptr->next = prevNode -> next;
prevNode-> next = ptr;

return ptr;
}




void LLtraversal(struct Node* ptr){
    while(ptr!=NULL){
                      
            printf("The data at node is %d\n",ptr->data);
            ptr = ptr->next;
        
    }
    printf("\n");
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

printf("The Linked list before insertion is:\n");
LLtraversal(head);

 head = insertatbeginning(head,77);

 //insertatindex(head,99,1); //doesnt work if we want to insert in the beginning

// insertatend(head,97);

 //insertafternode(head,third,88);//doesnt work if we want to insert in the beginning

 printf("The Linked list after insertion is:\n");
 LLtraversal(head);

    return 0;
}
