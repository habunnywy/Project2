/**
贪吃蛇功能函数实现
copyright：luye@nankai.edu.cn
modified by：huawangl@nankai.edu.cn
时间：2020年5月7日
*/

#pragma once

class Snake//蛇类，包含了蛇的基本元素和蛇的所有活动，其中蛇是由链表构成的
{
public://这里没有写构造函数，同学们可以根据需要编写，但要注意指针指向时表发生混乱
	Snake(int x=0,int y=0) 
	{
		Set_x(x); Set_y(y);
	}
	//友元函数作用并不明显，可以通过Set来替代，请同学们思考如何实现
	friend void creat_food();//生成食物的函数
	friend void Initial(int s_long); //初始化函数，初始化蛇的身体的初始长度，以及出生位置
	friend void Print_snake(Snake* s,const char* p);//画蛇	
	void Set_x(int x);
	void Set_y(int y);
	int Get_x();
	int Get_y();
	
	
	void Set_next(Snake* s);
	Snake *Get_next();
	
	void Bite_self();//判断是否咬到自己
	void Can_not_crowall();//不能穿墙，所以碰到墙会死
	void Can_not_croblock();//不能碰障碍

	void Move();//蛇的移动
	
private:
	int s_x;//蛇的x，y坐标
	int s_y;
	
	Snake *next;//使用链表完成，两个数据域，存放横x纵y坐标。一个指针域，存放链接后续身体节点的地址
	
	
};


/*
struct Obstacle//障碍物结构体，内部有x和y两个量
{
	int x;//障碍物的横纵坐标
	int y;
};
*/

