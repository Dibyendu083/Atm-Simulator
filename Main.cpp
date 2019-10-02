#include <iostream>
#include<fstream>
#include "PersonDetails.h"

using namespace std;
#include<iostream>
using namespace std;

class Main{
	String CardNumber;
	String pin;
	public :
		Main();
		bool validate(String,String);
		void Options(int);
		void AccountType(PersonDetails);
		bool ChangePin(PersonDetails);
		bool BalanceDeposit(int);
		bool BalanceDeduct(int);
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
			cin>>pin;
			if(validate(CardNumber,pin)){
				int choice1;
				cout<<"Enter 1 for Balance Enquiry\nEnter 2 for Balance Withdrawal\nEnter 3 for Balance Deposit\nEnter 4 to change PIN\n Enter your choice:";
				cin>>choice1;
				Options(choice);
			}
			else
			{
				cout<<endl<<"Entered Card Number or PIN is incorrect";
			}
		case 2:
			PersonDetails p;
			cout<<endl<<"Your New Account with us opened successfully"<<endl<<"Thank You"<<endl;
	}
}


//*****************************//
//  @Dibyendu //

// Data Validation return true if match found else return false 
// Data is Stored in file name cardNumber.txt with 16 digit of card number and 14 digit pin number

bool Main::validate(String cardNo,String PIN){
	
     string fcnum,fpin;
    ifstream fin;					// File object for reading data
    fin.open("cardNumber.txt",ios::in);			// opening cardNumber.txt File
    fin.seekg(0);
    
    
    int found = 0;					// to check if matched found
    

	// file Reading
	
    while(fin>>fcnum )
    {
        
        
        if((fcnum.compare(cardNo)==0))
        {
            fin>>fpin;
            if((fpin.compare(PIN))==0)
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
bool Main::ChangePin(PersonDetails p){
	String PinOld;
	String PinNew;
	cout<<endl<<"Enter Current pin:";
	cin>>PinOld;
	cout<<endl<<"Enter New Pin:";
	cin>>PinNew;
	if(PinOld==p.pin){
		ofstream outFile;
		ifstream inFile;
		inFile.open("cardNumber",ios::in);
		outFile.open("cardNumber.txt",ios::out);
		while(inFile.seekg(1)!=pin);
		outFile.write(PinNew);
		cout<<endl<<"Pin changed successfully.";
		inFile.close();
		outFile.close();
		system.exit(0);	
	}	
	
}
void Main::Options(int c){
	switch(c){
		case 1:
			cout<<endl<<"Your Balance is:";
		case 2:
			int balWid;
			cout<<endl<<"Enter Amount to withdraw:";
			cin>>balWid;
			if(BalanceDeduct(balWid)){
				cout<<"Balance successfully deducted.";
				system.exit(0);
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
				system.exit(0);
			}
		case 4:
			if(ChangePin(PersonDetails p)){
				cout<<endl<<"Pin changed successfully.";
			}
			else{
				cout<<endl<<"Cannot change pin.";
				system.exit(0);
			}
	}
}
bool Main::BalanceDeduct(int bal){

}
bool Main::BalanceDeposit(int bal){
	
}

int main(int argc, char** argv) {
	system("pause");
	return 0;
}
