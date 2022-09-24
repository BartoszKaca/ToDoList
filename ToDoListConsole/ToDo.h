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
	int hour;
	int minute;
	int num{0};
	std::vector <std::string> tab;
	std::vector <int> days;
	std::vector <int>months;
	std::vector <int>years;
	std::vector <int>minutes;
	std::vector <int> hours;
public:
	bool abort=false;
	void edit_task(int num);
	void menu();
	void edit_exp_date(int num);//todo
	void print_date(int num);
	void get_num();
	void print_everything();
	void add_new(std::string name = " ", int day = 0, int month = 0, int year = 0, int minute = 0, int hour = 0);
	bool check_date(int num);
	void delete_pos(int pos);
	void update_date();
};

