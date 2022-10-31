
#include "Contact_Dynamic.h"

void menu()
{
	printf("***********************************\n");
	printf("****** 1.Add        2.Del  ********\n");
	printf("****** 3.Seacher    4.Modify ******\n");
	printf("****** 5.Show	    6.Sort  *******\n");
	printf("****** 7.Save	    0.Exit  *******\n");
	printf("***********************************\n");
}
int main()
{
	int input = 0;	// ѡ��ģʽ
	struct Contact con;// ����ͨѶ¼con,��������Ԫ�� ��Ϣ+����+��������
	InitContact(&con);// ��ʼ��ͨѶ¼Ϊ0��&��ַ���ܸı�����ֵ
	do
	{
		menu();
		printf("��ѡ��:->");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			AddContact(&con);
			break;
		case Del:
			DelContact(&con);
			break;
		case Seacher:
			SeacherContact(&con);
			break;
		case Modify:
			ModifyContact(&con);
			break;
		case Show:
			ShowContact(&con);
			break;
		case Sort:
			SortContact(&con);
			break;
		case Exit:
			// �˳�����ǰӦ�ͷŶ�̬���ٵĿռ�	
			SaveContact(&con);
			DestroyContact(&con);

			printf("�˳�����!\n");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			Sleep(1000);
			break;
		}
	} while (input);
	return 0;
}