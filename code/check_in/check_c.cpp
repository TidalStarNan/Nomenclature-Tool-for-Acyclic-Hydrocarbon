#include <iostream>

void notice();

void check_c(short position[100][4], short pointer[1][2])
{
	if (pointer[0][0] % 2 == 1 and pointer[0][1] == 0)
	{
		position[pointer[0][0]][2] = 2;
	}
	else
	{
		std::cout << "单键需位于两个碳之间\n";
		notice();
	}
}