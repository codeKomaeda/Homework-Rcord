#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

typedef struct userdate
{
	string name;//用户名
	int score = 0;//胜场数
}Userdate;

bool compare(const Userdate& tmp1, const Userdate& tmp2)
{
	return tmp1.score > tmp2.score;
}

void toplist()
{
	fstream link;
	int i = 0, count;
	string str;
	link.open(".\\users\\top.txt", ios::in | ios::out);
	if (!link)
	{
		cout << "找不到排行榜文件" << endl;
		exit(0);
	}
	count = topupdate(link);//重新排序排行榜
	cout << "欢迎您 " << player1_name << endl;
	cout << "您目前的胜场数为" << player1_scores << endl;
	cout << "以下为排行榜信息: " << endl;
	cout << " 排名\t" << "用户\t\t" << "胜场数" << endl;
	getline(link, str);
	while (i < count && str != "")//读出前10的数据并输出
	{
		if (str != "") {
			cout << " " << i + 1;
		}
		cout << str << endl;
		str.clear();
		getline(link, str);	
		++i;
	}
	cout << "查看完毕后,";
	system("pause");
	link.close();
	system("cls");
}

int topupdate(fstream& link)//此处为c++特有的引用，而非取地址
{
	string str;
	int i = 1, judge = 0;//judge用于判断榜单上是否有当前登录用户
	int min_score = player1_scores;
	Userdate t1;
	Userdate player1{player1_name, player1_scores};
	vector<Userdate> date;

	while (i < 10)//将文件中数据添加进date内
	{
		str = t1.name;//str作为临时变量
		link >> t1.name;
		link >> t1.score;
		i++;
		if (str == t1.name)//若相等则说明没有数据可读
		{
			if (player1_scores < t1.score && i == 10)//若player1的分数低于目前最小值，则无需添加
			{
				cout << "t1分数为 " << t1.score;
				judge = 1;
			}
			break;
		}
		if (t1.name == player1_name)//榜单上已有该用户，直接更新数据即可
		{
			t1.score = player1_scores;
			judge = 1;
		}
		if (player1_scores < t1.score && i == 10)//若player1的分数低于目前最小值，则无需添加
		{
			cout << "t1分数为 " << t1.score;
			judge = 1;
		}
		date.push_back(t1);
	}
	if (!judge)//判断是否添加用户数据到榜单上
	{
		printf("\nasada\n");
		date.push_back(player1);
	}
	sort(date.begin(),date.end(),compare);//排序
	link.clear();
	link.seekg(0, ios::beg);//文件指针返回开头
	for (auto mm = date.begin(); mm != date.end(); ++mm)//写入文件中
	{
		link << "\t" << (*mm).name << "\t\t" << (*mm).score << "\n";
	}
	link.clear();
	link.seekg(0, ios::beg);//文件指针返回开头
	return i;//返回排行榜上已有人数，若多于10人了，则返回11
}