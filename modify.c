#include"function.h"
//�޸�ְ����������

Status modify(DuLinkList *L)
{
	int i;			//����ѭ��
	int modifynum;				//��Ҫɾ����ְ������
	char modifyid[15];		//�洢��Ҫ�޸ĵ�ְ������
	printf("��������Ҫ�޸ĵ�ְ��������");
	scanf("%d",&modifynum);
	for(i = 0; i < modifynum; )		//ѭ���޸�
	{
		int flag = 0;			//��Ϊ�Ƿ��ж�Ӧְ���ı�־
		printf("�������%d����Ҫ�޸ĵ�ְ�����ţ�", i+1);
		scanf("%s", modifyid);
		if(strspn(modifyid, "0123456789") == strlen(modifyid) && strlen(modifyid) <= 10)		//�ж�����Ĺ����Ƿ���ϸ�ʽҪ��
		{
			DuLNode *p = L->head->next;
			while(p != L->tail)
			{
				if(strcmp(p->data.id,modifyid) == 0)
				{
					printf("ְ�������޸�ǰ�����ݣ�\n");
					printf("����:%s     ����:%s     ��λ����:%.2f     н������:%.2f     ְ�����:%.2f     ��Ч����:%.2f     Ӧ������:%.2f     ��������˰:%.2f     ʵ������:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
					printf("�����������ְ����������:\n");
					printf("�����ʽ������  ����  ��λ����  н������  ְ�����  ��Ч����<Enter>\n");
					scanf("%s%s%f%f%f%f", p->data.id, p->data.name, &p->data.gwgz, &p->data.xjgz, &p->data.zwjt, &p->data.jxgz);
					
					p->data.yfgz = p->data.gwgz + p->data.xjgz + p->data.zwjt + p->data.jxgz;		//����Ӧ������
					
					grsds(p);			//�����������˰
					
					p->data.sfgz = p->data.yfgz - p->data.grsds;		//����ʵ������
					
					printf("ְ�������޸ĺ�����ݣ�\n");
					printf("����:%s     ����:%s     ��λ����:%.2f     н������:%.2f     ְ�����:%.2f     ��Ч����:%.2f     Ӧ������:%.2f     ��������˰:%.2f     ʵ������:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
					flag = 1;		//�����޸ĳɹ�
					i++;
					break;
				}
				p = p->next;
			}
			if(flag == 1)
			{
				printf("�޸ĳɹ���\n");
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