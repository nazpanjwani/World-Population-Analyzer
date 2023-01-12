#include "Data.h"

using namespace std;

Data::Data(){
        head=NULL;
    }

Node* Data::get_head(){
    	return head;
	}

void Data:: insert_end(string country, string population, string yearly_change, string net_change, string land_area, string migrants, string fert_rate, string med_age, string urban_pop, string world_share){

    Node *temp;
    temp=head;
    
    Node *new_node=new Node(country,population,yearly_change,net_change,land_area,migrants,fert_rate,med_age,urban_pop,world_share);
    new_node->set_next(NULL);
    
    if(temp==NULL)
        head=new_node;
    else{
	    while(temp->get_next()!=NULL){
    	    temp=temp->get_next();
	    }
	    temp->set_next(new_node);
    }  
}

bool Data:: ifFound(string str){
	Node *temp=head;
	while(temp!=NULL){
		if(str==temp->get_country())
		return true;
		temp=temp->get_next();
	}
	return false;
}

void Data:: Delete_any(int pos){
	if(head==NULL)
	return;
	Node *temp=head;
	if (pos == 0){ 
        head = temp->get_next();
        delete(temp);      
        return; 
    }
    for (int i=0; temp!=NULL && i<pos-1; i++) 
         temp = temp->get_next();
	Node *next = temp->get_next()->get_next(); 
    delete(temp->get_next());
    temp->set_next(next);
    update_file();
    
}

int  Data:: get_pos(string str){
    for (int i = 0; i < str.length(); ++i) { 
        if (str[i] == ' '){
            str[i] = '-'; 
        } 
        if(str[i]=='-'){
 		    str[i+1]=toupper(str[i+1]);
	    }
    } 
    str[0]=toupper(str[0]);
	if(!ifFound(str)){
		cout<<"\n\nNo Such Record Exist!"<<endl;
		return -1;
	}
	else{
		cout<<"\n\nRecord Successfully Deleted! "<<endl;
	}
	Node *temp=head; int count=0;
	while(temp!=NULL && str!=temp->get_country()){
		count++;
		temp=temp->get_next();
	}
	return count;
}

void Data:: traverse(){

    Node *obj=head;
    while (obj!=NULL)
    {
        obj->get_data();
        cout<<endl;
        obj=obj->get_next();
    }
}

void Data:: search(string str){
	if(head==NULL)
	return;
	Node *temp=head;
	for (int i = 0; i < str.length(); ++i) { 
        if (str[i] == ' '){
            str[i] = '-'; 
        } 
        if(str[i]=='-'){
 		    str[i+1]=toupper(str[i+1]);
	    }
    } 
    str[0]=toupper(str[0]);
    bool found=false;
	while(temp!=NULL){
		if(str==temp->get_country())
		{
			temp->get_data();
			found=true;
			return;
		}
		temp=temp->get_next();
	}
	if(found==false)
	cout<<"No Such Record Exists! "<<endl;
}

void Data:: update_file(){
	Node *temp=head;
	ofstream outfile("updated.txt");
	while(temp!=NULL){
	outfile<<temp->get_country()<<"\t\t"<<temp->get_population()<<"\t"<<temp->get_yearly_change()<<"\t"<<temp->get_net_change()<<"\t"<<temp->get_density()<<"\t"<<temp->get_land_area()<<"\t"<<temp->get_migrants()<<"\t"<<temp->get_fert_rate()<<"\t"<<temp->get_med_age()<<"\t"<<temp->get_urban_pop()<<"\t"<<temp->get_world_share()<<endl;
	temp=temp->get_next();
	}
	outfile.close();
	remove("Population.txt");
    rename("updated.txt","Population.txt");
}

