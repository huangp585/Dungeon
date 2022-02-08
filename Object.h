#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Object {
public:
	Object();
	Object(string _name, string _tag);

	/* pure virtual function */
	virtual bool triggerEvent(Object*) = 0;
	
	/*set and get function*/
	void setName(string _name);
	void setTag(string _tag);
	string getName();
	string getTag();
private:
	string name;
	string tag;
};


#endif 
