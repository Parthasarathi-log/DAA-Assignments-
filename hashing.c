#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int i = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = table[i];
    table[i] = newNode;
}

int search(int key) {
    int i = hash(key);
    struct Node* temp = table[i];
    while (temp) {
        if (temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void delete(int key) {
    int i = hash(key);
    struct Node *temp = table[i], *prev = NULL;
    while (temp) {
        if (temp->data == key) {
            if (prev) prev->next = temp->next;
            else table[i] = temp->next;
            free(temp);
            printf("Deleted %d\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Not found\n");
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = table[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;
    while (1) {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter key: "); scanf("%d", &key); insert(key); break;
            case 2: printf("Enter key: "); scanf("%d", &key); 
                    if (search(key)) printf("Found\n"); else printf("Not Found\n");
                    break;
            case 3: printf("Enter key: "); scanf("%d", &key); delete(key); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}