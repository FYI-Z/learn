#include"function.h"
//���ְ����������
Status list(DuLinkList *L)
{
	DuLNode *p = L->head->next;		//pָ��ָ���ͷ
	if(p == L->tail)
	{
		printf("��ǰְ����������Ϊ�գ�\n");
		return ERROR;
	}
	printf("ȫ��ְ�������������£�\n");
	while(p != L->tail)
	{
		printf("����:%s     ����:%s     ��λ����:%.2f     н������:%.2f     ְ�����:%.2f     ��Ч����:%.2f     Ӧ������:%.2f     ��������˰:%.2f     ʵ������:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
		p = p->next;
	}
	return OK;
}