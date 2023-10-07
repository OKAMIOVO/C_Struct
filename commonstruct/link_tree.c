/**
 * @file link_tree.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 二叉树的链式存储
 * @version 0.1
 * @date 2023-03-15 17:54:00
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifdef TREE
#include <stdio.h>
#include <stdlib.h>
#include "stdtypedef.h"

/* 
*n个结点的二叉链表共有n*1个空链域
 */

void CreateBiTree(BiTree* T){
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = NULL;
    (*T)->rchild->rchild = NULL;
    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->rchild = NULL;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

// int main(){
//     BiTree (*T);
//     CreateBiTree(&(*T));
//     printf("%d",(*T)->lchild->lchild->data);
      
//     return 0;
// }

/* 
*指针指向的问题：本代码中，T的指向发生了变化，所以需要用返回值来更新T的指向
*同样的，link_stack.c文件中，top的指向也发生变化
*而像link_queue.c文件中，Q的指向没有变化,一直都是同一片内存区域，只不过变化的是rear和front的指向
*声明的是Q，Q无变化，而本文件中声明的T发生了指向的变化，所以需要更新
 */
#endif