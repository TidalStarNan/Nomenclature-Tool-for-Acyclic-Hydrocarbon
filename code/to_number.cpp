#include <iostream>
#include <string>

void to_chinese_num(short number)
{
	const char* chinese_ones[] = { "", "一", "二", "三", "四", "五", "六", "七", "八", "九" };
	const char* chinese_tens[] = { "", "十", "二十", "三十", "四十", "五十", "六十", "七十", "八十", "九十" };

	if (number <= 0 || number >= 100 )
	{
		std::string error = "中文数字位置编号错误\n错误值：" + std::to_string(number);
		throw std::out_of_range(error);
	}
	else
	{
		if (number < 10)
		{
			std::cout << chinese_ones[number];
			return;
		}
		else
		{
			short tens = number / 10;
			short ones = number % 10;

			std::cout << chinese_tens[tens] << chinese_ones[ones];
		}
	}
}

void to_heavenly_stems_num(short number)
{
	const char* heavenly_stems_nums[] = { "", "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};

	if (number <= 0 || number >= 100)
	{
		std::string error = "天干数字位置编号错误\n错误值：" + std::to_string(number);
		throw std::out_of_range(error);
	}
	else
	{
		if (number <= 10)
		{
			std::cout << heavenly_stems_nums[number];
		}
		else
		{
			to_chinese_num(number);
		}
	}
}