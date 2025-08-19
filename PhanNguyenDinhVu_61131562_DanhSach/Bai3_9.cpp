#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Ðinh nghia node luu tru chuoi ký tu
struct NodeString {
    char data[21];
    struct NodeString* next;
};

// Hàm thêm node vào danh sách liên ket cho chuoi
void appendString(struct NodeString** head_ref, char* new_data) {
    struct NodeString* new_node = (struct NodeString*)malloc(sizeof(struct NodeString));
    struct NodeString* last = *head_ref;
    strcpy(new_node->data, new_data);
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Hàm tìm thu tu chuoi ngan nhat
int timChuoiNganNhat(struct NodeString* head) {
    if (head == NULL)
        return -1;

    struct NodeString* current = head;
    int doDaiNganNhat = strlen(current->data);
    int viTri = 1, viTriNhoNhat = 1;
    current = current->next;

    while (current != NULL) {
        int len = strlen(current->data);
        viTri++;
        if (len < doDaiNganNhat) {
            doDaiNganNhat = len;
            viTriNhoNhat = viTri;
        }
        current = current->next;
    }
    return viTriNhoNhat;
}

int main() {
    struct NodeString* head = NULL;
    appendString(&head, "hello");
    appendString(&head, "world");
    appendString(&head, "hi");
    appendString(&head, "example");

    int viTriNhoNhat = timChuoiNganNhat(head);
    printf("Thu tu cua chuoi ngan nhat la: %d\n", viTriNhoNhat);

    return 0;
}

