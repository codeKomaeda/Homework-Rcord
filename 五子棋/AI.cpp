#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

void playgame_AI()
{
	Mouse my_mouse;//调用自己编写的类
	int player = 1;//判断是哪方下棋，用于在游戏界面写提示
	int keyword = 3;//鼠标点击棋盘
	outtextxy(760, 50, _T("玩家下棋"));
	keyword = my_mouse.ifbool(player);
	while (1)
	{
		if (keyword == 1) {
			ifVictory(2);	// 判断是否下完了五个一样的棋子
		}
		else if (keyword == 2) {
			hint();			// 提示该处已有棋子
			player = 2;
		}
		else if (keyword == 3) {  //玩家误触退出游戏或重开游戏
			player = 2;
		}
		if (player == 1) {  //切换棋手，并输出提示
			outtextxy(760, 50, _T("电脑下棋"));
			playchess_AI();
			player = 2;
		}
		else if (player == 2) {
			outtextxy(760, 50, _T("玩家下棋"));
			player = 1;
			keyword = my_mouse.ifbool(player);
		}
	}
}


void newGame_AI()
{
	// 重新开始游戏
	gameInterface();	// 初始化地图
	for (int i = 0; i < 15; i++) {	// 地图全部置为零
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
		a = rand() % 15;//产生0~15的随机数，定位棋盘
		Sleep(10);
		srand((unsigned)time(NULL));
		b = rand() % 15;
	} while (Map[a][b] != 0);
	Map[a][b] = 2;
	// 预先加载图片
	loadimage(&imageWhite, _T("./picture/white.png"), 30, 30);
	putimage(a * 50 + 15, b * 50 + 30, &imageWhite);
}