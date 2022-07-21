#ifndef ___LOOPLINK_H
#define ___LOOPLINK_H

typedef int datatype;
typedef struct Node
{
	union
	{
		datatype data; 		//普通节点数据域
		int len; 		//头结点数据域
	};
	struct Node* next; 	//指针域
}Looplink;

//创建
Looplink* list_create();
//尾插
int list_insert_tail(Looplink* L,datatype e);
//删头
Looplink* delete_head(Looplink* L);
//判空
int list_empty(Looplink* L);
//删除头结点后的遍历
void list_show2(Looplink* L);

//约瑟夫环
void Circle(Looplink* L,int n,int m);
#endif
