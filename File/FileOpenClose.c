/**
 * @file FileOpenClose.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 文件的读操作
 * @version 0.1
 * @date 2023-10-04 15:15:23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 /*
 流程：打开文件，读写文件，关闭文件
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "fileoperate.h"

#define N 100

void FileOperationOpen(){
    FILE *fp;

    char str[N+1];

    // 判断文件是否打开失败
    if((fp = fopen("/home/okami/C_Struct/File/test.txt","rt")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    // 循环读取文件的每一行数据
    while( fgets(str, N, fp) != NULL){
        printf("%s",str);
    }

    putchar('\n');

    // 操作结束后关闭文件
    fclose(fp);
}

// 字符读取函数fgetc
void FileOperationFgetc(){
    FILE *fp;
    char ch;

    // 判断文件是否打开失败
    if((fp = fopen("/home/okami/C_Struct/File/test.txt","rt")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    // 每次读取一个字符，直到读取完毕
    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }
    putchar('\n');

    if(ferror(fp)){
        puts("读取出错");
    }else{
        puts("读取成功");
    }

    fclose(fp);
}

// 字符写入函数fputc
void FileOperationFputc(){
    FILE *fp;

    char ch;

    // 判断文件是否成功打开
    if((fp = fopen("/home/okami/C_Struct/File/test.txt","wt+")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    printf("Input a string:\n");
    // 每次从键盘读取一个字符并写入文件
    while((ch = getchar()) != '\n'){
        fputc(ch, fp);
    }
    fclose(fp);
}

// 读字符串函数fgets
void FileOperationFgets(){
    FILE *fp;
    char str[N+1];
    if((fp = fopen("/home/okami/C_Struct/File/test.txt","rt")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    while(fgets(str,N,fp) != NULL){
        printf("%s",str);
    }

    fclose(fp);
}

// 写字符串函数fputs
void FileOperationFputs(){
    FILE *fp;
    char str[102] = {0};
    char *strTemp = "C C++ Java Linux Shell";
    if((fp = fopen("/home/okami/C_Struct/File/test.txt","at+")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    printf("Input a string:");
    
    strcat(str, "\n");
    strcat(str, strTemp);
    fputs(str, fp);
    fclose(fp);
}

// 以数据块的形式读写文件
void FileOperationDataBlock(){
    // 从键盘输入的数据放入a,从文件读取的数据放入b
    int a[5], b[5];
    int i,size = sizeof(int);
    FILE *fp;

    // 以二进制方式打开
    if((fp = fopen("/home/okami/C_Struct/File/test.txt","rb+")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    // 从键盘输入数据，并保存到数组a
    for(i = 0; i < 5; i++){
        scanf("%d",&a[i]);
    }

    // 将数组a的内容写入到文件
    fwrite(a, size, 5, fp);
    // 将文件中的位置指针重新定位到文件开头
    rewind(fp);
    // 从文件读取内容并保存到数组b
    fread(b, size, 5, fp);
    // 显示数组b的内容
    for(i = 0; i < 5; i++){
        printf("%d ",b[i]);
    }

    printf("\n");

    fclose(fp);
}

struct stu{
    char name[10];  // 姓名
    int num;        // 学号
    int age;        // 年龄
    float score;    // 成绩
}boya[2],boyb[2],boys[3],boy,*pa,*pb,*pboys;

void FileOperationDataBlock_Write(){
    FILE *fp;
    int i;
    pa = boya;
    pb = boyb;

    if((fp = fopen("/home/okami/C_Struct/File/test.txt","wb+")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    // 从键盘输入数据
    printf("Input data:\n");
    for(i = 0; i < 2; i++,pa++){
        scanf("%s %d %d %f",pa->name,&pa->num,&pa->age,&pa->score);
    }

    // 将数组boya的数据写入文件
    fwrite(boya, sizeof(struct stu), 2, fp);
    // 将文件指针重置到文件开头
    rewind(fp);
    // 从文件读取数据并保存到数据boyb
    fread(boyb, sizeof(struct stu), 2, fp);

    // 输出数组boyb中的数据
    for(i = 0; i < 2; i++,pb++){
        printf("%s %d %d %f\n",pb->name,pb->num,pb->age,pb->score);
    }
    fclose(fp);
}

// 格式化读写文件
void FileOperationFPrint_FScanf(){
    FILE *fp;

    int i;
    pa = boya;
    pb = boyb;

    if((fp = fopen("/home/okami/C_Struct/File/test.txt","wt+")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    // 从键盘读入数据，保存到boya
    printf("Input data:\n");
    for(i = 0; i < 2; i++,pa++){
        scanf("%s %d %d %f",pa->name,&pa->num,&pa->age,&pa->score); 
    }

    pa = boya;
    // 将boya中的数据写入到文件
    for(i = 0; i < 2; i++,pa++){
        fprintf(fp, "%s %d %d %f\n",pa->name,pa->num,pa->age,pa->score);
    }

    // 重置文件指针
    rewind(fp);
    // 从文件中读取数据，保存到boyb
    for(i = 0; i < 2; i++,pb++){
        fscanf(fp, "%s %d %d %f\n",pb->name,&pb->num,&pb->age,&pb->score);
    }
    pb = boyb;
    // 将boyb中的数据输出到显示器
    for(i = 0; i < 2; i++,pb++){
        printf("%s %d %d %f\n",pb->name,pb->num,pb->age,pb->score);
    }

    fclose(fp);
}

void FileOperationRandRW(){
    FILE *fp;
    int i;
    pboys = boys;

    if((fp = fopen("/home/okami/C_Struct/File/test.txt","wb+")) == NULL){
        puts("Fail to open file!");
        exit(0);
    }

    printf("Input data:\n");
    for(i = 0; i < 2; i++,pboys++){
        scanf("%s %d %d %f",pboys->name,&pboys->num,&pboys->age,&pboys->score);
    }

    fwrite(boys, sizeof(struct stu), 3, fp);        // 写入三条学生信息
    fseek(fp, sizeof(struct stu), SEEK_SET);    // 移动位置指针
    fread(&boy, sizeof(struct stu), 1, fp);     // 读取一条学生信息
    printf("%s %d %d %f\n",boy.name,boy.num,boy.age,boy.score);

    fclose(fp);
}
