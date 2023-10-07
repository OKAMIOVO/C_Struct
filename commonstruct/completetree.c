/**
 * @file test.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 构造完全二叉树
 * @version 0.1
 * @date 2023-03-31 20:56:47
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifdef TREE
#include <stdio.h>
#include <stdlib.h>
#include "stdtypedef.h"

/* 创建新节点 */
Node *createNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* 通过递归方式构建完全二叉树 */
Node *buildCompleteBinaryTree(int *arr, int index, int size) {
    if (index > size) {
        return NULL;
    }
    Node *node = createNode(arr[index]);
    node->left = buildCompleteBinaryTree(arr, index * 2, size);
    node->right = buildCompleteBinaryTree(arr, index * 2 + 1, size);
    return node;
}

/* 打印二叉树节点的值 */
void printBinaryTree(Node *node) {
    if (node != NULL) {
        printf("%d ", node->value);
        printBinaryTree(node->left);
        printBinaryTree(node->right);
    }
}

// int main() {
//     /* 读取用户输入的节点值 */
//     int arr[100];
//     int size = 0;
//     while (1) {
//         int value;
//         printf("请输入节点的值（输入-1结束）：");
//         scanf("%d", &value);
//         if (value == -1) {
//             break;
//         }
//         arr[size++] = value;
//     }

//     /* 构建一个完全二叉树 */
//     Node *root = buildCompleteBinaryTree(arr, 1, size - 1);

//     /* 打印二叉树节点的值 */
//     printf("完全二叉树的节点值为：\n");
//     printBinaryTree(root);
//     printf("\n");

//     return 0;
// }
#endif