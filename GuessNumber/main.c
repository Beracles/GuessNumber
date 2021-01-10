/*编写程序，实现一个“猜数”游戏：由计算机随机“想”出一个整数，从键盘输入整数进行猜测，
如果猜对了，则计算机给出信息WINNER并询问是否“再猜一次”？如果猜错了，计算机也给出相应
提示：输入的数是太大还是太小，对每次猜数都要记录，以反映猜数者的水平。最多可以连续猜10
次。如果10次都未猜中，则结束游戏，并询问是否“再猜一次”？如果想继续，则键入Y否则键入N。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<conio.h>
void main()
{
	int a, b, i, j, level2, level1, blood, flag1, reward;
	double RANGE;
	char ch, mod, str[100];
	printf("游戏介绍：\n");
	printf("    此游戏分为两个模式：自由模式和闯关模式。\n");
	printf("    自由模式：玩家一开始可在难度系数1至5中任意选择，当通过了5，就能选择6，通过了6，\n");
	printf("就能选择7，以此类推,最高难度系数是9，每次游戏所猜数的范围和次数由难度系数n确定，即 \n");
	printf("范围为0~10^n,次数为3*n+2,只要不退出或删除存档，程序会一直保存玩家所达到的最高难度。\n");
	printf("    闯关模式：共有9个关卡，不同的关卡即对应着不同的难度系数，玩家一开始有15滴血，每\n");
	printf("猜错一次，就会掉一滴血，血掉光后，玩家即死亡，程序会自动保存玩家死之前所到达的关卡 \n");
	printf("和到达该关卡时的血量，玩家下次(在不退出程序或删除存档的前提下)可以接着该关卡玩，每 \n");
	printf("通过一个关卡，下一个关卡即解锁，并且有按照所通过关卡号之和的规律奖励相应的血量，例 \n");
	printf("如，通过第五关则奖励1+2+3+4+5滴血。注意：此游戏只能通过键盘操作，并且请尽量按照提示\n");
	printf("进行操作，以免程序出错，尽管已经多次排查过，担仍不免有一些细小的问题；程序关闭后， \n");
	printf("一切游戏记录将不复存在。\n");
	system("pause");
	system("CLS");
delete_temp:
	level2 = 1;
	blood = 15;
	flag1 = 0;
	reward = 0;

start_page:
	printf("********************* 猜 ********* 数 ******** 游 ********* 戏 *********************\n");
	printf("首页>>>                                           “D”/“d”删除存档  Backspace退出\n");
	printf("                             请选择游戏模式(输入标号)：\n");//模式选择
	printf("                                   1.自由模式\n");
	printf("                                   2.闯关模式\n");
choose_mod:
	mod = _getch();
restart:
	i = 1;
	switch (mod)
	{
		case '1'://自由模式
		{
			system("CLS");
			printf("**************************************游戏开始**************************************\n");
		game_start_1:
			printf("首页>>>自由模式>>>                                                           esc返回\n");
			printf("                              请选择难度系数(输入标号)：\n");
			printf("                     1.很容易  2.容易  3.难  4.较难  5.很难  6.···\n");
		choose_level:
			ch = _getch();
			if (ch == 27)
			{
				system("CLS");
				goto start_page;
			}
			else
				level1 = ch - '0';
			if (level1 <= 0 || level1 > 9)
				goto choose_level;
			printf("                                     难度系数：%d\n", level1);
			printf("************************************************************************************\n");
			switch (level1)
			{
				case 1:break;
				case 2:break;
				case 3:break;
				case 4:break;
				case 5:break;
				default:
					switch (flag1)
					{
						case 0:
							printf("                          完成难度系数5以解锁更高难度系数。\n");
							printf("                                <“任意键”返回>");
							_getch();
							system("CLS");
							goto game_start_1;
							break;
						case 1:
							if (level1 == 6)
								break;
							else
							{
								printf("                              请先完成难度系数6的挑战！\n");
								printf("                                 <“任意键”返回>");
								_getch();
								system("CLS");
								goto game_start_1;
							}
							break;
						case 2:
							if (level1 == 6 || level1 == 7)
								break;
							else
							{
								printf("                              请先完成难度系数7的挑战！\n");
								printf("                                 <“任意键”返回>");
								_getch();
								system("CLS");
								goto game_start_1;
							}
							break;
						case 3:
							if (level1 == 6 || level1 == 7 || level1 == 8)
								break;
							else
							{
								printf("                              请先完成难度系数8的挑战！\n");
								printf("                                 <“任意键”返回>");
								_getch();
								system("CLS");
								goto game_start_1;
							}
							break;
						case 4:
							if (level1 == 6 || level1 == 7 || level1 == 8 || level1 == 9)
								break;
							else
							{
								printf("                              请先完成难度系数9的挑战！\n");
								printf("                                 <“任意键”返回>");
								_getch();
								system("CLS");
								goto game_start_1;
							}
							break;
						default:
							printf("                               这里已经没有什么可以挑战的了！");
							printf("                                     <“任意键”返回>");
							_getch();
							system("CLS");
							goto game_start_1;
					}
			}
			RANGE = pow(10, level1);
			srand((unsigned int)time(NULL));
			a = rand() % (int)RANGE;
		input_1:
			printf("请输入你第%2.d次猜到的数字：", i);
		input_4:
			gets_s(str, sizeof(char) * 100);
			if (strlen(str) == 0)
				goto input_4;
			for (j = 0; j < (int)strlen(str); j++)
				if (str[j] < '0' || str[j]>'9')
				{
					printf("                               无法识别！请重新输入！\n");
					goto input_1;
				}
			b = 0;
			for (j = strlen(str) - 1; j >= 0; j--)
				b += (str[strlen(str) - j - 1] - '0') * (int)pow(10, j);
			/*setbuf(stdin, NULL);
			scanf_s("%d", &b);
			setbuf(stdin, NULL);
			if (b < 0)
			{
				printf("                               无法识别！请重新输入！\n");
				goto input_1;
			}*/
			if (a == b)
			{
				i = 1;
				if (level1 == 5 + flag1)
				{
					flag1++;
					printf("                                  恭喜你！你赢了！\n");
					printf("                              成功解锁难度系数%d的挑战。\n", 5 + flag1);
					printf("                                 <“任意键”继续>\n");
					_getch();
					system("CLS");
					goto game_start_1;
				}
				printf("                                   恭喜你！你赢了！                                \n");
				printf("************************************ GAME  OVER ************************************\n");
				printf("                                  <“任意键”继续>\n");
				_getch();
				system("CLS");
				goto game_start_1;
			}
			else if (a > b)
				printf("太小了！\n");
			else
				printf("太大了！\n");
			if (i == 3 * level1 + 2)
			{
				printf("                                你已经连续%d次未猜中!\n", 3 * level1 + 2);
				printf("************************************ GAME  OVER ************************************\n");
				printf("                  <“ESC”返回首页>              <“Enter”继续>\n");
			restrict_input_1:
				ch = _getch();
				if (ch == 27)
				{
					system("CLS");
					goto start_page;
				}
				else if (ch == 13)
					goto restart;
				else
					goto restrict_input_1;
			}
			i++;
			goto input_1;
			break;
		}
		case '2'://闯关模式
		{
			system("CLS");
			printf("**************************************游戏开始**************************************\n");
		game_start_2:
			printf("首页>>>闯关模式>>>\n");
			printf("                                      <第%d关>                          难度系数：%d\n", level2, level2);
			printf("************************************************************************************\n");
			RANGE = pow(10, level2);
			srand((unsigned int)time(NULL));
			a = rand() % (int)RANGE;
		input_2:
			printf("请输入你第%2.d次猜到的数字：", i);
		input_3:
			gets_s(str, sizeof(char) * 100);
			if (strlen(str) == 0)
				goto input_3;
			for (j = 0; j < (int)strlen(str); j++)
				if (str[j] < '0' || str[j]>'9')
				{
					printf("                               无法识别！请重新输入！\n");
					goto input_2;
				}
			b = 0;
			for (j = strlen(str) - 1; j >= 0; j--)
				b += (str[strlen(str) - j - 1] - '0') * (int)pow(10, j);
			if (a == b)
			{
				reward += level2;
				switch (level2)
				{
					case 1:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得小型药剂，血量+%d", reward);
						break;
					case 2:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得中型药剂，血量+%d", reward);
						break;
					case 3:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得大型药剂，血量+%d", reward);
						break;
					case 4:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得超大药剂，血量+%d", reward);
						break;
					case 5:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得小瓶圣水，血量+%d", reward);
						break;
					case 6:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得中瓶圣水，血量+%d", reward);
						break;
					case 7:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得大瓶圣水，血量+%d", reward);
						break;
					case 8:
						printf("**************************************闯关成功！*************************************\n");
						printf("                                 获得无极圣水，血量+%d", reward);
						break;
					case 9:
						printf("**************************************闯关成功！*************************************\n");
						printf("                             你已经超神！通过了所有关卡。\n");
						printf("                  <“ESC”返回首页>              <“D”或“d”删除存档，重新开始>\n");
					restrict_input_2:
						ch = _getch();
						if (ch == 27)
						{
							system("CLS");
							goto start_page;
						}
						else if (ch == 'D' || ch == 'd')
						{
							level2 = 1;
							blood = 15;
							reward = 0;
							goto restart;
						}
						else
							goto restrict_input_2;
						break;
				}
				i = 1;
				level2++;
				blood += reward;
				printf("                  剩余血量：%d\n", blood);
				printf("                                恭喜你！成功解锁第%d关。\n", level2);
				printf("                  <“ESC”返回首页>              <“Enter”→下一关>\n");
			restrict_input_3:
				ch = _getch();
				if (ch == 27)
				{
					system("CLS");
					goto start_page;
				}
				else if (ch == 13)
				{
					system("CLS");
					goto game_start_2;
				}
				else
					goto restrict_input_3;
			}
			else if (a > b)
				printf("太小了！");
			else
				printf("太大了！");
			blood--;
			i++;
			printf("你掉了一滴血！                                                 剩余血量：%d\n", blood);
			if (blood <= 0)
			{
				printf("                                     你已经死了！\n");
				printf("************************************ GAME  OVER ************************************\n");
				printf("    <“ESC”返回首页>            <“Backspace”退出>            <“Enter”重玩此关>\n");
				blood = i - 1;
				i = 1;
			restrict_input_4:
				ch = _getch();
				if (ch == 8)
					goto end;
				else if (ch == 27)
				{
					system("CLS");
					goto start_page;
				}
				else if (ch == 13)
				{
					system("CLS");
					goto game_start_2;
				}
				else
					goto restrict_input_4;
			}
			goto input_2;
			break;
		}
		case 8:
			goto end;
			break;
		case 'D':
			system("CLS");
			goto delete_temp;
		case 'd':
			system("CLS");
			goto delete_temp;
		default:
			goto choose_mod;
	}
end:;
}