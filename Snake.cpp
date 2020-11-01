/**
贪吃蛇功能函数实现
copyright：luye@nankai.edu.cn
modified by：huawangl@nankai.edu.cn
时间：2020年5月7日
*/

#pragma once
#include"Function.h"
void Snake::Set_x(int x)
{
	s_x = x;
	
}

void Snake::Set_y(int y)
{
	s_y = y;
	
}

int Snake::Get_x()
{
	return s_x;
}

int Snake::Get_y()
{
	return s_y;
}

/*
void Snake::Set_direciton(int d) 
{
	direction=d;
}

int Snake::Get_direction() 
{
	return direction;
}
*/


void Snake::Set_next(Snake* s) 
{
	next = s;
}


Snake *Snake::Get_next()
{
	return next;
}

/*
void Snake::transmit_direction()//方向传递函数
{
	q=Get_next();
	while(q!=NULL)
	{
		q->Set_direciton(Get_direction());//这一级传给下一级
		q = Get_next();
	}
	
}
*/

void Snake::Bite_self()//检查是否咬到自己,就是检查头节点是否与身体其他任何一个节点碰触
{
	int x0 = Get_x(); int y0 = Get_y();
	q = Get_next();
	while (q != NULL)
	{
		if (q->Get_x() == x0 && q->Get_y() == y0) { end_condition = 2; return; }
		q = q->Get_next();
	}
	
}

void Snake::Can_not_crowall()//不能与墙相撞
{
	if (head->Get_x() == 0 || head->Get_x() == window_width-34 || head->Get_y() == 0 || head->Get_y()==window_height-1)
	{
		end_condition = 1;
		return;
	}
}

void Snake::Can_not_croblock()//
{
	int tempx = head->Get_x(), tempy = head->Get_y();
	int i = 0;
	while((o[i].X != 0 || o[i].Y != 0))
	{		
		if (tempx == o[i].X && tempy == o[i].Y) { end_condition = 4; return; }		
		i++;
	}
	
}


void Snake::Move()//蛇移动的函数
{
	int tempx, tempy;
	tempx = Get_x(), tempy = Get_y();//蛇变化前的坐标
	if(status==UP)
	{
		if ((tempy - 1 != food->Get_y()) || (tempx != food->Get_x()))//下一个不是食物
		{
			//头部的处理			
			q = new Snake();				
			q->Set_y(tempy - 1); q->Set_x(tempx);
			q->Set_next(head);
			head = q;

			//尾部的处理
			while ((q->Get_next())->Get_next()!=NULL)//找到倒数第二个，因为最后一个是我要丢弃的
			{
				q = q->Get_next();
			}
			ed=q->Get_next();
			q->Set_next(NULL);


		}
		else//下一个是食物
		{
			//只需要头部的处理			
			q = new Snake();
			q->Set_y(tempy - 1); q->Set_x(tempx);
			q->Set_next(head);
			head = q;
			
			food_exist = false;
			score += (difficult + 1) * add;
		}
	}

	if (status == DOWN)
	{
		if ((tempy + 1 != food->Get_y()) || (tempx != food->Get_x()))//下一个不是食物
		{
			//头部的处理			
			q = new Snake();
			q->Set_y(tempy + 1); q->Set_x(tempx);
			q->Set_next(head);
			head = q;

			//尾部的处理
			while ((q->Get_next())->Get_next() != NULL)//找到最后
			{
				q = q->Get_next();
			}
			ed = q->Get_next();
			q->Set_next(NULL);


		}
		else//下一个是食物
		{
			//只需要头部的处理			
			q = new Snake();
			q->Set_y(tempy + 1); q->Set_x(tempx);
			q->Set_next(head);
			head = q;

			food_exist = false;
			score += (difficult + 1) * add;
		}
	}


	if (status == LEFT)
	{
		if ((tempy  != food->Get_y()) || (tempx-1 != food->Get_x()))//下一个不是食物
		{
			//头部的处理			
			q = new Snake();
			q->Set_y(tempy); q->Set_x(tempx-1);
			q->Set_next(head);
			head = q;

			//尾部的处理
			while ((q->Get_next())->Get_next() != NULL)//找到最后
			{
				q = q->Get_next();
			}
			ed = q->Get_next();
			q->Set_next(NULL);


		}
		else//下一个是食物
		{
			//只需要头部的处理			
			q = new Snake();
			q->Set_y(tempy); q->Set_x(tempx-1);
			q->Set_next(head);
			head = q;

			food_exist = false;
			score += (difficult + 1) * add;
		}
	}

	if (status == RIGHT)
	{
		if ((tempy != food->Get_y()) || (tempx+1 != food->Get_x()))//下一个不是食物
		{
			//头部的处理			
			q = new Snake();
			q->Set_y(tempy); q->Set_x(tempx+1);
			q->Set_next(head);
			head = q;

			//尾部的处理
			while ((q->Get_next())->Get_next() != NULL)//找到最后
			{
				q = q->Get_next();
			}
			ed = q->Get_next();
			q->Set_next(NULL);


		}
		else//下一个是食物
		{
			//只需要头部的处理			
			q = new Snake();
			q->Set_y(tempy); q->Set_x(tempx+1);
			q->Set_next(head);
			head = q;

			food_exist = false;
			score += (difficult+1)*add;
		}
	}

}

