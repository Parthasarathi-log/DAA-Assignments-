#include <stdio.h>

typedef struct {
    int n;
    char from, aux, to;
    int state;
} Frame;

#define SIZE 100

void hanoi_recursive(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi_recursive(n - 1, from, to, aux);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi_recursive(n - 1, aux, from, to);
}

void hanoi_non_recursive(int n, char from, char aux, char to) {
    Frame stack[SIZE];
    int top = 0;

    stack[top++] = (Frame){n, from, aux, to, 0};

    while (top > 0) {
        Frame *f = &stack[top - 1];

        if (f->n == 1) {
            printf("Move disk 1 from %c to %c\n", f->from, f->to);
            top--;
        } else if (f->state == 0) {
            f->state = 1;
            stack[top++] = (Frame){f->n - 1, f->from, f->to, f->aux, 0};
        } else if (f->state == 1) {
            printf("Move disk %d from %c to %c\n", f->n, f->from, f->to);
            f->state = 2;
            stack[top++] = (Frame){f->n - 1, f->aux, f->from, f->to, 0};
        } else {
            top--;
        }
    }
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nRecursive Solution:\n");
    hanoi_recursive(n, 'A', 'B', 'C');

    printf("\nNon-Recursive Solution:\n");
    hanoi_non_recursive(n, 'A', 'B', 'C');

    return 0;
}
