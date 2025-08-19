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

//H�m dem
int demA(struct Node* head) {
    struct Node* current = head;
    int dem = 0;
    while (current != NULL) {
        if (current->data == 'A') {
            dem++;
        }
        current = current->next;
    }
    return dem;
}

int main() {
    struct Node* head = NULL;
    append(&head, 'B');
    append(&head, 'A');
    append(&head, 'C');
    append(&head, 'A');

    int dem = demA(head);
    printf("So luong ky tu 'A' la: %d\n", dem);

    return 0;
}

