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
void find();

int main() {
    int choice = 0, total_nodes = 0, search_element;
    while(choice != 9) {
        printf("\n\n **** MENU DRIVEN LINKED LIST ****");
        printf("\n1. Create a list");
        printf("\n2. Display the list");
        printf("\n3. Find a node");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter total number of nodes : ");
                    scanf("%d",&total_nodes);
                    create_list(total_nodes); break;
            case 2: display_list(); break;
            case 3: printf("\nEnter an element to search : ");
                    scanf("%d",&search_element);
                    find(search_element); break;
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

void find(int n) {
    struct node *current = start;
    if(start == NULL) {
        printf("Cannot find %d",n);
    }else {
        while(current != NULL) {
            if(current->data == n) {
                printf("%d found",n);
                return;
            }
            current = current->next;
        }
        printf("%d does'nt exists in the list",n);
    }
}