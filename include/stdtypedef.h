#ifndef __STDTYPEDEF_H__
#define __STDTYPEDEF_H__

#define bool  int
#define true  1
#define false 0

#define MAXSIZE 10 //定义最大长度

typedef struct {
    int data[MAXSIZE]; //使用静态数组存放数据元素
    int length;        //顺序表的长度
} SqList;

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

// 二叉树的结点（链式存储）
typedef struct BiTNode {
    int data;                        // 数据域
    struct BiTNode *lchild, *rchild; // 左、右孩子指针
} BiTNode, *BiTree;

// 线索二叉树结点
typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左、右线索标志；tag==0,表示指向孩子，tag==1表示指针是线索
} ThreadNode, *ThreadTree;

// 链式队列结点
typedef struct LinkNode {
    BiTNode* data; // 存指针而不是结点
    struct LinkNode* next;
} LinkNode;

// 链式队列
typedef struct {
    LinkNode *front, *rear; // 队列的队头和队尾指针
} LinkQueue;

/* 定义二叉树节点结构体 */
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct node {
    char* data; // 存储操作数或操作符
    struct node *lchild, *rchild;
}BTNode,*BTree;

typedef char VertexType;
typedef int EdgeType;
#define MAXV 5
typedef struct{                 // 图的定义
    int numVertices,numEdges;   // 图中实际的顶点数和边数
    VertexType VerticesList[MAXV];    // 顶点表
    EdgeType Edge[MAXV][MAXV];       // 邻接矩阵
}MGraph;

#endif
