/**
̰���߹��ܺ���ʵ��
copyright��luye@nankai.edu.cn
modified by��huawangl@nankai.edu.cn
ʱ�䣺2020��5��7��
*/

#pragma once
#include"Snake.h"
#include<iostream>
#include<stdlib.h>//�漴�����Ͱ��������ͷ�ļ�
#include<time.h>//ʱ�亯��time���������ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include<windows.h>//HANDLE�ࣨ����ࣩ��COORD�ࣨ�����ࣩ���������ͷ�ļ�

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

/**
�������
*/
#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 3
extern int status;

extern const int window_width;
extern const int window_height;
extern const int adjust;
extern Snake *head,*food;//ȫ��ָ�룬head����Զָ���һ���ڵ��ָ�룬food��ָ��ʳ���ָ��
extern Snake *q;//�������������õ���ָ��
extern Snake *ed;
extern int condition;//����������������Ѱ�����������ֱ�������ֵ��������������Ҳ��int ����
extern int end_condition;//��ʾ�����������=1��ײǽ��=2��ҧ���Լ���=3���Լ�����;4 ײ���ϰ������
extern int score;
extern int add;//�÷ֺ�ÿ��ʳ��ķ���
extern COORD o[100];
extern bool food_exist;
extern int speed[3];
extern char player_ID[80];
extern int difficult;


inline void Green_color();//��������
inline void Red_color();//�����ú�
inline void Blue_color();
inline void Yellow_color();//�����û�
inline void Cyan_color();
inline void White_color();

void Set_location(int x, int y);//��λ����
void Creat_obs(COORD o[], int n);//�����ϰ���
void Print_obs(COORD o[]);
void Initial(int s_long);//��ʼ������
void Print_snake(Snake* s,const char* p);//��p��ӡ��
void creat_food();
void creatMap();//������ͼ
void pause();//��ͣ
void Start();//��ʼ
void Playing();//������Ϸ
void Die();//����




