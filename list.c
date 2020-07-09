#include"function.h"
//浏览职工工资数据
Status list(DuLinkList *L)
{
	DuLNode *p = L->head->next;		//p指针指向表头
	if(p == L->tail)
	{
		printf("当前职工工资数据为空！\n");
		return ERROR;
	}
	printf("全体职工工资数据如下：\n");
	while(p != L->tail)
	{
		printf("工号:%s     姓名:%s     岗位工资:%.2f     薪级工资:%.2f     职务津贴:%.2f     绩效工资:%.2f     应发工资:%.2f     个人所得税:%.2f     实发工资:%.2f\n",p->data.id, p->data.name, p->data.gwgz, p->data.xjgz, p->data.zwjt, p->data.jxgz, p->data.yfgz, p->data.grsds, p->data.sfgz);
		p = p->next;
	}
	return OK;
}