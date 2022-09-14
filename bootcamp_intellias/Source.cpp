#include "bootcamp.h"

int main()
{
	std::ifstream fin;
	std::ofstream fout;	

	std::string path_for_in = "ReadFile.csv";
	std::string path_for_out = "WriteFile.csv";
	std::string string_for_vector;
	std::vector<std::string> vec;

	//Project runtime measurement starts from file opening
	Timer t;

	fin.open(path_for_in);
	fout.open(path_for_out);	

	if (!fin.is_open())
		std::cout << "File is not open" << std::endl;
	else
	{
		//Ignore 1st string with Name;...;Logged hours
		fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//Fill the vector to transfer the values, what ​​we need to the objects
		while (!fin.eof())
		{
			std::getline(fin, string_for_vector);
			if (fin.eof())
			{
				break;
			}
			vec.push_back(string_for_vector);
		}		
	
		int size = vec.size();

		//Creation of objects for each string of the file
		Employeer *emp = new Employeer[size];

		//Fill the objects with values, what ​​we need
		fill_the_class(emp, vec);	

		//Check whether the same names exist in the list of objects, and if so, sum the logged time
		class_comprassion(emp, size);

		//try-catch block for exept
		trycatchblock(emp, size);

		//Fill the file 
		fill_the_file(fout, emp, size);
		delete[] emp;
	}

	fout.close();
	fin.close();
	std::cout << std::endl;

	//End of project runtime measurement after closing the file
	std::cout << "Time parsing file is " << t.elapsed() << std::endl;;
	
	return 0;
}