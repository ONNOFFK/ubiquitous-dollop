#define _CRT_SECURE_NO_WARNINGS
#include "LinkStack.h" 
//链栈

extern int i;
//初始化栈
Status initLStack(LinkStack *s)
{
	if (s->top == NULL)
	{
		printf("已经初始化过啦~~");
	}
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)   //分配内存成功判断
		return ERROR;
	s->top = NULL;//先让top指针指向NULL
	s->count = 0;
	i = 1;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
	if (s->top == NULL)
		printf("栈列为空！");
	else
		printf("栈列不为空！");
	return SUCCESS;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if (s->top == NULL)
		return ERROR;
	else
		printf("目前栈顶为：%d\n", s->top->data);
	return SUCCESS;
}

//清空栈
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

//销毁栈
Status destroyLStack(LinkStack *s)//此处用不了~~
{
	clearLStack(&s);
	free(s);
	i = 0;
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length)
{
	if (s->top == NULL)
		return ERROR;
	*length = s->count;
	printf("目前栈长度为：%d", length);
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	if (i == 0)
	{
		printf("请先初始化！\n");
	}
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S)   //分配内存成功判断
		return ERROR;
	S->data = data;
	S->next = s->top;
	s->top = S;
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data)
{
	LinkStackPtr p;  //用来释放删除的结点
	if (s->top == NULL)
		return ERROR;
	*data = s->top->data;
	printf("出栈成员：%d", *data);
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}

//打印栈
Status TraverseList(LinkStack *s)
{
	if (s->count == 0)
	{
		return ERROR;
	}
	printf("当前数据为：");
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
			printf("请输入你想要的模式：\n");
		else
			printf("请再次输入你想要的模式：\n");
		a = scanf("%d", &e);
		if (a)
			break;
		else
		{
			printf("请输入数字！！！！！！\n\n");
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
			printf("请再次输入：\n");
		a = scanf("%d", &e);
		if (a)
			break;
		else
		{
			printf("请输入数字哦\n\n");
			gets(&(char)a);
			i++;
		}
	}
	return e;
}