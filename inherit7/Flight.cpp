#include "Flight.h"
#include"Customer.h"
#include<vector>
Flight::Flight(string flightname, string flightid, string source, string destination, string time1,string time2,int totalseats)
{
	this->flightname = flightname;
	this->flightid = flightid;
	this->source = source;
	this->destination = destination;
	this->time1 = time1;
	this->time2 = time2;
	this->totalseats = totalseats;
	seatsbooked = 0;
	seatsavailable = totalseats - seatsbooked;
}
string Flight::getflightname()
{
	return this->flightname;
}
string Flight::getflightid()
{
	return this->flightid;
}
string Flight::getsource()
{
	return this->source;
}
string Flight::getdestination()
{
	return this->destination;
}
string Flight::gettime1()
{
	return this->time1;
}
string Flight::gettime2()
{
	return this->time2;
}
int Flight::gettotalseats()
{
	return this->totalseats;
}
int Flight::getseatsbooked()
{
	return this->seatsbooked;
}
int Flight::getseatsavailable()
{
	return this->seatsavailable;
}
void Flight::setflightname(string flightname)
{
	this->flightname = flightname;
}
void Flight::setflightid(string flightid)
{
	this->flightid = flightid;
}
void Flight::settime1(string time1)
{
	this->time1 = time1;
}
void Flight::settime2(string time2)
{
	this->time2 = time2;
}
void Flight::setsource(string source)
{
	this->source = source;
}
void Flight::setdestination(string destination)
{
	this->destination = destination;
}
void Flight::settotalseats(int totalseats)
{
	this->totalseats = totalseats;
}
bool Flight::reservation(Customer obj)
{
	int x;
	bool flag = false;
	for (x = 0; x < customerlist.size(); x++)
	{
		if (obj.getid() == customerlist[x].getid())
		{
			flag = true;
			
			break;
		}
	}
	if (flag == true)
	{
		return false;
	}
	else
	{
		seatsbooked++;
		seatsavailable = totalseats - seatsbooked;
		customerlist.push_back(obj);
		return true;
	}
}
bool Flight::cancellation(Customer obj)
{
	int x, idx;
	bool flag = false;
	for (x = 0; x < customerlist.size(); x++)
	{
		if (obj.getid() == customerlist[x].getid())
		{
			flag = true;
			idx = x;
			
			break;

		}
	}
	if (flag == false)
	{
		return false;
	}
	else
	{
		customerlist.erase(customerlist.begin() + idx);
		seatsbooked--;
		seatsavailable = totalseats - seatsbooked;
		return true;
	}
}
vector<Customer>Flight::getcustomers()
{
	return customerlist;
}

	
