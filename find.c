#include"function.h"
//查询职工工资数据

Status find(DuLinkList *L)
{
	int i;			//控制循环
	int findnum;		//需要查询的职工总数
	char findid[15];		//存放需要查询职工的工号
	printf("请输入需要查询的职工总数：");
	scanf("%d",&findnum);
	for(i = 0; i < findnum; )
	{
		int flag = 0;			//作为是否查询成功的标志
		printf("请输入第%d个需要查询的职工工号：", i+1);
		scanf("%s",findid);
		if(strspn(findid, "0123456789") == strlen(findid) && strlen(findid) <= 10)		//判断输入的工号是否符合格式要求
		{
			DuLNode *p = L->head->next;		//p指针指向表头
			while(p != L->tail)
			{
				if(strcmp(p->data.id, findid)==0)
				{
					printf("第%d个查询的职工工资数据如下：\n",i+1);
					printf("工号:%s     姓名:%s     岗位工资:%.2f     薪级工资:%.2f     职务津贴:%.2f     绩效工资:%.2f     应发工资:%.2f     个人所得税:%.2f     实发工资:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
					i++;
					flag = 1;		//查询成功
				}
				p = p->next;
			}
			if(flag == 0)
			{
				printf("无此职工,请重新输入！\n");
			}
		}
		else
		{
			printf("输入的工号格式出错,请重新输入!\n");
		}
	}
	return OK;
}