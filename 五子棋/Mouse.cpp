#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

IMAGE imageBlack;	// ����ͼƬ�洢����
IMAGE imageWhite;	// ����ͼƬ�洢����

// ����¼�����ҳ���� (1����ע���˺ţ�2�����¼�˺ţ�3������ʾ��Ϸ����)
int Mouse::loadGame(void) {
	MOUSEMSG mouse;	// ������

	while (1) {
		mouse = GetMouseMsg();	// ����ϵͳ�ĺ���

		// ������������������
		if (mouse.uMsg == WM_LBUTTONDOWN) {
			if ((mouse.x > 440 && mouse.x < 640) && (mouse.y > 250 && mouse.y < 310)) {
				return 1;
			}
			else if ((mouse.x > 440 && mouse.x < 640) && (mouse.y > 350 && mouse.y < 410)) {
				return 2;
			}
			else if ((mouse.x > 440 && mouse.x < 640) && (mouse.y > 450 && mouse.y < 510)) {
				return 3;
			}
			else {
				continue;
			}
		}
	}
}

// ����¼�������ؿ���Ϸ���˳���Ϸ
bool Mouse::beginGame(void)
{
	MOUSEMSG mouse;	// ������

	while (1) {
		mouse = GetMouseMsg();	// ����ϵͳ�ĺ���

		// ������������������
		if (mouse.uMsg == WM_LBUTTONDOWN) {
			if ((mouse.x > 760 && mouse.x < 850) && (mouse.y > 250 && mouse.y < 300)) {
				newGame();
				return true;
			}
			else if ((mouse.x > 760 && mouse.x < 850) && (mouse.y > 450 && mouse.y < 500)) {
				return false;
			}
		}
	}
}

// ����¼�: �������
int Mouse::ifbool(int player) {
	MOUSEMSG mouse;	// ������
	Mouse my_mouse;
	while (1) {
		mouse = GetMouseMsg();	// ����ϵͳ�ĺ���

		// ������������������
		if (mouse.uMsg == WM_LBUTTONDOWN) {		// �������
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {		// �ж����������Ƿ��ڸ�����
					if ((mouse.x >= i * 50 + PLATE_X - 15 && mouse.x <= i * 50 + PLATE_X + 15) &&
						(mouse.y >= j * 50 + PLATE_Y - 15 && mouse.y <= j * 50 + PLATE_Y + 15)) {

						// �����㣬������û������
						if (Map[i][j] == 0) {
							my_mouse.x = i * 50 + PLATE_X;	// ����
							my_mouse.y = j * 50 + PLATE_Y;
							if (player == 1) {//Ϊ����
								Map[i][j] = 1;
								// Ԥ�ȼ���ͼƬ
								loadimage(&imageBlack, _T("./picture/black.png"), 30, 30);
								// �������µ��������
								putimage(my_mouse.x - 15, my_mouse.y - 15, &imageBlack);
							}
							else if (player == 2) {
								Map[i][j] = 2;
								// Ԥ�ȼ���ͼƬ
								loadimage(&imageWhite, _T("./picture/white.png"), 30, 30);
								// �������µ��������
								putimage(my_mouse.x - 15, my_mouse.y - 15, &imageWhite);
							}
							return 1;

						}
						else return 2;
					}
					else if ((mouse.x > 760 && mouse.x < 850) && (mouse.y > 250 && mouse.y < 300)) {	// ���¿�ʼ��Ϸ
						int judge = MessageBox(hwnd2, TEXT("��ȷ��Ҫ���½���һ����Ҷ�ս�𣿣��˻���սģʽ������ʹ�ã�����bug������"), TEXT("ע��!"), MB_YESNO);
						if (judge == 6) {
							newGame();	// ���¿�ʼ��Ϸ����
						}
						else if (judge == 7)
						{
							return 3;//���·���
						}				
					}				
					else if ((mouse.x > 760 && mouse.x < 850) && (mouse.y > 450 && mouse.y < 500)) {		// �˳���Ϸ����
					 // ��������
						int judge = MessageBox(hwnd2, TEXT("��ȷ��Ҫ�˳���Ϸ��"), TEXT("ע��!"), MB_YESNO);
						if (judge == 6) {
							closegraph();
							exit(1);
						}
						else if (judge == 7)
						{
							return 3;//���·���
						}
					}			
				}
			}
		}
	}
}