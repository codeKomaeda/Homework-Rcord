#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

typedef struct userdate
{
	string name;//�û���
	int score = 0;//ʤ����
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
		cout << "�Ҳ������а��ļ�" << endl;
		exit(0);
	}
	count = topupdate(link);//�����������а�
	cout << "��ӭ�� " << player1_name << endl;
	cout << "��Ŀǰ��ʤ����Ϊ" << player1_scores << endl;
	cout << "����Ϊ���а���Ϣ: " << endl;
	cout << " ����\t" << "�û�\t\t" << "ʤ����" << endl;
	getline(link, str);
	while (i < count && str != "")//����ǰ10�����ݲ����
	{
		if (str != "") {
			cout << " " << i + 1;
		}
		cout << str << endl;
		str.clear();
		getline(link, str);	
		++i;
	}
	cout << "�鿴��Ϻ�,";
	system("pause");
	link.close();
	system("cls");
}

int topupdate(fstream& link)//�˴�Ϊc++���е����ã�����ȡ��ַ
{
	string str;
	int i = 1, judge = 0;//judge�����жϰ����Ƿ��е�ǰ��¼�û�
	int min_score = player1_scores;
	Userdate t1;
	Userdate player1{player1_name, player1_scores};
	vector<Userdate> date;

	while (i < 10)//���ļ���������ӽ�date��
	{
		str = t1.name;//str��Ϊ��ʱ����
		link >> t1.name;
		link >> t1.score;
		i++;
		if (str == t1.name)//�������˵��û�����ݿɶ�
		{
			if (player1_scores < t1.score && i == 10)//��player1�ķ�������Ŀǰ��Сֵ�����������
			{
				cout << "t1����Ϊ " << t1.score;
				judge = 1;
			}
			break;
		}
		if (t1.name == player1_name)//�������и��û���ֱ�Ӹ������ݼ���
		{
			t1.score = player1_scores;
			judge = 1;
		}
		if (player1_scores < t1.score && i == 10)//��player1�ķ�������Ŀǰ��Сֵ�����������
		{
			cout << "t1����Ϊ " << t1.score;
			judge = 1;
		}
		date.push_back(t1);
	}
	if (!judge)//�ж��Ƿ�����û����ݵ�����
	{
		printf("\nasada\n");
		date.push_back(player1);
	}
	sort(date.begin(),date.end(),compare);//����
	link.clear();
	link.seekg(0, ios::beg);//�ļ�ָ�뷵�ؿ�ͷ
	for (auto mm = date.begin(); mm != date.end(); ++mm)//д���ļ���
	{
		link << "\t" << (*mm).name << "\t\t" << (*mm).score << "\n";
	}
	link.clear();
	link.seekg(0, ios::beg);//�ļ�ָ�뷵�ؿ�ͷ
	return i;//�������а�������������������10���ˣ��򷵻�11
}