#include"function.h"
//读取职工工资数据

Status read(DuLinkList *L)
{
	DuLNode *p;
	if((fp = fopen("gz.dat","rb")) == NULL)
	{
		printf("文件打开失败!\n");
		return ERROR;
	}
	p = (DuLNode*)malloc(sizeof(DuLNode));
	while(fread(p, sizeof(Employee), 1, fp) != 0)
	{
		//将文件中的职工工资数据存储到双向链表

		p->next = L->tail;
		p->prior =L->tail->prior;
		L->tail->prior->next = p;
		L->tail->prior = p;
		L->len++;
		p = (DuLNode*)malloc(sizeof(DuLNode));
	}
	fclose(fp);
	return OK;
}