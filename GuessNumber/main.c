/*��д����ʵ��һ������������Ϸ���ɼ����������롱��һ���������Ӽ��������������в²⣬
����¶��ˣ�������������ϢWINNER��ѯ���Ƿ��ٲ�һ�Ρ�������´��ˣ������Ҳ������Ӧ
��ʾ�����������̫����̫С����ÿ�β�����Ҫ��¼���Է�ӳ�����ߵ�ˮƽ��������������10
�Ρ����10�ζ�δ���У��������Ϸ����ѯ���Ƿ��ٲ�һ�Ρ������������������Y�������N��
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
	printf("��Ϸ���ܣ�\n");
	printf("    ����Ϸ��Ϊ����ģʽ������ģʽ�ʹ���ģʽ��\n");
	printf("    ����ģʽ�����һ��ʼ�����Ѷ�ϵ��1��5������ѡ�񣬵�ͨ����5������ѡ��6��ͨ����6��\n");
	printf("����ѡ��7���Դ�����,����Ѷ�ϵ����9��ÿ����Ϸ�������ķ�Χ�ʹ������Ѷ�ϵ��nȷ������ \n");
	printf("��ΧΪ0~10^n,����Ϊ3*n+2,ֻҪ���˳���ɾ���浵�������һֱ����������ﵽ������Ѷȡ�\n");
	printf("    ����ģʽ������9���ؿ�����ͬ�Ĺؿ�����Ӧ�Ų�ͬ���Ѷ�ϵ�������һ��ʼ��15��Ѫ��ÿ\n");
	printf("�´�һ�Σ��ͻ��һ��Ѫ��Ѫ�������Ҽ�������������Զ����������֮ǰ������Ĺؿ� \n");
	printf("�͵���ùؿ�ʱ��Ѫ��������´�(�ڲ��˳������ɾ���浵��ǰ����)���Խ��Ÿùؿ��棬ÿ \n");
	printf("ͨ��һ���ؿ�����һ���ؿ��������������а�����ͨ���ؿ���֮�͵Ĺ��ɽ�����Ӧ��Ѫ������ \n");
	printf("�磬ͨ�����������1+2+3+4+5��Ѫ��ע�⣺����Ϸֻ��ͨ�����̲����������뾡��������ʾ\n");
	printf("���в��������������������Ѿ�����Ų�������Բ�����һЩϸС�����⣻����رպ� \n");
	printf("һ����Ϸ��¼���������ڡ�\n");
	system("pause");
	system("CLS");
delete_temp:
	level2 = 1;
	blood = 15;
	flag1 = 0;
	reward = 0;

start_page:
	printf("********************* �� ********* �� ******** �� ********* Ϸ *********************\n");
	printf("��ҳ>>>                                           ��D��/��d��ɾ���浵  Backspace�˳�\n");
	printf("                             ��ѡ����Ϸģʽ(������)��\n");//ģʽѡ��
	printf("                                   1.����ģʽ\n");
	printf("                                   2.����ģʽ\n");
choose_mod:
	mod = _getch();
restart:
	i = 1;
	switch (mod)
	{
		case '1'://����ģʽ
		{
			system("CLS");
			printf("**************************************��Ϸ��ʼ**************************************\n");
		game_start_1:
			printf("��ҳ>>>����ģʽ>>>                                                           esc����\n");
			printf("                              ��ѡ���Ѷ�ϵ��(������)��\n");
			printf("                     1.������  2.����  3.��  4.����  5.����  6.������\n");
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
			printf("                                     �Ѷ�ϵ����%d\n", level1);
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
							printf("                          ����Ѷ�ϵ��5�Խ��������Ѷ�ϵ����\n");
							printf("                                <�������������>");
							_getch();
							system("CLS");
							goto game_start_1;
							break;
						case 1:
							if (level1 == 6)
								break;
							else
							{
								printf("                              ��������Ѷ�ϵ��6����ս��\n");
								printf("                                 <�������������>");
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
								printf("                              ��������Ѷ�ϵ��7����ս��\n");
								printf("                                 <�������������>");
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
								printf("                              ��������Ѷ�ϵ��8����ս��\n");
								printf("                                 <�������������>");
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
								printf("                              ��������Ѷ�ϵ��9����ս��\n");
								printf("                                 <�������������>");
								_getch();
								system("CLS");
								goto game_start_1;
							}
							break;
						default:
							printf("                               �����Ѿ�û��ʲô������ս���ˣ�");
							printf("                                     <�������������>");
							_getch();
							system("CLS");
							goto game_start_1;
					}
			}
			RANGE = pow(10, level1);
			srand((unsigned int)time(NULL));
			a = rand() % (int)RANGE;
		input_1:
			printf("���������%2.d�βµ������֣�", i);
		input_4:
			gets_s(str, sizeof(char) * 100);
			if (strlen(str) == 0)
				goto input_4;
			for (j = 0; j < (int)strlen(str); j++)
				if (str[j] < '0' || str[j]>'9')
				{
					printf("                               �޷�ʶ�����������룡\n");
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
				printf("                               �޷�ʶ�����������룡\n");
				goto input_1;
			}*/
			if (a == b)
			{
				i = 1;
				if (level1 == 5 + flag1)
				{
					flag1++;
					printf("                                  ��ϲ�㣡��Ӯ�ˣ�\n");
					printf("                              �ɹ������Ѷ�ϵ��%d����ս��\n", 5 + flag1);
					printf("                                 <�������������>\n");
					_getch();
					system("CLS");
					goto game_start_1;
				}
				printf("                                   ��ϲ�㣡��Ӯ�ˣ�                                \n");
				printf("************************************ GAME  OVER ************************************\n");
				printf("                                  <�������������>\n");
				_getch();
				system("CLS");
				goto game_start_1;
			}
			else if (a > b)
				printf("̫С�ˣ�\n");
			else
				printf("̫���ˣ�\n");
			if (i == 3 * level1 + 2)
			{
				printf("                                ���Ѿ�����%d��δ����!\n", 3 * level1 + 2);
				printf("************************************ GAME  OVER ************************************\n");
				printf("                  <��ESC��������ҳ>              <��Enter������>\n");
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
		case '2'://����ģʽ
		{
			system("CLS");
			printf("**************************************��Ϸ��ʼ**************************************\n");
		game_start_2:
			printf("��ҳ>>>����ģʽ>>>\n");
			printf("                                      <��%d��>                          �Ѷ�ϵ����%d\n", level2, level2);
			printf("************************************************************************************\n");
			RANGE = pow(10, level2);
			srand((unsigned int)time(NULL));
			a = rand() % (int)RANGE;
		input_2:
			printf("���������%2.d�βµ������֣�", i);
		input_3:
			gets_s(str, sizeof(char) * 100);
			if (strlen(str) == 0)
				goto input_3;
			for (j = 0; j < (int)strlen(str); j++)
				if (str[j] < '0' || str[j]>'9')
				{
					printf("                               �޷�ʶ�����������룡\n");
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
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 ���С��ҩ����Ѫ��+%d", reward);
						break;
					case 2:
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 �������ҩ����Ѫ��+%d", reward);
						break;
					case 3:
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 ��ô���ҩ����Ѫ��+%d", reward);
						break;
					case 4:
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 ��ó���ҩ����Ѫ��+%d", reward);
						break;
					case 5:
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 ���Сƿʥˮ��Ѫ��+%d", reward);
						break;
					case 6:
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 �����ƿʥˮ��Ѫ��+%d", reward);
						break;
					case 7:
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 ��ô�ƿʥˮ��Ѫ��+%d", reward);
						break;
					case 8:
						printf("**************************************���سɹ���*************************************\n");
						printf("                                 ����޼�ʥˮ��Ѫ��+%d", reward);
						break;
					case 9:
						printf("**************************************���سɹ���*************************************\n");
						printf("                             ���Ѿ�����ͨ�������йؿ���\n");
						printf("                  <��ESC��������ҳ>              <��D����d��ɾ���浵�����¿�ʼ>\n");
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
				printf("                  ʣ��Ѫ����%d\n", blood);
				printf("                                ��ϲ�㣡�ɹ�������%d�ء�\n", level2);
				printf("                  <��ESC��������ҳ>              <��Enter������һ��>\n");
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
				printf("̫С�ˣ�");
			else
				printf("̫���ˣ�");
			blood--;
			i++;
			printf("�����һ��Ѫ��                                                 ʣ��Ѫ����%d\n", blood);
			if (blood <= 0)
			{
				printf("                                     ���Ѿ����ˣ�\n");
				printf("************************************ GAME  OVER ************************************\n");
				printf("    <��ESC��������ҳ>            <��Backspace���˳�>            <��Enter������˹�>\n");
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