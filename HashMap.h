#pragma once

#include <string>
#include <iostream>

using namespace std;


class HashMap
{
	string* array;
	int size;
	int elements;
public:
	HashMap(int lenght):size(lenght)
	{
		array = new string[size];

		for (int i = 0; i < size; i++)
		{
			array[i] = "";
		}
		elements = 0;
	}
	int probe(string key);
	unsigned long hash(string key);
	void insert(const string key,const string password);
 
	bool search(string key, string password);

};