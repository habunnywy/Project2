/**
̰���߹��ܺ���ʵ��
copyright��luye@nankai.edu.cn
modified by��huawangl@nankai.edu.cn
ʱ�䣺2020��5��7��
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
void Snake::transmit_direction()//���򴫵ݺ���
{
	q=Get_next();
	while(q!=NULL)
	{
		q->Set_direciton(Get_direction());//��һ��������һ��
		q = Get_next();
	}
	
}
*/

void Snake::Bite_self()//����Ƿ�ҧ���Լ�,���Ǽ��ͷ�ڵ��Ƿ������������κ�һ���ڵ�����
{
	int x0 = Get_x(); int y0 = Get_y();
	q = Get_next();
	while (q != NULL)
	{
		if (q->Get_x() == x0 && q->Get_y() == y0) { end_condition = 2; return; }
		q = q->Get_next();
	}
	
}

void Snake::Can_not_crowall()//������ǽ��ײ
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


void Snake::Move()//���ƶ��ĺ���
{
	int tempx, tempy;
	tempx = Get_x(), tempy = Get_y();//�߱仯ǰ������
	if(status==UP)
	{
		if ((tempy - 1 != food->Get_y()) || (tempx != food->Get_x()))//��һ������ʳ��
		{
			//ͷ���Ĵ���			
			q = new Snake();				
			q->Set_y(tempy - 1); q->Set_x(tempx);
			q->Set_next(head);
			head = q;

			//β���Ĵ���
			while ((q->Get_next())->Get_next()!=NULL)//�ҵ������ڶ�������Ϊ���һ������Ҫ������
			{
				q = q->Get_next();
			}
			ed=q->Get_next();
			q->Set_next(NULL);


		}
		else//��һ����ʳ��
		{
			//ֻ��Ҫͷ���Ĵ���			
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
		if ((tempy + 1 != food->Get_y()) || (tempx != food->Get_x()))//��һ������ʳ��
		{
			//ͷ���Ĵ���			
			q = new Snake();
			q->Set_y(tempy + 1); q->Set_x(tempx);
			q->Set_next(head);
			head = q;

			//β���Ĵ���
			while ((q->Get_next())->Get_next() != NULL)//�ҵ����
			{
				q = q->Get_next();
			}
			ed = q->Get_next();
			q->Set_next(NULL);


		}
		else//��һ����ʳ��
		{
			//ֻ��Ҫͷ���Ĵ���			
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
		if ((tempy  != food->Get_y()) || (tempx-1 != food->Get_x()))//��һ������ʳ��
		{
			//ͷ���Ĵ���			
			q = new Snake();
			q->Set_y(tempy); q->Set_x(tempx-1);
			q->Set_next(head);
			head = q;

			//β���Ĵ���
			while ((q->Get_next())->Get_next() != NULL)//�ҵ����
			{
				q = q->Get_next();
			}
			ed = q->Get_next();
			q->Set_next(NULL);


		}
		else//��һ����ʳ��
		{
			//ֻ��Ҫͷ���Ĵ���			
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
		if ((tempy != food->Get_y()) || (tempx+1 != food->Get_x()))//��һ������ʳ��
		{
			//ͷ���Ĵ���			
			q = new Snake();
			q->Set_y(tempy); q->Set_x(tempx+1);
			q->Set_next(head);
			head = q;

			//β���Ĵ���
			while ((q->Get_next())->Get_next() != NULL)//�ҵ����
			{
				q = q->Get_next();
			}
			ed = q->Get_next();
			q->Set_next(NULL);


		}
		else//��һ����ʳ��
		{
			//ֻ��Ҫͷ���Ĵ���			
			q = new Snake();
			q->Set_y(tempy); q->Set_x(tempx+1);
			q->Set_next(head);
			head = q;

			food_exist = false;
			score += (difficult+1)*add;
		}
	}

}

