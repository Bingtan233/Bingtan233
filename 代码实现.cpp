#include<iostream>
#include <ctype.h>
#include<string>
#define MAX 1000
using namespace std;
struct Person
{
	string name_;
	int sex_;
	int age_;
	string phone;
	string address;
	Person() : name_(""), sex_(0), age_(0), phone(""), address("") {}
};

struct book
{
	Person array[MAX];
	int size = 0;

};
void addperson(book* books)
{
	if (books->size == MAX)
	{
		cout << "ͨѶ¼����" << "\n";
		return;
	}
	else
	{
		cout << "����������" << "\n";
		cin >> books->array[books->size].name_;
		cout << "�������ձ�1���У�0��Ů" << "\n";
		int sex = -1;
		while (true)
		{
			cin >> sex;
			if (cin.fail())
			{
				cin.clear();
				cin.clear(); // �������״̬
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "��������,����������";
			}
			else if (sex == 1 || sex == 0)
			{
				books->array[books->size].sex_ = sex;
				break;
			}
			else
				cout << "��������,����������";

		}
		cout << "����������" << "\n";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "������������������" << "\n";
			}
			else
			{
				books->array[books->size].age_ = age;
				break;
			}
		}
		cout << "�������ַ" << "\n";
		cin >> books->array[books->size].address;
		cout << "������绰" << "\n";
		cin >> books->array[books->size].phone;
		//��������
		books->size++;
		cout << "���³ɹ��ˣ���Ү" << "\n";
		system("pause");//�����������
		system("cls");
	}

}
int find(book* books, string name)
{
	for (int i = 0;i < books->size;i++)
	{
		if (books->array[i].name_ == name)
			return i;
	}
	return -1;

}
void showindex(book* books)
{
	if (books->size == 0)
	{
		cout << "qwqʲô��û����" << "\n";

	}
	else
	{
		for (int i = 0;i < books->size;i++)
		{
			cout << "������ " << books->array[i].name_ << "\t";
			cout << "�Ա� " << (books->array[i].sex_ ? "��" : "Ů") << "\t";
			cout << "���䣺 " << books->array[i].age_ << "\t";
			cout << "��ַ�� " << books->array[i].address << "\t";
			cout << "��ϵ��ʽ��" << books->array[i].phone << "\n";
		}
	}
	system("pause");
	system("cls");
}
void Delete(book* books)
{
	string name;
	cout << "������Ҫɾ������ϵ������";
	cin >> name;
	int ret = find(books, name);
	if (ret == -1)
		cout << "���޴���" << "\n";
	else
	{
		for (int i = ret;i < books->size;i++)
			books->array[i] = books->array[i + 1];
		books->size--;
		cout << "ɾ���ɹ�" << "\n";
	}
	system("pause");
	system("cls");
}
void findperson(book* books)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ������";
	cin >> name;
	int ret = find(books, name);
	if (ret == -1)
		cout << "���޴���" << "\n";
	else
	{
		cout << "������ " << books->array[ret].name_ << "\t";
		cout << "�Ա� " << (books->array[ret].sex_ ? "��" : "Ů") << "\t";
		cout << "���䣺 " << books->array[ret].age_ << "\t";
		cout << "��ַ�� " << books->array[ret].address << "\t";
		cout << "��ϵ��ʽ��" << books->array[ret].phone << "\n";
	}
	system("pause");
	system("cls");
}
void modify(book* books)
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ������";
	cin >> name;
	int ret = find(books, name);
	if (ret == -1)
		cout << "���޴���" << "\n";
	else
	{
		cout << "�������޸ĺ������" << "\n";
		cin >> books->array[ret].name_;
		cout << "�������޸ĺ���ձ�1���У�0��Ů" << "\n";
		int sex = -1;
		while (true)
		{
			cin >> sex;
			if (cin.fail())
			{
				cin.clear();
				cin.clear(); // �������״̬
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "��������,����������";
			}
			else if (sex == 1 || sex == 0)
			{
				books->array[ret].sex_ = sex;
				break;
			}
			else
				cout << "��������,����������";

		}
		cout << "�������޸ĺ������" << "\n";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "������������������" << "\n";
			}
			else
			{
				books->array[ret].age_ = age;
				break;
			}
		}
		cout << "�������µ�ַ" << "\n";
		cin >> books->array[ret].address;
		cout << "�������µ绰" << "\n";
		cin >> books->array[ret].phone;
	}
	system("pause");
	system("cls");

}
void clean(book* books)
{
	books->size = 0;
	cout << "��ճɹ�" << "\n";
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*************************" << "\n";
	cout << "***** 1�������ϵ�� *****" << "\n";
	cout << "***** 2����ʾ��ϵ�� *****" << "\n";
	cout << "***** 3��ɾ����ϵ�� *****" << "\n";
	cout << "***** 4��������ϵ�� *****" << "\n";
	cout << "***** 5���޸���ϵ�� *****" << "\n";
	cout << "***** 6�������ϵ�� *****" << "\n";
	cout << "***** 0���˳�ͨѶ¼ *****" << "\n";
	cout << "*************************" << "\n";

}

int main()
{
	book books;
	books.size = 0;
	int select = 0;//��ʼ���û��������
	while (true)
	{
		showMenu();//�˵�����
		while (!(cin >> select))
		{
			cin.clear();
			cin.clear(); // �������״̬
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��������,����������" << "\n";
		}
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&books);
			break;
		case 2://��ʾ��ϵ��
			showindex(&books);
			break;
		case 3://ɾ����ϵ��
			Delete(&books);
			break;
		case 4://������ϵ��
			findperson(&books);
			break;
		case 5://�޸���ϵ��
			modify(&books);
			break;
		case 6://�����ϵ��
			clean(&books);
			break;
		case 0://�˳�ͨѶ¼
		{
			cout << "��ӭ�´�ʹ��" << "\n";
			system("pause");
			return 0;
		}
		default:
			cout << "������������������" << "\n";

		}
	}

}
