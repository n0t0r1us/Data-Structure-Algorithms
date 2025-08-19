#include <stdio.h>
#include <stdlib.h>

// Cau truc 1 nút cua cây nhi phân
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
//Câu 1
// Hàm tao 1 nút moi
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Hàm chèn 1 nút vào cây nhi phân tìm kiem
Node* insertNode(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}
//Câu 2
// Hàm duyet cây theo thu tu giua (inorder) và in ra các giá tri
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
//Câu 3
// Hàm dem so nút có dúng 1 nhánh
int countSingleChildNodes(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        count = 1;
    return count + countSingleChildNodes(root->left) + countSingleChildNodes(root->right);
}
//Câu 4
// Hàm tính chieu cao cua cây nhi phân
int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
//Câu 5
// Hàm tìm kiem 1 nút và tra ve muc cua nó
int findNodeLevel(Node* root, int data, int level) {
    if (root == NULL) return -1;
    if (root->data == data) return level;
    if (data < root->data)
        return findNodeLevel(root->left, data, level + 1);
    else
        return findNodeLevel(root->right, data, level + 1);
}

// Hàm dem so nút lá cua 1 nút cu the
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
//Câu 6
// Hàm xóa 1 nút trong cây nhi phân tìm kiem
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
//Câu 7
// Hàm tính tong các nút nho hon 1 giá tri xác dinh
int sumLessThan(Node* root, int value) {
    if (root == NULL) return 0;
    int sum = 0;
    if (root->data < value)
        sum += root->data;
    sum += sumLessThan(root->left, value);
    sum += sumLessThan(root->right, value);
    return sum;
}
//Câu 8
// Hàm dem các nút có giá tri chan
int countEvenNodes(Node* root) {
    if (root == NULL) return 0;
    int count = (root->data % 2 == 0) ? 1 : 0;
    return count + countEvenNodes(root->left) + countEvenNodes(root->right);
}
//Câu 9
// Hàm kiem tra cây có cân bang hay không
int isBalanced(Node* root) {
    if (root == NULL) return 1;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}
//Câu 10
// Hàm tao cây nhu phân tìm kiem cân bang tu mang dã sap xep
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Mang dã sap xep de tao cây cân bang
    root = createBalancedBST(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	//Câu 2
    printf("Duyet cay theo thu tu giua: ");
    inorderTraversal(root);
    printf("\n");
	//Câu 3
    printf("So nut co 1 nhanh: %d\n", countSingleChildNodes(root));
    //Câu 4
    printf("Chieu cao cua cay: %d\n", treeHeight(root));
	//Câu 5
    int searchValue = 4;
    int level = findNodeLevel(root, searchValue, 0);
    if (level != -1)
        printf("Muc cua nut %d: %d\n", searchValue, level);
    else
        printf("Khong tim thay nut %d\n", searchValue);

    printf("So nut la cua cay: %d\n", countLeafNodes(root));
	//Câu 6
    root = deleteNode(root, 4);
    printf("Cay sau khi xoa nut 4: ");
    inorderTraversal(root);
    printf("\n");
	//Câu 7
    int threshold = 5;
    printf("Tong cac nut nho hon %d: %d\n", threshold, sumLessThan(root, threshold));
    //Câu 8
    printf("So luong nut co gia tri chan: %d\n", countEvenNodes(root));
    //Câu 9
    printf("Cay co can bang khong? %s\n", isBalanced(root) ? "Co" : "Khong");

    return 0;
}

