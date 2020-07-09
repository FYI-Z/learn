#include"function.h"
//初始化双向链表

Status InitDuLinkList(DuLinkList *L)
{
	L->head = (DuLNode*)malloc(sizeof(DuLNode));
	L->tail = (DuLNode*)malloc(sizeof(DuLNode));
	if(L->head == NULL || L->tail == NULL)
	{
		printf("带头节点和尾节点的双向非循环链表初始化失败！");
		return ERROR;
	}
	L->head->prior = NULL;
	L->tail->next = NULL;
	L->head->next = L->tail;
	L->tail->prior = L->head;
	L->len = 0;
	return OK;
}