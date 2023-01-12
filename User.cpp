#include "User.h"

using namespace std;

User::User(Data s1){
		s1.clean_data();
    	s1.update_file();
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\n                                                                     WORLD STATISTICS PORTAL"<<endl;
		cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		again:
		cout<<"Please choose an option: "<<endl;
		cout<<"\n\nLogin as: \n\t1. Admin\n\t2. Guest\n\t3. Exit"<<endl;
		int opt;
		cout<<"\nEnter your choice: ";
		cin>>opt;
		if(opt==1){
            verifyDetails(s1);
            system("cls");
			adminMenu(s1);
		}		
		else if(opt==2){
            cout<<"\nLogging in as guest..."<<endl;
            Sleep(2000);
            system("cls");
			guestMenu(s1);
		}
		else if(opt==3){
            exit(0);
		}
		else{
			cout<<"\nInvalid option. Try again!";
			goto again;
		}
	}	

void User:: adminMenu(Data &obj){
	int choice; string str;

	cout<<"\n\xDb\xDb\xDb\xDb\xB2 Choose a relevant option \xB2\xDb\xDb\xDb\xDb "<<endl;
	cout<<"\n 1.Display Records "<<endl;
	cout<<"\n 2.Delete Record   "<<endl;
	cout<<"\n 3.Update Record   "<<endl;
	cout<<"\n 4.Search Record   "<<endl;
	cout<<"\n 5.Sort Records    "<<endl;
	cout<<"\n 6.Predict population "<<endl;
	cout<<"\n 7.Calculate World Population "<<endl;
	cout<<"\n 8.Predict World Population"<<endl;
	cout<<"\n 9.Calculate Density"<<endl;
	cout<<"\n 10.Log out"<<endl;
	cout<<"\n 11.Log out and Exit "<<endl;
	
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	if(choice==1){

		cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\nCountry \t\tPopulation\tYearly change\tNet change    Land area\t\tMigrants  Fert. rate  Med. age  Urban pop.  World Share"<<endl;
		cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		obj.traverse();
	}
	else if(choice==2){
		cout<<"\nEnter country name to delete its record: ";
		cin.ignore();
		getline(cin,str);
		obj.Delete_any(obj.get_pos(str));
	}
	else if(choice==3){
		cout<<"\nEnter country name to update its record: ";
		cin.ignore();
		getline(cin,str);
		obj.update_record(str);
	}
	else if(choice==4){
		cout<<"\nEnter country name to search its record: ";
	    cin.ignore();
		getline(cin,str);
		cout<<endl;
		obj.search(str);
	}
	else if(choice==5){
		here:
		int opt;
		cout<<"\nSort by? "<<endl;
		cout<<"\n               1.Alphabetical order "<<endl;
		cout<<"\n               2.Population   "<<endl;
		cin>>opt;
		if(opt==1)
			obj.bubbleSort();
		else if(opt==2)
			obj.insertionSort(obj.get_head());
		else{
			cout<<"\nInvalid choice! Please select again."<<endl;
			goto here;
		}
	}
	else if(choice==6){
		int year;
		cout<<"\nPredict population how many years from now? ";
		cin>>year;
		obj.predict_pop(year);
	}
	else if(choice==7){
		obj.World_population();
	}
	else if(choice==8){
		int year;
		cout<<"\nPredict world population of how many years from now? ";
		cin>>year;
		obj.Predict_world_population(year);
	}
	else if(choice==9){
		obj.Calculate_density();
	}
	else if(choice==10){
		User us(obj);		
	}
	else if(choice==11){
		exit (0);
	}
	else{
		cout<<"\nInvalid Choice!";
		adminMenu(obj);
	}
	adminMenu(obj);
}

void User:: guestMenu(Data &obj){
	
	int choice; string str;
	cout<<"\n\xDb\xDb\xDb\xDb\xB2 Choose a relevant option \xB2\xDb\xDb\xDb\xDb "<<endl;
	cout<<"\n               1.Display Records "<<endl;
	cout<<"\n               2.Search Record   "<<endl;
	cout<<"\n               3.Sort Records    "<<endl;
	cout<<"\n               4.Predict population "<<endl;
	cout<<"\n               5.Log out "<<endl;
	cout<<"\n               6.Log out and Exit "<<endl;
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	if(choice==1){
		//system("Color 0A");
		cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\nCountry \t\tPopulation\tYearly change\tNet change    Land area\t\tMigrants  Fert. rate  Med. age  Urban pop.  World Share"<<endl;
		cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		obj.traverse();
	}

	else if(choice==2){
		cout<<"\nEnter country name to search its record: ";
	    cin.ignore();
		getline(cin,str);
		cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\nCountry \t\tPopulation\tYearly change\tNet change    Land area\t\tMigrants  Fert. rate  Med. age  Urban pop.  World Share"<<endl;
		cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		obj.search(str);
	}
	else if(choice==3){
		here:
		int opt;
		cout<<"\nSort by? "<<endl;
		cout<<"\n         1.Alphabetical order "<<endl;
		cout<<"\n         2.Population   "<<endl;
		cout<<"\n\nEnter your choice: ";
		cin>>opt;
		if(opt==1)
			obj.bubbleSort();
		else if(opt==2)
			obj.insertionSort(obj.get_head());
		else{
			cout<<"\nInvalid choice! Please select again."<<endl;
			goto here;
		}
		cout<<"\n\nRecords Sorted Successfully!"<<endl;
	}
	else if(choice==4){
		int year;
		cout<<"\nPredict population how many years from now? ";
		cin>>year;
		obj.predict_pop(year);
	}
	else if(choice==5){
		User us(obj);
	}
	else if(choice==6){
		exit (0);
	}
	else{
		cout<<"\nInvalid Choice!";
		guestMenu(obj);
	}
	guestMenu(obj);
}

void User:: verifyDetails(Data s1){
		int tries=0;

		cout<<"\nEnter username: ";
		cin>>username;
		set:
		cout<<"\nEnter password: ";	
		for (int i = 0; i < 11;i++) {
            password[i] = getch(); 
			putch('*');        
        }
		
		if(strcmp(password,"project0207")==0 || strcmp(password,"project1256")==0  ){
			cout<<"\n\nSuccessfully logging in as admin..."<<endl;			
            Sleep(2000);
	    }
	    else{
		char c;
		cout<<"\n\nPassword incorrect. Try again? (y/n)";
		cin>>c;
		    if(c=='y'){
			    if(tries<3){
				    tries++;
				    goto set;
			    }
			    else
			    cout<<"\n\nToo many tries! Logging in as guest..."<<endl;
			    Sleep(3000);
                system("cls");
			    guestMenu(s1);
		    }
		    else{
		    	cout<<"\n\nLogging in as guest..."<<endl;
			    Sleep(3000);
                system("cls");
			    guestMenu(s1);
			}
        }
	}

