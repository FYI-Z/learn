#include"function.h"
//��ѯְ����������

Status find(DuLinkList *L)
{
	int i;			//����ѭ��
	int findnum;		//��Ҫ��ѯ��ְ������
	char findid[15];		//�����Ҫ��ѯְ���Ĺ���
	printf("��������Ҫ��ѯ��ְ��������");
	scanf("%d",&findnum);
	for(i = 0; i < findnum; )
	{
		int flag = 0;			//��Ϊ�Ƿ��ѯ�ɹ��ı�־
		printf("�������%d����Ҫ��ѯ��ְ�����ţ�", i+1);
		scanf("%s",findid);
		if(strspn(findid, "0123456789") == strlen(findid) && strlen(findid) <= 10)		//�ж�����Ĺ����Ƿ���ϸ�ʽҪ��
		{
			DuLNode *p = L->head->next;		//pָ��ָ���ͷ
			while(p != L->tail)
			{
				if(strcmp(p->data.id, findid)==0)
				{
					printf("��%d����ѯ��ְ�������������£�\n",i+1);
					printf("����:%s     ����:%s     ��λ����:%.2f     н������:%.2f     ְ�����:%.2f     ��Ч����:%.2f     Ӧ������:%.2f     ��������˰:%.2f     ʵ������:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
					i++;
					flag = 1;		//��ѯ�ɹ�
				}
				p = p->next;
			}
			if(flag == 0)
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