#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstring>
#include <conio.h>
#include <Queue>
#include <windows.h>
#include <iomanip>
#include <cmath>
#include "User.h"
#include "User.cpp"

using namespace std;

int main(){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    Data obj;
    ifstream infile("Population.txt");
	string country;
	string population;
	string yearly_change;
	string net_change;
	string density;
	string land_area;
	string migrants;
	string fert_rate;
	string med_age;
	string urban_pop;
	string world_share;    
    while(infile>>country>>population>>yearly_change>>net_change>>land_area>>migrants>>fert_rate>>med_age>>urban_pop>>world_share)
	{
        obj.insert_end(country,population,yearly_change,net_change,land_area,migrants,fert_rate,med_age,urban_pop,world_share);
	}
	
	infile.close();
	User u1(obj);    
}

