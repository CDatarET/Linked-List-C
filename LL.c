#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void addToTail(struct node *head, int val){
    struct node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    current->next = newNode;
}

void disp(struct node *head){
    struct node *current = head->next;
    while(current != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct node head = {0, NULL};
    addToTail(&head, 1);
    addToTail(&head, 2);
    addToTail(&head, 3);
    disp(&head);

    return 0;
}
