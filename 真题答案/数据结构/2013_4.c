#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Lnode {
    Elemtype data;
    struct Lnode *next;
} Lnode, *Linkedlist;

void ReverseList(Linkedlist L) {
    Lnode *p = L->next;
    L->next = NULL;
    while (p != NULL) {
        Lnode *q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

void ChangeListA(Linkedlist A, Linkedlist B) {
    Lnode *b = B->next;
    Lnode *a = A->next;
    Lnode *pre = A;
    Lnode *p;
    while (a != NULL) {
        if (b == NULL) {
            p = a;
            pre->next = NULL;
            a = NULL;
            free(p);
        } else {
            if (a->data < b->data) {
                Lnode *p = a;
                a = a->next;
                pre->next = a;
                free(p);
            } else if (a->data == b->data) {
                pre = a;
                a = a->next;
                b = b->next;
            } else {
                b = b->next;
            }
        }
    }
    ReverseList(A);
}

Linkedlist CreateLinkedlist(Elemtype *array, int length) {
    Linkedlist L = (Linkedlist)malloc(sizeof(Lnode));
    L->next = NULL;
    for (int i = length - 1; i >= 0; i--) {
        Lnode *s = (Lnode*)malloc(sizeof(Lnode));
        s->data = array[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

int main() {
    Elemtype x[6] = {1, 2, 3, 4, 5, 6};
    Elemtype y[3] = {0, 3, 7};
    Linkedlist A = CreateLinkedlist(x, 6);
    Linkedlist B = CreateLinkedlist(y, 3);
    ChangeListA(A, B);
    Linkedlist p = A->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}