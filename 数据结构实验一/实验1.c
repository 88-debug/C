#include<stdio.h>
#include<stdlib.h>
typedef  int  elemtype;//把int改名为elemtype
#define  LIST_INIT_SIZE  20//初始长度
#define  LISTINCREMENT  10//增加长度
typedef struct List
{
	elemtype * list;//因为现在是顺序存储结构，所以这里存放数组的首地址
	int maxsize;//能放置数目的最大数
	int size;//当前存放的数目
}List;

void List_ini(List* a, int maxsize);//初始化线性表
void List_save();//存入数据，保持升序
void List_insert(int index, int n);//插入一个数，保持有序性
void List_delete();//节点的删除
void List_bianli();


void List_ini(List* a)//初始化线性表
{
	a->maxsize = LIST_INIT_SIZE;
	a->list = (int*)malloc(sizeof(int)*LIST_INIT_SIZE);//数组用来存放数，每个4字节，最多有maxsize这么多
	a->size = 0;//此时没有节点
	printf("此时线性表的大小为%d\n", a->size);
	printf("初始化线性表的地址大小占据%d个字节，当前数组大小为20\n", sizeof(a->list));
}

void List_save(List* a)
{
	int n = 6;
	printf("按照升序排列输入%d个数字\n",n);
	for (int i = 0; i < 6; i++)
	{
		
		scanf("%d",&a->list[i]);
		a->size++;
	}
	
}
void List_insert(List* a, int n)//index为想插入到第几个，n为键入的数字
{

	int index;
	if (a->size + 1 < a->maxsize || a->size + 1 == a->maxsize)
	{
		for (int i = 0; i < a->size; i++)//遍历找到应该插入的位置
		{
			if (a->list[i] == n || (a->list[i - 1]<n&&a->list[i]>n))
			{
				index = i;//找到位置
			}
		}
		for (int i = a->size; i > index; i--)
		{
			a->list[i] = a->list[i - 1];
		}
		a->list[index] = n;//插入完成
	}
	a->size++;
}

void List_delete(List* a,int x)
{   int index;
	int j = 0;
	if (a->size > 0)//不为空表	
	{
		for (int i = 0; i < a->size; i++)//遍历线性表
		{
			if (a->list[i] == x)//若有元素相等
			{
				index = i;
				for (int i = index; i <a->size; i++)
					a->list[i] = a->list[i + 1];//删除只需要从index 一个个往前挪就行了
				a->size--;
			}
		}
	}
	else
	{
		printf("此表为空表");
	}
}

void List_bianli(List* a)
{
	if (a->size>0)
	{
		printf("\n此时表中数据为：\n");
		for (int i = 0; i <a->size; i++)
		{
			printf("%d ", a->list[i]);
		}
	}
	else
	{
		printf("此表为空表");
	}
}
int main()
{
	List li;
	int insert;//要插入数据
	int delete1;
	List_ini(&li);
	List_save(&li);
	List_bianli(&li);
	printf("\n输入一个要插入的数字\n");
	scanf("%d", &insert);
	List_insert(&li, insert);
	List_bianli(&li);
	printf("\n输入一个要删除的数字\n");
	scanf("%d", &delete1);
	List_delete(&li, delete1);
	List_bianli(&li);
	system("pause");
	return 0;

}