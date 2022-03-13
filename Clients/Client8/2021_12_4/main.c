#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct Contact
{
	long long id;
	char name[20];
	int sex;
	char address[100];
	char national[10];
	char birth[20];
	char begin_date[20];
	char end_date[20];
	long long area;
};

typedef struct Contact Contact;

Contact contacts[100];
int num;

int searchContact(long long id)
{
	int index = 0;
	for (; index < num; ++index)
		if (contacts[index].id == id) return index;
	return -1;
}
void AscendingSort();
void DescendingSort();
void main_meau();
void Admin_meau();
void User_meau();
void Admin_add();
void Admin_cha(long long id);
void Admin_sort();
void Admin_query(long long id);
void Admin_delet(long long id);
void Admin_display();
void file_meau();
void Admin_input_file();
void Admin_delete_file(long long id);
void Admin_query_file(long long id);
void Admin_sort_file();
void Admin_add_file();

void User_query(long long id);

int main()
{
	while(1)
	{
		main_meau();
	}
	return 0;
}

void main_meau()
{
	while (1)
	{
		printf("1.Enter Admin meau\n");
		printf("2.Enter User meau\n");
		printf("3.exit\n");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Admin_meau();
			break;
		case 2:
			User_meau();
			break;
		case 3:
			exit(0);
		default:
			break;
		}
	}
}

void AscendingSort()
{
	Contact b;
	for (int i = 0; i < num; i++)
	{
		int k = i;
		for (int j = i + 1; j < num; j++)
		{
			if (contacts[j].area < contacts[k].area)
			{
				k = j;
			}
		}
		if (k != i)
		{
			b = contacts[i];
			contacts[i] = contacts[k];
			contacts[k] = b;
		}
	}

}
void DescendingSort()
{
	Contact b;
	for (int i = 0; i < num; i++)
	{
		int k = i;
		for (int j = i + 1; j < num; j++)
		{
			if (contacts[j].area > contacts[k].area)
			{
				k = j;
			}
		}
		if (k != i)
		{
			b = contacts[i];
			contacts[i] = contacts[k];
			contacts[k] = b;
		}
	}
}

void Admin_meau()
{
	printf("\n\n\n");
	long long id;
	while (1)
	{
		printf("1.Add contact\n");
		printf("2.change data\n");
		printf("3.sort\n");
		printf("4.query data\n");
		printf("5.delete data\n");
		printf("6.display\n");
		printf("7.goto main meau\n");
		printf("8.exit\n");
		printf("0.goto file meau\n");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Admin_add();
			break;
		case 2:
			printf("input id:\n");
			scanf("%lld", &id);
			Admin_cha(id);
			break;
		case 3:
			Admin_sort();
			break;
		case 4:
			printf("input id:\n");
			scanf("%lld", &id);
			Admin_query(id);
			break;
		case 5:
			printf("input id:\n");
			scanf("%lld", &id);
			Admin_delet(id);
			break;
		case 6:
			Admin_display();
			break;
		case 7:
			return;
		case 8:
			exit(0);
		case 0:
			file_meau();
		default:
			break;
		}

	}
}

void User_meau()
{
	printf("\n\n\n");
	while (1)
	{
		long long id;
		printf("1.query data\n");
		printf("2.goto main meau\n");
		printf("3.exit\n");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("input id:\n");
			scanf("%lld", &id);
			User_query(id);
			break;
		case 2:
			return;
		case 3:
			exit(0);
		default:
			break;
		}
	}
}

void Admin_add()
{
	printf("\n\n\n");
	printf("input id\n");
	scanf("%lld", &contacts[num].id);
	printf("input name\n");
	scanf("%s", contacts[num].name);
	printf("input sex\n");
	scanf("%d", &contacts[num].sex); 
	printf("input address\n");
	scanf("%s", contacts[num].address);
	printf("input national\n");
	scanf("%s", contacts[num].national);
	printf("input birthdate\n");
	scanf("%s", contacts[num].birth);
	printf("input begin_date\n");
	scanf("%s", contacts[num].begin_date);
	printf("input end_date\n");
	scanf("%s", contacts[num].end_date);
	contacts[num].area = contacts[num].id / 1e12;
	num++;
}

void Admin_cha(long long id)
{
	printf("\n\n\n");
	int index = searchContact(id);
	if (index == -1)
	{
		printf("error,id not exist");
		return;
	}
	printf("1.change id\n2.change name\n3.change sex\n4.change address\n5.change national\n6.change birthdate\n");
	printf("7.change begin_date\n8.change end_date\n9.goto main meau\n");
	int select;
	scanf("%d", &select);
	switch (select)
	{
	case 1:
		printf("input new id\n");
		scanf("%lld", &id);
		contacts[index].id = id;
		contacts[index].area = id / 1e12;
		break;
	case 2:
		printf("input new name\n");
		scanf("%s", contacts[index].name);
		break;
	case 3:
		printf("input new sex\n");
		scanf("%d", &contacts[index].sex);
		break;
	case 4:
		printf("input new address\n");
		scanf("%s", contacts[index].address);
		break;
	case 5:
		printf("input new national\n");
		scanf("%s", contacts[index].national);
		break;
	case 6:
		printf("input new birthdate\n");
		scanf("%s", contacts[index].birth);
		break;
	case 7:
		printf("input new begin date\n");
		scanf("%s", contacts[index].begin_date);
		break;
	case 8:
		printf("input new end date\n");
		scanf("%s", contacts[index].end_date);
		break;
	case 9:
		return;
	default:
		break;
	}
	
}

