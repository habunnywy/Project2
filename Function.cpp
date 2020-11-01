

#pragma once
#include"Function.h"

const int window_width=90;
const int window_height=40;
const int adjust = 13;
Snake *head, *food;//全局指针，head是永远指向第一个节点的指针，food是指向食物的指针，也是snake便于添加
Snake *q;//遍历整个蛇所用到的指针
Snake *ed;//清尾需要
int condition;//代表按键情况，上述把按键四种情况分别赋了整数值，所以这里的情况也是int 类型
int end_condition = 0;//表示结束的情况，=1，撞墙；=2，咬到自己；=3，自己结束;4 撞到障碍物而死
int difficult = 0;//0难度简单，1难度普通，2难度困难
int score = 0, add = 10;//得分和每个食物的分数
int status;
bool food_exist = false;//食物存在标志;
COORD o[100];//定义一个存放障碍物的结构体数组用来存放每一块障碍物的x，y坐标
char player_ID[80]="Habunny";
int speed[3] = { 150,100,50 };

const char *p1 = "■", *p2 = "  ", *p3 = "■";//p1是障碍和墙，p2为空，p3为食物。

inline void Green_color()//这里用到一个SetConsoleTextAttribute，
//是API设置控制台窗口颜色属性的函数，这里和句柄搭配
{                               // 设置颜色为绿色
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,                    //关键字设置
		FOREGROUND_GREEN |//设置前置绿色
		FOREGROUND_INTENSITY);//让字体变得更加明亮
}

inline void Red_color()//设置颜色为红色
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,                    //关键字设置
		FOREGROUND_RED |//设置前置红色
		FOREGROUND_INTENSITY);//让字体变得更加明亮
}

inline void Blue_color()//设置颜色为蓝色
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,                    //关键字设置
		FOREGROUND_BLUE |//设置前置蓝色
		FOREGROUND_INTENSITY);//让字体变得更加明亮
}

inline void Yellow_color()//设置颜色为黄色
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,                    //关键字设置
		FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);//让字体变得更加明亮
}

inline void Cyan_color()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_GREEN |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
}

inline void White_color()//设置颜色为白色,默认也是白色
{ 
	HANDLE hOut;
	hOut= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
}

