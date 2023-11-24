#include "Customer.h"
Customer::Customer(string name,string id, string email, string address, string halal)
{
	this->name = name;
	this->id = id;
	this->email = email;
	this->address = address;
	this->halal = halal;
}
string Customer::getname()
{
	return this->name;
}
string Customer::getid()
{
	return this->id;
}
string Customer::getemail()
{
	return this->email;
}
string Customer::getaddress()
{
	return this->address;
}
string Customer::gethalal()
{
	return this->halal;
}
void Customer::setname(string name)
{
	this->name = name;
}
void Customer::setid(string id)
{
	this->id = id;
}
void Customer::setemail(string email)
{
	this->email = email;
}
void Customer::setaddress(string address)
{
	this->address = address;
}
void Customer::sethalal(string halal)
{
	this->halal = halal;
}