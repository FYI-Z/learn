#include"function.h"
int main()
{
	int choose;		//�û�����
	DuLinkList L;
	InitDuLinkList(&L);			//��ʼ��˫������

	read(&L);			//��ȡְ����������
	while(1)
	{
		printf("***********************************\n");
		printf("****          ��ӭʹ��         ****\n");
		printf("****      ְ�����ʹ���ϵͳ     ****\n");
		printf("****         ��ѯ������1       ****\n");
		printf("****         �޸�������2       ****\n");
		printf("****         ���������3       ****\n");
		printf("****         ɾ��������4       ****\n");
		printf("****         ����������5       ****\n");
		printf("****         ���������6       ****\n");
		printf("****         �˳�������7       ****\n");
		printf("***********************************\n");
		printf("����������ѡ��");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:find(&L);break;
		case 2:modify(&L);break;
		case 3:add(&L);break;
		case 4:del(&L);break;
		case 5:write(&L);break;
		case 6:list(&L);break;
		case 7:printf("��л����ʹ�ã�\n");system("pause");return 0;
		default:printf("�������������������ѡ��\n");break;
		}
	}
}