#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;

// Declarations of the method
void create_list();
void display_list();

int main() {
    int choice = 0, total_nodes = 0;
    while(choice != 9) {
        printf("\n\n **** MENU DRIVEN LINKED LIST ****");
        printf("\n1. Create a list");
        printf("\n2. Display the list");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter total number of nodes : ");
                    scanf("%d",&total_nodes);
                    create_list(total_nodes); break;
            case 2: display_list(); break;
        }
    }
}

void create_list(int n) {
    int num;
    struct node *temp, *fnNode;
    start = (struct node *)malloc(sizeof(struct node));
    if(start == NULL) {
        printf("\nMemory cannot be allocated");
    }else{
        printf("\nEnter value for node 1 : ");
        scanf("%d",&num);
        start->data = num;
        start->next = NULL;
        temp = start;
        for(int i=2;i<=n;i++) {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) {
                printf("\nMemory cannot be allocated");
            }else{
                printf("Enter value for node %d : ",i);
                scanf("%d",&num);
                fnNode->data = num;
                fnNode->next = NULL;
                temp->next = fnNode;
                temp = temp->next;
            }
        }
    }
}

void display_list() {
    struct node *temp;
    if(start == NULL) {
        printf("\nList is empty");
    }else{
        temp = start;
        printf("\nValues inside the list are -> ");
        while(temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->next;    
        }
    }
}