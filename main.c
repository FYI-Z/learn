#include"function.h"
int main()
{
	int choose;		//用户命令
	DuLinkList L;
	InitDuLinkList(&L);			//初始化双向链表

	read(&L);			//读取职工工资数据
	while(1)
	{
		printf("***********************************\n");
		printf("****          欢迎使用         ****\n");
		printf("****      职工工资管理系统     ****\n");
		printf("****         查询请输入1       ****\n");
		printf("****         修改请输入2       ****\n");
		printf("****         添加请输入3       ****\n");
		printf("****         删除请输入4       ****\n");
		printf("****         保存请输入5       ****\n");
		printf("****         浏览请输入6       ****\n");
		printf("****         退出请输入7       ****\n");
		printf("***********************************\n");
		printf("请输入您的选择：");
		if(scanf("%d",&choose) != 1)		//输入的数据不是整形
		{
			while ((getchar()) != '\n');			//清除缓存区
			printf("输入错误，请重新输入您选择！\n");
		}
		else
		{
			switch(choose)
			{
			case 1:find(&L);break;
			case 2:modify(&L);break;
			case 3:add(&L);break;
			case 4:del(&L);break;
			case 5:write(&L);break;
			case 6:list(&L);break;
			case 7:printf("感谢您的使用！\n");system("pause");return 0;
			default:printf("输入错误，请重新输入您选择！\n");break;
			}
		}
	}
}
