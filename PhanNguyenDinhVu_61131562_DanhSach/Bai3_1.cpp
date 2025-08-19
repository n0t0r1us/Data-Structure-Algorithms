#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct Node {
    float data;
    struct Node* next;
};

// Hàm thêm node vào danh sách liên ket
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

// Hàm tìm so duong nho nhat
float timSoMinDuong(struct Node* head) {
    float soMinDuong = FLT_MAX;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data > 0 && current->data < soMinDuong) {
            soMinDuong = current->data;
        }
        current = current->next;
    }
    return soMinDuong;
}

int main() {
    struct Node* head = NULL;
    append(&head, -2.5);
    append(&head, 4.1);
    append(&head, 1.5);
    append(&head, -1.8);
    append(&head, 2.0);

    float soMinDuong = timSoMinDuong(head);
    if (soMinDuong == FLT_MAX)
        printf("Khong co so duong trong danh sach\n");
    else
        printf("So duong nho nhat la: %.2f\n", soMinDuong);

    return 0;
}