void Set_location(int x, int y)//定位函数，作用是定位给出坐标的位置方便打印出想要的东西
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);//GetStdHandle()函数获得指定的标准输入输出的句柄
	COORD coord;//坐标类（实际是个结构体）
	coord.X = 2*x;
	coord.Y = y;
	SetConsoleCursorPosition(hwnd, coord);
	
}
void Print_snake(Snake* s, const char* p)
{	
	int i = 0;
	q = s;
	do
	{
		i++;
		Set_location(q->Get_x(),q->Get_y());	
		if (i == 2) 
		{
			Blue_color();	
			cout << "★";
			Cyan_color();
		}
		else cout << p;		
		q = q->Get_next();
	} while (q != NULL);
	if (ed != NULL) 
	{
		Set_location(ed->Get_x(), ed->Get_y());
		cout << p2;		
	}
}
void Creat_obs(COORD o[], int n=0)//根据难度创造障碍物，窗体大小长x90方向：→，高y40方向：↓
{	
	int i = 0;
	if (n == 0)
	{
		for (i = 0; i < 4; i++) { o[i].X = 25+i; o[i].Y = 3; }//----型障碍 (3,26-28)

		for (; i < 9; i++) { o[i].X = 11+i; o[i].Y = 10; }//L型障碍(10,15-19)
		for (; i < 14; i++) { o[i].X = 19; o[i].Y = i+2; }//(11-15,19)

		for (; i < 20; i++) { o[i].X = i + 16; o[i].Y = i + 3; }//  \型障碍（17-22，30-35）

		for (; i < 25; i++) { o[i].X = 48; o[i].Y = i+5; }//    |型障碍（25-29，48）

		for (; i < 30; i++) { o[i].X = i-22; o[i].Y = 60-i; }//  /型障碍(35-31,2-6)
		o[i].X = 0; o[i].Y = 0;
	}
	else if(n==1)
	{
		for (i = 0; i < 4; i++) { o[i].X = 25 + i; o[i].Y = 3; }//----型障碍 (3,26-28)

		for (; i < 9; i++) { o[i].X = 11 + i; o[i].Y = 10; }//L型障碍(10,15-19)
		for (; i < 14; i++) { o[i].X = 19; o[i].Y = i + 2; }//(11-15,19)

		for (; i < 20; i++) { o[i].X = i + 16; o[i].Y = i + 3; }//  \型障碍（17-22，30-35）

		for (; i < 25; i++) { o[i].X = 51; o[i].Y = i - 5; }//    |型障碍（25-29，51）

		for (; i < 30; i++) { o[i].X = i - 22; o[i].Y = 60 - i; }//  /型障碍(35-31,2-6)

		for (; i < 35; i++) { o[i].X = i - 24; o[i].Y = 23; }//    巨型障碍1(6-10,23-27,8-10)
		for (; i < 40; i++) { o[i].X=6; o[i].Y = i - 12; }
		for (; i < 45; i++) { o[i].X = i - 32; o[i].Y = 25; }
		for (; i < 50; i++) { o[i].X=i-39; o[i].Y = 27; }

		for (; i < 58; i++) { o[i].X = 40; o[i].Y = i - 22; }//  巨型障碍2
		for (; i < 66; i++) { o[i].X = 49; o[i].Y = i-30; }
		for (; i < 71; i++) { o[i].X = 43; o[i].Y = i - 37; }
		for (; i < 76; i++) { o[i].X = 46; o[i].Y = i - 42; }
		for (; i < 86; i++) { o[i].X = i - 36; o[i].Y = 35; }
		for (; i < 89; i++) { o[i].X = i - 43; o[i].Y = 33; }

		o[i].X = 0; o[i].Y = 0;
	}
	else
	{
		for (i = 0; i < 4; i++) { o[i].X = 25 + i; o[i].Y = 3; }//----型障碍 (3,26-28)

		for (; i < 9; i++) { o[i].X = 11 + i; o[i].Y = 10; }//L型障碍(10,15-19)
		for (; i < 14; i++) { o[i].X = 19; o[i].Y = i + 2; }//(11-15,19)

		for (; i < 20; i++) { o[i].X = i + 16; o[i].Y = i + 3; }//  \型障碍（17-22，30-35）

		for (; i < 25; i++) { o[i].X = 51; o[i].Y = i - 5; }//    |型障碍（25-29，51）

		for (; i < 30; i++) { o[i].X = i - 22; o[i].Y = 60 - i; }//  /型障碍(35-31,2-6)

		for (; i < 35; i++) { o[i].X = i - 24; o[i].Y = 23; }//    巨型障碍1(6-10,23-27,8-10)
		for (; i < 40; i++) { o[i].X = 6; o[i].Y = i - 12; }
		for (; i < 45; i++) { o[i].X = i - 32; o[i].Y = 25; }
		for (; i < 50; i++) { o[i].X = i - 39; o[i].Y = 27; }

		for (; i < 58; i++) { o[i].X = 40; o[i].Y = i - 22; }//  巨型障碍2
		for (; i < 66; i++) { o[i].X = 49; o[i].Y = i - 30; }
		for (; i < 71; i++) { o[i].X = 43; o[i].Y = i - 37; }
		for (; i < 76; i++) { o[i].X = 46; o[i].Y = i - 42; }
		for (; i < 86; i++) { o[i].X = i - 36; o[i].Y = 35; }
		for (; i < 89; i++) { o[i].X = i - 43; o[i].Y = 33; }

		for (; i < 93; i++) { o[i].X = i - 47; o[i].Y = i - 81; }//V型障碍
		for (; i < 96; i++) { o[i].X = i - 47; o[i].Y = 103-i; }

		o[i].X = 0; o[i].Y = 0;
	}
}

