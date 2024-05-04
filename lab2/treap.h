#pragma once

#ifndef TREAP_H
#define TREAP_H

#include <stdio.h>
#include <stdlib.h>

// Структура для узла треапа
typedef struct TreapNode {
    int key;          // ключ узла
    int priority;     // приоритет узла
    struct TreapNode* left;   // левый потомок
    struct TreapNode* right;  // правый потомок
} TreapNode;

// Функция для создания нового узла
TreapNode* createNode(int key, int priority);

// Функция для вставки узла в треап
TreapNode* insert(TreapNode* root, int key, int priority);

// Функция для слияния двух треапов
TreapNode* merge(TreapNode* left, TreapNode* right);

// Функция для разделения треапа на два по заданному ключу
void split(TreapNode* root, int key, TreapNode** left, TreapNode** right);

// Функция для освобождения памяти, выделенной под треап
void freeTreap(TreapNode* root);

void visualizeTreap(TreapNode* root);

#endif /* TREAP_H */
