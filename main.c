#include <stdio.h>
#include <stdlib.h>
#include "looplink.h"
int main(int argc, const char *argv[])
{
	Looplink* L = list_create();
	if(NULL==L)
	{
		return -1;
	}
	int m,n;
	printf("请输入n>>>");
	scanf("%d",&n);
	printf("请输入m>>>");
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
		list_insert_tail(L,i+1);
	}
	//调用删除头节点的函数
	Looplink* S = delete_head(L);
	L = NULL;
	Circle(S,n,m);
	return 0;
}
