/**
̰���߹��ܺ���ʵ��
copyright��luye@nankai.edu.cn
modified by��huawangl@nankai.edu.cn
ʱ�䣺2020��5��7��
*/

#pragma once

class Snake//���࣬�������ߵĻ���Ԫ�غ��ߵ����л�����������������ɵ�
{
public://����û��д���캯����ͬѧ�ǿ��Ը�����Ҫ��д����Ҫע��ָ��ָ��ʱ��������
	Snake(int x=0,int y=0) 
	{
		Set_x(x); Set_y(y);
	}
	//��Ԫ�������ò������ԣ�����ͨ��Set���������ͬѧ��˼�����ʵ��
	friend void creat_food();//����ʳ��ĺ���
	friend void Initial(int s_long); //��ʼ����������ʼ���ߵ�����ĳ�ʼ���ȣ��Լ�����λ��
	friend void Print_snake(Snake* s,const char* p);//����	
	void Set_x(int x);
	void Set_y(int y);
	int Get_x();
	int Get_y();
	
	
	void Set_next(Snake* s);
	Snake *Get_next();
	
	void Bite_self();//�ж��Ƿ�ҧ���Լ�
	void Can_not_crowall();//���ܴ�ǽ����������ǽ����
	void Can_not_croblock();//�������ϰ�

	void Move();//�ߵ��ƶ�
	
private:
	int s_x;//�ߵ�x��y����
	int s_y;
	
	Snake *next;//ʹ��������ɣ����������򣬴�ź�x��y���ꡣһ��ָ���򣬴�����Ӻ�������ڵ�ĵ�ַ
	
	
};


/*
struct Obstacle//�ϰ���ṹ�壬�ڲ���x��y������
{
	int x;//�ϰ���ĺ�������
	int y;
};
*/

