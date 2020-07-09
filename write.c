#include"function.h"
//保存职工工资数据

Status write(DuLinkList *L)
{
	DuLNode *p = L->head->next;		//p指针指向表头
	if( p == L->tail)
	{
		printf("链表中没有职工数据！\n");
		return ERROR;
	}
	if((fp = fopen("gz.dat", "wb")) == NULL)
	{
		printf("文件打开失败！");
		return ERROR;
	}
	while(p != L->tail)
	{
		fwrite(p, sizeof(Employee), 1, fp);
		p = p->next;
	}
	printf("保存成功！\n");
	fclose(fp);
	return OK;
}