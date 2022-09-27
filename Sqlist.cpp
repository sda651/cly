#include<stdio.h>
#include<stdlib.h>

//�������״̬���� 
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
#define MAXSIZE 100		//˳�����ܴﵽ����󳤶� 

typedef int Status;  // Status--���������ͣ���ֵ�Ǻ��������״̬����
typedef char ElemType; 
typedef struct
{
	ElemType *elem;		//�洢�ռ���׵�ַ
	int length;			//��ǰ���� 
}SqList;				//˳���ṹ����ΪSqList 


//������
int main()
{
	Status InitList_SQ(SqList *L);		//���Ա�ĳ�ʼ��
	void DestroyList(SqList *L);		//�������Ա� 
	void ClearList(SqList *L);			//������Ա�
	void ShowList(SqList L);			//�����ʾ���Ա�
	int GetLength(SqList L);			//�����Ա�ĳ���
	int IsEmpty(SqList L);				//�ж����Ա��Ƿ�Ϊ��
	ElemType GetElem(SqList L, int i);	//˳����ȡֵ(����λ��i��ȡ��Ӧλ������Ԫ�ص�����)
	int LocateElem(SqList L, ElemType e);	//˳��ֵ����
	Status ListInsert_Sq(SqList *L, int i, ElemType e);	//���Ա�ָ��λ��i�Ĳ���
	Status ListDelete_Sq(SqList *L, int i);				//���Ա�ָ��λ��i��ɾ��
	
	SqList L;
	InitList_SQ(&L);
	int i;
	ElemType j = 'a';
	for(i = 0; j<='h';i++,j++)
	{
		ListInsert_Sq(&L, i+1, j);	
	}
	ShowList(L);
	printf("˳�����Ϊ��%d\n",GetLength(L));
	int n = 6;
	printf("˳����%dλΪ��%c\n",n,GetElem(L,n));
	ElemType e = 'e', recive = GetElem(L,n);
	printf("%c��˳����е�λ��Ϊ��%d\n",e,LocateElem(L,e));
	ListDelete_Sq(&L, n);
	ShowList(L);
	ListInsert_Sq(&L, n, recive);
	ShowList(L);
}


//˳���ĳ�ʼ��
Status InitList_SQ(SqList *L)		//����һ���յ�˳���L
{
	L->elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);		//Ϊ˳������ռ� 
	if(!L->elem) return OVERFLOW;	//�洢����ʧ��
	L->length = 0;					//�ձ���Ϊ0
	return OK; 
 } 
 
 //����˳���
void DestroyList(SqList *L)
{
	if(L) free(L);			//�ͷŴ洢�ռ� 
}

//���˳���
void ClearList(SqList *L)
{
	L->length = 0;			//�����Ա�����Ϊ0 
}

//��˳���ĳ���
int GetLength(SqList L) 
{
	return L.length;
}


//���˳���
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
 
 //�ж�˳����Ƿ�Ϊ��
 int IsEmpty(SqList L)
{
	if(L.length == 0) return 1;
	else return 0;
 } 
 
 
 //����λ�� i ��ȡ��Ӧλ������Ԫ��
 ElemType GetElem(SqList L, int i)
{
	if(i<1 || L.length<i) return ERROR;
	
	return L.elem[i-1];
}

//��ֵ����
int LocateElem(SqList L, ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i]==e) return i+1;
	}
	
	return 0;		//����ʧ�ܣ�����0�� 
}


//˳���ָ��λ�� i �Ĳ���
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	if(i<1 || i>L->length+1) return ERROR;		//iֵ���Ϸ�
	if(L->length == MAXSIZE)	return ERROR;		//��ǰ�洢�ռ����� 
	
	int j;
	for(j=L->length-1;j>=i-1;j--)
	{
		L->elem[j+1] = L->elem[j];				//����λ�ü�֮ǰ��Ԫ�غ��� 
	}
	L->elem[i-1] = e;							//����Ԫ��e�����i��λ�� 
	L->length ++;								//�� + 1
	return OK;
}


//˳���ָ��λ��i��ɾ��
 Status ListDelete_Sq(SqList *L, int i)
{
	if(i<1 || i>L->length+1) return ERROR;		//iֵ���Ϸ�
	
	int j;
	for(j=i-1;j<=L->length-1;j++)
	{
		L->elem[j] = L->elem[j+1];				//��ɾ��Ԫ��֮���Ԫ��ǰ�� 
	}
	L->length --;								//�� -1
	return OK; 
}

