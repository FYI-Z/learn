#include"function.h"
//��ʼ��˫������

Status InitDuLinkList(DuLinkList *L)
{
	L->head = (DuLNode*)malloc(sizeof(DuLNode));
	L->tail = (DuLNode*)malloc(sizeof(DuLNode));
	if(L->head == NULL || L->tail == NULL)
	{
		printf("��ͷ�ڵ��β�ڵ��˫���ѭ�������ʼ��ʧ�ܣ�");
		return ERROR;
	}
	L->head->prior = NULL;
	L->tail->next = NULL;
	L->head->next = L->tail;
	L->tail->prior = L->head;
	L->len = 0;
	return OK;
}