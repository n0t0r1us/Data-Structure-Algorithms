#include <stdio.h>
#include <stdlib.h>

// Cau truc 1 n�t cua c�y nhi ph�n
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
//C�u 1
// H�m tao 1 n�t moi
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// H�m ch�n 1 n�t v�o c�y nhi ph�n t�m kiem
Node* insertNode(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}
//C�u 2
// H�m duyet c�y theo thu tu giua (inorder) v� in ra c�c gi� tri
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
//C�u 3
// H�m dem so n�t c� d�ng 1 nh�nh
int countSingleChildNodes(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        count = 1;
    return count + countSingleChildNodes(root->left) + countSingleChildNodes(root->right);
}
//C�u 4
// H�m t�nh chieu cao cua c�y nhi ph�n
int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
//C�u 5
// H�m t�m kiem 1 n�t v� tra ve muc cua n�
int findNodeLevel(Node* root, int data, int level) {
    if (root == NULL) return -1;
    if (root->data == data) return level;
    if (data < root->data)
        return findNodeLevel(root->left, data, level + 1);
    else
        return findNodeLevel(root->right, data, level + 1);
}

// H�m dem so n�t l� cua 1 n�t cu the
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
//C�u 6
// H�m x�a 1 n�t trong c�y nhi ph�n t�m kiem
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
//C�u 7
// H�m t�nh tong c�c n�t nho hon 1 gi� tri x�c dinh
int sumLessThan(Node* root, int value) {
    if (root == NULL) return 0;
    int sum = 0;
    if (root->data < value)
        sum += root->data;
    sum += sumLessThan(root->left, value);
    sum += sumLessThan(root->right, value);
    return sum;
}
//C�u 8
// H�m dem c�c n�t c� gi� tri chan
int countEvenNodes(Node* root) {
    if (root == NULL) return 0;
    int count = (root->data % 2 == 0) ? 1 : 0;
    return count + countEvenNodes(root->left) + countEvenNodes(root->right);
}
//C�u 9
// H�m kiem tra c�y c� c�n bang hay kh�ng
int isBalanced(Node* root) {
    if (root == NULL) return 1;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}
//C�u 10
// H�m tao c�y nhu ph�n t�m kiem c�n bang tu mang d� sap xep
Node* createBalancedBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = createNode(arr[mid]);
    root->left = createBalancedBST(arr, start, mid - 1);
    root->right = createBalancedBST(arr, mid + 1, end);
    return root;
}

int main() {
    Node* root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Mang d� sap xep de tao c�y c�n bang
    root = createBalancedBST(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	//C�u 2
    printf("Duyet cay theo thu tu giua: ");
    inorderTraversal(root);
    printf("\n");
	//C�u 3
    printf("So nut co 1 nhanh: %d\n", countSingleChildNodes(root));
    //C�u 4
    printf("Chieu cao cua cay: %d\n", treeHeight(root));
	//C�u 5
    int searchValue = 4;
    int level = findNodeLevel(root, searchValue, 0);
    if (level != -1)
        printf("Muc cua nut %d: %d\n", searchValue, level);
    else
        printf("Khong tim thay nut %d\n", searchValue);

    printf("So nut la cua cay: %d\n", countLeafNodes(root));
	//C�u 6
    root = deleteNode(root, 4);
    printf("Cay sau khi xoa nut 4: ");
    inorderTraversal(root);
    printf("\n");
	//C�u 7
    int threshold = 5;
    printf("Tong cac nut nho hon %d: %d\n", threshold, sumLessThan(root, threshold));
    //C�u 8
    printf("So luong nut co gia tri chan: %d\n", countEvenNodes(root));
    //C�u 9
    printf("Cay co can bang khong? %s\n", isBalanced(root) ? "Co" : "Khong");

    return 0;
}

