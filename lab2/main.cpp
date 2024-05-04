#include <iostream>
#include "pch.h"

extern "C" {
    #include "treap.h"
}

// Тест для функции вставки узла в пустой треап
TEST(TreapTest, Insert_InsertSingleNodeToEmptyTree_ValidTree) {
    TreapNode* root = nullptr;
    root = insert(root, 5, 10);
    EXPECT_EQ(root->key, 5);
    EXPECT_EQ(root->priority, 10);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
    freeTreap(root);
}

// Тест для функции вставки нескольких узлов и проверки свойств треапа
TEST(TreapTest, Insert_InsertMultipleNodes_ValidTree) {
    TreapNode* root = nullptr;
    root = insert(root, 5, 10);
    root = insert(root, 3, 15);
    root = insert(root, 7, 5);

    // Проверка свойств треапа
    EXPECT_EQ(root->key, 5);
    EXPECT_EQ(root->priority, 10);
    EXPECT_NE(root->left, nullptr);
    EXPECT_NE(root->right, nullptr);

    // Проверка свойств поддеревьев
    EXPECT_EQ(root->left->key, 3);
    EXPECT_EQ(root->left->priority, 15);
    EXPECT_EQ(root->right->key, 7);
    EXPECT_EQ(root->right->priority, 5);

    freeTreap(root);
}

// Тест для функции разделения треапа на два по заданному ключу
TEST(TreapTest, Split_SplitTree_ValidSplit) {
    TreapNode* root = nullptr;
    root = insert(root, 5, 10);
    root = insert(root, 3, 15);
    root = insert(root, 7, 5);

    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    split(root, 5, &left, &right);

    EXPECT_EQ(left->key, 3);
    EXPECT_EQ(left->priority, 15);
    EXPECT_EQ(right->key, 7);
    EXPECT_EQ(right->priority, 5);

    freeTreap(left);
    freeTreap(right);
}

// Тест для функции слияния двух треапов
TEST(TreapTest, Merge_MergeTrees_ValidMerge) {
    TreapNode* root1 = nullptr;
    root1 = insert(root1, 5, 10);
    root1 = insert(root1, 3, 15);

    TreapNode* root2 = nullptr;
    root2 = insert(root2, 7, 5);
    root2 = insert(root2, 8, 20);

    TreapNode* merged = merge(root1, root2);

    EXPECT_EQ(merged->key, 5);
    EXPECT_EQ(merged->priority, 10);
    EXPECT_EQ(merged->left->key, 3);
    EXPECT_EQ(merged->left->priority, 15);
    EXPECT_EQ(merged->right->key, 7);
    EXPECT_EQ(merged->right->priority, 5);
    EXPECT_EQ(merged->right->right->key, 8);
    EXPECT_EQ(merged->right->right->priority, 20);

    freeTreap(merged);
}

int main(int argc, char** argv) {
    TreapNode* root = nullptr;
    root = insert(root, 5, 10);
    root = insert(root, 3, 15);
    root = insert(root, 7, 5);

    visualizeTreap(root);
    TreapNode* root2 = nullptr;
    root2 = insert(root2, 6, 8);
    root2 = insert(root2, 8, 20);
    visualizeTreap(root2);
    root = merge(root, root2);
    visualizeTreap(root);
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;

    int key = 5; // ключ для разделения
    split(root, key, &left, &right);

    freeTreap(root);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
