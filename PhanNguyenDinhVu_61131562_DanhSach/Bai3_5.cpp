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
//hàm tìm so le
int timSoLeDau(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if ((int)current->data % 2 != 0) {
            return (int)current->data;
        }
        current = current->next;
    }
    return -1; // Không tìm thay so le
}

int main() {
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 4);
    append(&head, 9);

    int soLeDau = timSoLeDau(head);
    if (soLeDau == -1)
        printf("Khong co so le trong danh sach\n");
    else
        printf("So le dau tien la: %d\n", soLeDau);

    return 0;
}

