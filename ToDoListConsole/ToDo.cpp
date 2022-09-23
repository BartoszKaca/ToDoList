#include "ToDo.h"
#include <iostream>
#include <chrono>
#include <ctime>

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
		for(size_t i = 0; i < tab.size(); i++)
		{
			std::cout <<i<< tab[i] << " ";
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
		check_date(tab.size());
		num += 1;

	}
	//todo - check date witch current date!
	bool ToDo::check_date(int num)
	{
		
		if (days[num] == 0 && months[num] == 0 && years[num] == 0)
		{
			return true;
		}
		return true;
	}
	void ToDo::delete_pos(int pos)
	{
		tab.erase(tab.begin()+pos -1);
		days.erase(days.begin() + pos - 1);
		months.erase(months.begin() + pos - 1);
		years.erase(years.begin() + pos - 1);
		num -= 1;
	}
	void ToDo::update_date()
	{
		struct tm parts;
		std::time_t now_c = time(0);
		localtime_s(&parts, &now_c);

		 year = 1900 + parts.tm_year;
		month = 1 + parts.tm_mon;
		day = parts.tm_mday;
	}

