#pragma once

#ifndef TREAP_H
#define TREAP_H

#include <stdio.h>
#include <stdlib.h>

// ��������� ��� ���� ������
typedef struct TreapNode {
    int key;          // ���� ����
    int priority;     // ��������� ����
    struct TreapNode* left;   // ����� �������
    struct TreapNode* right;  // ������ �������
} TreapNode;

// ������� ��� �������� ������ ����
TreapNode* createNode(int key, int priority);

// ������� ��� ������� ���� � �����
TreapNode* insert(TreapNode* root, int key, int priority);

// ������� ��� ������� ���� �������
TreapNode* merge(TreapNode* left, TreapNode* right);

// ������� ��� ���������� ������ �� ��� �� ��������� �����
void split(TreapNode* root, int key, TreapNode** left, TreapNode** right);

// ������� ��� ������������ ������, ���������� ��� �����
void freeTreap(TreapNode* root);

void visualizeTreap(TreapNode* root);

#endif /* TREAP_H */
