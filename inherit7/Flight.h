#pragma once
#include"Customer.h"
#include<iostream>
#include<vector>
using namespace std;
class Flight
{
private:
	string flightname, flightid, source, destination, time1, time2;
	int totalseats, seatsbooked, seatsavailable;
	vector<Customer>customerlist;
public:
	Flight(string flightname, string flightid, string source, string destination, string time1, string time2, int totalseats);
	string getflightname();
	string getflightid();
	string getsource();
	string getdestination();
	string gettime1();
	string gettime2();
	int gettotalseats();
	int getseatsbooked();
	int getseatsavailable();
	void setflightname(string flightname);
	void setflightid(string flightid);
	void setsource(string source);
	void setdestination(string destination);
	void settime1(string time1);
	void settime2(string time2);
	void settotalseats(int totalseats);
	bool reservation(Customer obj);
	bool cancellation(Customer obj);
	vector<Customer>getcustomers();
};
