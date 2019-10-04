/*
String class taking  'abhishek sharma' as 'abhishek', not taking space and after string as input.
balanceDeduct and balanceDeposit method not defined.
generateCardNumber ,generatePin is not defined.
*/

#include <iostream>
#include<string>
#include<fstream>
#include "PersonDetails.h"



using namespace std;
#include<iostream>
using namespace std;

class Main{
	String CardNumber;
	String Pin;
	public :
		Main();
		bool validate(String,String);
		void Options(int);
		void AccountType(PersonDetails);
		bool ChangePin(String,String);
	/*	bool BalanceDeposit(int);
		bool BalanceDeduct(int);
*/
};
Main::Main(){
	cout<<"constructor called"<<endl;
	int choice;
	cout<<"Enter 1 for Existing Account\nEnter 2 for New Account\nEnter your choice:";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"Enter Card Number:";
			cin>>CardNumber;
			cout<<"Enter pin:";
			cin>>Pin;
			if(validate(CardNumber,Pin)){
				int choice1;
				cout<<"Enter 1 for Balance Enquiry\nEnter 2 for Balance Withdrawal\nEnter 3 for Balance Deposit\nEnter 4 to change PIN\n Enter your choice:";
				cin>>choice1;
				Options(choice);
			}
			else
			{
				cout<<endl<<"Entered Card Number or PIN is incorrect";
			}
			break;
		case 2:
			case 2:
			PersonDetails p;
			cout<<p.name.get()<<','<<p.fatherName.get()<<','<<p.motherName.get()<<','<<p.gender.get()<<','<<p.address.get()<<','<<p.contactNo.get()<<','<<p.CardNumber.get()<<','<<p.pin.get()<<','<<p.AccountType.get()<<endl;
			fstream outFile;
			outFile.open("Account_details.csv",ios::out| ios::app);
			outFile.seekp(0,ios_base::end);
			outFile<<p.name.get()<<','<<p.fatherName.get()<<','<<p.motherName.get()<<','<<p.gender.get()<<','<<p.address.get()<<','<<p.contactNo.get()<<','<<p.CardNumber.get()<<','<<p.pin.get()<<','<<p.AccountType.get()<<"\n";
			outFile.close();
			cout<<endl<<"Your New Account with us opened successfully"<<endl<<"Thank You"<<endl;
	}
}


//*****************************//
//  @Dibyendu //

// Data Validation return true if match found else return false 
// Data is Stored in file name cardNumber.txt with 16 digit of card number and 14 digit pin number

bool Main::validate(String cardNo,String PIN){
	
     String fcnum,fpin;
    ifstream fin;					// File object for reading data
    fin.open("cardNumber.csv",ios::in);			// opening cardNumber.txt File
    fin.seekg(0);
    
    
    int found = 0;					// to check if matched found
    // file Reading
	fin>>fcnum>>",";
    while(fin>>fcnum )
    {
        
		fin>>fcnum>>",";
        
        if((fcnum==cardNo))
        {
            fin>>fpin>>",";
            if((fpin==Pin));
             found=1;
        }
       
    }
    fin.close();
            
    if(found==1)
    return true;
    else
    {
        return false;
    }
	
}

//***************************************************************//
bool Main::ChangePin(String cardNo,String pin){
	String PinOld;
	String PinNew;
	cout<<endl<<"Enter Current pin:";
	cin>>PinOld;
	cout<<endl<<"Enter New Pin:";
	cin>>PinNew;
	if(PinOld==pin){
		ofstream outFile;
		ifstream inFile;
		inFile.open("cardNumber.csv",ios::in);
		outFile.open("cardNumber.csv",ios::out);
		while(!((String)inFile.get()==CardNumber));
		if((String)inFile.get()==pin){
			outFile<<PinNew;
		}
		cout<<endl<<"Pin changed successfully.";
		inFile.close();
		outFile.close();
		return true;
		//system.exit();	
	}	
	return false;
}
void Main::Options(int c){
	switch(c){
		case 1:
			cout<<endl<<"Your Balance is:";
	/*	case 2:
			int balWid;
			cout<<endl<<"Enter Amount to withdraw:";
			cin>>balWid;
			if(BalanceDeduct(balWid)){
				cout<<"Balance successfully deducted.";
				return ;
				//system.exit(0);
			}
			else{
				cout<<"Given Amount cannot be deducted.";
			}
		case 3:
			int balDep;
			cout<<endl<<"Enter Amount to deposit:";
			cin>>balDep;
			if(BalanceDeposit(balDep)){
				cout<<endl<<"Balance successfully deposited";
				return;
				//system.exit(0);
			}
	*/	case 4:
			if(ChangePin(CardNumber,Pin)){
				cout<<endl<<"Pin changed successfully.";
			}
			else{
				cout<<endl<<"Cannot change pin.";
				//system.exit(0);
			}
	}
}
/*bool Main::BalanceDeduct(int bal){

}
bool Main::BalanceDeposit(int bal){
	
}
*/



int main(int argc, char** argv) {
	Main m;
	system("pause");
	return 0;
}
