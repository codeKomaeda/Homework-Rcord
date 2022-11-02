#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int Map[15][15] = { 0 };//棋盘

void playgame()//玩游戏
{
	Mouse my_mouse;//调用自己编写的类
	int player = 1;//判断是哪方下棋，用于在游戏界面写提示
	int keyword = 3;//鼠标点击棋盘
	outtextxy(760, 50, _T("黑子下棋"));
	while (1) {	
		keyword = my_mouse.ifbool(player);
		if (keyword == 1) {
			ifVictory(1);	// 判断是否下完了五个一样的棋子
		}
		else if (keyword == 2) {
			hint();			// 提示该处已有棋子
			continue;
		}
		else if (keyword == 3) //玩家误触退出游戏或重开游戏
		{
			continue;
		}
		if (player == 1) //切换棋手，并输出提示
		{
			outtextxy(760, 50, _T("白子下棋"));
			player = 2;
		}
		else if (player == 2) {
			outtextxy(760, 50, _T("黑字下棋"));
			player = 1;
		}
	}
}

// 重新开始游戏
void newGame(void)
{
	// 重新开始游戏
	gameInterface();	// 初始化地图
	for (int i = 0; i < 15; i++) // 地图全部置为零
	{
		for (int j = 0; j < 15; j++)
		{
			Map[i][j] = 0;
		}
	}
	playgame();
}

void hint()// 提示该处已有棋子
{
	MessageBox(hwnd2, TEXT("该处已有棋子，请重下"), TEXT("提示"), MB_OK);
}

// 判断是否下完了五个一样的棋子
void ifVictory(int mode) 
{
	for (int i = 0; i < 15; i++) 
	{
		for (int j = 0; j < 15; j++) 
		{
			// 核心算法，游戏棋子判断
			if ((Map[i][j] == 1 && Map[i - 1][j - 1] == 1 && Map[i - 2][j - 2] == 1 && Map[i - 3][j - 3] == 1 && Map[i - 4][j - 4] == 1) ||		// 左上角
				(Map[i][j] == 1 && Map[i + 1][j - 1] == 1 && Map[i + 2][j - 2] == 1 && Map[i + 3][j - 3] == 1 && Map[i + 4][j - 4] == 1) ||		// 右上角
				(Map[i][j] == 1 && Map[i - 1][j + 1] == 1 && Map[i - 2][j + 2] == 1 && Map[i - 3][j + 3] == 1 && Map[i - 4][j + 4] == 1) ||		// 左下角
				(Map[i][j] == 1 && Map[i + 1][j + 1] == 1 && Map[i + 2][j + 2] == 1 && Map[i + 3][j + 3] == 1 && Map[i + 4][j + 4] == 1) ||		// 右下角
				(Map[i][j] == 1 && Map[i][j - 1] == 1 && Map[i][j - 2] == 1 && Map[i][j - 3] == 1 && Map[i][j - 4] == 1) ||				// 上
				(Map[i][j] == 1 && Map[i][j + 1] == 1 && Map[i][j + 2] == 1 && Map[i][j + 3] == 1 && Map[i][j + 4] == 1) ||				// 下
				(Map[i][j] == 1 && Map[i - 1][j] == 1 && Map[i - 2][j] == 1 && Map[i - 3][j] == 1 && Map[i - 4][j] == 1) ||				// 左
				(Map[i][j] == 1 && Map[i + 1][j] == 1 && Map[i + 2][j] == 1 && Map[i + 3][j] == 1 && Map[i + 4][j] == 1)) {				// 右
				Victory(1);	// 执行胜利代码
			}
			else if ((Map[i][j] == 2 && Map[i - 1][j - 1] == 2 && Map[i - 2][j - 2] == 2 && Map[i - 3][j - 3] == 2 && Map[i - 4][j - 4] == 2) ||		// 左上角
				(Map[i][j] == 2 && Map[i + 1][j - 1] == 2 && Map[i + 2][j - 2] == 2 && Map[i + 3][j - 3] == 2 && Map[i + 4][j - 4] == 2) ||		// 右上角
				(Map[i][j] == 2 && Map[i - 1][j + 1] == 2 && Map[i - 2][j + 2] == 2 && Map[i - 3][j + 3] == 2 && Map[i - 4][j + 4] == 2) ||		// 左下角
				(Map[i][j] == 2 && Map[i + 1][j + 1] == 2 && Map[i + 2][j + 2] == 2 && Map[i + 3][j + 3] == 2 && Map[i + 4][j + 4] == 2) ||		// 右下角
				(Map[i][j] == 2 && Map[i][j - 1] == 2 && Map[i][j - 2] == 2 && Map[i][j - 3] == 2 && Map[i][j - 4] == 2) ||				// 上
				(Map[i][j] == 2 && Map[i][j + 1] == 2 && Map[i][j + 2] == 2 && Map[i][j + 3] == 2 && Map[i][j + 4] == 2) ||				// 下
				(Map[i][j] == 2 && Map[i - 1][j] == 2 && Map[i - 2][j] == 2 && Map[i - 3][j] == 2 && Map[i - 4][j] == 2) ||				// 左
				(Map[i][j] == 2 && Map[i + 1][j] == 2 && Map[i + 2][j] == 2 && Map[i + 3][j] == 2 && Map[i + 4][j] == 2)) {				// 右
				if (mode == 2)//若是电脑获胜
				{
					Victory(3);
				}
				else Victory(2);	// 执行胜利代码
			}
		}
	}
}

void Victory(int victory)
{
	ofstream tmp_user;//用于打开胜者的文件并将其胜场数+1
	if (victory == 1)
	{
		tmp_user.open(".\\users\\" + player1_name + ".txt", ios::in | ios::out);
		tmp_user << ++player1_scores;
		tmp_user.close();
		MessageBox(hwnd2, TEXT("恭喜黑棋获胜"), TEXT("胜者已产生"), MB_OK);
		int judge = MessageBox(hwnd2, TEXT("您确定要重玩一局吗？"), TEXT("注意!"), MB_YESNO);
		if (judge == 6) {
			newGame();	// 重新开始游戏函数
		}
		else if (judge == 7) {
			closegraph();
			exit(1);;//无事发生
		}
	}
	else if (victory == 2)
	{
		tmp_user.open(".\\users\\" + player2_name + ".txt", ios::in | ios::out);
		tmp_user << ++player2_scores; 
		tmp_user.close();
		MessageBox(hwnd2, TEXT("恭喜白棋获胜"), TEXT("胜者已产生"), MB_OK);
		int judge = MessageBox(hwnd2, TEXT("您确定要重玩一局吗？"), TEXT("注意!"), MB_YESNO);
		if (judge == 6)
		{
			newGame();	// 重新开始游戏函数
		}
		else if (judge == 7)
		{
			closegraph();
			exit(1);;//无事发生
		}
	}
	else if (victory == 3) {
		MessageBox(hwnd2, TEXT("恭喜电脑获胜(您在故意输?)"), TEXT("胜者已产生"), MB_OK);
		int judge = MessageBox(hwnd2, TEXT("您确定要重玩一局吗？"), TEXT("注意!"), MB_YESNO);
		if (judge == 6) {
			newGame_AI();	// 重新开始游戏函数
		}
		else if (judge == 7) {
			closegraph();
			exit(1);;//无事发生
		}
	}
}