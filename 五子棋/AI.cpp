#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

void playgame_AI()
{
	Mouse my_mouse;//�����Լ���д����
	int player = 1;//�ж����ķ����壬��������Ϸ����д��ʾ
	int keyword = 3;//���������
	outtextxy(760, 50, _T("�������"));
	keyword = my_mouse.ifbool(player);
	while (1)
	{
		if (keyword == 1) {
			ifVictory(2);	// �ж��Ƿ����������һ��������
		}
		else if (keyword == 2) {
			hint();			// ��ʾ�ô���������
			player = 2;
		}
		else if (keyword == 3) {  //������˳���Ϸ���ؿ���Ϸ
			player = 2;
		}
		if (player == 1) {  //�л����֣��������ʾ
			outtextxy(760, 50, _T("��������"));
			playchess_AI();
			player = 2;
		}
		else if (player == 2) {
			outtextxy(760, 50, _T("�������"));
			player = 1;
			keyword = my_mouse.ifbool(player);
		}
	}
}


void newGame_AI()
{
	// ���¿�ʼ��Ϸ
	gameInterface();	// ��ʼ����ͼ
	for (int i = 0; i < 15; i++) {	// ��ͼȫ����Ϊ��
		for (int j = 0; j < 15; j++) {
			Map[i][j] = 0;
		}
	}
	playgame_AI();
}

void playchess_AI()
{
	int a, b;
	do
	{
		srand((unsigned)time(NULL));
		a = rand() % 15;//����0~15�����������λ����
		Sleep(10);
		srand((unsigned)time(NULL));
		b = rand() % 15;
	} while (Map[a][b] != 0);
	Map[a][b] = 2;
	// Ԥ�ȼ���ͼƬ
	loadimage(&imageWhite, _T("./picture/white.png"), 30, 30);
	putimage(a * 50 + 15, b * 50 + 30, &imageWhite);
}