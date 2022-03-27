#define _CRT_SECURE_NO_WARNINGS
#include "LinkStack.h" 
//��ջ

extern int i;
//��ʼ��ջ
Status initLStack(LinkStack *s)
{
	if (s->top == NULL)
	{
		printf("�Ѿ���ʼ������~~");
	}
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)   //�����ڴ�ɹ��ж�
		return ERROR;
	s->top = NULL;//����topָ��ָ��NULL
	s->count = 0;
	i = 1;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if (s->top == NULL)
		printf("ջ��Ϊ�գ�");
	else
		printf("ջ�в�Ϊ�գ�");
	return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if (s->top == NULL)
		return ERROR;
	else
		printf("Ŀǰջ��Ϊ��%d\n", s->top->data);
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s)
{
	if (s->top == NULL)
		return ERROR;
	LinkStackPtr p, q;
	p = s->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->count = 0;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)//�˴��ò���~~
{
	clearLStack(&s);
	free(s);
	i = 0;
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	if (s->top == NULL)
		return ERROR;
	*length = s->count;
	printf("Ŀǰջ����Ϊ��%d", length);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	if (i == 0)
	{
		printf("���ȳ�ʼ����\n");
	}
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S)   //�����ڴ�ɹ��ж�
		return ERROR;
	S->data = data;
	S->next = s->top;
	s->top = S;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{
	LinkStackPtr p;  //�����ͷ�ɾ���Ľ��
	if (s->top == NULL)
		return ERROR;
	*data = s->top->data;
	printf("��ջ��Ա��%d", *data);
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}

//��ӡջ
Status TraverseList(LinkStack *s)
{
	if (s->count == 0)
	{
		return ERROR;
	}
	printf("��ǰ����Ϊ��");
	LinkStackPtr p;
	p = s->top;
	while (p)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("NULL\n\n");
	return SUCCESS;
}

int Scanf_strong1()
{
	ElemType  e, i = 0, a;
	while (1)
	{
		if (i == 0)
			printf("����������Ҫ��ģʽ��\n");
		else
			printf("���ٴ���������Ҫ��ģʽ��\n");
		a = scanf("%d", &e);
		if (a)
			break;
		else
		{
			printf("���������֣�����������\n\n");
			gets(&(char)a);
			i++;
		}
	}
	return e;
}

int Scanf_strong2()
{
	ElemType  e, i = 0, a;
	while (1)
	{
		if (i == 0);
		else
			printf("���ٴ����룺\n");
		a = scanf("%d", &e);
		if (a)
			break;
		else
		{
			printf("����������Ŷ\n\n");
			gets(&(char)a);
			i++;
		}
	}
	return e;
}