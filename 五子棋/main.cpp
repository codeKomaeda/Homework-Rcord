#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int main()
{
	//绘制游戏首界面（用户注册与登录，查看规则）
	initgraphGame();
	//选择模式并开始游戏或查看排行榜
	SelectMode();

	return 0;
}