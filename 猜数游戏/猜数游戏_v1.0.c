/*编写程序，实现一个“猜数”游戏：由计算机随机“想”出一个整数，从键盘输入整数进行猜测，
如果猜对了，则计算机给出信息WINNER并询问是否“再猜一次”？如果猜错了，计算机也给出相应
提示：输入的数是太大还是太小，对每次猜数都要记录，以反映猜数者的水平。最多可以连续猜10
次。如果10次都未猜中，则结束游戏，并询问是否“再猜一次”？如果想继续，则键入Y否则键入N。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<conio.h>
void main()
{
	int a, b, i, blood=30;
	double RANGE, level;
	char ch, mod;
	printf("******************** 猜 ********* 数 ******** 游 ********* 戏 ********************\n");

start_page:
	printf("首页>>>                                                                    esc退出\n");
module_choose:
	printf("                       请选择游戏模式(输入标号)：\n");//模式选择
	printf("                             1.自由模式\n");
	printf("                             2.闯关模式\n");
	mod = _getch();
	_getch();
	switch (mod)
	{
	case '1':goto free_module;
		break;
	case '2':level = 1;
		goto chapter;
		break;
	case 27:goto end;
		break;
	default:
		printf("没有其他模式了，先玩着这俩吧！\n");
		goto module_choose;
	}

	printf("***************游戏开始****************\n");
free_module://自由模式
	if (mod == '1') 
	{
		printf("首页>>>自由模式>>>\n");
		printf("                             请选择难度系数(输入标号)：\n");
		printf("                      1.很容易  2.容易  3.难  4.较难  5.很难\n");
		printf("难度系数：");
		scanf_s("%lf", &level);
		switch((int)level)
		{
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		case 5:break;
		default:printf("以为自己很厉害是吧！那就先来个最难的。");
			level = 5;
		}
	}

chapter://闯关模式
	i = 0;
	if (mod == '2')
		printf("首页>>>闯关模式>>>                 <第%.lf关>                             难度系数：%.lf\n", level,level);
	RANGE = pow(10, level);
	srand((unsigned int)time(NULL));
	a = rand() % (int)RANGE;
loop:
	if (i == 0)
		printf("请输入你猜到的数字：");
	else
		printf("请输入你第%d次猜到的数字：",i+1);
	for(;;)
	{
		_flushall();
		scanf_s("%d", &b);
		if (b <= 0)
		{
			printf("亲！你按错键了，请输入正整数：");
			_flushall();
			scanf_s("%d", &b);
		}
		else
			break;
	}
	if (a == b)
	{
		if (mod == '1')
		{
			printf("***************WINNER***************\n");
			printf("*************GAME  OVER*************\n");
			printf("按“ESC”键返回首页，按“N”或“n”键退出游戏，按其他键继续当前模式。\n");
			ch = _getch();
			_getch();
			if (ch == 'N' || ch == 'n')
				goto end;
			else if (ch == 27)
				goto start_page;
			else
				goto free_module;
		}
		if (mod == '2')
		{
			switch((int)level)
			{
			case 1:printf("闯关成功！获得小型药剂，血量+%.lf", 2 * level - 1);
				break;
			case 2:printf("闯关成功！获得中型药剂，血量+%.lf", 2 * level - 1);
				break;
			case 3:printf("闯关成功！获得大型药剂，血量+%.lf", 2 * level - 1);
				break;
			case 4:printf("闯关成功！获得巨型药剂，血量+%.lf", 2 * level - 1);
				break;
			case 5:
				printf("恭喜您成功通关，正式授予您“大神”的称号！\n继续向着太阳前进吧！\n");
				printf("<“ESC”返回首页>    <“N”或“n”退出>    <其他键继续当前模式>\n");
				ch = _getch();
				_getch();
				if (ch == 'N' || ch == 'n')
					goto end;
				else if (ch == 27)
					goto start_page;
				else
				{
					level = 1;
					goto chapter;
				}
				break;
			}
			blood += (int)(2 * level - 1);
			printf("剩余血量：%d\n", blood);
			level++;
			printf("按任意键进入下一关\n");
			_getch();
			_getch();
			goto chapter;
		}
	}
	if (mod == '2')
	{
		if (a > b)
			printf("太小了！");
		else
			printf("太大了！");
		blood--;
		printf("你掉了一滴血！");
		printf("剩余血量：%d\n", blood);
		if (blood == 0)
		{
			printf("你已经死了。\n");
			printf("*************GAME  OVER*************\n");
			printf("按“ESC”键返回首页，按“N”或“n”键退出游戏，按其他键继续当前模式。\n");
			ch = _getch();
			_getch();
			if (ch == 'N' || ch == 'n')
				goto end;
			else if (ch == 27)
				goto start_page;
			else
			{
				level = 1;
				goto chapter;
			}
		}
	}
	else if (a > b)
		printf("太小了！\n");
	else
		printf("太大了！\n");
	i++;
	if (i == 10 && mod=='1')
	{
		printf("你已经连续10次未猜中!\n");
		printf("*************GAME  OVER*************\n");
		printf("按“ESC”键返回首页，按“N”或“n”键退出游戏，按其他键继续当前模式，\n");
		ch = _getch();
		_getch();
		if (ch == 'N' || ch == 'n')
			goto end;
		else if (ch == 27)
			goto start_page;
		else
			goto free_module;
	}
	goto loop;
end:;
}