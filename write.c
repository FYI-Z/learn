#include"function.h"
//����ְ����������

Status write(DuLinkList *L)
{
	DuLNode *p = L->head->next;		//pָ��ָ���ͷ
	if( p == L->tail)
	{
		printf("������û��ְ�����ݣ�\n");
		return ERROR;
	}
	if((fp = fopen("gz.dat", "wb")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		return ERROR;
	}
	while(p != L->tail)
	{
		fwrite(p, sizeof(Employee), 1, fp);
		p = p->next;
	}
	printf("����ɹ���\n");
	fclose(fp);
	return OK;
}