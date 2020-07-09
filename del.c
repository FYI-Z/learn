#include"function.h"
//删除职工工资数据

Status del(DuLinkList *L)
{
	int i;			//控制循环
	char delid[15];			//存放需要删除的职工工号
	int delnum;				//需要删除的职工总数
	printf("请输入需要删除的职工总数：");
	scanf("%d",&delnum);
	for(i = 0; i < delnum; )		//循环删除
	{
		int flag = 0;			//作为是否删除成功的标志
		printf("请输入第%d个需要删除的职工工号：", i+1);
		scanf("%s",delid);
		if(strspn(delid, "0123456789") == strlen(delid) && strlen(delid) <= 10)		//判断输入的工号是否符合格式要求
		{
			DuLNode *p = L->head->next;	
			while(p != L->tail)
			{
				if(strcmp(p->data.id,delid) == 0)			//存在对应工号的职工
				{
					printf("需要删除的职工工资数据：\n");
					printf("工号:%s     姓名:%s     岗位工资:%.2f     薪级工资:%.2f     职务津贴:%.2f     绩效工资:%.2f     应发工资:%.2f     个人所得税:%.2f     实发工资:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
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
				printf("删除成功！\n");
			}
			else
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