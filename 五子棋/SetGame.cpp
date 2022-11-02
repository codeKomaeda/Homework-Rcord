#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

HWND hwnd2;

// ��Ϸ�׽���
void initgraphGame(void) {
	//��¼������
	Mouse my_mouse;
	HWND hwnd;
	// ��ʼ��ͼ�����
	hwnd = initgraph(1080, 720);//1080 * 720 �ķֱ���Ӧ���ڶ�����ʾ��

	// ��ͼƬӦ���ڽ�����
	loadimage(0, _T("./picture/background.jpg"));

	// ��������ı�����ɫΪ͸��
	setbkmode(TRANSPARENT);
	// ����������ɫ
	settextcolor(RGB(255, 0, 0));
	// ���û��ʴ�ϸ
	setlinestyle(PS_SOLID, 5);

	// ��������
	settextstyle(60, 0, _T("΢���ź�"));
	// д��
	outtextxy(445, 250, _T("ע���˺�"));
	outtextxy(445, 350, _T("��¼�˺�"));
	outtextxy(445, 450, _T("�鿴����"));
	//�����������ľ���
	rectangle(440, 250, 640, 310);
	rectangle(440, 350, 640, 410);
	rectangle(440, 450, 640, 510);

	// ��һ�����ľ���
	rectangle(400, 110, 680, 220);

	// ��������
	settextstyle(120, 0, _T("΢���ź�"));
	// ����������ɫ
	settextcolor(RGB(255, 200, 88));

	// д��(��������������)
	outtextxy(400, 100, _T("������"));

	//�鿴����
	if (3 == my_mouse.loadGame()) {		
		MessageBox(hwnd, TEXT("�������У��ڰ��������壬�ᡢ�ݡ���б���������ӻ�ʤ��"), TEXT("����"), MB_OK);
		initgraphGame();
	}
	//ע���˺�
	else if (1 == my_mouse.loadGame()) {
		closegraph();
		user_register();
		initgraphGame();
	}
	//��¼�˺�
	else if (2 == my_mouse.loadGame()) {
		closegraph();
		user_login();
	}
	Sleep(50);
	
	closegraph();
}

//ѡ����Ϸģʽ�Ͳ鿴���а�
void SelectMode()
{
	//��¼������
	Mouse my_mouse;
	// ��ʼ��ͼ�����
	initgraph(1080, 720);//1080 * 720 �ķֱ���Ӧ���ڶ�����ʾ��

	// ��ͼƬӦ���ڽ�����
	loadimage(0, _T("./picture/background.jpg"));

	// ��������ı�����ɫΪ͸��
	setbkmode(TRANSPARENT);

	// ����������ɫ
	settextcolor(RGB(255, 0, 0));
	// ���û��ʴ�ϸ
	setlinestyle(PS_SOLID, 5);

	// ��������
	settextstyle(60, 0, _T("΢���ź�"));
	// д��
	outtextxy(445, 250, _T("�˻���ս"));
	outtextxy(445, 350, _T("��Ҷ�ս"));
	settextstyle(50, 0, _T("΢���ź�"));
	outtextxy(445, 450, _T("�鿴���а�"));
	//�����������ľ���
	rectangle(440, 250, 640, 310);
	rectangle(440, 350, 640, 410);
	rectangle(440, 450, 640, 510);

	// ��һ�����ľ���
	rectangle(400, 110, 680, 220);

	// ��������
	settextstyle(120, 0, _T("΢���ź�"));
	// ����������ɫ
	settextcolor(RGB(255, 200, 88));
	// д��(��������������)
	outtextxy(400, 100, _T("������"));

	//�鿴���а�
	if (3 == my_mouse.loadGame()) {
		closegraph();
		toplist();
		SelectMode();
	}
	//�˻���ս
	else if (1 == my_mouse.loadGame()) {
		newGame_AI();
	}//��Ҷ�ս
	else if (2 == my_mouse.loadGame()) {
		//�ȵ�¼�û�2���˺�
		closegraph();
		user_login();
		newGame();
	}
	closegraph();
}

void gameInterface(void) {
	// ��ʼ��ͼ�����
	hwnd2 = initgraph(GRAPHICS_X, GRAPHICS_Y);
	// ����ͼ��ı�����ɫ
	setbkcolor(RGB(255, 200, 88));
	// Ӧ�õ�ͼ����
	cleardevice();
	// ���û�����ɫ
	setlinecolor(RGB(0, 0, 0));
	// ���û��ʴ�ϸ
	setlinestyle(PS_SOLID, 3);
	// ��һ�����ľ���
	rectangle(PLATE_X, PLATE_Y, PLATE_XX, PLATE_YY);
	// �����
	plate();
	// ��Ϸ��ť
	gameButton();
}

// ��Ϸ ��ʼ�������� ���������
void gameButton(void) {
	// ���û��ʴ�ϸ
	setlinestyle(PS_SOLID, 2);
	// ����������ɫ
	settextcolor(RGB(0, 0, 0));
	// ��������
	settextstyle(25, 0, _T("΢���ź�"));
	// ������ķ���
	rectangle(750, 40, 860, 100);
	rectangle(760, 250, 850, 300);
	// д��
	outtextxy(767, PLATE_Y * 5 + 10, _T("�ؿ�һ��"));
	// ������ķ���
	rectangle(760, 450, 850, 500);
	// д��
	outtextxy(767, 460, _T("������Ϸ"));
	// ��������
	settextstyle(30, 0, _T("΢���ź�"));
	// ������
	outtextxy(700 / 2, 10, _T("������"));
}

//������
void plate() {
	// ���û��ʴ�ϸ
	setlinestyle(PS_SOLID, 2);

	for (int i = 0; i < 13; i++) {
		//	�̶�ֵ����һ��ƫ����
		line(PLATE_X, PLATE_Y + (OFFSET * (i + 1)), PLATE_XX, PLATE_Y + (OFFSET * (i + 1)));	// ��
		line(PLATE_X + (OFFSET * (i + 1)), PLATE_Y, PLATE_X + (OFFSET * (i + 1)), PLATE_YY);	// ��
	}
}