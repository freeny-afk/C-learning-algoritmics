// �������� � �������� ������� ������ �� C++

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct node {
    int value;
    node* left, * right;
    int cl = 0, cr = 0;
};

// ������� ����
node* newNode(int it) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = it;
    temp->left = temp->right = NULL;
    return temp;
}

// ����� ������
void printTree(node* root) {
    if (root != NULL) {
        // ������� ����
        printTree(root->left);

        // ������� ������
        cout << root->value << " -> ";

        // ������� �����
        printTree(root->right);
    }
}

// ��������� ���� 
node* addNode(node* node, int key) {
    // ���������� ����� ����, ���� ������ ������
    if (node == NULL) return newNode(key);

    // �������� � ������ ����� � ��������� ����
    if (key < node->value) {
        node->left = addNode(node->left, key);
    }
    else {
        node->right = addNode(node->right, key);
    }
    return node;
}

//����� ����
int searchNode(node* root, int key)
{
    node* ptr = root;
    while (root != NULL)
    {
        if (ptr->left != nullptr && ptr->left->value == key)
            return key;
        if (ptr->right != nullptr && ptr->right->value == key)
            return key;
        if (key < ptr->value) {
            ptr = ptr->left;
            continue;
        }
        if (key > ptr->value){
            ptr = ptr->right;
            continue;
        }
        return NULL;
    }
    return NULL;
}

int depthTree(node* root)
{
    if (root == NULL) return 0;
    return max(depthTree(root->left), depthTree(root->right)) + 1;
}

// ������ �������
int main() {
    setlocale(LC_ALL, "Russian");
    int yn;
    cin >> yn;
    struct node* root = NULL;
    for (int i = 0; i < yn; i++) {
        root = addNode(root, 1 + rand() % 15);
    }

    cout << "��������������� �����: ";
    printTree(root);

    cout << endl << searchNode(root, 5);
    cout << endl << depthTree(root);
}