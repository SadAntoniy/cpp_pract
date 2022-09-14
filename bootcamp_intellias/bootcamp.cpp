#include "bootcamp.h"

Timer::Timer() : m_beg(std::chrono::high_resolution_clock::now()) 
{ }

void Timer::reset() 
{ 
	m_beg = std::chrono::high_resolution_clock::now(); 
}

double Timer::elapsed() const
{
	return std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1> >>(std::chrono::high_resolution_clock::now() - m_beg).count();
}

void Employeer::setName(std::string name) { this->name = name; }
void Employeer::setEmail(std::string email) { this->email = email; }
void Employeer::setDepartment(std::string department) { this->department = department; }
void Employeer::setPosition(std::string position) { this->position = position; }
void Employeer::setProject(std::string project) { this->project = project; }
void Employeer::setTask(std::string task) { this->task = task; }
void Employeer::setData_year(int data_year) { this->data_year = data_year; }
void Employeer::setData_month(int data_month) { this->data_month = data_month; }
void Employeer::setData_day(int data_day) { this->data_day = data_day; }
void Employeer::setLogged_hours(int logged_hours) { this->logged_hours = logged_hours; }

std::string Employeer::getName() { return name; }
std::string Employeer::getEmail() { return email; }
std::string Employeer::getDepartment() { return department; }
std::string Employeer::getPosition() { return position; }
std::string Employeer::getProject() { return project; }
std::string Employeer::getTask() { return task; }
int Employeer::getData_year() { return data_year; }
int Employeer::getData_month() { return data_month; }
int Employeer::getData_day() { return data_day; }
int Employeer::getLogged_hours() { return logged_hours; }

void Employeer::totalHours(int logged_hours) { this->logged_hours += logged_hours; }

bool Employeer::operator == (Employeer& other) { return ((this->name == other.name) && (this->data_month == other.data_month)); }
Employeer Employeer::operator = (Employeer& other)
{
	this->name = other.name;
	this->email = other.email;
	this->department = other.department;
	this->position = other.position;
	this->project = other.project;
	this->task = other.task;
	this->data_year = other.data_year;
	this->data_month = other.data_month;
	this->data_day = other.data_day;
	this->logged_hours = other.logged_hours;

	return *this;
}

void check_for_numbers(Employeer*& emp, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::string str = emp[i].getName();
		for (auto ch : str)
		{
			if (ch >= '0' && ch <= '9')
			{
				emp[i].totalHours(1);
				throw std::invalid_argument("Any name has a number in the record");
			}
		}			
	}
}

void fill_the_class(Employeer*& emp, std::vector<std::string> vec)
{
	int i = 0;

	for (auto& v : vec)
	{

		int count = 0;
		int count_symbol = 0;
		std::string str;
		for (auto s : v)
		{
			count_symbol++;
			if (s != ';')
			{
				str += s;
				if (count_symbol == (v.size()))
				{
					int total_hours = std::stoi(str);
					emp[i].setLogged_hours(total_hours);
				}
			}
			else
			{
				count++;
				if (count == 1)
				{
					emp[i].setName(str);
					str = "";
				}
				else if (count == 7)
				{
					std::string sub;
					int count_month = 0;

					for (auto ss : str)
					{
						if (ss == '-' || ss == '\0')
						{
							count_month++;
							int num_val = std::stoi(sub);

							if (count_month == 2)
							{
								emp[i].setData_month(num_val);
							}
							emp[i].setData_year(num_val);
							sub = "";
						}
						else
							sub += ss;
						str = "";
					}
				}
				else
					str = "";
			}
		}
		if (i < vec.size() - 1)
			i++;
		//fout << '\n';
	}
}

void class_comprassion(Employeer*& emp, int& size)
{
	int tmp_size = size;
	Employeer* tmp_emp = new Employeer[size];

	for (int i = 0; i < size; i++) {
		tmp_emp[i] = emp[i];
	}

	delete[] emp;

	for (int i = 0; i < tmp_size; ++i)
	{
		for (int j = i + 1; j < tmp_size; ++j)
		{
			if (tmp_emp[i] == tmp_emp[j])
			{
				tmp_emp[i].totalHours(tmp_emp[j].getLogged_hours());
				for (int k = j + 1; k < tmp_size; k++)
				{
					tmp_emp[k - 1] = tmp_emp[k];
				}
				tmp_size--;
				j--;
			}
		}
	}

	emp = new Employeer[tmp_size];
	size = tmp_size;

	for (int i = 0; i < size; ++i)
	{
		if (tmp_emp[i].getName() == "")
			continue;
		emp[i] = tmp_emp[i];
	}

	delete[]tmp_emp;
}

void fill_the_file(std::ofstream& fout, Employeer*& emp, int size)
{
	fout << "Name;Month;Total hours" << '\n';
	for (int i = 0; i < size; ++i)
	{
		fout << emp[i].getName() << ";";
		int what_month = emp[i].getData_month();
		switch (what_month)
		{
		case 1:
			fout << "January;";
			break;
		case 2:
			fout << "February;";
			break;
		case 3:
			fout << "March;";
			break;
		case 4:
			fout << "April;";
			break;
		case 5:
			fout << "May;";
			break;
		case 6:
			fout << "June;";
			break;
		case 7:
			fout << "July;";
			break;
		case 8:
			fout << "August;";
			break;
		case 9:
			fout << "September;";
			break;
		case 10:
			fout << "October;";
			break;
		case 11:
			fout << "November;";
			break;
		case 12:
			fout << "December;";
			break;
		default:
			break;
		}
		fout << emp[i].getLogged_hours() << '\n';
	}
}

void trycatchblock(Employeer* emp, int size) {
	try
	{
		check_for_numbers(emp, size);

	}
	catch (const char* ex)
	{
		std::cout << std::endl;
		std::cout << ex << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << std::endl;
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "any exept" << std::endl;
	}
}