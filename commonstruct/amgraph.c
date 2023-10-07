/**
 * @file amgraph.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 图的邻接矩阵存储
 * @version 0.1
 * @date 2023-08-24 09:06:05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "commonstruct.h"
#include "stdtypedef.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define correct 1
#define error   -1

// 获取顶点的下标
int LocateVertices(MGraph G, VertexType V) {
    int i;
    for (i = 0; i < G.numVertices; i++) {
        if (G.VerticesList[i] == V) {
            return i;
        }
    }
    return error;
}

// 无向图
void CreateMGraph(MGraph* G) {
    printf("请输入图的总顶点数和总边数：\n");
    scanf("%d %d", &(G->numVertices), &(G->numEdges));
    // 对图的邻接矩阵进行初始化操作
    int i, j;
    for (i = 0; i < G->numVertices; i++) {
        for (j = 0; j < G->numVertices; j++) {
            G->Edge[i][j] = 0;
        }
    }
    // 完成各个顶点的输入
    for (i = 0; i < G->numVertices; i++) {
        printf("请输入第%d个点的名称：\n", i + 1);
        getchar();
        scanf("%c", &(G->VerticesList[i]));
    }
    // 完成各条边的输入
    for (i = 1; i <= G->numEdges; i++) {
        printf("请输入第%d条边的两个顶点的名称：\n", i);
        getchar();
        VertexType c1, c2;
        int x, y;
        scanf("%c %c", &c1, &c2);
        x = LocateVertices(*G, c1);
        y = LocateVertices(*G, c2);
        G->Edge[x][y] = 1;
        G->Edge[y][x] = 1;
    }
}

// 有向图
void CreateMGraphDirect(MGraph* G) {
    printf("请输入图的总顶点数和总边数：\n");
    scanf("%d %d", &(G->numVertices), &(G->numEdges));
    // 对图的邻接矩阵进行初始化操作
    int i, j;
    for (i = 0; i < G->numVertices; i++) {
        for (j = 0; j < G->numVertices; j++) {
            G->Edge[i][j] = 0;
        }
    }
    // 完成各个顶点的输入
    for (i = 0; i < G->numVertices; i++) {
        printf("请输入第%d个点的名称：\n", i + 1);
        getchar();
        scanf("%c", &(G->VerticesList[i]));
    }
    // 完成各条边的输入
    for (i = 1; i <= G->numEdges; i++) {
        printf("请输入第%d条边的两个顶点的名称：\n", i);
        getchar();
        VertexType c1, c2;
        int x, y;
        scanf("%c %c", &c1, &c2);
        x = LocateVertices(*G, c1);
        y = LocateVertices(*G, c2);
        G->Edge[x][y] = 1;
        // G->Edge[y][x] = 1;
    }
}

// 输出图的邻接矩阵
void ShowMGraph(MGraph G) {
    int i, j;
    printf("  ");
    for (i = 0; i < G.numVertices; i++) {
        printf("%c ", G.VerticesList[i]);
    }
    printf("\n");
    for (i = 0; i < G.numVertices; i++) {
        printf("%c ", G.VerticesList[i]);
        for (j = 0; j < G.numVertices; j++) {
            printf("%d ", G.Edge[i][j]);
        }
        printf("\n");
    }
}
