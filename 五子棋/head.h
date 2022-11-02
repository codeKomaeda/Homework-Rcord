#pragma once

using namespace std;

#include <io.h>//批量读取文件
#include <time.h>//获取随机数实现AI随机下棋
#include <iostream>
#include <string>
#include <graphics.h> //EasyX图形库
#include <fstream> //文件操作
#include <vector> //容器用于存放用户文件夹下的文件名
#include <algorithm>

#define GRAPHICS_X 880
#define GRAPHICS_Y 780

// 游戏棋盘
#define PLATE_X	 30				//
#define PLATE_Y  50				//	棋盘的矩形的坐标值
#define PLATE_XX 50*14+PLATE_X	
#define PLATE_YY 50*15			///
// 偏移量
#define	OFFSET   50	// 每个棋盘空格相隔50像素

extern vector<string> Allfiles;//用于保存全部用户名
extern string player1_name;//用户1名字
extern int player1_scores;//用户1胜场数
extern string player2_name;//用户2名字
extern int player2_scores;//用户2胜场数
extern int Map[15][15];//棋盘
extern HWND hwnd2;//记录棋盘画面，用于输出提示
extern IMAGE imageWhite;//白棋的图片

class Mouse
{
public:
	int x;
	int y;

	int loadGame(void);//鼠标首页面点击
	bool beginGame(void);// 鼠标事件：点击重开游戏与退出游戏
	int ifbool(int player);// 鼠标事件: 点击操作
} ;

void initgraphGame();//初始化游戏
void gameInterface();//游戏界面
void plate();//画棋盘
void SelectMode();//选择游戏模式
void gameButton();//游戏按钮
void newGame();//新游戏
void playgame();//玩游戏
void hint();//提示该处已经有棋子
void ifVictory(int mode);//判断是否有人获胜
void Victory(int victory);//输出胜利提示信息

void user_register();//用户注册
void user_login();//用户登录
void getFiles(string path, vector<string>& files);//批量读取用户数据文件
void toplist();//查看排行榜
int topupdate(fstream& link);//增添修改排行榜数据,返回排行榜上已有玩家数量

//人机部分的代码
void newGame_AI();//人机模式下的新游戏
void playgame_AI();//人机模式下的玩游戏
void playchess_AI();//AI下棋