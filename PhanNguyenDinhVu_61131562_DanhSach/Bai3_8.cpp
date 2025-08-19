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

// Hàm tìm kiem
int timACuoi(struct Node* head) {
    struct Node* current = head;
    int viTri = 0;
    int viTriCuoi = -1;
    while (current != NULL) {
        viTri++;
        if (current->data == 'A') {
            viTriCuoi = viTri;
        }
        current = current->next;
    }
    return viTriCuoi;
}

int main() {
    struct Node* head = NULL;
    append(&head, 'C');
    append(&head, 'A');
    append(&head, 'A');
    append(&head, 'E');

    int viTriCuoi = timACuoi(head);
    if (viTriCuoi == -1)
        printf("Khong co ky tu 'A' trong danh sach\n");
    else
        printf("Thu tu cua phan tu cuoi cung mang ky tu 'A' la: %d\n", viTriCuoi);

    return 0;
}

