#include <iostream>
#include<string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Main{
	string CardNumber;
	string pin;
	public :
		Main();
		bool validate(string,string);
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
			PersonDetails p();
			AccountType(PersonDetails p);
			cout<<endl<<"Your New Account with us opened successfully"<<endl<<"Thank You"<<endl;
	}
}
bool Main::validate(String cardNo,String PIN){
	
}
bool Main::ChangePin(PersonDetails p){
	
	
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
