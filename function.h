/*---The Program Author: ����---*/

/*---------������ͷ�ļ�---------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*------------�궨��-----------*/
#define OK 1			
#define ERROR 0

/*----------�Զ�������---------*/
typedef int Status;

/***********************************

			ְ���ṹ�嶨��

************************************/
typedef struct Employee
{
	char id[15];				//����
	char name[20];				//����
	float gwgz;				//��λ����
	float xjgz;				//н������
	float zwjt;				//ְ�����	
	float jxgz;				//��Ч����			
	float yfgz;				//Ӧ������
	float grsds;				//��������˰
	float sfgz;				//ʵ������
}Employee;

/***************************************

			˫������洢�ṹ

***************************************/
typedef struct DuLNode
{
	Employee data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode;
	
typedef struct			//����ͷ�ڵ��β�ڵ�
{
	DuLNode *head;
	DuLNode	*tail;
	int len;		//�����ȼ�ְ������
}DuLinkList;

/******************************

			��������

******************************/
Status InitDuLinkList(DuLinkList *L);	//��ʼ��˫������
Status read(DuLinkList *L);			//��ȡְ����������
Status find(DuLinkList *L);			//��ѯְ����������
Status modify(DuLinkList *L);		//�޸�ְ����������
Status add(DuLinkList *L);			//���ְ����������
Status del(DuLinkList *L);			//ɾ��ְ����������
Status write(DuLinkList *L);			//����ְ����������
Status list(DuLinkList *L);			//���ְ����������	
Status grsds(DuLNode *p);			//�����������˰

/**************************************

				ȫ�ֱ���

**************************************/
FILE *fp;				//ָ���ļ���ָ��