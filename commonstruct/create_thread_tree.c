/**
 * @file create_thread_tree.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 测试线索二叉树
 * @version 0.1
 * @date 2023-03-16 20:42:35
 * 
 * @copyrchild Copyrchild (c) 2023
 * 
 */
#ifdef TREE
#include <stdio.h>
#include <stdlib.h>
#include "stdtypedef.h"

// 全局变量 pre,指向当前访问结点的前驱
ThreadNode* pre = NULL;

/* ThreadTree CreateBiTree(ThreadTree T) {
    T = (ThreadNode*)malloc(sizeof(ThreadNode));
    T->data = 1;
    T->lchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    T->rchild = (ThreadNode*)malloc(sizeof(ThreadNode));

    T->lchild->data = 2;
    T->lchild->lchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    T->lchild->rchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    T->lchild->rchild->data = 5;
    T->lchild->rchild->lchild = NULL;
    T->lchild->rchild->rchild = NULL;
    T->rchild->data = 3;
    T->rchild->lchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    T->rchild->lchild->data = 6;
    T->rchild->lchild->lchild = NULL;
    T->rchild->lchild->rchild = NULL;
    T->rchild->rchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    T->rchild->rchild->data = 7;
    T->rchild->rchild->lchild = NULL;
    T->rchild->rchild->rchild = NULL;
    T->lchild->lchild->data = 4;
    T->lchild->lchild->lchild = NULL;
    T->lchild->lchild->rchild = NULL;

    return T;
} */

/* ThreadNode* create_node(int data) {
    ThreadNode* new_node = (ThreadNode*) malloc(sizeof(ThreadNode));
    new_node->data = data;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}

ThreadNode* insert_node(ThreadNode* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (root->lchild == NULL) {
        // root->ltag = 0;
        root->lchild = insert_node(root->lchild, data);
    } else if (root->rchild == NULL) {
        // root->rtag = 0;
        root->rchild = insert_node(root->rchild, data);
    } else {
        // 如果左右节点都不为空，则递归插入左右子树
        insert_node(root->lchild, data);
        insert_node(root->rchild, data);
    }
    return root;
} */

/* 创建新节点 */
ThreadNode *createNode(int value) {
    ThreadNode *node = (ThreadNode *)malloc(sizeof(ThreadNode));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;
    node->ltag = 0;
    node->rtag = 0;
    return node;
}

/* 通过递归方式构建完全二叉树 */
ThreadNode *buildCompleteBinaryTree(int *arr, int index, int size) {
    if (index > size) {
        return NULL;
    }
    ThreadNode *node = createNode(arr[index]);
    node->lchild = buildCompleteBinaryTree(arr, index * 2, size);
    node->rchild = buildCompleteBinaryTree(arr, index * 2 + 1, size);
    return node;
}

// 访问结点
void visit(ThreadNode* q) {
    if (q->lchild == NULL) { // 左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
    printf("%d\n", q->data);
}

// 中序遍历二叉树,一边遍历一边线索化
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild); // 中序遍历左子树
        visit(T);            // 访问根节点
        InThread(T->rchild); // 中序遍历右子树
    }
}

// 中序线索化二叉树T
void CreateInThread(ThreadTree T) {
    pre = NULL;      // pre初始为NULL
    if (T != NULL) { // 非空二叉树才能线索化
        InThread(T); // 中序线索化二叉树
        if (pre->rchild == NULL)
            pre->rtag = 1; // 处理遍历的最后一个结点
    }
}

// int main() {
//     ThreadTree T = NULL;
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
//     T = buildCompleteBinaryTree(arr, 1, size - 1);
//     CreateInThread(T);

//     return 0;
// }
#endif