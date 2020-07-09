#include"function.h"
//添加职工工资数据

Status add(DuLinkList *L)
{
	int i;		//控制循环
	int addnum;		//需要添加的职工总数
	printf("请输入需要添加的职工总数：");
	scanf("%d", &addnum);
	printf("输入格式：工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资<Enter>\n");
	for(i = 0; i<addnum; )
	{
		DuLNode *p = (DuLNode*)malloc(sizeof(DuLNode));
		printf("请输入第%d个需要添加的职工工资数据：\n", i+1);
		scanf("%s%s%f%f%f%f", p->data.id, p->data.name, &p->data.gwgz, &p->data.xjgz, &p->data.zwjt, &p->data.jxgz);
		if(strspn(p->data.id, "0123456789") == strlen(p->data.id) && strlen(p->data.id) <= 10)		//判断输入的工号是否符合格式要求
		{
			p->data.yfgz = p->data.gwgz + p->data.xjgz + p->data.zwjt + p->data.jxgz;		//计算应发工资

			grsds(p);			//计算个人所得税
			
			p->data.sfgz = p->data.yfgz - p->data.grsds;		//计算实发工资
			
			//将职工数据插入双向链表表尾

			p->next = L->tail;
			p->prior = L->tail->prior;
			L->tail->prior->next = p;
			L->tail->prior = p;
			L->len++;
			i++;
			printf("添加成功！\n");
		}
		else
		{
			printf("输入的工号格式出错,请重新输入!\n");
		}
	}
	return OK;
}