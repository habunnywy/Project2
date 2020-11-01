/**
贪吃蛇功能函数实现
copyright：luye@nankai.edu.cn
modified by：huawangl@nankai.edu.cn
时间：2020年5月7日
*/
/*
#include <syswait.h>
usleep(n) //n微秒
Sleep（n）//n毫秒
sleep（n）//n秒
*/
#include "Function.h"
char keep = 'Y';

int main()//主函数
{
	while (keep == 'Y' || keep == 'y') 
	{
		Start();
		Playing();//游戏进行时	
		Die();
		
		cout << endl << "是否重新开始？  是 输入Y   否 输入其它任意键退出游戏";
		cout << endl <<endl<< "请输入： ";
		cin >> keep;
	}
	return 0;
}