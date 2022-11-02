#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

string player1_name;
int player1_scores;
string player2_name;
int player2_scores;

//�û�ע��
void user_register()
{
	ofstream tmp_user;
	string name, code;
	string filePath = ".\\users";
	vector<string> files;
	
	
	//��ȡ���е��ļ����������ļ����ļ�
	getFiles(filePath, files);

	while (1)
	{
		while (1)
		{
			size_t i;
			cout << "�������û���: ";
			cin >> name;
			for (i = 0; i < files.size(); i++) {
				if (files[i] == name + ".txt") {
					cout << "���û����ѱ�ʹ�ã����������룡" << endl;
					break;
				}
			}
			if (i == files.size()) break;
		}
		tmp_user.open(".\\users\\" + name + ".txt", ios::out);
		if (!tmp_user)//����ʧ��
		{
			cout << "����ʧ�ܣ�������" << endl;
		}
		else//�����ɹ�
		{
			tmp_user << '0' << endl;//���û�ʤ����Ϊ0
			cout << "����������: ";
			cin >> code;
			tmp_user << code;
			cout << "ע��ɹ�,";
			system("pause");
			system("cls");
			tmp_user.close(); 
			break;//�����ɹ����˳�ȥ
		}	
	}
	tmp_user.close();
}
//�û���¼
void user_login()
{
	ifstream tmp_user;
	string name, code;
	string filePath = ".\\users";
	vector<string> files;

	//��ȡ���е��ļ����������ļ����ļ�
	getFiles(filePath, files);
	vector<string> Allfiles = files;
	while (1)
	{
		while (1)
		{
			size_t i;
			cout << "�������û���: ";
			cin >> name;
			for (i = 0; i < files.size(); i++) {
				if (files[i] == name + ".txt" && player1_name == "") //�û�1��δ��¼ʱ���ҵ��˻�
				{
					player1_name = name;
					break;
				}
				else if (files[i] == name + ".txt" && player1_name != "") //�û�2��¼
				{
					player2_name = name;
					break;
				}
			}
			if (i == files.size()) {
				cout << "���û������ڣ�����������" << endl;
			}
			else {
				break;
			}
		}
		tmp_user.open(".\\users\\" + name + ".txt", ios::out || ios::in);
		if (!tmp_user)//���˻�ʧ��
		{
			cout << "��¼ʧ�ܣ�������" << endl;
		}
		else//�ɹ�
		{
			string code_tmp;//��Ŷ�ȡ������
			int victory_tmp;
			tmp_user >> victory_tmp;//��ȡ����һ��
			tmp_user >> code_tmp;
			while (1) {	
				cout << "����������: ";
				cin >> code;	
				if (code == code_tmp) {
					cout << "��¼�ɹ�,";
					if (player2_name != "") player2_scores = victory_tmp;//��¼�����û�2
					else player1_scores = victory_tmp;//�û�2δ��¼����Ϊ�û�1
					system("pause");
					system("cls");
					break;
				}
				cout << "�������" << endl;
			}
			break;
		}
	}
	tmp_user.close();
}

//��ȡ�ļ�����ȫ���û���
void getFiles(string path, vector<string>& files)
{
	//�ļ����
	intptr_t hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮
			//�������,�����б�
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