#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insAtFirst() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of node: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void insAtLast() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insAtPosition() {
    int pos, i = 1;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of node: ");
    scanf("%d", &newNode->data);
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delAtFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delAtLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void delAtPosition() {
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL || pos <= 0) {
        printf("Invalid operation\n");
        return;
    }

    if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int ch, ch1;

    do {
        printf("\n\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n1. Insert At First\n2. Insert At Last\n3. Insert At Position\nEnter your choice: ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: insAtFirst(); break;
                    case 2: insAtLast(); break;
                    case 3: insAtPosition(); break;
                    default: printf("Wrong choice\n");
                }
                break;
            case 2:
                printf("\n1. Delete At First\n2. Delete At Last\n3. Delete At Position\nEnter your choice: ");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1: delAtFirst(); break;
                    case 2: delAtLast(); break;
                    case 3: delAtPosition(); break;
                    default: printf("Wrong choice\n");
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (ch != 4);
}
