#ifndef NODE_H
#define NODE_H

#include <cmath>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstring>
#include <conio.h>
#include <Queue>
#include <windows.h>

using namespace std;

class Node{
	private:
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
	string pop_status;
	string predicted_pop;
    Node *next;
    public:
    Node(string country, string population, string yearly_change, string net_change, string land_area, string migrants, string fert_rate, string med_age, string urban_pop, string world_share);
	void set_next(Node *temp);
	Node *get_next();
	void get_data();
	string get_country();
	string get_population();
    string get_yearly_change();
	string get_net_change();
	string get_density();
	string get_land_area();
	string get_migrants();
	string get_fert_rate();
	string get_med_age();
	string get_urban_pop();
	string get_world_share();
    void set_population(string str);
	void set_yearly_change(string str);
	void set_net_change(string num);
	void set_density(string num);
	void set_land_area(string num);
	void set_migrants(string num);
	void set_fert_rate(string str);
	void set_med_age(string str);
	void set_urban_pop(string str);
	void set_world_share(string str);
};


#endif
