#include"function.h"
//���ְ����������

Status add(DuLinkList *L)
{
	int i;		//����ѭ��
	int addnum;		//��Ҫ��ӵ�ְ������
	printf("��������Ҫ��ӵ�ְ��������");
	scanf("%d", &addnum);
	printf("�����ʽ������  ����  ��λ����  н������  ְ�����  ��Ч����<Enter>\n");
	for(i = 0; i<addnum; )
	{
		DuLNode *p = (DuLNode*)malloc(sizeof(DuLNode));
		printf("�������%d����Ҫ��ӵ�ְ���������ݣ�\n", i+1);
		scanf("%s%s%f%f%f%f", p->data.id, p->data.name, &p->data.gwgz, &p->data.xjgz, &p->data.zwjt, &p->data.jxgz);
		if(strspn(p->data.id, "0123456789") == strlen(p->data.id) && strlen(p->data.id) <= 10)		//�ж�����Ĺ����Ƿ���ϸ�ʽҪ��
		{
			p->data.yfgz = p->data.gwgz + p->data.xjgz + p->data.zwjt + p->data.jxgz;		//����Ӧ������

			grsds(p);			//�����������˰
			
			p->data.sfgz = p->data.yfgz - p->data.grsds;		//����ʵ������
			
			//��ְ�����ݲ���˫�������β

			p->next = L->tail;
			p->prior = L->tail->prior;
			L->tail->prior->next = p;
			L->tail->prior = p;
			L->len++;
			i++;
			printf("��ӳɹ���\n");
		}
		else
		{
			printf("����Ĺ��Ÿ�ʽ����,����������!\n");
		}
	}
	return OK;
}