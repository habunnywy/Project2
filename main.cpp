/**
̰���߹��ܺ���ʵ��
copyright��luye@nankai.edu.cn
modified by��huawangl@nankai.edu.cn
ʱ�䣺2020��5��7��
*/
/*
#include <syswait.h>
usleep(n) //n΢��
Sleep��n��//n����
sleep��n��//n��
*/
#include "Function.h"
char keep = 'Y';

int main()//������
{
	while (keep == 'Y' || keep == 'y') 
	{
		Start();
		Playing();//��Ϸ����ʱ	
		Die();
		
		cout << endl << "�Ƿ����¿�ʼ��  �� ����Y   �� ��������������˳���Ϸ";
		cout << endl <<endl<< "�����룺 ";
		cin >> keep;
	}
	return 0;
}