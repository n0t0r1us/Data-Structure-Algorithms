#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct Node {
    float data;
    struct Node* next;
};

// H�m th�m node v�o danh s�ch li�n ket
void append(struct Node** head_ref, float new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// h�m t�nh tong c�c so �m
float tongSoAm(struct Node* head) {
    float tong = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data < 0) {
            tong += current->data;
        }
        current = current->next;
    }
    return tong;
}

int main() {
    struct Node* head = NULL;
    append(&head, -2.5);
    append(&head, -1.5);
    append(&head, 1.5);
    append(&head, -3.0);

    float tong = tongSoAm(head);
    printf("Tong cac so am la: %.2f\n", tong);

    return 0;
}

