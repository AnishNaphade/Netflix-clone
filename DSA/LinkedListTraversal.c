
#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node* next;

};



void LLtraversal(struct Node* ptr){
    while(ptr!=NULL){
        for(int i = 1;i<4;i++){
            printf("The data at node %d is %d\n",i,ptr->data);
            ptr = ptr->next;
        }
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

LLtraversal(head);

    return 0;
}
