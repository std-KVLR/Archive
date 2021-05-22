#ifndef READ_H
#define READ_H

#include <ctime>
#include <cstdlib>

struct Reading
{

	size_t day = 0;
        size_t hour = 0;
        double temperature = 0;
	char scale = 'c'; 
        Reading() = default;
        Reading(size_t vDay, size_t vHour, double vTemper, char scaleV)
                :day(vDay), hour(vHour), temperature(vTemper)
        {
		if(scaleV != 'c' && scaleV != 'f'){
		        throw -99;
		}
		scale = scaleV;
		
	}
	void toC()
	{
		if(scale == 'f'){
			temperature = 0.5 * temperature - 32;
			scale = 'c';
		}
	}
	void toF()
	{
		if(scale == 'c'){
			temperature = 1.8 * temperature + 32;
			scale = 'f';
		}
	}
};

Reading randReading()
{
        static bool flag = false;
        if(flag == false){
            srand(time(NULL));
            flag = 1;
        }
	char scaleV;
	if((1 + rand()%2) == 1) scaleV = 'c';
	else scaleV = 'f'; 
        return Reading(1+rand()%31, 0+rand()%23, (rand()-rand())/(double)rand(), scaleV);
}

#endif