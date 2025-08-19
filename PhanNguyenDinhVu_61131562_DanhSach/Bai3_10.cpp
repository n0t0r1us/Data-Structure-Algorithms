#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// �inh nghia node luu tru chuoi k� tu
struct NodeString {
    char data[21];
    struct NodeString* next;
};

// H�m th�m node v�o danh s�ch li�n ket cho chuoi
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

// H�m t�m chuoi c� do d�i d�i nhat
char* timChuoiDaiNhat(struct NodeString* head) {
    if (head == NULL)
        return NULL;

    struct NodeString* current = head;
    char* chuoiDaiNhat = current->data;
    int doDaiDaiNhat = strlen(current->data);
    current = current->next;

    while (current != NULL) {
        int len = strlen(current->data);
        if (len > doDaiDaiNhat) {
            doDaiDaiNhat = len;
            chuoiDaiNhat = current->data;
        }
        current = current->next;
    }
    return chuoiDaiNhat;
}

int main() {
    struct NodeString* head = NULL;
    appendString(&head, "hello");
    appendString(&head, "world");
    appendString(&head, "example");
    appendString(&head, "C programming");

    char* chuoiDaiNhat = timChuoiDaiNhat(head);
    if (chuoiDaiNhat != NULL)
        printf("Chuoi dai nhat la: %s\n", chuoiDaiNhat);
    else
        printf("Danh sach rong\n");

    return 0;
}

