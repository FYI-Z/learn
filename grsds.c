#include"function.h"
//计算个人所得税

Status grsds(DuLNode *p)
{
	if(p->data.yfgz > 100000)
	{
		p->data.grsds = (p->data.yfgz-100000) * 0.45;
	}
	else if(p->data.yfgz > 80000 && p->data.yfgz <= 100000)
	{
		p->data.grsds = (p->data.yfgz-80000) * 0.40;
	}
	else if(p->data.yfgz > 60000 && p->data.yfgz <= 80000)
	{
		p->data.grsds = (p->data.yfgz-60000) * 0.35;
	}
	else if(p->data.yfgz > 40000 && p->data.yfgz <= 60000)
	{
		p->data.grsds = (p->data.yfgz-40000) * 0.30;
	}
	else if(p->data.yfgz > 20000 && p->data.yfgz <= 40000)
	{
		p->data.grsds = (p->data.yfgz-20000) * 0.25;
	}
	else if(p->data.yfgz > 5000 && p->data.yfgz <= 20000)
	{
		p->data.grsds = (p->data.yfgz-5000) * 0.20;
	}
	else if(p->data.yfgz > 2000 && p->data.yfgz <= 5000)
	{
		p->data.grsds = (p->data.yfgz-2000) * 0.15;
	}
	else if(p->data.yfgz > 500 && p->data.yfgz <= 2000)
	{
		p->data.grsds = (p->data.yfgz-500) * 0.10;
	}
	else
	{
		p->data.grsds = p->data.yfgz * 0.05;
	}
	return OK;
}