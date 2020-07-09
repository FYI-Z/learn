/*---The Program Author: 李章---*/

/*---------包含的头文件---------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*------------宏定义-----------*/
#define OK 1			
#define ERROR 0

/*----------自定义类型---------*/
typedef int Status;

/***********************************

			职工结构体定义

************************************/
typedef struct Employee
{
	char id[15];				//工号
	char name[20];				//姓名
	float gwgz;				//岗位工资
	float xjgz;				//薪级工资
	float zwjt;				//职务津贴	
	float jxgz;				//绩效工资			
	float yfgz;				//应发工资
	float grsds;				//个人所得税
	float sfgz;				//实发工资
}Employee;

/***************************************

			双向链表存储结构

***************************************/
typedef struct DuLNode
{
	Employee data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode;
	
typedef struct			//设置头节点和尾节点
{
	DuLNode *head;
	DuLNode	*tail;
	int len;		//链表长度即职工人数
}DuLinkList;

/******************************

			函数声明

******************************/
Status InitDuLinkList(DuLinkList *L);	//初始化双向链表
Status read(DuLinkList *L);			//读取职工工资数据
Status find(DuLinkList *L);			//查询职工工资数据
Status modify(DuLinkList *L);		//修改职工工资数据
Status add(DuLinkList *L);			//添加职工工资数据
Status del(DuLinkList *L);			//删除职工工资数据
Status write(DuLinkList *L);			//保存职工工资数据
Status list(DuLinkList *L);			//浏览职工工资数据	
Status grsds(DuLNode *p);			//计算个人所得税

/**************************************

				全局变量

**************************************/
FILE *fp;				//指向文件的指针