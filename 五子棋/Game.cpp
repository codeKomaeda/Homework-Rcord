#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int Map[15][15] = { 0 };//����

void playgame()//����Ϸ
{
	Mouse my_mouse;//�����Լ���д����
	int player = 1;//�ж����ķ����壬��������Ϸ����д��ʾ
	int keyword = 3;//���������
	outtextxy(760, 50, _T("��������"));
	while (1) {	
		keyword = my_mouse.ifbool(player);
		if (keyword == 1) {
			ifVictory(1);	// �ж��Ƿ����������һ��������
		}
		else if (keyword == 2) {
			hint();			// ��ʾ�ô���������
			continue;
		}
		else if (keyword == 3) //������˳���Ϸ���ؿ���Ϸ
		{
			continue;
		}
		if (player == 1) //�л����֣��������ʾ
		{
			outtextxy(760, 50, _T("��������"));
			player = 2;
		}
		else if (player == 2) {
			outtextxy(760, 50, _T("��������"));
			player = 1;
		}
	}
}

// ���¿�ʼ��Ϸ
void newGame(void)
{
	// ���¿�ʼ��Ϸ
	gameInterface();	// ��ʼ����ͼ
	for (int i = 0; i < 15; i++) // ��ͼȫ����Ϊ��
	{
		for (int j = 0; j < 15; j++)
		{
			Map[i][j] = 0;
		}
	}
	playgame();
}

void hint()// ��ʾ�ô���������
{
	MessageBox(hwnd2, TEXT("�ô��������ӣ�������"), TEXT("��ʾ"), MB_OK);
}

// �ж��Ƿ����������һ��������
void ifVictory(int mode) 
{
	for (int i = 0; i < 15; i++) 
	{
		for (int j = 0; j < 15; j++) 
		{
			// �����㷨����Ϸ�����ж�
			if ((Map[i][j] == 1 && Map[i - 1][j - 1] == 1 && Map[i - 2][j - 2] == 1 && Map[i - 3][j - 3] == 1 && Map[i - 4][j - 4] == 1) ||		// ���Ͻ�
				(Map[i][j] == 1 && Map[i + 1][j - 1] == 1 && Map[i + 2][j - 2] == 1 && Map[i + 3][j - 3] == 1 && Map[i + 4][j - 4] == 1) ||		// ���Ͻ�
				(Map[i][j] == 1 && Map[i - 1][j + 1] == 1 && Map[i - 2][j + 2] == 1 && Map[i - 3][j + 3] == 1 && Map[i - 4][j + 4] == 1) ||		// ���½�
				(Map[i][j] == 1 && Map[i + 1][j + 1] == 1 && Map[i + 2][j + 2] == 1 && Map[i + 3][j + 3] == 1 && Map[i + 4][j + 4] == 1) ||		// ���½�
				(Map[i][j] == 1 && Map[i][j - 1] == 1 && Map[i][j - 2] == 1 && Map[i][j - 3] == 1 && Map[i][j - 4] == 1) ||				// ��
				(Map[i][j] == 1 && Map[i][j + 1] == 1 && Map[i][j + 2] == 1 && Map[i][j + 3] == 1 && Map[i][j + 4] == 1) ||				// ��
				(Map[i][j] == 1 && Map[i - 1][j] == 1 && Map[i - 2][j] == 1 && Map[i - 3][j] == 1 && Map[i - 4][j] == 1) ||				// ��
				(Map[i][j] == 1 && Map[i + 1][j] == 1 && Map[i + 2][j] == 1 && Map[i + 3][j] == 1 && Map[i + 4][j] == 1)) {				// ��
				Victory(1);	// ִ��ʤ������
			}
			else if ((Map[i][j] == 2 && Map[i - 1][j - 1] == 2 && Map[i - 2][j - 2] == 2 && Map[i - 3][j - 3] == 2 && Map[i - 4][j - 4] == 2) ||		// ���Ͻ�
				(Map[i][j] == 2 && Map[i + 1][j - 1] == 2 && Map[i + 2][j - 2] == 2 && Map[i + 3][j - 3] == 2 && Map[i + 4][j - 4] == 2) ||		// ���Ͻ�
				(Map[i][j] == 2 && Map[i - 1][j + 1] == 2 && Map[i - 2][j + 2] == 2 && Map[i - 3][j + 3] == 2 && Map[i - 4][j + 4] == 2) ||		// ���½�
				(Map[i][j] == 2 && Map[i + 1][j + 1] == 2 && Map[i + 2][j + 2] == 2 && Map[i + 3][j + 3] == 2 && Map[i + 4][j + 4] == 2) ||		// ���½�
				(Map[i][j] == 2 && Map[i][j - 1] == 2 && Map[i][j - 2] == 2 && Map[i][j - 3] == 2 && Map[i][j - 4] == 2) ||				// ��
				(Map[i][j] == 2 && Map[i][j + 1] == 2 && Map[i][j + 2] == 2 && Map[i][j + 3] == 2 && Map[i][j + 4] == 2) ||				// ��
				(Map[i][j] == 2 && Map[i - 1][j] == 2 && Map[i - 2][j] == 2 && Map[i - 3][j] == 2 && Map[i - 4][j] == 2) ||				// ��
				(Map[i][j] == 2 && Map[i + 1][j] == 2 && Map[i + 2][j] == 2 && Map[i + 3][j] == 2 && Map[i + 4][j] == 2)) {				// ��
				if (mode == 2)//���ǵ��Ի�ʤ
				{
					Victory(3);
				}
				else Victory(2);	// ִ��ʤ������
			}
		}
	}
}

void Victory(int victory)
{
	ofstream tmp_user;//���ڴ�ʤ�ߵ��ļ�������ʤ����+1
	if (victory == 1)
	{
		tmp_user.open(".\\users\\" + player1_name + ".txt", ios::in | ios::out);
		tmp_user << ++player1_scores;
		tmp_user.close();
		MessageBox(hwnd2, TEXT("��ϲ�����ʤ"), TEXT("ʤ���Ѳ���"), MB_OK);
		int judge = MessageBox(hwnd2, TEXT("��ȷ��Ҫ����һ����"), TEXT("ע��!"), MB_YESNO);
		if (judge == 6) {
			newGame();	// ���¿�ʼ��Ϸ����
		}
		else if (judge == 7) {
			closegraph();
			exit(1);;//���·���
		}
	}
	else if (victory == 2)
	{
		tmp_user.open(".\\users\\" + player2_name + ".txt", ios::in | ios::out);
		tmp_user << ++player2_scores; 
		tmp_user.close();
		MessageBox(hwnd2, TEXT("��ϲ�����ʤ"), TEXT("ʤ���Ѳ���"), MB_OK);
		int judge = MessageBox(hwnd2, TEXT("��ȷ��Ҫ����һ����"), TEXT("ע��!"), MB_YESNO);
		if (judge == 6)
		{
			newGame();	// ���¿�ʼ��Ϸ����
		}
		else if (judge == 7)
		{
			closegraph();
			exit(1);;//���·���
		}
	}
	else if (victory == 3) {
		MessageBox(hwnd2, TEXT("��ϲ���Ի�ʤ(���ڹ�����?)"), TEXT("ʤ���Ѳ���"), MB_OK);
		int judge = MessageBox(hwnd2, TEXT("��ȷ��Ҫ����һ����"), TEXT("ע��!"), MB_YESNO);
		if (judge == 6) {
			newGame_AI();	// ���¿�ʼ��Ϸ����
		}
		else if (judge == 7) {
			closegraph();
			exit(1);;//���·���
		}
	}
}