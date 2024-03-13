
#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node* next;

};






 struct Node* insertincll(struct Node* head,int data){
    struct Node* p = head ->next;
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr ->data = data;

    while (p->next!=head)
    {
        p=p->next;
        /* code */
    }
    p->next = ptr;
    ptr ->next = head;
    head = ptr;

    return head;

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
   third->next = head;
printf("Circular linked list before insertion:\n");
LLtraversal(head);
 head = insertincll(head,69);
printf("Circular linked list after insertion:\n");
LLtraversal(head);

    return 0;
}


void LLtraversal(struct Node* head){

    struct Node* ptr = head;

    printf("The data at node is %d\n",ptr->data);
            ptr = ptr->next;

    while(ptr!=head){
        
            printf("The data at node is %d\n",ptr->data);
            ptr = ptr->next;
        
    }
    
}