void Data:: update_record(string str1){
	string change=str1;
	for (int i = 0; i < change.length(); ++i) { 
        if (change[i] == ' '){
            change[i] = '-'; 
        } 
        if(change[i]=='-'){
 		    change[i+1]=toupper(change[i+1]);
	    }
    } 
    change[0]=toupper(change[0]);
    cout<<change<<endl;
	bool found=false;
	Node *temp=head;
	while(temp!=NULL){
		if(change==temp->get_country()){
			found=true;
			goto DoIt;
		}
		temp=temp->get_next();
	}
	if(found==false){
		cout<<"No Such Record Exist!"<<endl;
		return;
	}
	DoIt:
	int num; string str, lin, fln, iin;
	cout<<"\nChoose number for updating any entity of "<<temp->get_country();
	cout<<"\nPopulation        1";
	cout<<"\nYearly Change     2";
	cout<<"\nNet Change        3";
	cout<<"\nLand Area         4";
	cout<<"\nMigrants          5";
	cout<<"\nFertility Rate    6";
	cout<<"\nMed. Age          7";
	cout<<"\nUrban Population  8";
	cout<<"\nWorld Share       9";
	cout<<"\n\nEnter Your Choice for Updation: ";
	cin>>num;
	if(num==1){
		cout<<"\nEnter Updated Population: ";
		cin>>str;
		temp->set_population(str);
	}
	if(num==2){
		cout<<"\nEnter Updated Yearly Change: ";
		cin>>str;
		temp->set_yearly_change(str);
	}
	if(num==3){
		cout<<"\nEnter Updated Net Change: ";
		cin>>lin;
		temp->set_net_change(lin);
	}
	if(num==4){
		cout<<"\nEnter Updated Land Area: ";
		cin>>iin;
		temp->set_land_area(lin);
	}
	if(num==5){
		cout<<"\nEnter Updated Migrants: ";
		cin>>lin;
		temp->set_migrants(lin);
	}
	if(num==6){
		cout<<"\nEnter Updated Fertility Rate: ";
		cin>>str;
		temp->set_fert_rate(str);
	}
	if(num==7){
		cout<<"\nEnter Updated Med. Age: ";
		cin>>str;
		temp->set_med_age(str);
	}
	if(num==8){
		cout<<"\nEnter Updated Urban Population: ";
		cin>>str;
		temp->set_urban_pop(str);
	}
	if(num==9){
		cout<<"\nEnter Updated Population: ";
		cin>>str;
		temp->set_world_share(str);
	}
	char choice;
	cout<<"\nWant to change other entities? (Y/N)  ";
	cin>>choice;
	if(choice=='Y'||choice=='y')
	update_record(str1);
	else{
	    update_file();   
	    return;
	}
}

void Data:: bubbleSort(){
        Node *h, *temp , *left ,*temp1=head;
		int count=0;
		while(temp1!=NULL)
	    {
	    	count++;
	    	temp1=temp1->get_next();
		}   
	   for(int i=0;i<count;i++)
		{
		    left=NULL;
		    h=head;
			while(h->get_next()!=NULL)
		    {  	
			  	if(h->get_country()>h->get_next()->get_country())
			  	{
			  		if(left==NULL)
			  		{
			  			temp=h->get_next();
			  			h->set_next(temp->get_next());
			  			temp->set_next(h);
			  			head=left=temp;
					}	
					else
					{
						temp=h->get_next();
						left->set_next(temp);
			  			h->set_next(temp->get_next());
			  			temp->set_next(h);	
			  			left=temp;
					}
				}
				else
				{
				   temp=h->get_next();
				   left=h;
				   h=temp;	
				}	
			}		
		}
		update_file();
    }

void Data:: insertionSort(Node *head_ref) { 
    Node *sorted = NULL; 
    Node *current = head_ref; 
    while (current != NULL) { 
        Node *next = current->get_next(); 
        sortedInsert(&sorted, current); 
        current = next; 
    } 
	head=sorted;
	update_file();
} 

void Data::sortedInsert(Node** head_ref, Node* new_node) { 
     Node* current; 
    if (*head_ref == NULL || stoi((*head_ref)->get_population()) >= stoi(new_node->get_population())) { 
        new_node->set_next(*head_ref); 
        *head_ref = new_node; 
    } 
    else { 
        current = *head_ref; 
        while (current->get_next()!=NULL ) { 
            if(stoi(current->get_next()->get_population())<stoi(new_node->get_population()))
            current = current->get_next(); 
			else
			break;
        } 
        new_node->set_next(current->get_next());
        current->set_next( new_node) ; 
    } 
}

void Data:: predict_pop(int years){
	ifstream infile("Population.txt");
	long int predictedPop=0,pop;
	Node *obj=head;
	string population,rate,country;
	double growth_rate;
	int indent1=15;
	cout<<"\n----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"Country\t\tPopulation (2020)\tPredicted population by "<<2020+years<<endl;
	cout<<"\n----------------------------------------------------------------------------------------------------------------------\n";
 	while (obj!=NULL)
    {
    	if(obj->get_country().length()>=18)
	         indent1=2;
	     else if(obj->get_country().length()>=10&& obj->get_country().length()<20)
	         indent1=7;
	     else
	         indent1=15;
        population=obj->get_population();
	    stringstream convert(population);
        convert >> pop;
		rate=obj->get_yearly_change();
		rate.erase(rate.length()-1);
		growth_rate=stod(rate);
		growth_rate/=100;
		predictedPop=pop*exp(years*growth_rate);
		country=obj->get_country();
		cout<<country<<setw(indent1)<<'\t'<<obj->get_population()<<setw(15)<<predictedPop<<endl;
        obj=obj->get_next();
    }
	infile.close();
}

