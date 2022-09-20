#pragma once
#include<iostream>
#include<string.h>

using namespace std;

char out_char(int num)
{
	switch (num)
	{
	case 1:return 'A'; break;
	case 11:return 'J'; break;
	case 12:return 'Q'; break;
	case 13:return 'K'; break;
	default: return ' '; break;
	}
}
template<class T>

class Poker_Card {
public:

	Poker_Card()
	{
		
	}

	Poker_Card(int hide_num)
	{
		this->hide_card = hide_num;
		this->paddress = new T[104];
		this->show_card = 0;
	}

	int Ret_Length()
	{
		return this->hide_card + this->show_card;
	}

	void show_Yae()
	{
		/*cout << this->show_card + this->hide_card << endl;*/

		cout << "(" << this->hide_card << ")  ";

		for (int i = this->hide_card;i < this->show_card + this->hide_card;i++)
		{
			if (this->paddress[i] == 1 || this->paddress[i] == 11
				|| this->paddress[i] == 12 || this->paddress[i] == 13)
			{
				cout << out_char(this->paddress[i]) << "  ";
			}
			else
			{
				cout << this->paddress[i] << "  ";
			}
		}
	}
	void Push_back_P(Poker_Card<int>& Pk, int Num, int& F,int& step)
	{
		if (Num > Pk.Move_Able())
		{
			cout << "  Your operation is illegal(Your cannot move more than "
				<< Pk.Move_Able() << " cards";
			system("pause");
			return;
		}
		if (this->Ret_Length() == 0)
		{
			for (int i = 0; i < Num; i++)
			{
				this->paddress[i] = Pk.paddress[Pk.Ret_Length() - Num + i];
			}
			this->show_card += Num;
			Pk.show_card -= Num;
			step++;
		}
		else
		{	//�����ǿ�λ�����ж�
			if (Pk.paddress[Pk.Ret_Length() - Num] >= this->paddress[this->Ret_Length() - 1])
			{
				cout << "  Your operation is illegal(The card you want to insert is larger than the bottom)";
				system("pause");
				return;
			}
			for (int i = 0; i < Num; i++)
			{
				this->paddress[this->Ret_Length() + i] = Pk.paddress[Pk.Ret_Length() - Num + i];
			}
			this->show_card += Num;
			Pk.show_card -= Num;
			step++;
		}

		if (this->show_card >= 13)

		{
			int fulled_time = 0;
			for (int i = 1; i < 13; i++)
			{
				if (this->paddress[this->show_card + this->hide_card - i - 1]
					- this->paddress[this->show_card + this->hide_card - i] == 1)
				{
					fulled_time++;
				}
			}
			if (fulled_time == 12)
			{
				this->show_card -= 13;
				F++;
				this->If_reserve();
			}
		}
	}

	void Push_back_C1(int val)
	{
		this->paddress[this->show_card + this->hide_card] = val;
		this->hide_card++;
	}

	void Push_back_C2(int val,int&F)
	{
		this->paddress[this->show_card + this->hide_card] = val;
		this->show_card++;

		if (this->show_card >= 13)

		{
			int fulled_time = 0;
			for (int i = 1; i < 13; i++)
			{
				if (this->paddress[this->show_card + this->hide_card - i - 1]
					- this->paddress[this->show_card + this->hide_card - i] == 1)
				{
					fulled_time++;
				}
			}
			if (fulled_time == 12)
			{
				this->show_card -= 13;
				F++;
				this->If_reserve();
			}
		}
	}

	int Pop_back()
	{
		if ((this->show_card + this->hide_card) == 0)
		{
			cout << "There is empty" << endl;
			return 0;
		}
		else
		{
			this->show_card--;
			this->If_reserve();
		}
		return 0;
	}
	void Pop_back_P(Poker_Card<int>Pk,int Num)
	{
		
		if ((this->show_card + this->hide_card) == 0)
		{
			cout << "There is empty" << endl;
			return;
		}
	
		this->show_card -= Num;
		this->If_reserve();
		
		return;
	}

	void If_reserve()
	{
		if (this->show_card == 0 && this->hide_card > 0)
		{
			this->show_card++;
			this->hide_card--;
		}
	}

	int Bottom()
	{
		return this->paddress[this->hide_card + this->show_card - 1];
	}

	int Move_Able()
	{
		int Max = 1;
		int L = this->hide_card + this->show_card;
		while (L - 1 - this->hide_card)
		{
			if (this->paddress[L - 2] - this->paddress[L - 1] != 1)
			{
				break;
			}
			Max++;
			L--;
		}
		return Max;
	}

private:
	T* paddress;
	int show_card;
	int hide_card;
};