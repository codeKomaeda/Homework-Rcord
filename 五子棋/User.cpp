#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

string player1_name;
int player1_scores;
string player2_name;
int player2_scores;

//用户注册
void user_register()
{
	ofstream tmp_user;
	string name, code;
	string filePath = ".\\users";
	vector<string> files;
	
	
	//读取所有的文件，包括子文件的文件
	getFiles(filePath, files);

	while (1)
	{
		while (1)
		{
			size_t i;
			cout << "请输入用户名: ";
			cin >> name;
			for (i = 0; i < files.size(); i++) {
				if (files[i] == name + ".txt") {
					cout << "该用户名已被使用，请重新输入！" << endl;
					break;
				}
			}
			if (i == files.size()) break;
		}
		tmp_user.open(".\\users\\" + name + ".txt", ios::out);
		if (!tmp_user)//创建失败
		{
			cout << "创建失败，请重试" << endl;
		}
		else//创建成功
		{
			tmp_user << '0' << endl;//新用户胜场数为0
			cout << "请输入密码: ";
			cin >> code;
			tmp_user << code;
			cout << "注册成功,";
			system("pause");
			system("cls");
			tmp_user.close(); 
			break;//创建成功后退出去
		}	
	}
	tmp_user.close();
}
//用户登录
void user_login()
{
	ifstream tmp_user;
	string name, code;
	string filePath = ".\\users";
	vector<string> files;

	//读取所有的文件，包括子文件的文件
	getFiles(filePath, files);
	vector<string> Allfiles = files;
	while (1)
	{
		while (1)
		{
			size_t i;
			cout << "请输入用户名: ";
			cin >> name;
			for (i = 0; i < files.size(); i++) {
				if (files[i] == name + ".txt" && player1_name == "") //用户1还未登录时，找到账户
				{
					player1_name = name;
					break;
				}
				else if (files[i] == name + ".txt" && player1_name != "") //用户2登录
				{
					player2_name = name;
					break;
				}
			}
			if (i == files.size()) {
				cout << "该用户不存在，请重新输入" << endl;
			}
			else {
				break;
			}
		}
		tmp_user.open(".\\users\\" + name + ".txt", ios::out || ios::in);
		if (!tmp_user)//打开账户失败
		{
			cout << "登录失败，请重试" << endl;
		}
		else//成功
		{
			string code_tmp;//存放读取的密码
			int victory_tmp;
			tmp_user >> victory_tmp;//读取跳过一行
			tmp_user >> code_tmp;
			while (1) {	
				cout << "请输入密码: ";
				cin >> code;	
				if (code == code_tmp) {
					cout << "登录成功,";
					if (player2_name != "") player2_scores = victory_tmp;//登录的是用户2
					else player1_scores = victory_tmp;//用户2未登录，则为用户1
					system("pause");
					system("cls");
					break;
				}
				cout << "密码错误" << endl;
			}
			break;
		}
	}
	tmp_user.close();
}

//读取文件夹下全部用户名
void getFiles(string path, vector<string>& files)
{
	//文件句柄
	intptr_t hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}