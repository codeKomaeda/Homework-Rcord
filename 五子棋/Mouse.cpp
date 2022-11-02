#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

IMAGE imageBlack;	// 黑棋图片存储变量
IMAGE imageWhite;	// 白棋图片存储变量

// 鼠标事件：首页面点击 (1代表注册账号，2代表登录账号，3代表显示游戏规则)
int Mouse::loadGame(void) {
	MOUSEMSG mouse;	// 鼠标变量

	while (1) {
		mouse = GetMouseMsg();	// 调用系统的函数

		// 如果有鼠标左键点击操作
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

// 鼠标事件：点击重开游戏与退出游戏
bool Mouse::beginGame(void)
{
	MOUSEMSG mouse;	// 鼠标变量

	while (1) {
		mouse = GetMouseMsg();	// 调用系统的函数

		// 如果有鼠标左键点击操作
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

// 鼠标事件: 点击操作
int Mouse::ifbool(int player) {
	MOUSEMSG mouse;	// 鼠标变量
	Mouse my_mouse;
	while (1) {
		mouse = GetMouseMsg();	// 调用系统的函数

		// 如果有鼠标左键点击操作
		if (mouse.uMsg == WM_LBUTTONDOWN) {		// 下棋操作
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {		// 判断鼠标的坐标是否在该区域
					if ((mouse.x >= i * 50 + PLATE_X - 15 && mouse.x <= i * 50 + PLATE_X + 15) &&
						(mouse.y >= j * 50 + PLATE_Y - 15 && mouse.y <= j * 50 + PLATE_Y + 15)) {

						// 等于零，该区域没有棋子
						if (Map[i][j] == 0) {
							my_mouse.x = i * 50 + PLATE_X;	// 下棋
							my_mouse.y = j * 50 + PLATE_Y;
							if (player == 1) {//为黑子
								Map[i][j] = 1;
								// 预先加载图片
								loadimage(&imageBlack, _T("./picture/black.png"), 30, 30);
								// 将棋子下到棋板上面
								putimage(my_mouse.x - 15, my_mouse.y - 15, &imageBlack);
							}
							else if (player == 2) {
								Map[i][j] = 2;
								// 预先加载图片
								loadimage(&imageWhite, _T("./picture/white.png"), 30, 30);
								// 将棋子下到棋板上面
								putimage(my_mouse.x - 15, my_mouse.y - 15, &imageWhite);
							}
							return 1;

						}
						else return 2;
					}
					else if ((mouse.x > 760 && mouse.x < 850) && (mouse.y > 250 && mouse.y < 300)) {	// 重新开始游戏
						int judge = MessageBox(hwnd2, TEXT("您确定要重新进行一局玩家对战吗？（人机对战模式下请勿使用，会有bug产生）"), TEXT("注意!"), MB_YESNO);
						if (judge == 6) {
							newGame();	// 重新开始游戏函数
						}
						else if (judge == 7)
						{
							return 3;//无事发生
						}				
					}				
					else if ((mouse.x > 760 && mouse.x < 850) && (mouse.y > 450 && mouse.y < 500)) {		// 退出游戏操作
					 // 结束程序
						int judge = MessageBox(hwnd2, TEXT("您确定要退出游戏吗？"), TEXT("注意!"), MB_YESNO);
						if (judge == 6) {
							closegraph();
							exit(1);
						}
						else if (judge == 7)
						{
							return 3;//无事发生
						}
					}			
				}
			}
		}
	}
}