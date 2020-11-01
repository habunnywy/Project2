/**
贪吃蛇功能函数实现
copyright：luye@nankai.edu.cn
modified by：huawangl@nankai.edu.cn
时间：2020年5月7日
*/

#pragma once
#include"Snake.h"
#include<iostream>
#include<stdlib.h>//随即函数就包含在这个头文件
#include<time.h>//时间函数time包含在这个头文件
#include <conio.h>
#include <stdio.h>
#include<windows.h>//HANDLE类（句柄类）与COORD类（坐标类）包含在这个头文件

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

/**
方向控制
*/
#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 3
extern int status;

extern const int window_width;
extern const int window_height;
extern const int adjust;
extern Snake *head,*food;//全局指针，head是永远指向第一个节点的指针，food是指向食物的指针
extern Snake *q;//遍历整个蛇所用到的指针
extern Snake *ed;
extern int condition;//代表按键情况，上述把按键四种情况分别赋了整数值，所以这里的情况也是int 类型
extern int end_condition;//表示结束的情况，=1，撞墙；=2，咬到自己；=3，自己结束;4 撞到障碍物而死
extern int score;
extern int add;//得分和每个食物的分数
extern COORD o[100];
extern bool food_exist;
extern int speed[3];
extern char player_ID[80];
extern int difficult;


inline void Green_color();//字体置绿
inline void Red_color();//字体置红
inline void Blue_color();
inline void Yellow_color();//字体置黄
inline void Cyan_color();
inline void White_color();

void Set_location(int x, int y);//定位函数
void Creat_obs(COORD o[], int n);//创建障碍物
void Print_obs(COORD o[]);
void Initial(int s_long);//初始化函数
void Print_snake(Snake* s,const char* p);//用p打印蛇
void creat_food();
void creatMap();//创建地图
void pause();//暂停
void Start();//开始
void Playing();//进行游戏
void Die();//死亡




