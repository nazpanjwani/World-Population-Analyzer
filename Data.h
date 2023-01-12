#ifndef DATA_H
#define DATA_H

#include "Node.h"
#include "Node.cpp"

class Data{
	private:
    Node *head;
    
    public:
    Data();
    void insert_end(string, string, string, string, string, string, string, string, string, string);
    void traverse();
    int get_pos(string);
    void Delete_any(int);
    bool ifFound(string);
    void search(string);
    void update_file();
    void update_record(string);
    void bubbleSort();
	void sortedInsert(Node** , Node* );
	void insertionSort(Node*);
	void predict_pop(int);
	string check_word(string);
	void clean_data();
	void World_population();
	void Predict_world_population(int);
	void Calculate_density();
	void Add_density_in_file();
    Node* get_head();
};


#endif
