#include<iostream>
#include "String.h"
using namespace std;
class PersonDetails{
	String name;
	String fatherName;
	String motherName;
	String gender;
	String address;
	String contactNo;
	String cardNumber;
	String pin;
	String AccountType;
	double balance=0;
	double overdraftLimit=0;
	public :
		PersonDetails();
		long int generateCardNumber();
		int generatePin();
};

PersonDetails::PersonDetails(){
	cout<<"constructor for person details called"<<endl;
	cout<<"Enter Aplicant's Name (first name middle name last name):";
	cin>>name;
	cout<<"Enter Father's Name(first name middle name last name):";
	cin>>fatherName;
	cout<<"Enter Mother's Name(first name middle name last name):";
	cin>>motherName;
	cout<<"Enter Aplicant's Gender (Male/Female):";
	cin>>gender;
	cout<<"Enter Aplicant's Address:";
	cin>>address;
	cout<<"Enter Contact Number:";
	cin>>contactNo;
	cout<<"Enter Account Type:"<<endl<<"Enter 1 for Savings Account"<<endl<<"Enter 2 for Current Account"<<endl<<"Enter choice:";
	int c;
	cin>>c;
	cout<<"Enter Account Opening Balance(above 1000) :";
	cin>>balance;
	if(c==2){
		cout<<"Your Overdraft Limit is:"<<5*balance;
	}
	this->cardNumber=generateCardNumber();
	this->pin=generatePin();
}
class AccountType{
	String type;
	int openBalance;
	public:
		AccountType(PersonDetails );
};
