#include <iostream>

void notice();

void check_q(short position[100][4], short pointer[1][2])
{
	if (pointer[0][1] == 1 or pointer[0][1] == -1)
	{
		if (pointer[0][0] % 2 == 0)
		{
			position[pointer[0][0]][pointer[0][1] + 2] = 0;
		}
	}
	else
	{
		std::cout << "你只能删除取代基 QAQ\n";
		notice();
	}
}