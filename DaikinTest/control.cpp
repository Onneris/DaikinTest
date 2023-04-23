#include "DaikinTest.h"

//function of control for heating and cooling


//Control loop for the system, return a value depending if we need to heat,cool or do nothing The return 4 is there if there is a problem but it should never report it.
// 

int control_loop(int sensor, int temp_min, int temp_max)
{
	if (sensor < temp_min)
	{
		_sleep(1000);
		return 1;
	}
	else if (sensor > temp_max)
	{
		_sleep(1000);
		return 2;
	}

	else if (temp_min < sensor < temp_max)
	{
		return 3;
	}
		return 4;
	
}