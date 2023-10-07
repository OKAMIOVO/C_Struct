/**
 * @file levelorder.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 二叉树的层次遍历
 * @version 0.1
 * @date 2023-03-15 20:22:53
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
 *算法思想：
 *①初始化一个辅助队列
 *②根结点入队
 *③若队列非空，则队头结点出队，访问该结点，并将其左、右孩子插入队尾（如果有的话）
 *④重复③直至队列为空
 */
#ifdef TREE
#include <stdio.h>
#include <stdlib.h>
#include "stdtypedef.h"

#define bool  int
#define true  1
#define false 0

// 初始化队列（带头结点）
void InitQueue(LinkQueue* Q) {
    // 初始时，front,rear都指向头结点
    Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

// 判断队列是否为空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        printf("队列为空!\n");
        return true;
    } else {
        printf("队列非空！\n");
        return false;
    }
}

// 入队
void EnQueue(LinkQueue* Q, BiTNode* x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s; // 新节点插入到rear之后
    Q->rear = s;       // 修改表尾指针
    // printf("元素%d入队成功！\n",x);
}

// 出队
BiTNode* DeQueue(LinkQueue* Q, BiTNode* x) {
    if (Q->front == Q->rear) {
        printf("队列为空！\n");
        return false;
    }
    LinkNode* p = Q->front->next;
    x = p->data;              // 用变量x返回队头元素
    Q->front->next = p->next; // 修改头结点的next指针
    if (Q->rear == p)         // 此次是最后一个结点出队
        Q->rear = Q->front;   // 修改rear指针
    free(p);                  // 释放结点空间
    return x;
}

void CreateBiTree(BiTree* T) {
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;

}

// 输出结点本身的值
void visit(BiTNode* e) { printf("%d\n", e->data); }

// 层序遍历
void levelorder(BiTree T) {
    LinkQueue Q;
    InitQueue(&Q); // 初始化辅助队列
    BiTree p;
    EnQueue(&Q, T);          // 将根节点入队
    while (!IsEmpty(Q)) {        // 队列不空则循环
        p = DeQueue(&Q, p);   // 队头结点出队
        visit(p);           // 访问出队结点
        if (p->lchild != NULL)
            EnQueue(&Q, p->lchild); // 左孩子入队
        if (p->rchild != NULL)
            EnQueue(&Q, p->rchild); // 右孩子入队
    }
}

// int main(){
//     BiTree T;
//     CreateBiTree(&T);

//     levelorder(T);
      
//     return 0;
// }
#endif