
#include "Contact_Dynamic.h"

//					����ʵ��

//			���Һ�����ʵ��
static int FindBy_name(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//			1.��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->capacity = DEFAULT_SZ;
	ps->sz = 0;
	// ���ļ������е���Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
};

//	������ü�麯��������������
void CheckCaptcity(struct Contact* ps);

void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("Contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact:%s ", strerror(errno));
		return;
	}

	//	��ȡ�ļ�����ŵ�ͨѶ¼��
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
		//	��ȡ�ļ��е����ݵ�tmp�У�һ��һ����
		//	fread����������ʵ��������������һ��һ�������С��1����ֹͣѭ��
	{
		CheckCaptcity(ps);
		ps->data[ps->sz] = tmp;
		ps->sz++;
	}

	fclose(pfRead);
	pfRead = NULL;
}


//			2.1.���ͨѶ¼����
void CheckCaptcity(struct Contact* ps)
{
	if (ps->sz == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�!\n");
			printf("��ǰ������%d ", ps->capacity);
		}	
		else
		{
			printf("����ʧ��!\n");
		}
	}
}
//			2.���һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps)
{
	CheckCaptcity(ps);
	//	��⵱ǰͨѶ¼����|
	// 1. ����->���ӿռ�	2. û����ɶҲ����
	// û�������濪ʼ��������
	printf("����������:>");
	scanf("%s", ps->data[ps->sz].name);
	printf("����������:>");
	scanf("%d", &(ps->data[ps->sz].age));
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->sz].sex);
	printf("���������:>");
	scanf("%s", ps->data[ps->sz].tele);
	printf("�������ַ:>");
	scanf("%s", ps->data[ps->sz].addr);

	ps->sz++;
	printf("��ӳɹ�!��ǰ��%d����Ϣ��\n", ps->sz);
	Sleep(1200);

} 

//			3.��ӡͨѶ¼�����Ϣ
void ShowContact(const struct Contact* ps)
{
	if (ps->sz == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "����", "��ַ");
		//  ��ӡ����
		int i = 0;
		for (i = 0; i < ps->sz; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-13s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
	Sleep(1200);
}

//			4.ɾ��ͨѶ¼��ĳ��ָ������Ϣ
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���û�������:");
	scanf("%s", name);
	//  ���������û���λ��
	int ret = FindBy_name(ps, name);
	//  ɾ����Ϣ
	if (ret == -1)
	{	// �Ѿ����˻�û�ҵ�
		printf("���޴���!\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->sz - 1; j++)
		{// j=i,���ҵ���λ�ÿ�ʼ��5��4λ�ã�6��5λ�ã����ֱ�����
			ps->data[j] = ps->data[j + 1];
		}
		ps->sz--;// ���һ��λ��--�����һ��λ��ɾ�����ܷ���
		printf("ɾ���ɹ�!\n");
	}
	Sleep(1200);
}

//			5.����ָ����ϵ�˵���Ϣ
void SeacherContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����û�������:");
	scanf("%s", name);
	//  ���������û���λ��
	int ret = FindBy_name(ps, name);
	if (ret == -1)
	{
		printf("���޴���!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "����", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-13s\t%-20s\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
	}
	Sleep(2000);
}

//			6.�޸�ָ����ϵ�˵���Ϣ
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��û�������:");
	scanf("%s", name);
	//  ���������û���λ��
	int ret = FindBy_name(ps, name);
	if (ret == -1)
	{
		printf("���޴���!\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ret].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ret].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ret].sex);
		printf("���������:>");
		scanf("%s", ps->data[ret].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ret].addr);
		printf("�޸ĳɹ�!\n");
	}
	Sleep(500);
}

//			 . ��ͨѶ¼����
void SortContact(struct Contact* ps)
{
	;
}

//			8.�ͷŶ�̬���ٵĿռ�
void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

//			7. ��ͨѶ¼���ݱ��浽�ļ�
void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("Contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact:%s ", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}