void Print_obs(COORD o[])//打印障碍物
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);//获取屏幕句柄
	int i = 0;
	while ((o[i].X) != 0 || (o[i].Y) != 0) 
	{
		COORD coord; coord.X = 2*o[i].X; coord.Y = o[i].Y;//这样可以省好多临时变量
		SetConsoleCursorPosition(hwnd, coord);
		cout << p1;
		i++;
	}
}

void creat_food()//不加参数会一直处理，随机生成食物,并打印
{	
	if (!food_exist) 
	{
		srand((unsigned int)time(NULL));
		food = new Snake();
		food->Set_next(NULL);

		int i = 0, x = 0, y = 0, tempx = 0, tempy = 0;

		x = rand() % (window_width - 35) + 1;
		y = rand() % (window_height - 3) + 1;
		q = head;

		while ((o[i].X!=0||o[i].Y!=0) || q != NULL)                      //食物出现在障碍物或蛇的位置。重新生成
		{
			if (q != NULL) { tempx = q->Get_x(); tempy = q->Get_y(); }
			if ((o[i].X == x && o[i].Y == y) || (tempx == x && tempy == y))
			{
				x = rand() % (window_width - 35) + 1;
				y = rand() % (window_height - 2) + 1;
				i = 0; q = head;//重新遍历
				continue;
			}
			if (o[i].X != 0 || o[i].Y != 0) i++;
			if (q != NULL) q = q->Get_next();
		}

		food->Set_x(x);
		food->Set_y(y);
		
		food_exist = true;

		Red_color();
		Print_snake(food, p3); 
		White_color();
	}

}

void Initial(int s_long)//初始化蛇，蛇一开始可设置为四节
{
	head = new Snake();	
	head->Set_x(20);
	head->Set_y(20);
	
	q = head;
	for (int i = 1; i < s_long; i++) 
	{   
		q->Set_next(new Snake());
		q = q->Get_next();		
		q->Set_x(20 - i);
		q->Set_y(20);		
	}
	q->Set_next(NULL);//最后一节没下一节了
	Print_snake(head,p1);
}



void creatMap()//创建地图
{
	system("cls");
	int i = 0, j = 0;//j为行(x)    i为列(y)
	for (; j < window_width-adjust; j++)
	{
		Set_location(j, i);
		cout << p1;
	}
	for (i = 1; i < window_height - 1; i++)
	{
		for (j = 0; j < window_width-adjust; j++)
		{
			if ((i == 13 && j >= window_width - 34) || j == 0 || j == window_width - 34 || j == window_width - 1-adjust)
			{
				Set_location(j, i);
				cout << p1;
				continue;
			}
			else
			{
				Set_location(j, i);
				cout << p2;
			}

		}
	}
	//i++;
	for (j = 0; j < window_width-adjust; j++)
	{
		Set_location(j, i);
		cout << p1;
	}

}

