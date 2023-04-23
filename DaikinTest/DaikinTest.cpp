// DaikinTest.cpp : Defines the entry point for the application.
//

// Daikine_test.cpp : Defines the entry point for the application.
//

#include "DaikinTest.h"


using namespace std;
//Initialisating part of the project 

int therm(0), temp_sensor(0), temp_min_util(0), temp_max_util(0), KB_value(0);


//function 
//Set the value for the min and max temp


void set_temp()
{
	do {
		cout << "Input temp min" << endl;
		cin >> temp_min_util;
		//Check if the cin fail (wrong type, only get the integers value, no float)
		if (cin.fail())
		{
			cin.clear(); cin.ignore(512, '\n');
			cout << "Error Only numerical values accepted" << std::endl;
		}
		else if (100 < temp_min_util || temp_min_util < 0)
		{
			cout << "Temp outside range (0-100°C)" << endl;

		}
		else
		{
			break;
		}
	} while (1);
	do {
		cout << "Input temp max" << endl;
		cin >> temp_max_util;

		//Check if the cin fail (wrong type, only get the integer value, no float
		if (cin.fail())
		{
			cin.clear(); cin.ignore(512, '\n');
			cout << "Error Only numerical values accepted" << std::endl;
		}
		else if (100 < temp_max_util || temp_max_util < 0)
		{
			cout << "Temp outside range (0-100°C)" << endl;

		}
		else
		{
			break;
		}
	} while (1);

	cout << "temp_max :" << temp_max_util << endl << "temp_min : " << temp_min_util << endl;

	//To be sure that KB_Value is reset
	KB_value = 0;
}


//Function to set the value of the sensor with a protection against wrong value encoded
void set_sensor()
{
	do {
		cout << "Input sensor temp (0-100°C). only integer" << endl;
		cin >> temp_sensor;

		//Check if the cin fail (wrong type, only get the integer value, no float
		if (cin.fail())
		{
			cin.clear(); cin.ignore(512, '\n');
			cout << "Error Only numerical values accepted" << std::endl;
		}
		else {
			break;
		}
	} while (1);

	while (100 < temp_sensor || temp_sensor < 0)
	{
		cout << "Temp sensor outside range (0-100°C)" << endl;
		cin >> temp_sensor;
	}
	//To be sure that KB_Value is reset
	KB_value = 0;
}



int main()
{


	cout << "init" << endl << "Press enter to set the sensor temp and escape to set the min and max temp" << endl;


	while (1)
	{
		// Temp def
		set_temp();

		if (temp_max_util <= temp_min_util)
		{
			cout << "Please enter a temp max superior to the temp min" << endl;
			set_temp();
		}
		else
		{
			do
			{
				//Control part of the system

				therm = control_loop(temp_sensor, temp_min_util, temp_max_util);

				switch (therm)
				{

				case 1:
				{
					cout << "Heating " << temp_sensor << endl;
					temp_sensor++;
					break;
				}
				case 2:
				{
					cout << "Cooling " << temp_sensor << endl;
					temp_sensor--;
					break;
				}
				case 3:
				{
					cout << "Not heating or cooling " << endl << "Please enter a new value for the sensor" << endl;
					set_sensor();
					break;
				}
				default:
				{
					cout << "error" << endl << "Error value: " << therm << endl;
					break;
				}
				}




				//control input to break from the boucle and set temp again
				if (_kbhit())
				{
					KB_value = _getch();

					if (KB_value == 13)// 13 = enter key
					{
						set_sensor();

					}
				}
			} while (KB_value != 27); // 27= escape key
		}
	}



	return 0;
}

