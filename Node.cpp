
using namespace std;

Node:: Node(string country, string population, string yearly_change, string net_change, string land_area, string migrants, string fert_rate, string med_age, string urban_pop, string world_share){
        this->country=country;
        this->fert_rate=fert_rate;
        this->land_area=land_area;
        this->med_age=med_age;
        this->migrants=migrants;
        this->net_change=net_change;
        this->population=population;
        this->urban_pop=urban_pop;
        this->world_share=world_share;
        this->yearly_change=yearly_change;
        next=NULL;
    }

void Node:: set_next(Node *temp){
    	next=temp;
	}

Node* Node:: get_next(){
		return next;
	}

void Node:: get_data(){
		int indent1=15, indent2=15;
		if(country.length()>=20)
	        indent1=2;
	    else if(country.length()>=10&& country.length()<20)
	        indent1=7;
	    else
	        indent1=15;
		cout<<country<< setw(indent1)<<'\t'<<population<<setw(indent2)<<yearly_change<<setw(indent2)<<net_change<<setw(indent2)<<land_area<<setw(indent2)<<migrants<<setw(10)<<fert_rate<<setw(10)<<med_age<<setw(10)<<urban_pop<<setw(12)<<world_share<<endl;
    }

string Node:: get_country(){
		return country;
	}

string Node:: get_population(){
		return population;
	}

string Node:: get_yearly_change(){
    	return yearly_change;
	}

string Node:: get_net_change(){
		return net_change;
	}

string Node:: get_density(){
		return density;
	}

string Node:: get_land_area(){
		return land_area;
	}

string Node:: get_migrants(){
		return migrants;
	}	

string Node:: get_fert_rate(){
		return fert_rate;
	}

string Node:: get_med_age(){
		return med_age;
	}

string Node:: get_urban_pop(){
		return urban_pop;
	}

string Node:: get_world_share(){
		return world_share;
	}

void Node:: set_population(string str){
    	population=str;
	}

void Node:: set_yearly_change(string str){
    	yearly_change=str;
	}

void Node:: set_net_change(string num){
    	net_change=num;
	}

void Node:: set_density(string num){
    	density=num;
	}

void Node:: set_land_area(string num){
    	land_area=num;
	}

void Node:: set_migrants(string num){
    	migrants=num;
	}

void Node:: set_fert_rate(string str){
    	fert_rate=str;
	}

void Node:: set_med_age(string str){
    	med_age=str;
	}

void Node:: set_urban_pop(string str){
    	urban_pop=str;
	}

void Node:: set_world_share(string str){
    	world_share=str;
	}

