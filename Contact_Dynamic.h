
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <errno.h>

//#define MAX 1000
#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30


// ����һ��ͨѶ¼�ڵ���Ϣ
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//	����һ��������ö�٣�ʹswitch����ڷ���д
enum option
{
	Exit,
	Add,
	Del,
	Seacher,
	Modify,
	Show,
	Sort,
	Save
};

// ͨѶ¼���͵Ĵ�����ֻ��һ������ 
struct Contact
{
	struct PeoInfo *data;// ���һ����Ϣ
	int	capacity;//	��¼��ǰ����
	int sz;// ��¼��ǰ����Ԫ�ظ���
};

// ��������


// 1.��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);

// 2.���һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

// 3.��ӡͨѶ¼�����Ϣ
void ShowContact(const struct Contact* ps);

// 4.ɾ��ͨѶ¼��ĳ��ָ������Ϣ
void DelContact(struct Contact* ps);

// 5.����ͨѶ¼��ָ������ϵ����Ϣ
void SeacherContact(const struct Contact* ps);

// 6.�޸�ͨѶ¼��ָ����ϵ�˵���Ϣ
void ModifyContact(struct Contact* ps);

// 7.����ͨѶ¼��ָ����ϵ����Ϣ
void SortContact(struct Contact* ps);

// 9.�˳�����ǰ�ͷŶ�̬���ٵĿռ� 
void DestroyContact(struct Contact* ps);

// 7.�洢ͨѶ¼����ϵ����Ϣ���ļ�
void SaveContact(struct Contact* ps);

// 8.�����ļ���������ϵ����Ϣ��ͨѶ¼
void LoadContact(struct Contact* ps);