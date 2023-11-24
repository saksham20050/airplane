#include<iostream>
#include<string>
#include<stdio.h>
#include"Customer.h"
#include"Flight.h"
using namespace std;
vector<Customer>customer;
vector<Flight>flightlist;
vector<Customer>customerreserve;
int x;
bool checkemail(string customeremail)
{
	bool flag = false;
	for (x = 0; x < customeremail.length(); x++)
	{
		if (customeremail[x]=='@')
		{
			flag = true;
			break;
		}
	}
	return flag;
}
bool checkid(string customerid)
{
	bool flag;
	flag = false;
	for (x = 0; x < customer.size(); x++)
	{
		if (customerid == customer[x].getid())
		{
			flag = true;
			break;
		}
	}
	return flag;
}
bool checkdigitid(string customerid)
{
	bool flag = false;
	int c=0;
	for (x = 0; x < customerid.length(); x++)
	{
		c++;
	}
	if (c == 3)
	{
		flag = true;
	}
	return flag;
}
void addcustomer()
{
	string customername, customerid, customeremail, customeraddress, customerhalal;
	while (true)
	{
		
		cout << "Enter the name of the customer " << endl;
		getline(cin, customername);
		if (customername == "")
		{
			cout << "Sorry the customer name u entered cant be blank,pls enter a valid customer name " << endl;

		}
		else
		{
			break;
		}

	}
	while (true)
	{
		cout << "Enter the 3 digit id of the customer " << endl;
		getline(cin, customerid);
		if (checkid(customerid) == true)
		{
			cout << "Sorry the customer id u entered is already in the database,pls enter a new customer id " << endl;

		}
		else if (customerid == "")
		{
			cout << "Sorry the customer id cant be blank,pls enter a valid customer id " << endl;
		}
		else if (checkdigitid(customerid) == false)
		{
			cout << "Sorry the id u entered must be of 3 digits " << endl;
		}
		else if (customerid[0] == '0')
		{
			cout << "Sorry the customer id cant start with 0,pls enter a valid customer id " << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the email of the customer " << endl;
		getline(cin, customeremail);
		if (customeremail == "")
		{
			cout << "Sorry the email of the customer cant be blank,pls enter a valid email for the customer " << endl;
		}
		else if (checkemail(customeremail) == false)
		{
			cout << "Sorry the email must contain @,pls enter the email id again " << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the address for the customer " << endl;
		getline(cin, customeraddress);
		if (customeraddress == "")
		{
			cout << "Sorry the address cant be blank,pls enter the address again " << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter whether the customer can eat halal meat or not " << endl;
		getline(cin, customerhalal);
		if (customerhalal == "")
		{
			cout << "Sorry the answer cant be blank,pls give a valid answer" << endl;
		}
		else
		{
			break;
		}
	}
	Customer obj(customername, customerid, customeremail, customeraddress, customerhalal);
	customer.push_back(obj);
	cout << "Customer added successfully " << endl;
}
void editcustomer()
{
	string customername, customeremail, customeraddress, customerhalal,editid;
	int idx;
	cout << "Enter the id of the customer which u wanna edit " << endl;
	getline(cin, editid);
	bool flag = false;
	for (x = 0; x < customer.size(); x++)
	{
		if (editid == customer[x].getid())
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in the list,pls enter a valid customer id" << endl;
	}
	else
	{
		while (true)
		{
			cout << "Enter the name of the customer " << endl;
			getline(cin, customername);
			if (customername == "")
			{
				cout << "Sorry the customer name u entered cant be blank,pls enter a valid customer name " << endl;

			}
			else
			{
				break;
			}

		}
		while (true)
		{
			cout << "Enter the email of the customer " << endl;
			getline(cin, customeremail);
			if (customeremail == "")
			{
				cout << "Sorry the email of the customer cant be blank,pls enter a valid email for the customer " << endl;
			}
			else if (checkemail(customeremail) == false)
			{
				cout << "Sorry the email must contain @,pls enter the email id again " << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter the address for the customer " << endl;
			getline(cin, customeraddress);
			if (customeraddress == "")
			{
				cout << "Sorry the address cant be blank,pls enter the address again " << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter whether the customer can eat halal meat or not " << endl;
			getline(cin, customerhalal);
			if (customerhalal == "")
			{
				cout << "Sorry the answer cant be blank,pls give a valid answer" << endl;
			}
			else
			{
				break;
			}
		}
		Customer obj1(customername, editid, customeremail, customeraddress, customerhalal);
		customer[idx] = obj1;
		cout << "Customer edited successfully " << endl;
	}
}
void deletecustomer()
{
	string findid;
	int idx;
	cout << "Enter the id against which u wanna delete the customer " << endl;
	getline(cin, findid);
	bool flag = false;
	for (x = 0; x < customer.size(); x++)
	{
		if (findid == customer[x].getid())
		{
			flag = true;
			idx = x;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in the database,pls enter a valid customer id " << endl;
	}
	else
	{
		customer.erase(customer.begin() + idx);
		cout << "Customer Deletion Successfull" << endl;
	}
}
bool checkflightid(string idflight)
{
	bool flag = false;
	for (x = 0; x < flightlist.size(); x++)
	{
		if (idflight == flightlist[x].getflightid())
		{
			flag = true;
			break;
		}
	}
	return flag;

}

void addflight()
{
	string nameflight, idflight, sourceflight, destinationflight, time1flight, time2flight;
	int totalseatsflight;
	while (true)
	{
		
		cout << "Enter the name of the flight " << endl;
		getline(cin, nameflight);
		if (nameflight == "")
		{
			cout << "SOrry the flight name u entered cant be blank,pls enter the flight name again " << endl;

		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the id of the flight " << endl;
		getline(cin, idflight);
		if (checkflightid(idflight) == true)
		{
			cout << "Sorry the flight id already exists in the database,pls enter a new flight id " << endl;
		}
		else if (idflight == "")
		{
			cout << "Sorry the flight id cant be blank,pls enter the flight id again " << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter from where the flight will take off " << endl;
		getline(cin, sourceflight);
		if (sourceflight == "")
		{
			cout << "Sorry thee flight source cant be blank,pls enter a valid source for flight " << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter where will the flight land " << endl;
		getline(cin, destinationflight);
		if (destinationflight == "")
		{
			cout << "Sorry the destination of the flight cant be blank,pls enter something " << endl;
		}
		else
		{
			break;
		}

	}
	while (true)
	{
		cout << "Pls enter when will the flight take off from the airport" << endl;
		getline(cin, time1flight);
		if (time1flight == "")
		{
			cout << "Sorry the take off flight cant be blank,pls enter a valid take off time " << endl;

		}
		else
		{
			break;
		}

	}
	while (true)
	{
		cout << "Pls enter the arrival time of the flight " << endl;
		getline(cin, time2flight);
		if (time2flight == "")
		{
			cout << "Sorry the arrival time of the flight cant be blank,pls enter a valid arrival time" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Pls enter the total number of seats in the flight " << endl;
		cin >> totalseatsflight;
		if (totalseatsflight == 0)
		{
			cout << "Sorry the total seats in the flight cant be 0,pls enter something " << endl;
		}
		else
		{
			break;

		}
	}
	Flight obj(nameflight, idflight, sourceflight, destinationflight, time1flight, time2flight, totalseatsflight);
	flightlist.push_back(obj);
	cout << "Flight added successfull" << endl;
}
void editflight()
{
	string findid;
	int idx;
	cout << "Enter the id of the flight against which u wanna edit the flight details " << endl;
	getline(cin, findid);
	bool flag = false;
	for (x = 0; x < flightlist.size(); x++)
	{
		if (findid == flightlist[x].getflightid())
		{
			flag = true;
			idx = x;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in the database,pls enter a valid id " << endl;
	}
	else
	{
		string nameflight, sourceflight, destinationflight, time1flight, time2flight;
		int totalseatsflight;
		while (true)
		{
			cout << "Enter the name of the flight " << endl;
			getline(cin, nameflight);
			if (nameflight == "")
			{
				cout << "SOrry the flight name u entered cant be blank,pls enter the flight name again " << endl;

			}
			else
			{
				break;
			}
		}
		
		while (true)
		{
			cout << "Enter from where the flight will take off " << endl;
			getline(cin, sourceflight);
			if (sourceflight == "")
			{
				cout << "Sorry thee flight source cant be blank,pls enter a valid source for flight " << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter where will the flight land " << endl;
			getline(cin, destinationflight);
			if (destinationflight == "")
			{
				cout << "Sorry the destination of the flight cant be blank,pls enter something " << endl;
			}
			else
			{
				break;
			}

		}
		while (true)
		{
			cout << "Pls enter when will the flight take off from the airport" << endl;
			getline(cin, time1flight);
			if (time1flight == "")
			{
				cout << "Sorry the take off flight cant be blank,pls enter a valid take off time " << endl;

			}
			else
			{
				break;
			}

		}
		while (true)
		{
			cout << "Pls enter the arrival time of the flight " << endl;
			getline(cin, time2flight);
			if (time2flight == "")
			{
				cout << "Sorry the arrival time of the flight cant be blank,pls enter a valid arrival time" << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Pls enter the total number of seats in the flight " << endl;
			cin >> totalseatsflight;
			if (totalseatsflight == 0)
			{
				cout << "Sorry the total seats in the flight cant be 0,pls enter something " << endl;
			}
			else
			{
				break;

			}
		}
		Flight obj1(nameflight, findid, sourceflight, destinationflight, time1flight, time2flight, totalseatsflight);
		flightlist[idx] = obj1;
		cout << "Flight edited Successfull" << endl;
	}
}
void deleteflight()
{
	string findid;
	int idx;
	cout << "Enter the id against which u wanna delete the flight from the database" << endl;
	getline(cin, findid);
	bool flag = false;
	for (x = 0; x < flightlist.size(); x++)
	{
		if (findid == flightlist[x].getflightid())
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in the database,pls enter the id again " << endl;
	}
	else
	{
		flightlist.erase(flightlist.begin() + idx);
		cout << "Flight Deletion Successfull " << endl;
	}
}
void reservationofflight()
{
	string hotid,chillid;
	int idx,m;
	cout << "Enter the id of the customer against whom u wanna do the reservation " << endl;
	getline(cin, hotid);
	bool l = false;
	for (x = 0; x < customer.size(); x++)
	{
		if (customer[x].getid() == hotid)
		{
			m = x;
			l = true;
			break;
		 }
	}
	if (l == false)
	{
		cout << "Sorry the id u entered is not in the database pls enter the id again " << endl;
	}

	
	cout << "Enter the id of the flight in which u wanna do the reservation " << endl;
	getline(cin, chillid);
	bool flag = false;
	for (x = 0; x < flightlist.size(); x++)
	{
		if (flightlist[x].getflightid() == chillid)
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "SOrry the flight id u entered is not in our database,pls enter a valid flight id " << endl;
	}
	else
	{
		flightlist[idx].reservation(customer[m]);
		cout << "Flight reserved successfully!!!" << endl;
	}
}
void cancellationofflight()
{
	string cancelid;
	int idx,l;
	cout << "Enter the customer id against which u wanna do the cancellation " << endl;
	getline(cin, cancelid);
	bool flag = false;
	for (x = 0; x < customer.size(); x++)
	{
		if (cancelid == customer[x].getid())
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in our database pls enter the id again " << endl;
	}
	string chillid;
	cout << "Enter the id of the flight in which u wanna do the reservation " << endl;
	getline(cin, chillid);
	bool k = false;
	for (x = 0; x < flightlist.size(); x++)
	{
		if (flightlist[x].getflightid() == chillid)
		{
			l = x;
			k = true;
			break;
		}
	}
	if (k == false)
	{
		cout << "SOrry the flight id u entered is not in our database,pls enter a valid flight id " << endl;
	}
	else
	{
		flightlist[l].cancellation(customer[idx]);
		cout << "Flight cancellation successfull!!!" << endl;
	}
	
}
void showsummary()
{
	string findid;
	int idx;
	cout << "Enter the flight id for which u wanna show the summary " << endl;
	getline(cin, findid);
	bool flag = false;
	for (x = 0; x < flightlist.size(); x++)
	{
		if (findid == flightlist[x].getflightid())
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in our databse,pls enter the id again " << endl;
	}
	else
	{
		customerreserve = flightlist[idx].getcustomers();
		cout << "The name of the flight is : " << flightlist[idx].getflightname() << endl;
		cout << "The id of the flight is : " << flightlist[idx].getflightid() << endl;
		cout << "The source from where the flight will take off is : " << flightlist[idx].getsource() << endl;
		cout << "The destination where the flight will land is : " << flightlist[idx].getdestination() << endl;
		cout << "The time at which the flight will take off is : " << flightlist[idx].gettime1() << endl;
		cout << "The time when the flight will land is : " << flightlist[idx].gettime2() << endl;
		cout << "The total seats in the flight are : " << flightlist[idx].gettotalseats() << endl;
		cout << "The total number of seats booked are : " << flightlist[idx].getseatsbooked() << endl;
		cout << "The seats available are " << flightlist[idx].getseatsavailable() << endl;
		cout << "The Customer list for  the particular flight is " << endl;
		for (x = 0; x <customerreserve.size(); x++)
		{
			cout << "Name : " << customerreserve[x].getname() << "\t Id : " << customerreserve[x].getid() << endl;
		}
	}

}
int main()
{
	int choice;
	while (true)
	{
		cout << "*****Menu*****" << endl;
		cout << "1.Add Customer " << endl;
		cout << "2.Edit Customer details" << endl;
		cout << "3.Delete Customer " << endl;
		cout << "4.Add a new Flight " << endl;
		cout << "5.Edit the flight details" << endl;
		cout << "6.Delete a flight " << endl;
		cout << "7.Reserve a seat for the customer " << endl;
		cout << "8.Cancel a seat for the customer " << endl;
		cout << "9.Show summary for a customer " << endl;
		cout << "10. Exit" << endl;
		cout << "Enter the choice " << endl;
		cin >> choice;
		getchar();
		switch (choice)
		{
		case 1:
		{
			addcustomer();
			break;
		}
		case 2:
		{
			editcustomer();
			break;
		}
		case 3:
		{
			deletecustomer();
			break;
		}
		case 4:
		{
			addflight();
			break;
		}
		case 5:
		{
			editflight();
			break;
		}
		case 6:
		{
			deleteflight();
			break;
		}
		case 7:
		{
			reservationofflight();
			break;
		}
		case 8:
		{
			cancellationofflight();
			break;
		}
		case 9:
		{
			showsummary();
			break;
		}
		case 10:
		{
			return 0;
		}
		default:
		{
			cout << "Pls enter a valid choice" << endl;
			
		}
		}
	}
}
