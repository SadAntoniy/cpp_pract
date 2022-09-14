#pragma once
#include <chrono>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>

class Timer
{
public:
	Timer();	
	void reset(); 
	double elapsed() const;
	
private:

	std::chrono::time_point<std::chrono::high_resolution_clock> m_beg;

};

class Employeer
{
public:
	
	void setName(std::string name);
	void setEmail(std::string email);
	void setDepartment(std::string department);
	void setPosition(std::string position);
	void setProject(std::string project);
	void setTask(std::string task);
	void setData_year(int data_year);
	void setData_month(int data_month);
	void setData_day(int data_day);
	void setLogged_hours(int logged_hours);

	std::string getName();
	std::string getEmail();
	std::string getDepartment();
	std::string getPosition();
	std::string getProject();
	std::string getTask();
	int getData_year();
	int getData_month();
	int getData_day();
	int getLogged_hours();

	void totalHours(int logged_hours);

	bool operator == (Employeer& other);
	Employeer operator = (Employeer& other);

private:
	std::string name;
	std::string email;
	std::string department;
	std::string position;
	std::string project;
	std::string task;
	int data_year;
	int data_month;
	int data_day;
	int logged_hours;
};

void check_for_numbers(Employeer*& emp, int size);
void fill_the_class(Employeer*& emp, std::vector<std::string> vec);
void class_comprassion(Employeer*& emp, int& size);
void fill_the_file(std::ofstream& fout, Employeer*& emp, int size);
void trycatchblock(Employeer* emp, int size);