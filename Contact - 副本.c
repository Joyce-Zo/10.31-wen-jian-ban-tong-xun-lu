
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
	int input = 0;	// 选择模式
	struct Contact con;// 创建通讯录con,包含三个元素 信息+容量+已有数量
	InitContact(&con);// 初始化通讯录为0，&地址才能改变里面值
	do
	{
		menu();
		printf("请选择:->");
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
			// 退出程序前应释放动态开辟的空间	
			SaveContact(&con);
			DestroyContact(&con);

			printf("退出程序!\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			Sleep(1000);
			break;
		}
	} while (input);
	return 0;
}