string Data:: check_word(string str){
	bool flag=false;
	queue<char> q;
	for (int i = 0; i < str.length(); ++i) {
	     if(str[i] == '(' || str[i] == ')')
              str.erase(i,1);
         i++;
    }
    if(str[0]=='-')
    	q.push(str[0]);
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >='0' &&str[i] <= '9') {
        	flag=true;
            q.push(str[i]);
        }
        if(flag==true&&str[i]=='.')
        q.push(str[i]);
    }
    str="";
    while(!q.empty()){
    	str+=q.front();
    	q.pop();
	}
    if(flag==false)
    str='0';
    return str;
}

void Data:: clean_data(){
	if(head==NULL)
	return;
	Node *temp=head;
	while(temp!=NULL)
	{
		temp->set_population(check_word(temp->get_population()));
		temp->set_yearly_change(check_word(temp->get_yearly_change()));
		temp->set_net_change(check_word(temp->get_net_change()));
		temp->set_land_area(check_word(temp->get_land_area()));
		temp->set_fert_rate(check_word(temp->get_fert_rate()));
		temp->set_med_age(check_word(temp->get_med_age()));
		temp->set_urban_pop(check_word(temp->get_urban_pop()));
		temp->set_world_share(check_word(temp->get_world_share()));
		temp=temp->get_next();
	}
}

void Data:: World_population(){
    Node *temp=head;
    long long int world_pop=0;
	long int pop=0;
    
    while(temp!=NULL)
	{
    	string str=temp->get_population();
    	stringstream convert(str);
    	convert>>pop;
    	world_pop=world_pop+pop;
    	temp=temp->get_next();
	}
	cout<<"\n\nWorld Population: "<<world_pop<<endl<<endl;
} 

void Data:: Predict_world_population(int years){
	long int predictedPop=0,pop;
	long long int world_pred_pop;
	Node *temp=head;
	string population,str_rate,country;
	double growth_rate;
    while (temp!=NULL)
    {
        population=temp->get_population();
        pop=stol(population);
		str_rate=temp->get_yearly_change();
		str_rate.erase(str_rate.length()-1);
		growth_rate=stod(str_rate);
		growth_rate/=100;
		predictedPop=pop*exp(years*growth_rate);
		country=temp->get_country();
		world_pred_pop=world_pred_pop+predictedPop;
		
        temp=temp->get_next();
    }
    cout<<"\nPredicted World Population of "<<years<<" years from now: "<<world_pred_pop<<endl<<endl;
}

void Data:: Calculate_density(){

	Node *temp=head;
	int den=0;
	long int pop, mig, area;
	string str;
	while(temp!=NULL)
	{
	    stringstream convert(temp->get_population());
    	convert>>pop;
    	area=stol(temp->get_land_area());
    	mig=stol(temp->get_migrants());
    	den=(pop+mig)/area;
    	str=to_string(den);
       	temp->set_density(str);
		temp=temp->get_next();
	}
	Add_density_in_file();
}

void Data:: Add_density_in_file(){
	Node *temp=head;
	cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\nCountry \t\tPopulation\tYearly change\tNet change    Density   Land area\tMigrants  Fert. rate  Med. age  Urban pop.  World Share"<<endl;
	cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	int indent1=15, indent2=15;
	ofstream outfile("Population_density.txt");
	while(temp!=NULL)
	{
	     if(temp->get_country().length()>=20)
	         indent1=2;
	     else if(temp->get_country().length()>=10&& temp->get_country().length()<20)
	         indent1=7;
	     else
	         indent1=15;
		 cout<<temp->get_country()<< setw(indent1)<<'\t'<<temp->get_population()<<setw(indent2)<<temp->get_yearly_change()<<setw(indent2)<<temp->get_net_change()<<setw(10)<<temp->get_density()<<setw(indent2)<<temp->get_land_area()<<setw(indent2)<<temp->get_migrants()<<setw(10)<<temp->get_fert_rate()<<setw(10)<<temp->get_med_age()<<setw(10)<<temp->get_urban_pop()<<setw(10)<<temp->get_world_share()<<endl;
         outfile<<temp->get_country()<<'\t'<<temp->get_population()<<"\t"<<temp->get_yearly_change()<<"\t\t"<<temp->get_net_change()<<"\t\t"<<temp->get_density()<<"\t\t"<<temp->get_land_area()<<"\t\t"<<temp->get_migrants()<<"\t\t"<<temp->get_fert_rate()<<'\t'<<temp->get_med_age()<<'\t'<<temp->get_urban_pop()<<'\t'<<temp->get_world_share()<<endl;
		
		 temp=temp->get_next();
	}
	outfile.close();
}