void pause()//暂停函数，当按下空格，表示要暂停游戏
{
	while (1)
	{
		Sleep(300);//延时函数，1000表示延时1s，这里是延时0.3s
		if (GetAsyncKeyState(VK_SPACE))//VK表示键盘按键行为，“_”表示是哪一个按键，这里判断是空格按键
			break;                   //这里判断如果按键是SPACE 就要终止游戏  async异步的，同步异步的概念同学们会在大二时学到。
	}
}
void Start()//开始游戏
{
	/***********欢迎界面**************/
	system("mode con cols=160 lines=40");//窗口长宽设置
	PlaySound(TEXT("hy.wav"), NULL, SND_ASYNC | SND_LOOP);//异步并循环播放欢迎曲
	Set_location(40,10);

	

	cout << "贪吃蛇小游戏"<<endl<<endl<<endl<<endl;
	cout << "                                                   游戏规则如下："<< endl<<endl;
	cout << "                                                   不能穿墙，不能咬到自己"<<endl;
	printf("                                                   用↑.↓.←.→分别控制蛇的移动");
	
	Set_location(43,16);
	cout <<"               请输入你的ID：";
	cin >> player_ID;
	Set_location(32,20);
	cout <<"不同难度下，蛇的速度和障碍物个数都会不同哦！" ;
	Set_location(27,22);
	cout << "难度输入  0：简单(1个食物+10)   1：普通(1个食物+20)   2：困难(1个食物+30)"<<endl<<"    ";	
	cin >> difficult;
	while (difficult > 2 || difficult < 0) { cout << endl << "    难度有误，请重新输入难度："; cin >> difficult; }
	cout << "----------------------------------------------------------------请按空格键开始游戏----------------------------------------------------------------";
	
	pause();
	system("cls");
	/**********画出地图**********/
	creatMap();
	/********用户提示性信息************/
	Set_location(window_width-27,4);
	Green_color();
	cout << "玩家ID： ";	
	cout << player_ID << endl;
	
	Set_location(window_width - 27, 6);
	Yellow_color();
	score = 0;
	cout << "玩家分数: " << score << endl;
	White_color();

	Set_location(window_width-27,15);
	cout << "游戏规则如下:" ;
	Set_location(window_width - 32, 17);
	cout << "不能穿墙，不能咬到自己" ;	
	Set_location(window_width-32,19);
	printf("用↑.↓.←.→分别控制蛇的移动.");//cout << "用箭头控制蛇的移动";
	Set_location(window_width-32,21);
	cout << "按空格键space暂停";
	Set_location(window_width-32,21);
	cout << "       可按ESC键退出游戏";
	Set_location(window_width-30,25);
	cout << "■ 障碍";
	Set_location(window_width-30,27);
	Red_color();
	cout << "■ 食物";
	Set_location(window_width-30,29);
	Cyan_color();
	cout << "■ 蛇";
	White_color();
	/*********画出障碍***********/
	Creat_obs(o, difficult);
	Print_obs(o);
	
	/**********画蛇和食物********/
	ed = NULL;
	Initial(4);
	food_exist = 0;
	/***********蛇的初始移动状态********/
	status = RIGHT;
	end_condition = 0;
	PlaySound(TEXT("play.wav"), NULL, SND_ASYNC | SND_LOOP);//异步且循环播放音乐
	
	

}
void Playing()//进行游戏中
{
	while (true) 
	{
		creat_food();
		/**********隐藏光标**********/
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
		CursorInfo.bVisible = false; //隐藏控制台光标
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
		if (GetAsyncKeyState(VK_UP) && status != DOWN)//windows键盘按键API
		{
			status = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && status != UP)
		{
			status = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && status != RIGHT)
		{
			status = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && status != LEFT)
		{
			status = RIGHT;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			end_condition = 3;			
		}
		/*********接收后开始移动**********/
		head->Move();
		Cyan_color();
		Print_snake(head, p1);
		White_color();
		/**********死亡判断**************/
		head->Bite_self();
		head->Can_not_croblock();
		head->Can_not_crowall();
		if (end_condition) break;
		/***********分数变更*************/
		Set_location(window_width - 22, 6);
		Yellow_color();
		cout << score;
		White_color();
		/************速度控制************/
		Sleep(speed[difficult]);
	}

}

void Die()//游戏结束
{
	system("cls");
	Set_location(window_width-60, 9);
	if(end_condition==1)
	{
		cout << "你撞墙了，GAME OVER。";
	}
	else if(end_condition == 2)
	{
		cout << "你咬到自己了，GAME OVER。";
	}
	else if(end_condition==3)
	{
		cout << "你已经结束了游戏。";
	}
	else if(end_condition==4)
	{
		cout << "你撞到障碍物了，GAME OVER";
	}

	Set_location(window_width-60, 10);
	cout << "最终得分是："<<score;
	cout << endl << endl << endl<<endl;

	
}

