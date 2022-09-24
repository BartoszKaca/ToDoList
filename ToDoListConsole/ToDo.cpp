#include "ToDo.h"
#include <iostream>
#include <chrono>
#include <ctime>
	void ToDo::menu()	
	{
		std::cout << "Options: " << std::endl;
		std::cout << "1. check how many things are in to do? " << std::endl;
		std::cout << "2. print tasks " << std::endl;
		std::cout << "3. add new task " << std::endl;
		std::cout << "4. edit expiration date " << std::endl;
		std::cout << "5. edit existing task" << std::endl;
		std::cout << "6. exit" << std::endl;
		int w{ 0 };
		std::cin >> w;
		switch (w)
		{
		case 1:
			get_num();
			break;
		case 2:
			print_everything();
			break;
		case 3:
		{
			std::cout << "name of the task:" << std::endl;
			std::string name;
			std::cin >> name;
			std::cout << "/n You want to provide an expiration date?(Y if yes): " << std::endl;
			char x;
			std::cin >> x;
			if (x == 'y'||x=='Y')
			{
				std::cout << "/nNow, provide expiration date in this format: Minutes Hours Day Month Year, "<<std::endl;
				int minute, hour, day, month, year;
				std::cin >> minute >> hour >> day >> month >> year;
				add_new(name, day, month, year, minute, hour);
			}
			else
			{
				add_new(name);
			}
			if (!check_date(num))
			{
				std::cout << "Not a valid expiration date! Edit this one out!" << std::endl;
				edit_exp_date(num);
			}
			num += 1;
			break;
		}
		case 4:
		{
			std::cout << "which task do you want to edit?" << std::endl;
			int num;
			std::cin >> num;
			edit_exp_date(num);
			break;
		}
		case 5:
		{
			std::cout << "which task do you want to edit?" << std::endl;
			int num;
			std::cin >> num;
			edit_task(num);
			break;
		}
		case 6:
			abort = true;
			break;
		default:
			break;
		}
	}
	void ToDo::edit_exp_date(int num)
	{
		std::cout << "/n If you want no expiration date, just type-in zeros" << std::endl;
		std::cout<<"Now, provide expiration date in this format: Minutes Hours Day Month Year, "<<std::endl;
		int minute, hour, day, month, year;
		std::cin >> minute >> hour >> day >> month >> year;
		days[num] = day;
		years[num] = year;
		months[num] = month;
		hours[num] = hour;
		minutes[num] = minute;
		if (!check_date(num))
		{
			std::cout << "Not a valid expiration date! Edit this one out!" << std::endl;
			edit_exp_date(num);
		}
	}
	void ToDo::print_date(int num)
	{
		if (months[num] != 0 && years[num] != 0 && days[num] != 0)
		{
			if (hours[num])
			{
				std::cout <<minutes[num]<<":" << hours[num]<<" " << days[num] << "-" << months[num] << "-" << years[num];

			}
			else
			{
				std::cout << days[num] << "-" << months[num] << "-" << years[num];
			}
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
	void ToDo::add_new(std::string name, int day, int month, int year, int minute, int hour)
	{
		tab.push_back(name);
		days.push_back(day);
		months.push_back(month);
		years.push_back(year);
		minutes.push_back(minute);
		hours.push_back(hour);
		std::cout << tab.size();
		check_date(tab.size()-1);


	}
	void ToDo::edit_task(int num)
	{
		std::cout << "name of the task:" << std::endl;
		std::string name;
		std::cin >> name;
		tab[num] = name;
		edit_exp_date(num);
	}
	bool ToDo::check_date(int num)
	{
		
		if (days[num] == 0 && months[num] == 0 && years[num] == 0)
		{
			return true;
		}
		else {
			if (year == years[num])
			{
				if (month == months[num])
				{
					if (day == days[num])
					{
						if (hour == hours[num])
						{
							if (minute == minutes[num])
							{
								return false;
							}
							else if (minute < minutes[num]) return true;
							else return false;
						}
						else if (hour < hours[num]) return true;
						else return false;
					}
					else if (day < days[num]) return true;
					else return false;
				}
				else if (month < months[num]) return true;
				else return false;
			}
			else if (year < years[num]) return true;
			else return false;
				
		}
		return true;
	}
	void ToDo::delete_pos(int pos)
	{
		tab.erase(tab.begin()+pos -1);
		days.erase(days.begin() + pos - 1);
		months.erase(months.begin() + pos - 1);
		years.erase(years.begin() + pos - 1);
		hours.erase(hours.begin() + pos - 1);
		minutes.erase(minutes.begin() + pos - 1);
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
		hour = parts.tm_hour;
		minute = parts.tm_min;
	}

