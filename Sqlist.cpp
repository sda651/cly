#include<stdio.h>
#include<stdlib.h>

//结果函数状态代码 
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
#define MAXSIZE 100		//顺序表可能达到的最大长度 

typedef int Status;  // Status--函数的类型，其值是函数结果的状态代码
typedef char ElemType; 
typedef struct
{
	ElemType *elem;		//存储空间的首地址
	int length;			//当前长度 
}SqList;				//顺序表结构类型为SqList 


//主函数
int main()
{
	Status InitList_SQ(SqList *L);		//线性表的初始化
	void DestroyList(SqList *L);		//销毁线性表 
	void ClearList(SqList *L);			//清空线性表
	void ShowList(SqList L);			//输出显示线性表
	int GetLength(SqList L);			//求线性表的长度
	int IsEmpty(SqList L);				//判断线性表是否为空
	ElemType GetElem(SqList L, int i);	//顺序表的取值(根据位置i获取相应位置数据元素的内容)
	int LocateElem(SqList L, ElemType e);	//顺序按值查找
	Status ListInsert_Sq(SqList *L, int i, ElemType e);	//线性表指定位置i的插入
	Status ListDelete_Sq(SqList *L, int i);				//线性表指定位置i的删除
	
	SqList L;
	InitList_SQ(&L);
	int i;
	ElemType j = 'a';
	for(i = 0; j<='h';i++,j++)
	{
		ListInsert_Sq(&L, i+1, j);	
	}
	ShowList(L);
	printf("顺序表长度为：%d\n",GetLength(L));
	int n = 6;
	printf("顺序表第%d位为：%c\n",n,GetElem(L,n));
	ElemType e = 'e', recive = GetElem(L,n);
	printf("%c在顺序表中的位置为：%d\n",e,LocateElem(L,e));
	ListDelete_Sq(&L, n);
	ShowList(L);
	ListInsert_Sq(&L, n, recive);
	ShowList(L);
}


//顺序表的初始化
Status InitList_SQ(SqList *L)		//构造一个空的顺序表L
{
	L->elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);		//为顺序表分配空间 
	if(!L->elem) return OVERFLOW;	//存储分配失败
	L->length = 0;					//空表长度为0
	return OK; 
 } 
 
 //销毁顺序表
void DestroyList(SqList *L)
{
	if(L) free(L);			//释放存储空间 
}

//清空顺序表
void ClearList(SqList *L)
{
	L->length = 0;			//将线性表长度置为0 
}

//求顺序表的长度
int GetLength(SqList L) 
{
	return L.length;
}


//输出顺序表
void ShowList(SqList L)
{
	int i;
	printf("The List : ");
	for(i=0;i<L.length;i++)
	{
		printf("%c, ",L.elem[i]);
	}
	printf("\n");
 } 
 
 //判断顺序表是否为空
 int IsEmpty(SqList L)
{
	if(L.length == 0) return 1;
	else return 0;
 } 
 
 
 //根据位置 i 获取相应位置数据元素
 ElemType GetElem(SqList L, int i)
{
	if(i<1 || L.length<i) return ERROR;
	
	return L.elem[i-1];
}

//按值查找
int LocateElem(SqList L, ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i]==e) return i+1;
	}
	
	return 0;		//查找失败，返回0； 
}


//顺序表指定位置 i 的插入
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	if(i<1 || i>L->length+1) return ERROR;		//i值不合法
	if(L->length == MAXSIZE)	return ERROR;		//当前存储空间已满 
	
	int j;
	for(j=L->length-1;j>=i-1;j--)
	{
		L->elem[j+1] = L->elem[j];				//插入位置及之前的元素后移 
	}
	L->elem[i-1] = e;							//将新元素e放入第i个位置 
	L->length ++;								//表长 + 1
	return OK;
}


//顺序表指定位置i的删除
 Status ListDelete_Sq(SqList *L, int i)
{
	if(i<1 || i>L->length+1) return ERROR;		//i值不合法
	
	int j;
	for(j=i-1;j<=L->length-1;j++)
	{
		L->elem[j] = L->elem[j+1];				//被删除元素之后的元素前移 
	}
	L->length --;								//表长 -1
	return OK; 
}

