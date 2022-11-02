#pragma once

using namespace std;

#include <io.h>//������ȡ�ļ�
#include <time.h>//��ȡ�����ʵ��AI�������
#include <iostream>
#include <string>
#include <graphics.h> //EasyXͼ�ο�
#include <fstream> //�ļ�����
#include <vector> //�������ڴ���û��ļ����µ��ļ���
#include <algorithm>

#define GRAPHICS_X 880
#define GRAPHICS_Y 780

// ��Ϸ����
#define PLATE_X	 30				//
#define PLATE_Y  50				//	���̵ľ��ε�����ֵ
#define PLATE_XX 50*14+PLATE_X	
#define PLATE_YY 50*15			///
// ƫ����
#define	OFFSET   50	// ÿ�����̿ո����50����

extern vector<string> Allfiles;//���ڱ���ȫ���û���
extern string player1_name;//�û�1����
extern int player1_scores;//�û�1ʤ����
extern string player2_name;//�û�2����
extern int player2_scores;//�û�2ʤ����
extern int Map[15][15];//����
extern HWND hwnd2;//��¼���̻��棬���������ʾ
extern IMAGE imageWhite;//�����ͼƬ

class Mouse
{
public:
	int x;
	int y;

	int loadGame(void);//�����ҳ����
	bool beginGame(void);// ����¼�������ؿ���Ϸ���˳���Ϸ
	int ifbool(int player);// ����¼�: �������
} ;

void initgraphGame();//��ʼ����Ϸ
void gameInterface();//��Ϸ����
void plate();//������
void SelectMode();//ѡ����Ϸģʽ
void gameButton();//��Ϸ��ť
void newGame();//����Ϸ
void playgame();//����Ϸ
void hint();//��ʾ�ô��Ѿ�������
void ifVictory(int mode);//�ж��Ƿ����˻�ʤ
void Victory(int victory);//���ʤ����ʾ��Ϣ

void user_register();//�û�ע��
void user_login();//�û���¼
void getFiles(string path, vector<string>& files);//������ȡ�û������ļ�
void toplist();//�鿴���а�
int topupdate(fstream& link);//�����޸����а�����,�������а��������������

//�˻����ֵĴ���
void newGame_AI();//�˻�ģʽ�µ�����Ϸ
void playgame_AI();//�˻�ģʽ�µ�����Ϸ
void playchess_AI();//AI����