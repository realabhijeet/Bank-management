#include<iostream>
#include<vector>
using namespace std;
class BankAccount{
	private:
		string name;
		int accountNum;
		double balance;
	public:
		BankAccount(string n, int ac,double bal){
			name = n;
			accountNum = ac;
			balance = bal;
		}
		string getName(){
			return name;
		}
		int getAccountNum(){
			return accountNum;
			}
		double getBalance(){
			return balance;
		}
		void deposit(double amount){
			balance = balance + amount;
		}	
		void withdraw(double amount){
			if(balance >= amount){
				balance = balance - amount;
				cout<<"Withdraw Successfully..."<<endl;
			}else{
				cout<<"Insufficient Balance...."<<endl;
			}
		}	
};
class BankManagement{
	private:
		vector<BankAccount> accounts;
	public:
		void AddAccount(string name,int accountNum,double balance){
			accounts.push_back(BankAccount(name,accountNum,balance));
		}
		void showAllAccounts(){
			cout<<"All Account Holders "<<endl;
			for(int i = 0; i<accounts.size();i++){
				cout<<"Name :"<<accounts[i].getName()<<" Account Number :"<<accounts[i].getAccountNum()<<" Balance :"<<accounts[i].getBalance()<<endl;
			}
		}
		void searchAccount(int account){
			cout<<"Account Holder "<<endl;
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNum()==account){
				cout<<"Name :"<<accounts[i].getName()<<" Account Number :"<<accounts[i].getAccountNum()<<" Balance :"<<accounts[i].getBalance()<<endl;	
				}
			}
		}
		BankAccount* findAccount(int accountNum){
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNum()==accountNum){
					return &accounts[i];
				}
			}
		}
};
main(){
	
	BankManagement bank;
	int choice;
	char op;
	do{
		system("cls");
		//cout<<"<<<<<<<<<< Bank Management System >>>>>>>>>>"<<endl;
		cout << "-------------------------------" << endl;
    	cout << "Bank Management System" << endl;
    	cout << "-------------------------------" << endl;
		cout<<endl;
		cout<<"1. Creat New Account"<<endl;
		cout<<"2. Show All Account"<<endl;
		cout<<"3. Search Account"<<endl;
		cout<<"4. Deposit Money"<<endl;
		cout<<"5. Withdraw Money"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"======================"<<endl;
		cout<<"Enter Your Choice :";
		cin>>choice;
		switch(choice){
			case 1:{
				string name;
				int accountNum;
				double balance;
				cout<<"Enter Name :";
				cin>>name;
				cout<<"Enter Account Number :";
				cin>>accountNum;
				cout<<"Enter Initial Balance :";
				cin>>balance;
				bank.AddAccount(name,accountNum,balance);
				cout<<"Account Created Successfully...."<<endl;
				break;
			}
			case 2:{
				bank.showAllAccounts();
				break;
			}
			case 3:{
				int accountNum;
				cout<<"Enter Account Number :";
				cin>>accountNum;
				bank.searchAccount(accountNum);
				break;
			}
			case 4:{
				int accountNum;
				double amount;
				cout<<"Enter Account Number to Deposit Money :";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"Enter Amount to Deposit :";
					cin>>amount;
					account->deposit(amount);
					cout<<""<<amount<<" Deposit Successfully ...."<<endl;
				}else{
					cout<<"Acount Not Found ..."<<endl;
				}
				break;
			}
			case 5:{
				int accountNum;
				double amount;
				cout<<"Enter Account Number to Withdraw Money :";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"Enter Amount to withdraw :";
					cin>>amount;
					account->withdraw(amount);
					
				}else{
					cout<<"Acount Not Found ..."<<endl;
				}
				break;
			}
			case 6:{
				exit(1);
				break;
			}
	}
	cout<<"Do You Want to Continue or Exit ?? [press 'y' to continue]";
	cin>>op;
		
	}while(op == 'y'||op =='Y');
	
}