#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    char nim[10];
    int ukt;
    int nominal;
    struct Node *next;
} Node;

Node* createNode(char name[], char nim[], int ukt, int nominal) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    strcpy(newNode->nim, nim);
    newNode->ukt = ukt;
    newNode->nominal = nominal;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node **head, Node **tail, char name[], char nim[], int ukt, int nominal) {
    Node *newNode = createNode(name, nim, ukt, nominal);
    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void dequeue(Node **head, Node **tail) {
    if (*head == NULL) {
        printf("Queue is empty. Cannot remove data.\n");
    } else {
        Node *temp = *head;
        *head = (*head)->next;
        if (*head == NULL) {
            *tail = NULL;
        }
        free(temp);
    }
}

void printQueue(Node *head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue:\n");
        int count = 1;
        while (head != NULL) {
            printf("%d. Name: %s, NIM: %s, UKT: %d, Nominal: %d\n", count++, head->name, head->nim, head->ukt, head->nominal);
            head = head->next;
        }
    }
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int choice;
    do {
        printf("\nMenu\n");
        printf("1. Add Data\n");
        printf("2. Remove Data\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[100];
                char nim[10];
                int ukt, nominal;
                printf("\nInput Data Mahasiswa\n");
                printf("Nama : ");
                getchar();
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                printf("NIM : ");
                fgets(nim, sizeof(nim), stdin);
                strtok(nim, "\n");
                printf("UKT : ");
                scanf("%d", &ukt);
                printf("Nominal : ");
                scanf("%d", &nominal);
                enqueue(&head, &tail, name, nim, ukt, nominal);
                break;
            }
            case 2:
                printf("\nData Mahasiswa\n");
                printf("Nama : %s\n", Node[head].name);
                printf("NIM : %s\n", Node[head].nim);
                printf("UKT : %d\n", Node[head].ukt);
                printf("Nominal : %d\n", Node[head].nominal);
                dequeue(&head, &tail);
                break;
            case 3:
                printQueue(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    // Free memory before exiting
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
