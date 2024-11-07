#include<stdio.h>
#include<stdlib.h>

void insert();
void deletion();
void display();
void find();

typedef struct node *position;
position newnode, temp, L = NULL, P;

struct node {
    int data;
    position next;
    position prev;
};

void insert() {
    int pos, i;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &newnode->data);
    
    if (L == NULL) {
        L = newnode;
        L->next = NULL;
        L->prev = NULL;
    } else {
        printf("\nEnter the position where the data is to be inserted: ");
        scanf("%d", &pos);
        
        if (pos == 1) {
            newnode->next = L;
            newnode->prev = NULL;
            L->prev = newnode;
            L = newnode;
        } else {
            P = L;
            for (i = 1; i < pos - 1 && P->next != NULL; i++) {
                P = P->next;
            }
            newnode->next = P->next;
            if (P->next != NULL)
                P->next->prev = newnode;
            P->next = newnode;
            newnode->prev = P;
        }
    }
}

void deletion() {
    int pos, i;
    if (L == NULL)
        printf("\nThe list is empty\n");
    else {
        printf("\nEnter the position of the data to be deleted: ");
        scanf("%d", &pos);
        
        if (pos == 1) {
            temp = L;
            L = temp->next;
            if (L != NULL)
                L->prev = NULL;
            printf("\nThe deleted element is %d", temp->data);
            free(temp);
        } else {
            P = L;
            for (i = 1; i < pos - 1; i++) {
                P = P->next;
            }
            temp = P->next;
            printf("\nThe deleted element is %d", temp->data);
            P->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = P;
            free(temp);
        }
    }
}

void display() {
    if (L == NULL)
        printf("\nNo elements in the list.\n");
    else {
        printf("\nThe elements in the list are:\n");
        for (P = L; P != NULL; P = P->next) {
            printf("%d ", P->data);
        }
        printf("\n");
    }
}

void find() {
    int a, flag = 0, count = 0;
    if (L == NULL)
        printf("\nThe list is empty\n");
    else {
        printf("\nEnter the element to be searched: ");
        scanf("%d", &a);
        
        for (P = L; P != NULL; P = P->next) {
            count++;
            if (P->data == a) {
                flag = 1;
                printf("\nThe element is found at position %d\n", count);
                break;
            }
        }
        
        if (flag == 0)
            printf("\nThe element is not found\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. FIND");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert();
                    break;
            case 2: deletion();
                    break;
            case 3: display();
                    break;
            case 4: find();
                    break;
            case 5: exit(0);
        }
    } while (choice != 5);
    
    return 0;
}
