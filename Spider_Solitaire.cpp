#include<iostream>
#include"Poker_Card.hpp"
#include<ctime>

using namespace std;

void show_Menu()
{
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "------------------- Welcome to the Spider Solitaire ----------------------" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	cout << "  Please make your choice��" << endl;
	cout << "---------------------------" << endl;
	cout << "-> 1.Play(key:1)" << endl;
	cout << "-> 2.Exit(key:2)" << endl;
	cout << "-> 3.Rank(key:3)" << endl;
	cout << "------------------------------" << endl;
	cout << "  And your alternation is : ";
	
}
//��ʾ����
void Display_Row(Poker_Card<int>*arr,int Deal,int F,int step)
{
	system("cls");
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "------------------- Welcome to the Spider Solitaire ----------------------" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "----"; arr[i].If_reserve(); arr[i].show_Yae(); cout << "\n" << endl;
	}
	cout << "->" << Deal << " * 10[]" << "       Step:" << step << "          Finish:" << F;
}

int* Play_Distribute()
{
	srand((unsigned)time(NULL));
	static int arr[104] = { 0 };
	for (int i = 1; i <= 13; i++)
	{
		int s = 8;
		while (s)
		{
			int temp = rand() % 104;
			if (arr[temp] == 0)
			{
				arr[temp] = i;
				s--;
			}
		}
	}
	return arr;
}
int main()
{
	int arr[10] = { 0 };
	int fg = 0;

	show_Menu();
	int Step = 0;
	int choice = 0;
	int Deal = 5;
	int Finish = 0;

	while (1)
	{
		cin >> choice;
		cout << "------------------------------" << endl;
		switch (choice)
		{
		case 1: {

			Poker_Card<int>* Tpoint = new Poker_Card<int>[10];

			Poker_Card<int>link1(0); Tpoint[0] = link1;
			Poker_Card<int>link2(0); Tpoint[1] = link2;
			Poker_Card<int>link3(0); Tpoint[2] = link3;
			Poker_Card<int>link4(0); Tpoint[3] = link4;
			Poker_Card<int>link5(0); Tpoint[4] = link5;
			Poker_Card<int>link6(0); Tpoint[5] = link6;
			Poker_Card<int>link7(0); Tpoint[6] = link7;
			Poker_Card<int>link8(0); Tpoint[7] = link8;
			Poker_Card<int>link9(0); Tpoint[8] = link9;
			Poker_Card<int>link10(0); Tpoint[9] = link10;

			int* arr = Play_Distribute();

			int T = 10; int S = 0;
			while (T)
			{
				for (int i = 0; i < 10; i++)
				{
					if (S > 53) break;
					Tpoint[i].Push_back_C1(arr[S]);
					S++;
				}
				T--;
			}

			while (1)
			{
				Display_Row(Tpoint, Deal, Finish, Step);
				cout << "\n  Your alternation is (1.Move 2.Deal): ";

				int swift = 0;
				cin >> swift;
				switch (swift)
				{
				case 1: {
					int from = 0; int to = 0;
					int Num = 0;

					cout << "  Move from : "; cin >> from;
					if (from < 1 || from > 10)
					{
						cout << "  Your operation is illegal(the 'from' isn't in a legal range)\n";
						system("pause");
						break;
					}
					cout << "\tNumber(Max:" << Tpoint[from - 1].Move_Able() << "):"; cin >> Num;

					cout << "  Move to : "; cin >> to;
					if (to < 1 || to > 10)
					{
						cout << "  Your operation is illegal(the 'to' isn't in a legal range)\n";
						system("pause");
						break;
					}

					Tpoint[to - 1].Push_back_P(Tpoint[from - 1], Num, Finish, Step);

					break;
				}
				case 2: {
					if (Deal == 0)
					{
						cout << "\n  There is no chance to Deal\n";
						system("pause");
						break;
					}
					int G = 0;
					for (int i = 0; i < 10; i++)
					{
						if (Tpoint[i].Ret_Length() != 0)
						{
							G++;
						}
					}
					if (G != 10)
					{
						cout << "  Your operation is illegal(There are more than one empty states)";
						system("pause");
						break;
					}
					int s = 0;
					for (int t = 104 - 10 * Deal; t < 114 - 10 * Deal; t++)
					{
						Tpoint[s].Push_back_C2(arr[t], Finish);
						s++;
					}
					Deal--;
					break;
				}
				}
				if (Finish == 8)
				{
					cout << "You have finished,the game is over" << endl;
					system("pause");
					return 0;
				}
			}
			break;
		};
		case 2: {
			return 0;
			break;
		}
		case 3: {

		}
		}
	}
	system("pause");
	return 0;
}