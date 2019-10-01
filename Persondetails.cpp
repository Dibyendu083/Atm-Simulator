#include<iostream>
using namespace std;
class PersonDetails{
	String name;
	String fatherName;
	String motherName;
	String gender;
	String address;
	String contactNo;
	public :
		PersonDetails();
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
}
class AccountType{
	String type;
	int openBalance;
	public:
		AccountType(PersonDetails );
};
AccountType::AccountType(PersonDetails p){
	cout<<"constructor for account type called"<<endl;
	cout<<"Enter 1 for Savings Account"<<endl<<"Enter 2 for Current Account"<<endl<<"Enter your choice:";
	int ch;
	cin>>ch;
	
}
