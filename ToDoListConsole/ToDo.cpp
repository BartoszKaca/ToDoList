#include "ToDo.h"
#include <iostream>

	void ToDo::print_date(int num)
	{
		if (months[num] != 0 && years[num] != 0)
		{
			std::cout << days[num] << "-" << months[num] << "-" << years[num];
		}
	}
	void ToDo::get_num()
	{
		std::cout <<"number of things to do:"<< num << std::endl;
	}
	void ToDo::print_everything()
	{
		for(size_t i = 0; i < num; i++)
		{
			std::cout << tab[i] << " ";
			print_date(i);
			std::cout << std::endl;
		}
	}
	void ToDo::add_new(std::string name, int day, int month, int year)
	{
		tab.push_back(name);
		days.push_back(day);
		months.push_back(month);
		years.push_back(year);
		check_date(tab.size)

	}
	bool ToDo::check_date(int num, int day, int month, int year)
	{
		if (year > years[num])
		{
			if
		}

	}
	void ToDo::delete_pos(int pos)
	{

	}

