#include"function.h"
//ɾ��ְ����������

Status del(DuLinkList *L)
{
	int i;			//����ѭ��
	char delid[15];			//�����Ҫɾ����ְ������
	int delnum;				//��Ҫɾ����ְ������
	printf("��������Ҫɾ����ְ��������");
	scanf("%d",&delnum);
	for(i = 0; i < delnum; )		//ѭ��ɾ��
	{
		int flag = 0;			//��Ϊ�Ƿ�ɾ���ɹ��ı�־
		printf("�������%d����Ҫɾ����ְ�����ţ�", i+1);
		scanf("%s",delid);
		if(strspn(delid, "0123456789") == strlen(delid) && strlen(delid) <= 10)		//�ж�����Ĺ����Ƿ���ϸ�ʽҪ��
		{
			DuLNode *p = L->head->next;	
			while(p != L->tail)
			{
				if(strcmp(p->data.id,delid) == 0)			//���ڶ�Ӧ���ŵ�ְ��
				{
					printf("��Ҫɾ����ְ���������ݣ�\n");
					printf("����:%s     ����:%s     ��λ����:%.2f     н������:%.2f     ְ�����:%.2f     ��Ч����:%.2f     Ӧ������:%.2f     ��������˰:%.2f     ʵ������:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
					p->prior->next = p->next;
					p->next->prior = p->prior;
					L->len--;
					i++;
					flag = 1;
					break;
				}
				p = p->next;
			}
			if(flag == 1)
			{
				printf("ɾ���ɹ���\n");
			}
			else
			{
				printf("�޴�ְ��,���������룡\n");
			}
		}
		else
		{
			printf("����Ĺ��Ÿ�ʽ����,����������!\n");
		}
	}
	return OK;
}