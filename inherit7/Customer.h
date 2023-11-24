#pragma once
#include<iostream>
using namespace std;
class Customer
{
private:
	string name,id, email, address, halal;
public:
	Customer(string name, string id,string email, string address, string halal);
	string getname();
	string getid();
	string getemail();
	string getaddress();
	string gethalal();
	void setname(string name);
	void setid(string id);
	void setemail(string email);
	void setaddress(string address);
	void sethalal(string halal);

};

