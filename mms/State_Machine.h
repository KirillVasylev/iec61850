#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_
#include<vector>
#include<string>
#include<list>
#include<fstream>
#include<iostream>
#include "ASN_Type.h"

using namespace std;

typedef enum
{
	BASIC = 0,
	NODE = 1
}Node_Types;

typedef struct
{
	unsigned char  name;
	vector<unsigned char>next;
	int type;
}Rule;

class State_Machine
{
protected:
	vector<string> next_node;	
	list<unsigned char> message;
	int socket;
	vector<Rule>rules;
	vector<string> stack;
	vector<int>size_node;
	void init();
	int check_next(unsigned char currrent_symbol);
	unsigned char get_char_by_name(string name);
	int get_type(unsigned char current_symbol);
	string get_name_by_char(unsigned char symbol);

public:
	State_Machine();
	State_Machine(int sock, string buff);
	int start(int sock, string buff);
	int next_step();
	
};
#endif //STATE_MACHINE_H_