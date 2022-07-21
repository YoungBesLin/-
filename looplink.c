#include <stdio.h>
#include <stdlib.h>
#include "looplink.h"
//创建
Looplink* list_create()
{
	Looplink* L = (Looplink*)malloc(sizeof(Looplink));	
	if(NULL==L)
	{
		printf("创建失败！\n");
		return NULL;
	}
	L->len = 0;
	L->next = L; 	//初始化时头节点的指针域指向自己

//	printf("创建成功\n");
	return L;
}
//判空
int list_empty(Looplink* L)
{
	return L->next == L?1:0; 		//1表示空 0表示非空
}
//尾插
int list_insert_tail(Looplink* L,datatype e)
{
	if(NULL==L)
	{
		printf("所给链表不合法\n");
		return -1;
	}
	//申请新节点
	Looplink* p = (Looplink*)malloc(sizeof(Looplink));
	if(NULL == p)
	{
		printf("节点申请失败!\n");
		return -2;
	}
	p->data=e;
	p->next = NULL;
	//遍历指针到最后一个节点
	Looplink* q = L;
	while(q->next != L)
	{
		q = q->next;
	}
	//插入逻辑
	p->next = L;
	q->next = p;
	//表的变化
	L->len++;
	//printf("尾插成功!\n");
	return 0;
}
//删头节点
Looplink* delete_head(Looplink* L)
{
	//判断逻辑
	if(NULL == L||list_empty(L))
	{
		printf("删除失败\n");
		return NULL;
	}
	//定义遍历指针指向最后一个节点
	Looplink* p = L->next;
	while(p->next!=L)
	{
		p = p->next;
	}	
	//孤立头节点
	p->next = L->next;
	//删除头节点
	free(L);
	L=NULL;
//	printf("头节点删除成功!\n");
	//返回第一个节点的地址
	return p->next;
}


//约瑟夫环
void Circle(Looplink* L,int n,int m)
{
	Looplink* p = L;
	Looplink* q = L;
	while(n>0)
	{
		for(int i=1;i<3;i++)
		{
			q=q->next;
		}
		for(int i=1;i<4;i++)
		{
			p=p->next;

		}
		q->next = p->next;
		printf("%d\t",p->data);
		p=p->next;
		q=q->next;
		n--;
	}
	printf("\n");
}
