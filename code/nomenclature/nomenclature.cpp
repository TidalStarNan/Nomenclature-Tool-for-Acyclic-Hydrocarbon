#include <iostream>

void to_chinese_num(short num);
void to_heavenly_stems_num(short num);
void to_halogen_num(short num);

//{ "¡¡", "Ì¼", "Ò»", "¶þ", "Èý", "£¿", "¼×", "ÒÒ", "±û", "¶¡", "Îì", "¼º", "¸ý", "ÐÁ", "ÈÉ", "ôÇ", "°±", "·ú", "ÂÈ", "äå", "µâ", "Ïõ" };
//     0    1    2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21

void nomenclature(short position[100][4], short chain_length)
{
	bool from_left = true;
	short left = 0;
	short right = 0;

	bool has_oh = false;
	short oh_count = 0;
	short oh_positions[100]{};

	bool has_nh2 = false;
	short nh2_count = 0;
	short nh2_positions[100]{};

	bool has_double_bond = false;
	short double_bond_count = 0;
	short double_bond_positions[100]{};

	bool has_triple_bond = false;
	short triple_bond_count = 0;
	short triple_bond_positions[100]{};

	bool has_halogen = false;
	short halogen_count = 0;
	short halogen_positions[100]{};

	bool has_no2 = false;
	short no2_count = 0;
	short no2_positions[100]{};

	bool has_alkyl = false;
	short alkyl_count = 0;
	short alkyl_positions[100]{};

	for (short x = 0; x < chain_length * 2 -1; x++)
	{
		if (position[x][1] == 15 or position[x][3] == 15)
		{
			has_oh = true;
			oh_positions[oh_count] = x / 2 + 1;
			oh_count++;
		}
		if (position[x][1] == 16 or position[x][3] == 16)
		{
			has_nh2 = true;
			nh2_positions[nh2_count] = x / 2 + 1;
			nh2_count++;
		}
		if (position[x][2] == 3)
		{
			has_double_bond = true;
			double_bond_positions[double_bond_count] = (x + 1) / 2;
			double_bond_count++;
		}
		if (position[x][2] == 4)
		{
			has_triple_bond = true;
			triple_bond_positions[triple_bond_count] = (x + 1) / 2;
			triple_bond_count++;
		}
		if ((position[x][1] >= 17 and position[x][1] <= 20) or (position[x][3] >= 17 and position[x][3] <= 20))
		{
			has_halogen = true;
		}
		if (position[x][1] == 21 or position[x][3] == 21)
		{
			has_no2 = true;
			no2_positions[no2_count] = x / 2 + 1;
			no2_count++;
		}
		if ((position[x][1] >= 6 and position[x][1] <= 14) or (position[x][3] >= 6 and position[x][3] <= 14))
		{
			has_alkyl = true;
		}
	}

	if (has_oh == true)
	{
		if (oh_positions[0] < chain_length - oh_positions[oh_count - 1] + 1)
		{
			from_left = true;
			goto name_part;
		}
		else if (oh_positions[0] > chain_length - oh_positions[oh_count - 1] + 1)
		{
			from_left = false;
			goto name_part;
		}
		else
		{
			for (short i = 0; i < oh_count; i++)
			{
				left += oh_positions[i];
				right += chain_length - oh_positions[i] + 1;
			}
			if (left < right)
			{
				from_left = true;
				left = 0;
				right = 0;
				goto name_part;
			}
			else if (left > right)
			{
				from_left = false;
				left = 0;
				right = 0;
				goto name_part;
			}
		}
	}

	if (has_nh2 == true)
	{
		if (nh2_positions[0] < chain_length - nh2_positions[nh2_count - 1] + 1)
		{
			from_left = true;
			goto name_part;
		}
		else if (nh2_positions[0] > chain_length - nh2_positions[nh2_count - 1] + 1)
		{
			from_left = false;
			goto name_part;
		}
		else
		{
			for (short i = 0; i < nh2_count; i++)
			{
				left += nh2_positions[i];
				right += chain_length - nh2_positions[i] + 1;
			}
			if (left < right)
			{
				from_left = true;
				left = 0;
				right = 0;
				goto name_part;
			}
			else if (left > right)
			{
				from_left = false;
				left = 0;
				right = 0;
				goto name_part;
			}
		}
	}

	if (has_double_bond == true)
	{
		if (double_bond_positions[0] < chain_length - double_bond_positions[double_bond_count - 1])
		{
			from_left = true;
			goto name_part;
		}
		else if (double_bond_positions[0] > chain_length - double_bond_positions[double_bond_count - 1])
		{
			from_left = false;
			goto name_part;
		}
		else
		{
			for (short i = 0; i < double_bond_count; i++)
			{
				left += double_bond_positions[i];
				right += chain_length - double_bond_positions[i];
			}
			if (left < right)
			{
				from_left = true;
				left = 0;
				right = 0;
				goto name_part;
			}
			else if (left > right)
			{
				from_left = false;
				left = 0;
				right = 0;
				goto name_part;
			}
		}
	}

	if (has_triple_bond == true)
	{
		if (triple_bond_positions[0] < chain_length - triple_bond_positions[triple_bond_count - 1])
		{
			from_left = true;
			goto name_part;
		}
		else if (triple_bond_positions[0] > chain_length - triple_bond_positions[triple_bond_count - 1])
		{
			from_left = false;
			goto name_part;
		}
		else
		{
			for (short i = 0; i < triple_bond_count; i++)
			{
				left += triple_bond_positions[i];
				right += chain_length - triple_bond_positions[i];
			}
			if (left < right)
			{
				from_left = true;
				left = 0;
				right = 0;
				goto name_part;
			}
			else if (left > right)
			{
				from_left = false;
				left = 0;
				right = 0;
				goto name_part;
			}
		}
	}

	if (has_halogen == true)
	{
		has_halogen = false;
		for (short halogen = 17; halogen <= 20; halogen++)
		{
			for (short i = 0; i < 100; i++)
				{
					halogen_positions[i] = 0;
				}
			halogen_count = 0;

			for (short x = 0; x < chain_length * 2 - 1; x += 2)
			{
				if (position[x][1] == halogen)
				{
					has_halogen = true;
					halogen_positions[halogen_count] = x / 2 + 1;
					halogen_count++;
				}
				if (position[x][3] == halogen)
				{
					has_halogen = true;
					halogen_positions[halogen_count] = x / 2 + 1;
					halogen_count++;
				}
			}
			if (has_halogen == true)
			{
				if (halogen_positions[0] < chain_length - halogen_positions[halogen_count - 1] + 1)
				{
					from_left = true;
					goto name_part;
				}
				else if (halogen_positions[0] > chain_length - halogen_positions[halogen_count - 1] + 1)
				{
					from_left = false;
					goto name_part;
				}
				else
				{
					for (short i = 0; i < halogen_count; i++)
					{
						left += halogen_positions[i];
						right += chain_length - halogen_positions[i] + 1;
					}
					if (left < right)
					{
						from_left = true;
						left = 0;
						right = 0;
						goto name_part;
					}
					else if (left > right)
					{
						from_left = false;
						left = 0;
						right = 0;
						goto name_part;
					}
				}
			}
		}
	}

	if (has_no2 == true)
	{
		if (no2_positions[0] < chain_length - no2_positions[no2_count - 1] + 1)
		{
			from_left = true;
			goto name_part;
		}
		else if (no2_positions[0] > chain_length - no2_positions[no2_count - 1] + 1)
		{
			from_left = false;
			goto name_part;
		}
		else
		{
			for (short i = 0; i < no2_count; i++)
			{
				left += no2_positions[i];
				right += chain_length - no2_positions[i] + 1;
			}
			if (left < right)
			{
				from_left = true;
				left = 0;
				right = 0;
				goto name_part;
			}
			else if (left > right)
			{
				from_left = false;
				left = 0;
				right = 0;
				goto name_part;
			}
		}
	}

	if (has_alkyl == true)
	{
		has_alkyl = false;
		for (short alkyl = 6; alkyl <= 14; alkyl++)
		{
			for (short i = 0; i < 100; i++)
			{
				alkyl_positions[i] = 0;
			}
			alkyl_count = 0;

			for (short x = 0; x < chain_length * 2 - 1; x += 2)
			{
				if (position[x][1] == alkyl)
				{
					has_alkyl = true;
					alkyl_positions[alkyl_count] = x / 2 + 1;
					alkyl_count++;
				}
				if (position[x][3] == alkyl)
				{
					has_alkyl = true;
					alkyl_positions[alkyl_count] = x / 2 + 1;
					alkyl_count++;
				}
			}
			if (has_alkyl == true)
			{
				if (alkyl_positions[0] < chain_length - alkyl_positions[alkyl_count - 1] + 1)
				{
					from_left = true;
					goto name_part;
				}
				else if (alkyl_positions[0] > chain_length - alkyl_positions[alkyl_count - 1] + 1)
				{
					from_left = false;
					goto name_part;
				}
				else
				{
					for (short i = 0; i < alkyl_count; i++)
					{
						left += alkyl_positions[i];
						right += chain_length - alkyl_positions[i] + 1;
					}
					if (left < right)
					{
						from_left = true;
						left = 0;
						right = 0;
						goto name_part;
					}
					else if (left > right)
					{
						from_left = false;
						left = 0;
						right = 0;
						goto name_part;
					}
				}
			}
		}
	}

name_part:
	bool first_out = false;
	std::cout << "\n´ËÓÐ»ú»¯ºÏÎïÃû³ÆÎª£º";
	
	if (has_alkyl == true)
	{
		for (short alkyl = 6; alkyl <= 14; alkyl++)
		{
			has_alkyl = false;
			for (short i = 0; i < 100; i++)
			{
				alkyl_positions[i] = 0;
			}
			alkyl_count = 0;

			for (short x = 0; x < chain_length * 2 - 1; x += 2)
			{
				if (position[x][1] == alkyl)
				{
					has_alkyl = true;
					alkyl_positions[alkyl_count] = x / 2 + 1;
					alkyl_count++;
				}
				if (position[x][3] == alkyl)
				{
					has_alkyl = true;
					alkyl_positions[alkyl_count] = x / 2 + 1;
					alkyl_count++;
				}
			}

			if (has_alkyl == true)
			{
				if (from_left == true)
				{
					if (first_out == false)
					{
						first_out = true;
					}
					else
					{
						std::cout << "-";
					}

					std::cout << alkyl_positions[0];
					for (short i = 1; i < alkyl_count; i++)
					{
						std::cout<< "," << alkyl_positions[i];
					}
					std::cout << "-";

					if (alkyl_count > 1)
					{
						to_chinese_num(alkyl_count);
					}
					to_heavenly_stems_num(alkyl - 5);
					std::cout << "»ù";
				}
				else
				{
					if (first_out == false)
					{
						first_out = true;
					}
					else
					{
						std::cout << "-";
					}

					std::cout << chain_length - alkyl_positions[alkyl_count - 1] + 1;
					for (short i = alkyl_count - 2; i >= 0; i--)
					{
						std::cout << "," << chain_length - alkyl_positions[i] + 1;
					}
					std::cout << "-";

					if (alkyl_count > 1)
					{
						to_chinese_num(alkyl_count);
					}
					to_heavenly_stems_num(alkyl - 5);
					std::cout << "»ù";
				}
			}
		}
	}

	if (has_no2 == true)
	{
		if (from_left == true)
		{
			if (first_out == false)
			{
				first_out = true;
			}
			else
			{
				std::cout << "-";
			}

			std::cout << no2_positions[0];
			for (short i = 1; i < no2_count; i++)
			{
				std::cout << "," << no2_positions[i];
			}

			std::cout << "-";
			if (no2_count > 1)
			{
				to_chinese_num(no2_count);
			}
			std::cout << "Ïõ»ù";
		}
		else
		{
			if (first_out == false)
			{
				first_out = true;
			}
			else
			{
				std::cout << "-";
			}

			std::cout << chain_length - no2_positions[no2_count - 1] + 1;
			for (short i = no2_count - 2; i >= 0; i--)
			{
				std::cout << "," << chain_length - no2_positions[i] + 1;
			}

			std::cout << "-";
			if (no2_count > 1)
			{
				to_chinese_num(no2_count);
			}
			std::cout << "Ïõ»ù";
		}
	}

	if (has_halogen == true)
	{
		for (short halogen = 17; halogen <= 20; halogen++)
		{
			has_halogen = false;
			for (short i = 0; i < 100; i++)
			{
				halogen_positions[i] = 0;
			}
			halogen_count = 0;

			for (short x = 0; x < chain_length * 2 - 1; x += 2)
			{
				if (position[x][1] == halogen)
				{
					has_halogen = true;
					halogen_positions[halogen_count] = x / 2 + 1;
					halogen_count++;
				}
				if (position[x][3] == halogen)
				{
					has_halogen = true;
					halogen_positions[halogen_count] = x / 2 + 1;
					halogen_count++;
				}
			}

			if (has_halogen == true)
			{
				if (from_left == true)
				{
					if (first_out == false)
					{
						first_out = true;
					}
					else
					{
						std::cout << "-";
					}

					std::cout << halogen_positions[0];
					for (short i = 1; i < halogen_count; i++)
					{
						std::cout << "," << halogen_positions[i];
					}

					std::cout << "-";
					if (halogen_count > 1)
					{
						to_chinese_num(halogen_count);
					}
					to_halogen_num(halogen - 16);
				}
				else
				{
					if (first_out == false)
					{
						first_out = true;
					}
					else
					{
						std::cout << "-";
					}

					std::cout << chain_length - halogen_positions[halogen_count - 1] + 1;
					for (short i = halogen_count - 2; i >= 0; i--)
					{
						std::cout << "," << chain_length - halogen_positions[i] + 1;
					}

					std::cout << "-";
					if (halogen_count > 1)
					{
						to_chinese_num(halogen_count);
					}
					to_halogen_num(halogen - 16);
				}
			}
		}
	}

	if (has_nh2 == true and has_oh == true)
	{
		if (from_left == true)
		{
			if (first_out == false)
			{
				first_out = true;
			}
			else
			{
				std::cout << "-";
			}
			std::cout << nh2_positions[0];
			for (short i = 1; i < nh2_count; i++)
			{
				std::cout << "," << nh2_positions[i];
			}

			std::cout << "-";
			if (nh2_count > 1)
			{
				to_chinese_num(nh2_count);
			}
			std::cout << "°±»ù";
		}
		else
		{
			if (first_out == false)
			{
				first_out = true;
			}
			else
			{
				std::cout << "-";
			}
			std::cout << chain_length - nh2_positions[nh2_count - 1] + 1;
			for (short i = nh2_count - 2; i >= 0; i--)
			{
				std::cout << "," << chain_length - nh2_positions[i] + 1;
			}
			
			std::cout << "-";
			if (nh2_count > 1)
			{
				to_chinese_num(nh2_count);
			}
			std::cout << "°±»ù";
		}
	}

	to_heavenly_stems_num(chain_length);

	if (has_double_bond == true)
	{
		if (from_left == true)
		{
			std::cout << "-";
			std::cout << double_bond_positions[0];
			for (short i = 1; i < double_bond_count; i++)
			{
				std::cout << "," << double_bond_positions[i];
			}
			std::cout << "-";
			if (double_bond_count > 1)
			{
				to_chinese_num(double_bond_count);
			}
			std::cout << "Ï©";
		}
		else
		{
			std::cout << "-";
			std::cout << chain_length - double_bond_positions[double_bond_count - 1];
			for (short i = double_bond_count - 2; i >= 0; i--)
			{
				std::cout << "," << chain_length - double_bond_positions[i];
			}
			std::cout << "-";
			if (double_bond_count > 1)
			{
				to_chinese_num(double_bond_count);
			}
			std::cout << "Ï©";
		}
	}

	if (has_triple_bond == true)
	{
		if (from_left == true)
		{
			std::cout << "-";
			std::cout << triple_bond_positions[0];
			for (short i = 1; i < triple_bond_count; i++)
			{
				std::cout << "," << triple_bond_positions[i];
			}
			std::cout << "-";
			if (triple_bond_count > 1)
			{
				to_chinese_num(triple_bond_count);
			}
			std::cout << "È²";
		}
		else
		{
			std::cout << "-";
			std::cout << chain_length - triple_bond_positions[triple_bond_count - 1];
			for (short i = triple_bond_count - 2; i >= 0; i--)
			{
				std::cout << "," << chain_length - triple_bond_positions[i];
			}
			std::cout << "-";
			if (triple_bond_count > 1)
			{
				to_chinese_num(triple_bond_count);
			}
			std::cout << "È²";
		}
	}

	if (has_double_bond == false and has_triple_bond == false)
	{
		if (has_nh2 == true or has_oh == true)
		{
			if (chain_length > 10)
			{
				std::cout << "Íé";
			}
		}
		else
		{
			std::cout << "Íé";
		}
	}

	if (has_nh2 == true and has_oh == false)
	{
		if (from_left == true)
		{
			std::cout << "-";
			std::cout << nh2_positions[0];
			for (short i = 1; i < nh2_count; i++)
			{
				std::cout << "," << nh2_positions[i];
			}

			std::cout << "-";
			if (nh2_count > 1)
			{
				to_chinese_num(nh2_count);
			}
			std::cout << "°·";
		}
		else
		{
			std::cout << "-";
			std::cout << chain_length - nh2_positions[nh2_count - 1] + 1;
			for (short i = nh2_count - 2; i >= 0; i--)
			{
				std::cout << "," << chain_length - nh2_positions[i] + 1;
			}

			std::cout << "-";
			if (nh2_count > 1)
			{
				to_chinese_num(nh2_count);
			}
			std::cout << "°·";
		}
	}

	if (has_oh == true)
	{
		if (from_left == true)
		{
			std::cout << "-";
			std::cout << oh_positions[0];
			for (short i = 1; i < oh_count; i++)
			{
				std::cout << "," << oh_positions[i];
			}
			std::cout << "-";
			if (oh_count > 1)
			{
				to_chinese_num(oh_count);
			}
			std::cout << "´¼";
		}
		else
		{
			std::cout << "-";
			std::cout << chain_length - oh_positions[oh_count - 1] + 1;
			for (short i = oh_count - 2; i >= 0; i--)
			{
				std::cout << "," << chain_length - oh_positions[i] + 1;
			}
			std::cout << "-";
			if (oh_count > 1)
			{
				to_chinese_num(oh_count);
			}
			std::cout << "´¼";
		}
	}
}