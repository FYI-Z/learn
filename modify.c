#include"function.h"
//修改职工工资数据

Status modify(DuLinkList *L)
{
	int i;			//控制循环
	int modifynum;				//需要删除的职工总数
	char modifyid[15];		//存储需要修改的职工工号
	printf("请输入需要修改的职工总数：");
	scanf("%d",&modifynum);
	for(i = 0; i < modifynum; )		//循环修改
	{
		int flag = 0;			//作为是否有对应职工的标志
		printf("请输入第%d个需要修改的职工工号：", i+1);
		scanf("%s", modifyid);
		if(strspn(modifyid, "0123456789") == strlen(modifyid) && strlen(modifyid) <= 10)		//判断输入的工号是否符合格式要求
		{
			DuLNode *p = L->head->next;
			while(p != L->tail)
			{
				if(strcmp(p->data.id,modifyid) == 0)
				{
					printf("职工工资修改前的数据：\n");
					printf("工号:%s     姓名:%s     岗位工资:%.2f     薪级工资:%.2f     职务津贴:%.2f     绩效工资:%.2f     应发工资:%.2f     个人所得税:%.2f     实发工资:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
					printf("请重新输入该职工工资数据:\n");
					printf("输入格式：工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资<Enter>\n");
					scanf("%s%s%f%f%f%f", p->data.id, p->data.name, &p->data.gwgz, &p->data.xjgz, &p->data.zwjt, &p->data.jxgz);
					
					p->data.yfgz = p->data.gwgz + p->data.xjgz + p->data.zwjt + p->data.jxgz;		//计算应发工资
					
					grsds(p);			//计算个人所得税
					
					p->data.sfgz = p->data.yfgz - p->data.grsds;		//计算实发工资
					
					printf("职工工资修改后的数据：\n");
					printf("工号:%s     姓名:%s     岗位工资:%.2f     薪级工资:%.2f     职务津贴:%.2f     绩效工资:%.2f     应发工资:%.2f     个人所得税:%.2f     实发工资:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
					flag = 1;		//数据修改成功
					i++;
					break;
				}
				p = p->next;
			}
			if(flag == 1)
			{
				printf("修改成功！\n");
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