#include "treap.h"

// ������� ��� �������� ������ ����
TreapNode* createNode(int key, int priority) {
    TreapNode* newNode = (TreapNode*)malloc(sizeof(TreapNode));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->priority = priority;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

TreapNode* insert(TreapNode* root, int key, int priority) {
    if (root == NULL)
        return createNode(key, priority);

    // ���� ���� ������, ��� ���� �������� ����, ���� �����
    if (key < root->key) {
        root->left = insert(root->left, key, priority);
        // ��������� ���� � ������� ����������� ����
        if (root->left->priority > root->priority) {
            TreapNode* temp = root->left;
            root->left = temp->right;
            temp->right = root;
            return temp;
        }
    }
    // ����� ���� ������
    else {
        root->right = insert(root->right, key, priority);
        // ��������� ���� � ������� ����������� ����
        if (root->right->priority > root->priority) {
            TreapNode* temp = root->right;
            root->right = temp->left;
            temp->left = root;
            return temp;
        }
    }
    return root;
}

TreapNode* merge(TreapNode* left, TreapNode* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    // ���������� ��� ��������� � ������ ���������� ������
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    }
    else {
        right->left = merge(left, right->left);
        return right;
    }
}

void split(TreapNode* root, int key, TreapNode** left, TreapNode** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
    }
    else if (key < root->key) {
        split(root->left, key, left, &(root->left));
        *right = root;
    }
    else {
        split(root->right, key, &(root->right), right);
        *left = root;
    }
}

// ������� ��� ������������ ������, ���������� ��� �����
void freeTreap(TreapNode* root) {
    if (root != NULL) {
        freeTreap(root->left);
        freeTreap(root->right);
        free(root);
    }
}

// ������� ��� ������ �������
void printIndent(int indent) {
    for (int i = 0; i < indent; ++i)
        printf("    "); // 4 ������� �� �������
}

// ����������� ������� ��� ������ ������ � �������
void printTreap(TreapNode* root, int indent) {
    if (root == NULL)
        return;

    // ������ ������� ��������� � ��������
    printTreap(root->right, indent + 1);

    // ����� ����� � ���������� �������� ���� � ��������
    printIndent(indent);
    printf("(%d,%d)\n", root->key, root->priority);

    // ������ ������ ��������� � ��������
    printTreap(root->left, indent + 1);
}

// ������� ��� ������ ������ ������ � �������
void visualizeTreap(TreapNode* root) {
    printf("Treap visualization:\n");
    printTreap(root, 0); // �������� � ����� � ������� 0
}