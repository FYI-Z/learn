#include"function.h"
//��ȡְ����������

Status read(DuLinkList *L)
{
	DuLNode *p;
	if((fp = fopen("gz.dat","rb")) == NULL)
	{
		printf("�ļ���ʧ��!\n");
		return ERROR;
	}
	p = (DuLNode*)malloc(sizeof(DuLNode));
	while(fread(p, sizeof(Employee), 1, fp) != 0)
	{
		//���ļ��е�ְ���������ݴ洢��˫������

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