#pragma once
#include <vector>
#include <string>
class ToDo
{
private:
	int num;
	std::vector <std::string> tab;
	std::vector <int> days;
	std::vector <int>months;
	std::vector <int>years;
public:
	void print_date(int num);
	void get_num();
	void print_everything();
	void add_new(std::string name = " ", int day = 0, int month = 0, int year = 0);
	bool check_date(int num, int day, int month, int year);
	void delete_pos(int pos);
};

