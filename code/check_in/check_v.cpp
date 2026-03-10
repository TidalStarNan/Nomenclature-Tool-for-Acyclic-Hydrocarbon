#include <iostream>

void notice();

void check_v(short position[100][4], short& chain_length, short pointer[1][2])
{
	if (pointer[0][1] == 0)
	{
		if (pointer[0][0] % 2 == 1 and position[pointer[0][0] - 2][2] == 2 and position[pointer[0][0] + 2][2] == 2)
		{
			if ((position[pointer[0][0] - 1][1] != 0 and position[pointer[0][0] - 1][3] != 0) or (position[pointer[0][0] + 1][1] != 0 and position[pointer[0][0] + 1][3] != 0))
			{
				std::cout << "双键任意侧的碳原子上不能有两个取代基\n";
				notice();
			}
			else
			{
				position[pointer[0][0]][2] = 3;
			}
		}
		else if (pointer[0][0] == 1 and position[3][2] == 0)
		{
			position[1][2] = 3;
		}
		else if (pointer[0][0] == 1 and position[3][2] == 2)
		{
			if (position[2][1] != 0 and position[2][3] != 0)
			{
				std::cout << "双键右侧的碳原子上不能有两个取代基\n";
				notice();
			}
			else
			{
				position[1][2] = 3;
			}
		}
		else if (pointer[0][0] == chain_length * 2 - 3 and position[chain_length * 2 - 5][2] == 2)
		{
			if (position[chain_length * 2 - 4][1] != 0 and position[chain_length * 2 - 4][3] != 0)
			{
				std::cout << "双键左侧的碳原子上不能有两个取代基\n";
				notice();
			}
			else
			{
				position[chain_length * 2 - 3][2] = 3;
			}
		}
		else
		{
			std::cout << "双键需位于两个单键碳之间\n";
			notice();
		}
	}
	else
	{
		std::cout << "双键需位于两个单键碳之间\n";
		notice();
	}
}