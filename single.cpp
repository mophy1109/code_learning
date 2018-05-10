#include <iostream>

using namespace std;
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node *next;
} Node;

/* 初始化顺序线性表 */
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if (!(*L))							 /* 存储分配失败 */
	{
		return ERROR;
	}
	(*L)->next = NULL; /* 指针域为空 */
	return OK;
}
