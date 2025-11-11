#include <iostream>
#include <string>

void to_chinese(short number)
{
	if (number > 0 and number < 11)
	{
		switch (number)
		{
		case 1:
			std::cout << "甲";
			break;
		case 2:
			std::cout << "乙";
			break;
		case 3:
			std::cout << "丙";
			break;
		case 4:
			std::cout << "丁";
			break;
		case 5:
			std::cout << "戊";
			break;
		case 6:
			std::cout << "己";
			break;
		case 7:
			std::cout << "庚";
			break;
		case 8:
			std::cout << "辛";
			break;
		case 9:
			std::cout << "壬";
			break;
		case 10:
			std::cout << "癸";
			break;
		default:
			std::cout << "";
			break;
		}
	}
	else if (number > 10)
	{
		short tens = number / 10;
		short units = number % 10;
		std::string result = "";

		if (tens == 1)
		{
			std::cout << "十";
		}
		else
		{
			switch (tens)
			{
			case 2:
				std::cout << "二十";
				break;
			case 3:
				std::cout << "三十";
				break;
			case 4:
				std::cout << "四十";
				break;
			case 5:
				std::cout << "五十";
				break;
			case 6:
				std::cout << "六十";
				break;
			case 7:
				std::cout << "七十";
				break;
			case 8:
				std::cout << "八十";
				break;
			case 9:
				std::cout << "九十";
				break;
			default:
				break;
			}
		}

		switch (units)
		{
		case 1:
			std::cout << "一";
			break;
		case 2:
			std::cout << "二";
			break;
		case 3:
			std::cout << "三";
			break;
		case 4:
			std::cout << "四";
			break;
		case 5:
			std::cout << "五";
			break;
		case 6:
			std::cout << "六";
			break;
		case 7:
			std::cout << "七";
			break;
		case 8:
			std::cout << "八";
			break;
		case 9:
			std::cout << "九";
			break;
		default:
			break;
		}
	}
}
