#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c; int f;
    struct Node *l, *r;
} Node;

Node* newNode(char c, int f) {
    Node* n = malloc(sizeof(Node));
    n->c = c; n->f = f; n->l = n->r = 0;
    return n;
}

int findMin(Node* arr[], int used[], int n) {
    int min = -1;
    for(int i=0; i<n; i++)
        if (!used[i] && (min==-1 || arr[i]->f < arr[min]->f))
            min = i;
    return min;
}

void printCodes(Node* root, int code[], int len) {
    if (!root) return;
    if (!root->l && !root->r) {
        printf("%c: ", root->c);
        for (int i=0; i<len; i++) printf("%d", code[i]);
        printf("\n");
    }
    code[len] = 0; printCodes(root->l, code, len+1);
    code[len] = 1; printCodes(root->r, code, len+1);
}

int main() {
    char letters[] = {'a','c','d','e','o','m','s','t','u'};
    int freq[] = {20,11,2,10,15,8,10,22,2};
    int n = 9;

    Node* nodes[20];
    int used[20] = {0};

    for(int i=0; i<n; i++)
        nodes[i] = newNode(letters[i], freq[i]);

    int size = n;
    while (size > 1) {
        int i = findMin(nodes, used, n);
        used[i] = 1;
        int j = findMin(nodes, used, n);
        used[j] = 1;

        Node* parent = newNode('$', nodes[i]->f + nodes[j]->f);
        parent->l = nodes[i];
        parent->r = nodes[j];

        nodes[i] = parent;
        used[j] = 1; 

        used[i] = 0; 
        size--;
    }

    int code[20];
    printCodes(nodes[findMin(nodes, used, n)], code, 0);

    return 0;
}
