#define _CRT_SECURE_NO_WARNINGS
#include "LinkStack.h" 

int i;
int main()
{
	LinkStack* s;
	ElemType e,data,length;
	if (initLStack(&s))//������SUCCESS
	{
		printf("��ʼ���ɹ�~~\n");
	}
	while (1)
	{
		printf("                        -----------------�˵�ѡ��-----------------\n");
		printf("                          -- 0 ��ʼ��\n");
		printf("                          -- 1 ��Ա��ջ     -- 2 �õ�ջ��Ԫ��\n");
		printf("                          -- 3 ��Ա��ջ     -- 4 �ж�ջ�Ƿ�Ϊ��\n");
		printf("                          -- 5 ���ջ       -- 6 ���ջ����\n");
		printf("                          -- 7 ����ջ       -- 8 ��ӡջ\n");
		printf("                        ------------------------------------------\n");
		e = Scanf_strong1();
		system("cls");
		switch (e)
		{
		case 0:

		case 1:
			printf("������������ջ�����ݣ�\n");
			data = Scanf_strong2();
			if (pushLStack(&s, data))
				printf("��ջ�ɹ���\n");
			if(!(TraverseList(&s)))   //��ӡ����
				printf("ջ��Ϊ�գ��޷���ӡ��\n");
			break;
		case 2:
			if (!(getTopLStack(&s, &e)))
				printf("ջ��Ϊ�գ��޷���ȡջ��\n"); 
			break;
		case 3:
			if (!(popLStack(&s, &data)))
				printf("��Ϊ��ջ���޷�ɾ�����ݣ�\n");
			if (!(TraverseList(&s)))   //��ӡ����
				printf("ջ��Ϊ��,�޷���ӡ��\n");
			break;
		case 4:
			isEmptyLStack(&s);
			break;
		case 5:
			if (!(clearLStack(&s)))
				printf("��Ϊ��ջ��\n");
			else
				printf("��ճɹ���\n");
			break;
		case 6:
			if(!(LStackLength(&s, &length)))
			{ 
				printf("��Ϊ��ջ������Ϊ��0\n");
			}
			break;
		case 7:
			destroyLStack(&s);
			printf("���ٳɹ���\n");
			break;
		case 8:
			if (!(TraverseList(&s)))
				printf("ջ��Ϊ�գ�\n");
			break;
		default:
			printf("ֻ��8��ģʽŶ~~~~���������(Enter����)\n");
			getchar();
			getchar();
			system("cls");
		}
	}
}

