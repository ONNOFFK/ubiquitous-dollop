#define _CRT_SECURE_NO_WARNINGS
#include "LinkStack.h" 

int i;
int main()
{
	LinkStack* s;
	ElemType e,data,length;
	if (initLStack(&s))//若返回SUCCESS
	{
		printf("初始化成功~~\n");
	}
	while (1)
	{
		printf("                        -----------------菜单选项-----------------\n");
		printf("                          -- 0 初始化\n");
		printf("                          -- 1 成员入栈     -- 2 得到栈顶元素\n");
		printf("                          -- 3 成员出栈     -- 4 判断栈是否为空\n");
		printf("                          -- 5 清空栈       -- 6 检测栈长度\n");
		printf("                          -- 7 销毁栈       -- 8 打印栈\n");
		printf("                        ------------------------------------------\n");
		e = Scanf_strong1();
		system("cls");
		switch (e)
		{
		case 0:

		case 1:
			printf("请输入你想入栈的数据：\n");
			data = Scanf_strong2();
			if (pushLStack(&s, data))
				printf("入栈成功！\n");
			if(!(TraverseList(&s)))   //打印看看
				printf("栈链为空，无法打印！\n");
			break;
		case 2:
			if (!(getTopLStack(&s, &e)))
				printf("栈列为空！无法获取栈顶\n"); 
			break;
		case 3:
			if (!(popLStack(&s, &data)))
				printf("此为空栈，无法删除数据！\n");
			if (!(TraverseList(&s)))   //打印看看
				printf("栈链为空,无法打印！\n");
			break;
		case 4:
			isEmptyLStack(&s);
			break;
		case 5:
			if (!(clearLStack(&s)))
				printf("此为空栈！\n");
			else
				printf("清空成功！\n");
			break;
		case 6:
			if(!(LStackLength(&s, &length)))
			{ 
				printf("现为空栈，长度为：0\n");
			}
			break;
		case 7:
			destroyLStack(&s);
			printf("销毁成功！\n");
			break;
		case 8:
			if (!(TraverseList(&s)))
				printf("栈链为空！\n");
			break;
		default:
			printf("只有8个模式哦~~~~重新输入叭(Enter进入)\n");
			getchar();
			getchar();
			system("cls");
		}
	}
}

