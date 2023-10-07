/**
 * @file postorder_recursion.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 二叉树的后序遍历--递归实现
 * @version 0.1
 * @date 2023-03-15 20:05:47
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifdef TREE
#include <stdio.h>
#include <stdlib.h>
#include "stdtypedef.h"

void CreateBiTree(BiTree* T){
    *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=1;
    (*T)->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild=(BiTNode*)malloc(sizeof(BiTNode));
  
    (*T)->lchild->data=2;
    (*T)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data=5;
    (*T)->lchild->rchild->lchild=NULL;
    (*T)->lchild->rchild->rchild=NULL;
    (*T)->rchild->data=3;
    (*T)->rchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data=6;
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    (*T)->rchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data=7;
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;

}

// 输出结点本身的值
void visit(BiTNode *e){
    printf("%d",e->data);
}

// 中序遍历
void PreOrder(BiTree T){
    if(T != NULL){
        PreOrder(T->lchild);    //递归遍历左子树
        PreOrder(T->rchild);    //递归遍历右子树
        visit(T);               //访问根节点
    }
}

// int main(){
//     BiTree T;
//     CreateBiTree(&T);
//     printf("后序遍历：\n");
//     PreOrder(T);
      
//     return 0;
// }
#endif