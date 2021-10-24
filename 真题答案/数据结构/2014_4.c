#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Lnode {
    Elemtype data;
    struct Lnode *next;
} Lnode, *Linkedlist;

void ChangeList(Linkedlist L) {
    Lnode *s = L->next;
    if (s != NULL) {
        Linkedlist p = (Linkedlist)malloc(sizeof(Lnode));
        p->next = NULL;
        while (s != NULL && s->next != NULL) {
            Lnode *n = s->next;
            s->next = n->next;
            n->next = p->next;
            p->next = n;
            if (s->next != NULL) {
                s = s->next;
            }
        }
        s->next = p->next;
        free(p);
    }
}

Linkedlist CreateLinkedlist(Elemtype *array, int length) {
    Linkedlist L = (Linkedlist)malloc(sizeof(Lnode));
    L->next = NULL;
    for (int i = length - 1; i >= 0; i--) {
        Lnode *s = (Lnode *)malloc(sizeof(Lnode));
        s->data = array[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

int main() {
    Elemtype x[6] = {1, 2, 3, 4, 5, 6};
    Linkedlist L = CreateLinkedlist(x, 6);
    ChangeList(L);
    Linkedlist p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}