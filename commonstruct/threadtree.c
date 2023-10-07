/**
 * @file threadtree.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 线索二叉树
 * @version 0.1
 * @date 2023-03-16 18:56:33
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifdef TREE
#include <stdio.h>
#include <stdlib.h>
#include "stdtypedef.h"

// 全局变量 pre,指向当前访问结点的前驱
ThreadNode* pre = NULL;

void CreateBiTree(ThreadTree* T) {
    *T = (ThreadNode*)malloc(sizeof(ThreadNode));
    (*T)->data = 1;
    (*T)->lchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    (*T)->rchild = (ThreadNode*)malloc(sizeof(ThreadNode));

    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    (*T)->lchild->rchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (ThreadNode*)malloc(sizeof(ThreadNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;

}

/* // 前序初始化二叉树
ThreadTree CreateBiTree(ThreadTree T) {
    int data;
    scanf("%d", &data);
    if (data != 9999) {
        if (!(T = (ThreadNode *)malloc(sizeof(ThreadNode)))) {
            printf("申请结点失败！\n");
            return T;
        } else {
            T->data = data;
            T->ltag = 0;
            T->rtag = 0;
            CreateBiTree(T->lchild); // 初始化左子树
            CreateBiTree(T->rchild); // 初始化右子树
        }
    } else {
        T = NULL;
    }

    return T;
} */

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
    printf("%d", q->data);
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
//     ThreadTree T;
//     CreateBiTree(&T);
//     CreateInThread(T);

//     return 0;
// }
#endif