void Admin_sort()
{
	printf("1.Ascending\n");
	printf("2.Descending\n");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		AscendingSort();
		break;
	case 2:
		DescendingSort();
		break;
	default:
		break;
	}
	Admin_display();
}

void Admin_query(long long id)
{
	printf("\n\n\n");
	int index=searchContact(id);
	if (index == -1)
	{
		printf("error,id not exist");
		return;
	}
	printf("id:%lld\n", contacts[index].id);
	printf("name:%s\n", contacts[index].name);
	printf("sex:%d\n", contacts[index].sex);
	printf("address:%s\n", contacts[index].address);
	printf("national:%s\n", contacts[index].national);
	printf("birthdate:%s\n", contacts[index].birth);
	printf("begin date:%s\n", contacts[index].begin_date);
	printf("end_date:%s\n", contacts[index].end_date);
	printf("area num:%lld\n", contacts[index].area);
	printf("\n\n\n");
}

void Admin_delet(long long id)
{
	int index = searchContact(id);
	if (index == -1)
	{
		printf("error,id not exist\n");
		return;
	}
	num--;
	if (index == -1) { printf(""); }
	Contact temp = contacts[num];
	contacts[num] = contacts[index];
	contacts[index] = temp;
}

void Admin_display()
{
	for (int i = 0; i < num; i++)
		Admin_query(contacts[i].id);
}


void User_query(long long id)
{
	Admin_query(id);
}

void file_meau()
{
	printf("\n\n\n");
	while (1)
	{
		long long id;
		printf("1.Input data\n");
		printf("2.Add new employee\n");
		printf("3.Delete data\n");
		printf("4.Query data\n");
		printf("5.Sort data\n");
		printf("0.exit\n");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Admin_input_file();
			break;
		case 2:
			Admin_add_file();
		case 3:
			printf("input id:\n");
			scanf("%lld", &id);
			Admin_delete_file(id);
			break;
		case 4:
			printf("input id:\n");
			scanf("%lld", &id);
			Admin_query_file(id);
			break;
		case 5:
			Admin_sort_file();
		case 0:
			exit(0);
		default:
			break;
		}
	}
}

void Admin_add_file()
{
	FILE* fp = fopen("Staff.data", "a+");
	printf("\n\n\n");
	printf("input id\n");
	scanf("%lld", &contacts[num].id);
	printf("input name\n");
	scanf("%s", contacts[num].name);
	printf("input sex\n");
	scanf("%d", &contacts[num].sex);
	printf("input address\n");
	scanf("%s", contacts[num].address);
	printf("input national\n");
	scanf("%s", contacts[num].national);
	printf("input birthdate\n");
	scanf("%s", contacts[num].birth);
	printf("input begin_date\n");
	scanf("%s", contacts[num].begin_date);
	printf("input end_date\n");
	scanf("%s", contacts[num].end_date);
	contacts[num].area = contacts[num].id / 1e12;
	num++;
	fprintf(fp, "%lld\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%lld\n\n", contacts[num].id, contacts[num].name, contacts[num].sex, contacts[num].address, contacts[num].national, contacts[num].birth, contacts[num].begin_date, contacts[num].end_date, contacts[num].area);
	fclose(fp);
}

void Admin_input_file()
{
	FILE* fp = fopen("Staff.data", "w");
	for(int i=0;i<num;++i)
		fprintf(fp, "%lld\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%lld\n\n", contacts[i].id, contacts[i].name, contacts[i].sex, contacts[i].address, contacts[i].national, contacts[i].birth, contacts[i].begin_date, contacts[i].end_date, contacts[i].area);
	fclose(fp);
}

void Admin_delete_file(long long id)
{
	Admin_delet(id);
	Admin_input_file();
}

void Admin_query_file(long long id)
{
	int i = searchContact(id);
	FILE* fp = fopen("QueryResult.txt", "w");
	fprintf(fp, "%lld\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%lld\n\n", contacts[i].id, contacts[i].name, contacts[i].sex, contacts[i].address, contacts[i].national, contacts[i].birth, contacts[i].begin_date, contacts[i].end_date, contacts[i].area);
	fclose(fp);
}
void Admin_sort_file()
{
	Contact b;
	for (int i = 0; i < num; i++)
	{
		int k = i;
		for (int j = i + 1; j < num; j++)
		{
			if (contacts[j].birth[0] < contacts[k].birth[0])
			{
				k = j;
			}
		}
		if (k != i)
		{
			b = contacts[i];
			contacts[i] = contacts[k];
			contacts[k] = b;
		}
	}
	FILE* fp = fopen("Staff_sorted.txt", "w");
	for (int i = 0; i < num; ++i)
		fprintf(fp, "%lld\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%lld\n\n", contacts[i].id, contacts[i].name, contacts[i].sex, contacts[i].address, contacts[i].national, contacts[i].birth, contacts[i].begin_date, contacts[i].end_date, contacts[i].area);
	fclose(fp);


}