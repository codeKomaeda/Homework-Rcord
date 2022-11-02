#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

HWND hwnd2;

// 游戏首界面
void initgraphGame(void) {
	//记录鼠标操作
	Mouse my_mouse;
	HWND hwnd;
	// 初始化图像界面
	hwnd = initgraph(1080, 720);//1080 * 720 的分辨率应用于多数显示屏

	// 将图片应用于界面中
	loadimage(0, _T("./picture/background.jpg"));

	// 设置字体的背景颜色为透明
	setbkmode(TRANSPARENT);
	// 设置字体颜色
	settextcolor(RGB(255, 0, 0));
	// 设置画笔粗细
	setlinestyle(PS_SOLID, 5);

	// 设置字体
	settextstyle(60, 0, _T("微软雅黑"));
	// 写字
	outtextxy(445, 250, _T("注册账号"));
	outtextxy(445, 350, _T("登录账号"));
	outtextxy(445, 450, _T("查看规则"));
	//画出三个空心矩形
	rectangle(440, 250, 640, 310);
	rectangle(440, 350, 640, 410);
	rectangle(440, 450, 640, 510);

	// 画一个空心矩形
	rectangle(400, 110, 680, 220);

	// 设置字体
	settextstyle(120, 0, _T("微软雅黑"));
	// 设置字体颜色
	settextcolor(RGB(255, 200, 88));

	// 写字(六个字填满格子)
	outtextxy(400, 100, _T("五子棋"));

	//查看规则
	if (3 == my_mouse.loadGame()) {		
		MessageBox(hwnd, TEXT("黑子先行，黑白轮流下棋，横、纵、或斜向连满五子获胜。"), TEXT("规则"), MB_OK);
		initgraphGame();
	}
	//注册账号
	else if (1 == my_mouse.loadGame()) {
		closegraph();
		user_register();
		initgraphGame();
	}
	//登录账号
	else if (2 == my_mouse.loadGame()) {
		closegraph();
		user_login();
	}
	Sleep(50);
	
	closegraph();
}

//选择游戏模式和查看排行榜
void SelectMode()
{
	//记录鼠标操作
	Mouse my_mouse;
	// 初始化图像界面
	initgraph(1080, 720);//1080 * 720 的分辨率应用于多数显示屏

	// 将图片应用于界面中
	loadimage(0, _T("./picture/background.jpg"));

	// 设置字体的背景颜色为透明
	setbkmode(TRANSPARENT);

	// 设置字体颜色
	settextcolor(RGB(255, 0, 0));
	// 设置画笔粗细
	setlinestyle(PS_SOLID, 5);

	// 设置字体
	settextstyle(60, 0, _T("微软雅黑"));
	// 写字
	outtextxy(445, 250, _T("人机对战"));
	outtextxy(445, 350, _T("玩家对战"));
	settextstyle(50, 0, _T("微软雅黑"));
	outtextxy(445, 450, _T("查看排行榜"));
	//画出三个空心矩形
	rectangle(440, 250, 640, 310);
	rectangle(440, 350, 640, 410);
	rectangle(440, 450, 640, 510);

	// 画一个空心矩形
	rectangle(400, 110, 680, 220);

	// 设置字体
	settextstyle(120, 0, _T("微软雅黑"));
	// 设置字体颜色
	settextcolor(RGB(255, 200, 88));
	// 写字(六个字填满格子)
	outtextxy(400, 100, _T("五子棋"));

	//查看排行榜
	if (3 == my_mouse.loadGame()) {
		closegraph();
		toplist();
		SelectMode();
	}
	//人机对战
	else if (1 == my_mouse.loadGame()) {
		newGame_AI();
	}//玩家对战
	else if (2 == my_mouse.loadGame()) {
		//先登录用户2的账号
		closegraph();
		user_login();
		newGame();
	}
	closegraph();
}

void gameInterface(void) {
	// 初始化图像界面
	hwnd2 = initgraph(GRAPHICS_X, GRAPHICS_Y);
	// 设置图像的背景颜色
	setbkcolor(RGB(255, 200, 88));
	// 应用到图像中
	cleardevice();
	// 设置画笔颜色
	setlinecolor(RGB(0, 0, 0));
	// 设置画笔粗细
	setlinestyle(PS_SOLID, 3);
	// 画一个空心矩形
	rectangle(PLATE_X, PLATE_Y, PLATE_XX, PLATE_YY);
	// 画棋板
	plate();
	// 游戏按钮
	gameButton();
}

// 游戏 开始，结束， 五子棋绘制
void gameButton(void) {
	// 设置画笔粗细
	setlinestyle(PS_SOLID, 2);
	// 设置字体颜色
	settextcolor(RGB(0, 0, 0));
	// 设置字体
	settextstyle(25, 0, _T("微软雅黑"));
	// 字体外的方框
	rectangle(750, 40, 860, 100);
	rectangle(760, 250, 850, 300);
	// 写字
	outtextxy(767, PLATE_Y * 5 + 10, _T("重开一局"));
	// 字体外的方框
	rectangle(760, 450, 850, 500);
	// 写字
	outtextxy(767, 460, _T("结束游戏"));
	// 设置字体
	settextstyle(30, 0, _T("微软雅黑"));
	// 五子棋
	outtextxy(700 / 2, 10, _T("五子棋"));
}

//画棋盘
void plate() {
	// 设置画笔粗细
	setlinestyle(PS_SOLID, 2);

	for (int i = 0; i < 13; i++) {
		//	固定值加上一个偏移量
		line(PLATE_X, PLATE_Y + (OFFSET * (i + 1)), PLATE_XX, PLATE_Y + (OFFSET * (i + 1)));	// 行
		line(PLATE_X + (OFFSET * (i + 1)), PLATE_Y, PLATE_X + (OFFSET * (i + 1)), PLATE_YY);	// 纵
	}
}