#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
class ToDo
{
private:
	int year;
	int month;
	int day;
	int num;
	std::vector <std::string> tab;
	std::vector <int> days;
	std::vector <int>months;
	std::vector <int>years;
public:
	void menu();
	void print_date(int num);
	void get_num();
	void print_everything();
	void add_new(std::string name = " ", int day = 0, int month = 0, int year = 0);//todo: overload it, so user can write only hours and minutes
	bool check_date(int num);
	void delete_pos(int pos);
	void update_date();
};

