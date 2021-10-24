#include <stdio.h>
#define MAXSIZE 1000

typedef int Elemtype;
typedef struct {
    Elemtype data[MAXSIZE];
    int length;
} Sqlist;

void GradeSort(Sqlist *L) {
    for (int i = 0, j = L->length - 1; i < j; i++, j--) {
        while (L->data[i] >= 60) {
            i++;
        }
        while (L->data[j] < 60) {
            j--;
        }
        if (i < j) {
            int temp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = temp;
        }
    }
}

int main() {
    Sqlist L = {{10, 20, 68, 30, 40, 80}, 6};
    GradeSort(&L);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
}
