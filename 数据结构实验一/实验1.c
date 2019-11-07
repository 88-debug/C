#include<stdio.h>
#include<stdlib.h>
typedef  int  elemtype;//��int����Ϊelemtype
#define  LIST_INIT_SIZE  20//��ʼ����
#define  LISTINCREMENT  10//���ӳ���
typedef struct List
{
	elemtype * list;//��Ϊ������˳��洢�ṹ������������������׵�ַ
	int maxsize;//�ܷ�����Ŀ�������
	int size;//��ǰ��ŵ���Ŀ
}List;

void List_ini(List* a, int maxsize);//��ʼ�����Ա�
void List_save();//�������ݣ���������
void List_insert(int index, int n);//����һ����������������
void List_delete();//�ڵ��ɾ��
void List_bianli();


void List_ini(List* a)//��ʼ�����Ա�
{
	a->maxsize = LIST_INIT_SIZE;
	a->list = (int*)malloc(sizeof(int)*LIST_INIT_SIZE);//���������������ÿ��4�ֽڣ������maxsize��ô��
	a->size = 0;//��ʱû�нڵ�
	printf("��ʱ���Ա�Ĵ�СΪ%d\n", a->size);
	printf("��ʼ�����Ա�ĵ�ַ��Сռ��%d���ֽڣ���ǰ�����СΪ20\n", sizeof(a->list));
}

void List_save(List* a)
{
	int n = 6;
	printf("����������������%d������\n",n);
	for (int i = 0; i < 6; i++)
	{
		
		scanf("%d",&a->list[i]);
		a->size++;
	}
	
}
void List_insert(List* a, int n)//indexΪ����뵽�ڼ�����nΪ���������
{

	int index;
	if (a->size + 1 < a->maxsize || a->size + 1 == a->maxsize)
	{
		for (int i = 0; i < a->size; i++)//�����ҵ�Ӧ�ò����λ��
		{
			if (a->list[i] == n || (a->list[i - 1]<n&&a->list[i]>n))
			{
				index = i;//�ҵ�λ��
			}
		}
		for (int i = a->size; i > index; i--)
		{
			a->list[i] = a->list[i - 1];
		}
		a->list[index] = n;//�������
	}
	a->size++;
}

void List_delete(List* a,int x)
{   int index;
	int j = 0;
	if (a->size > 0)//��Ϊ�ձ�	
	{
		for (int i = 0; i < a->size; i++)//�������Ա�
		{
			if (a->list[i] == x)//����Ԫ�����
			{
				index = i;
				for (int i = index; i <a->size; i++)
					a->list[i] = a->list[i + 1];//ɾ��ֻ��Ҫ��index һ������ǰŲ������
				a->size--;
			}
		}
	}
	else
	{
		printf("�˱�Ϊ�ձ�");
	}
}

void List_bianli(List* a)
{
	if (a->size>0)
	{
		printf("\n��ʱ��������Ϊ��\n");
		for (int i = 0; i <a->size; i++)
		{
			printf("%d ", a->list[i]);
		}
	}
	else
	{
		printf("�˱�Ϊ�ձ�");
	}
}
int main()
{
	List li;
	int insert;//Ҫ��������
	int delete1;
	List_ini(&li);
	List_save(&li);
	List_bianli(&li);
	printf("\n����һ��Ҫ���������\n");
	scanf("%d", &insert);
	List_insert(&li, insert);
	List_bianli(&li);
	printf("\n����һ��Ҫɾ��������\n");
	scanf("%d", &delete1);
	List_delete(&li, delete1);
	List_bianli(&li);
	system("pause");
	return 0;

}