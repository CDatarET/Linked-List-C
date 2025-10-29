/*
Authored by Chaitanya Datar
Panel F1 #8
1262242226
*/ //is there anything wrong? assume head is dummyhead and real head is head.next 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int prn;
    char name[20];
    struct node *next;
};

void addToTail(struct node *head){
    printf("enter prn: ");
    int prn;
    scanf("%d", &prn);

    printf("enter name: ");
    char name[20];
    scanf("%s", name);
    printf("\n");

    struct node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->prn = prn;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    current->next = newNode;
}

int len(struct node *head){
    struct node *current = head;
    int ret = 0;
    while(current->next != NULL){
        ret++;
        current = current->next;
    }
    return(ret);
}

void deleteAtIndex(struct node *head){
    printf("enter index to delete: ");
    int index;
    scanf("%d", &index);

    if(index < 0 || len(head) <= index){
        printf("Invalid position\n");
        return;
    }

    struct node *current = head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    printf("deleted %s at index %d\n", current->next->name, index);
    current->next = current->next->next;
}

void addAtIndex(struct node *head){
    printf("enter prn: ");
    int prn;
    scanf("%d", &prn);

    printf("enter name: ");
    char name[20];
    scanf("%s", name);
    printf("\n");

    printf("enter index: ");
    int index;
    scanf("%d", &index);

    if(len(head) < index || index < 0){
        printf("Invalid position\n");
        return;
    }

    struct node *current = head;
    for(int i = 0; i < index; i++){
        current = current->next;

    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->prn = prn;
    strcpy(newNode->name, name);
    newNode->next = current->next;
    current->next = newNode;
}

void disp(struct node *head){
    struct node *current = head->next;
    while(current != NULL){
        printf("%d ", current->prn);
        printf("%s", current->name);
        current = current->next;
        printf("\n");
    }
    printf("\n");
}

void init(struct node *head){
    int nodes;
    printf("Enter initial nodes: ");
    scanf("%d", &nodes);
    struct node *current = head;

    for(int i = 0; i < nodes; i++){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter name: ");
        scanf("%s", newNode->name);
        printf("Enter prn: ");
        scanf("%d", &newNode->prn);
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
        printf("\n");
    }
}

void reverse(struct node *head){
    struct node *prev = NULL;
    struct node *current = head->next;
    while(current != NULL){
        struct node *future = current->next;
        current->next = prev;
        prev = current;
        current = future;
    }
    head->next = prev;
}

void sort(struct node *head){
    int l = len(head);
    for(int i = 1; i < l; i++){
        struct node *prev = head;
        struct node *current = head->next;

        for(int j = 0; j < l - i; j++){
            struct node *temp = current->next;
            if(current->prn > temp->prn){
                prev->next = temp;
                current->next = temp->next;
                temp->next = current;
                prev = temp;
            }
            else{
                prev = current;
                current = current->next;
            }
        }
    }
}

void merge(struct node *head, struct node *head2){
    init(head2);
    disp(head2);
    disp(head);
    sort(head);
    sort(head2);

    struct node *current1 = head;
    struct node *current2 = head2;
    struct node *temp;
    int flag = 0;
    if(current1->prn < current2->prn){
        temp = head;
        flag = 1;
    }
    else{
        temp = head2;
        flag = 0;
    }

    while(current1 != NULL && current2 != NULL){
        if(current1->prn < current2->prn){
            temp->next = current1;
            temp = current1;
            current1 = current1->next;
        }
        else{
            temp->next = current2;
            temp = current2;
            current2 = current2->next;
        }
    }

    if(current1 == NULL){
        temp->next = current2;
    }

    if(current2 == NULL){
        temp->next = current1;
    }

    if(flag == 1){
        disp(head);
    }
    else{
        disp(head2);
    }
}

int main(){
    printf("hello world\n");
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;

    struct node *head2;
    head2 = (struct node*)malloc(sizeof(struct node));
    head2->next = NULL;
    init(head);

    char yn = 'y';
    while(yn == 'y'){
        printf("Enter choice\n");
        printf("1 for append to list\n");
        printf("2 for adding at index\n");
        printf("3 for deleting at index\n");
        printf("4 for reverse\n");
        printf("5 for sort\n");
        printf("6 for merge\n");
        printf("7 for display list\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addToTail(head);
                break;

            case 2:
                addAtIndex(head);
                break;

            case 3:
                deleteAtIndex(head);
                break;
            
            case 4:
                reverse(head);
                disp(head);
                break;

            case 5:
                sort(head);
                disp(head);
                break;

            case 6:
                merge(head, head2);
                break;
            case 7:
                disp(head);

        }

        printf("another operation? y/n\n");
        scanf(" %c", &yn);
    }

    return 0;
}
