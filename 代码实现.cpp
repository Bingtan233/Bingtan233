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
		cout << "通讯录已满" << "\n";
		return;
	}
	else
	{
		cout << "请输入姓名" << "\n";
		cin >> books->array[books->size].name_;
		cout << "请输入姓别，1：男，0：女" << "\n";
		int sex = -1;
		while (true)
		{
			cin >> sex;
			if (cin.fail())
			{
				cin.clear();
				cin.clear(); // 清除错误状态
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入有误,请重新输入";
			}
			else if (sex == 1 || sex == 0)
			{
				books->array[books->size].sex_ = sex;
				break;
			}
			else
				cout << "输入有误,请重新输入";

		}
		cout << "请输入年龄" << "\n";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入有误，请重新输入" << "\n";
			}
			else
			{
				books->array[books->size].age_ = age;
				break;
			}
		}
		cout << "请输入地址" << "\n";
		cin >> books->array[books->size].address;
		cout << "请输入电话" << "\n";
		cin >> books->array[books->size].phone;
		//更新人数
		books->size++;
		cout << "更新成功了，好耶" << "\n";
		system("pause");//按任意键继续
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
		cout << "qwq什么都没有呢" << "\n";

	}
	else
	{
		for (int i = 0;i < books->size;i++)
		{
			cout << "姓名： " << books->array[i].name_ << "\t";
			cout << "性别： " << (books->array[i].sex_ ? "男" : "女") << "\t";
			cout << "年龄： " << books->array[i].age_ << "\t";
			cout << "地址： " << books->array[i].address << "\t";
			cout << "联系方式：" << books->array[i].phone << "\n";
		}
	}
	system("pause");
	system("cls");
}
void Delete(book* books)
{
	string name;
	cout << "请输入要删除的联系人姓名";
	cin >> name;
	int ret = find(books, name);
	if (ret == -1)
		cout << "查无此人" << "\n";
	else
	{
		for (int i = ret;i < books->size;i++)
			books->array[i] = books->array[i + 1];
		books->size--;
		cout << "删除成功" << "\n";
	}
	system("pause");
	system("cls");
}
void findperson(book* books)
{
	string name;
	cout << "请输入要查找的联系人姓名";
	cin >> name;
	int ret = find(books, name);
	if (ret == -1)
		cout << "查无此人" << "\n";
	else
	{
		cout << "姓名： " << books->array[ret].name_ << "\t";
		cout << "性别： " << (books->array[ret].sex_ ? "男" : "女") << "\t";
		cout << "年龄： " << books->array[ret].age_ << "\t";
		cout << "地址： " << books->array[ret].address << "\t";
		cout << "联系方式：" << books->array[ret].phone << "\n";
	}
	system("pause");
	system("cls");
}
void modify(book* books)
{
	string name;
	cout << "请输入要修改的联系人姓名";
	cin >> name;
	int ret = find(books, name);
	if (ret == -1)
		cout << "查无此人" << "\n";
	else
	{
		cout << "请输入修改后的姓名" << "\n";
		cin >> books->array[ret].name_;
		cout << "请输入修改后的姓别，1：男，0：女" << "\n";
		int sex = -1;
		while (true)
		{
			cin >> sex;
			if (cin.fail())
			{
				cin.clear();
				cin.clear(); // 清除错误状态
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入有误,请重新输入";
			}
			else if (sex == 1 || sex == 0)
			{
				books->array[ret].sex_ = sex;
				break;
			}
			else
				cout << "输入有误,请重新输入";

		}
		cout << "请输入修改后的年龄" << "\n";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入有误，请重新输入" << "\n";
			}
			else
			{
				books->array[ret].age_ = age;
				break;
			}
		}
		cout << "请输入新地址" << "\n";
		cin >> books->array[ret].address;
		cout << "请输入新电话" << "\n";
		cin >> books->array[ret].phone;
	}
	system("pause");
	system("cls");

}
void clean(book* books)
{
	books->size = 0;
	cout << "清空成功" << "\n";
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*************************" << "\n";
	cout << "***** 1、添加联系人 *****" << "\n";
	cout << "***** 2、显示联系人 *****" << "\n";
	cout << "***** 3、删除联系人 *****" << "\n";
	cout << "***** 4、查找联系人 *****" << "\n";
	cout << "***** 5、修改联系人 *****" << "\n";
	cout << "***** 6、清空联系人 *****" << "\n";
	cout << "***** 0、退出通讯录 *****" << "\n";
	cout << "*************************" << "\n";

}

int main()
{
	book books;
	books.size = 0;
	int select = 0;//初始化用户输入变量
	while (true)
	{
		showMenu();//菜单调用
		while (!(cin >> select))
		{
			cin.clear();
			cin.clear(); // 清除错误状态
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入有误,请重新输入" << "\n";
		}
		switch (select)
		{
		case 1://添加联系人
			addperson(&books);
			break;
		case 2://显示联系人
			showindex(&books);
			break;
		case 3://删除联系人
			Delete(&books);
			break;
		case 4://查找联系人
			findperson(&books);
			break;
		case 5://修改联系人
			modify(&books);
			break;
		case 6://清空联系人
			clean(&books);
			break;
		case 0://退出通讯录
		{
			cout << "欢迎下次使用" << "\n";
			system("pause");
			return 0;
		}
		default:
			cout << "输入有误，请重新输入" << "\n";

		}
	}

}
