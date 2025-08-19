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

//hàm tìm so chan cuoi cùng
int timSoChanCuoi(struct Node* head) {
    struct Node* current = head;
    int soChanCuoi = -1;
    while (current != NULL) {
        if ((int)current->data % 2 == 0) {
            soChanCuoi = (int)current->data;
        }
        current = current->next;
    }
    return soChanCuoi;
}

int main() {
    struct Node* head = NULL;
    append(&head, 3);
    append(&head, 7);
    append(&head, 4);
    append(&head, 8);

    int soChanCuoi = timSoChanCuoi(head);
    if (soChanCuoi == -1)
        printf("Khong co so chan trong danh sach\n");
    else
        printf("So chan cuoi cung la: %d\n", soChanCuoi);

    return 0;
}

