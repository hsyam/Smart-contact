#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
using namespace std;
fstream dataFile;
const string filename = "data.txt";

class  Contactnode
{
	private :	

		string phone, fristName, lastName, email, job;
		Contactnode * next;
	public :
		Contactnode *ContactTop;
		Contactnode *ContactTopBack;
		void getDataFromFileToNode();
		void AddContact();
		void printAll();
		void print(string num);
		void updataSingle(int query);
		void updataAll();
		void sort();
		bool search(int query, string val);
		void deleteContact(string num);
		bool ValEmail(string email); 
		bool ValNumber(string num);
		void sortAndSavaFile();
};

int main()
{
	Contactnode contactObj;
	contactObj.getDataFromFileToNode();
	
	cout << "\t\t  _____ __  __          _____ _______    _____            _             _   " << endl;
	cout << "\t\t / ____|  \\/  |   /\\   |  __ \\__   __|  / ____|          | |           | |  " << endl;
	cout << "\t\t| (___ | \\  / |  /  \\  | |__) | | |    | |     ___  _ __ | |_ __ _  ___| |_ " << endl;
	cout << "\t\t \\___ \\| |\\/| | / /\\ \\ |  _  /  | |    | |    / _ \\| '_ \\| __/ _` |/ __| __|" << endl;
	cout << "\t\t ____) | |  | |/ ____ \\| | \\ \\  | |    | |___| (_) | | | | || (_| | (__| |_ " << endl;
	cout << "\t\t|_____/|_|  |_/_/    \\_\\_|  \\_\\ |_|     \\_____\\___/|_| |_|\\__\\__,_|\\___|\\__|" << endl;
	int operationNum = 0;
	char operation;
	cout << "\n\t\t\t\t\t\tSelect operation \n" << endl;
	cout << "\t\tA) Add new contact \t  \t D) Delete contact" << endl << endl;
	cout << "\t\tC) Print contacts \t  \t P) Print All " << endl << endl;
	cout << "\t\tU) Update \t \t \t S) Search" << endl << endl;
	cout << "\t\tH) Help \t\t\t Q) Quit" << endl << endl;
	while (operationNum != 8) {
		cout << "\n\t\t\t\Enter operation \n" << endl;
		cin >> operation;
		switch (operation)
		{
		case 'A':
		case 'a':
			operationNum = 1;
			break;
		case 'D':
		case 'd':
			operationNum = 2;
			break;
		case 'P':
		case 'p':
			operationNum = 3;
			break;
		case 'c':
		case 'C':
			operationNum = 4;
			break;
		case 'U':
		case 'u':
			operationNum = 5;
			break;
		case 's':
		case 'S':
			operationNum = 6;
			break;
		case 'h':
		case 'H':
			operationNum = 7;
			break;
		case 'q':
		case 'Q':
			operationNum = 8;
			break;
		default:
			operationNum = 7;
			break;
		}
		
		if (operationNum == 1) {
			system("cls");
			cout << "\t \t \t Add New Contact " << endl;
			contactObj.AddContact();
		}
		if (operationNum == 2) {
			system("cls");
			string num;
			cout << "\t \t \t Delete Contact " << endl;
			cout << "Enter Phone number For Delete" << endl;
			cin >> num;
			contactObj.deleteContact(num);
		}
		if (operationNum == 3) {
			system("cls");
			string num;
			cout << "\t \t \t Display Contacts " << endl;
			contactObj.printAll();
		}
		if (operationNum == 4) {
			string num;
			system("cls");
			cout << "\t \t \t Display Contacts " << endl;
			cout << "Enter Phone number For Display " << endl;
			cin >> num;
			contactObj.print(num);
		}
		if (operationNum == 5) {
			system("cls");
			cout << "\t \t \t Update Area " << endl;
			int x = 0;
			while (x != 7)
			{
				cout << "1 ) Update Frist Name \t \t \t 2 )Update last Name " << endl;
				cout << "3 ) Update phone \t  \t \t 4 )Update email " << endl;
				cout << "5 ) Update job  \t \t \t 6 )Update All   " << endl;
				cout << "7 ) Quit    " << endl;
				cout << "\t \t Enter Value" << endl; 
				cin >> x;

				if (x == 1) {
					contactObj.updataSingle(1);
				}
				if (x == 2) {
					contactObj.updataSingle(2);
				}
				if (x == 3) {
					contactObj.updataSingle(3);
				}
				if (x == 4) {
					contactObj.updataSingle(4);
				}
				if (x == 5) {
					contactObj.updataSingle(5);
				}
				if (x == 6) {
					contactObj.updataAll();
				}

			} 
			
		}

		if (operationNum == 6) {
		
			system("cls");
			cout << "\t \t \t Search Area " << endl;
			int x = 0;
			string val;
			while (x != 5)
			{
				cout << "1 ) Search By phone \t \t \t 2 )Search Frist Name " << endl;
				cout << "3 ) Search By email \t  \t \t 4 )Search By job " << endl;
				cout << "5 ) Quit    " << endl;
				cout << "\t \t Enter Value" << endl;
				cin >> x;

				if (x == 1) {
					cout << "Enter Phone Number  For Search" << endl;
					cin >> val;
					contactObj.search(1,val);
				}
				if (x == 2) {
					cout << "Enter Frist name For Search" << endl;
					cin >> val;
					contactObj.search(2, val);
				}
				if (x == 3) {
					cout << "Enter Email For Search" << endl;
					cin >> val;
					contactObj.search(3, val);
				}
				if (x == 4) {
					cout << "Enter job For Search" << endl;
					cin >> val;
					contactObj.search(4,val);
				}

			}

		}

		if (operationNum == 7) {
			system("cls");
			cout << "\t \t \t Help Area" << endl;
			cout << "\n\t\t\t\t\t\tSelect operation \n" << endl;
			cout << "\t\tA) Add new contact \t  \t D) Delete contact" << endl << endl;
			cout << "\t\tC) Print contacts \t  \t P) Print All " << endl << endl;
			cout << "\t\tU) Update \t \t \t S) Search" << endl << endl;
			cout << "\t\tH) Help \t\t\t Q) Quit" << endl << endl;
		}

	}


	return 0;
};
/*
	validation EMAIL With regex
*/
bool Contactnode::ValEmail(string email) {

	regex pattern;
	pattern = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
	return regex_match(email, pattern);
}
/*
validation phone
*/
bool Contactnode::ValNumber(string num) {

	if (num.length() != 11) {
		return false;
	}
	return true ; 
}

/*
	Get Data from File then Store it in Stack Based in Linked list
*/
void  Contactnode::getDataFromFileToNode() {
	dataFile.open(filename);
	while (dataFile.good()) {
		if (ContactTop != NULL) {
			Contactnode *temp = new Contactnode();
			dataFile >> temp->fristName;
			dataFile >> temp->lastName;
			dataFile >> temp->email;
			dataFile >> temp->phone;
			dataFile >> temp->job;
			temp->next = ContactTop;
			ContactTop = temp;
			ContactTopBack = temp;
		}
		else
		{
			ContactTop = new Contactnode();
			dataFile >> ContactTop->fristName;
			dataFile >> ContactTop->lastName;
			dataFile >> ContactTop->email;
			dataFile >> ContactTop->phone;
			dataFile >> ContactTop->job;
			ContactTop->next = NULL;
			ContactTopBack = ContactTop; 
		}
	}
	
	dataFile.close();
};

/*
	Add Contact to List 
	then use sortAndSavaFile() function to sort and save list in file

*/

void Contactnode::AddContact(){
	string fristName, lastName, email, phone, job;
	cout << "Enter Frist Name of contact " << endl;
	cin >> fristName;
	cout << "Enter last Name of contact " << endl;
	cin >> lastName;
	cout << "Enter email of contact " << endl;
	cin >> email;
		while (ValEmail(email)	!= true)
		{
			cout << "Enter Vaild email of contact " << endl;
			cin >> email;
		}
	cout << "Enter Phone number of contact " << endl;
	cin >> phone;
		while (ValNumber(phone) != true)
		{
			cout << "Enter Vaild Phone number of contact " << endl;
			cin >> phone;
		}
	cout << "Enter Job of contact " << endl;
	cin >> job;
	if (ContactTop != NULL) {  
		Contactnode *temp = new Contactnode;
		temp->fristName = fristName; 
		temp->lastName = lastName;
		temp->email = email;
		temp->phone = phone;
		temp->job = job;
		temp->next = ContactTop;
		ContactTop = temp;
		ContactTopBack = temp;
	}
	else {
		ContactTop = new Contactnode();
		ContactTop->fristName = fristName;
		ContactTop->lastName = lastName;
		ContactTop->email = email;
		ContactTop->phone = phone;
		ContactTop->job = job;
		ContactTop->next = NULL;
		ContactTopBack = ContactTop;
	}
	
	sortAndSavaFile();
};
/*
	print All list
*/
void Contactnode::printAll() {
	cout << "\t -----------------------------------------------------------------------------------" << endl;
	cout << "\t Frist Name \t Last name \t Phone \t\t Email \t \t\t Job " << endl;
	while (ContactTop != NULL)
	{
		cout  << " \t " << ContactTop->fristName << "\t\t" << ContactTop->lastName << "\t\t" << ContactTop->phone << "\t" << ContactTop->email << "\t\t" << ContactTop->job << endl;
		ContactTop = ContactTop->next;
	}
	ContactTop = ContactTopBack;
};
/*
	print Single Contact with number
	print(Phone number)
*/
void Contactnode::print(string num) {
	bool check = false; 
	while (ContactTop != NULL)
	{
		if (ContactTop->phone == num) {
			cout << "\t -----------------------------------------------------------------------------------" << endl;
			cout << "\t Frist Name \t Last name \t Phone \t\t Email \t \t\t Job " << endl;
			cout << " \t " << ContactTop->fristName << "\t\t" << ContactTop->lastName << "\t\t" << ContactTop->phone << "\t" << ContactTop->email << "\t\t" << ContactTop->job << endl;
			cout << "\t -----------------------------------------------------------------------------------" << endl;
			check = true;
			break; 
		}
		
		ContactTop = ContactTop->next;
		
	}

	 if (check == false) {
		cout << "Invaild Number" << endl;
	}
	ContactTop = ContactTopBack;
};

/*
	search in list with different ways
	search (Way number , value)
	return : True or False
*/

bool Contactnode::search(int num,string val) {
	bool check = false;
	/*
	Search by Number
	*/
	if (num == 1) {
		while (ContactTop != NULL)
		{
			if (ContactTop->phone == val) {
				cout << "\t \t \t \t Founded" << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				cout << "\t Frist Name \t Last name \t Phone \t\t Email \t \t\t Job " << endl;
				cout << " \t " << ContactTop->fristName << "\t\t" << ContactTop->lastName << "\t\t" << ContactTop->phone << "\t" << ContactTop->email << "\t\t" << ContactTop->job << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				check = true;
				break;
			}
			
			ContactTop = ContactTop->next;
			
		}

		if (check == false) {
			cout << "Cannot find" << endl;
		}
	}
	/*
	search by first  name
	*/
	else if (num == 2) {
		while (ContactTop != NULL)
		{
			if (ContactTop->fristName == val) {
				cout << "\t \t \t \t Founded" << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				cout << "\t Frist Name \t Last name \t Phone \t\t Email \t \t\t Job " << endl;
				cout << " \t " << ContactTop->fristName << "\t\t" << ContactTop->lastName << "\t\t" << ContactTop->phone << "\t" << ContactTop->email << "\t\t" << ContactTop->job << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				check = true;
				break;
			}

			ContactTop = ContactTop->next;
			
		}

		if (check == false) {
			cout << "Cannot found" << endl;
		}
	}
	/*
	Email
	*/
	else if (num == 3) {
		while (ContactTop != NULL)
		{
			if (ContactTop->email == val) {
				cout << "\t \t \t \t Founded" << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				cout << "\t Frist Name \t Last name \t Phone \t\t Email \t \t\t Job " << endl;
				cout << " \t " << ContactTop->fristName << "\t\t" << ContactTop->lastName << "\t\t" << ContactTop->phone << "\t" << ContactTop->email << "\t\t" << ContactTop->job << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				check = true;
				break;
			}

			ContactTop = ContactTop->next;
			
		}

		if (check == false) {
			cout << "Cannot found" << endl;
		}
	}
	/*
	Job
	*/
	else if (num == 4) {
		while (ContactTop != NULL)
		{
			if (ContactTop->job == val) {
				cout << "\t \t \t \t Founded" << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				cout << "\t Frist Name \t Last name \t Phone \t\t Email \t \t\t Job " << endl;
				cout << " \t " << ContactTop->fristName << "\t\t" << ContactTop->lastName << "\t\t" << ContactTop->phone << "\t" << ContactTop->email << "\t\t" << ContactTop->job << endl;
				cout << "\t -----------------------------------------------------------------------------------" << endl;
				check = true;
			
			}

			ContactTop = ContactTop->next;
			 
		}

		if (check == false) {
			cout << "Cannot found" << endl;
		}
	}
	ContactTop = ContactTopBack;
	return check;
};

/*
	update in list with different ways
	search (Way number)
	return : Void
*/

void Contactnode::updataSingle(int query) {
	string  num;
	cout << "\t Enter Phone number for search " << endl;
	cin >> num;

	while (ValNumber(num) != true) {
	cout << "\t Enter Vaild Phone number  " << endl;
	cin >> num;
	}
	while (search(1,num) != true)
	{
	cout << "\t Enter Vaild Phone number for search " << endl;
	cin >> num;
	}

	
	string NewNum = num;
	while (ContactTop != NULL) {
		if (ContactTop->phone == NewNum) {
			string val;
			
			/*
				update Frist Name 
			*/
			if (query == 1) {
				cout << "Enter First Name for update" << endl;
				cin >> val;
				ContactTop->fristName = val;
			}
			/*
			update last Name
			*/
			else if (query == 2) {
				cout << "Enter last Name for update" << endl;
				cin >> val;
				ContactTop->lastName = val;
			}
			/*
			update phone
			*/
			else if (query == 3) {
				cout << "Enter last phone number for update" << endl;
				cin >> val;
				while (ValNumber(val) != true) {
					cout << "Enter vaild phone for update" << endl;
					cin >> val;
				}
				
				ContactTop->phone = val;
			}
			/*
			update email
			*/
			else if (query == 4) {
				cout << "Enter Email for update" << endl;
				cin >> val;
				while (ValEmail(val) != true)
				{
					cout << "Enter vaild Email for update" << endl;
					cin >> val;
				}
				ContactTop->email = val;
			}
			/*
			update job
			*/
			else if (query == 5) {
				cout << "Enter job for update" << endl;
				cin >> val;
				ContactTop->job = val;
			}
		}
		
		ContactTop = ContactTop->next;
	}

	ContactTop = ContactTopBack;
	sortAndSavaFile();
}


/*
	update All date bised in phone number
*/

void Contactnode::updataAll() {

	string  num;
	cout << "\t Enter Phone number for search " << endl;
	cin >> num;

	while (ValNumber(num) != true) {
		cout << "\t Enter Vaild Phone number  " << endl;
		cin >> num;
	}
	while (search(1, num) != true)
	{
		cout << "\t Enter Vaild Phone number for search " << endl;
		cin >> num;
	}


	string NewNum = num;
	while (ContactTop != NULL) {
		if (ContactTop->phone == NewNum) {
			string val;
			cout << "Enter First Name for update" << endl;
			cin >> val;
			ContactTop->fristName = val;
			cout << "Enter last Name for update" << endl;
			cin >> val;
			ContactTop->lastName = val;
			cout << "Enter last phone number for update" << endl;
			cin >> val;
			while (ValNumber(val) != true) {
				cout << "Enter vaild phone for update" << endl;
				cin >> val;
			}

			ContactTop->phone = val;
			cout << "Enter Email for update" << endl;
			cin >> val;
			while (ValEmail(val) != true)
			{
				cout << "Enter vaild Email for update" << endl;
				cin >> val;
			}
			ContactTop->email = val;
			cout << "Enter job for update" << endl;
			cin >> val;
			ContactTop->job = val;
		}
		ContactTop = ContactTop->next;
	}
	ContactTop = ContactTopBack;
	sortAndSavaFile();
}


/*
	delete date bised in phone number
*/

void Contactnode::deleteContact(string num){
	while (ValNumber(num) != true) {
		cout << "\t Enter Vaild Phone number  " << endl;
		cin >> num;
	}
	if (ContactTop != NULL) {
		while (ContactTop != NULL) {
			if ((ContactTop->next)->phone == num) {
				ContactTop->next = (ContactTop->next)->next;
				cout << "Deleted" << endl;
				break;
				
			}
			ContactTop = ContactTop->next;
		}
	}
	
	ContactTop = ContactTopBack;

	sortAndSavaFile();
}
/*
	Sort the list
*/
void Contactnode::sort()
{
	Contactnode *temp = ContactTopBack, *TEMP;
	ContactTop = ContactTopBack;
	while (temp != NULL)
	{
		while (ContactTop != NULL)
		{

			if (ContactTop->next != NULL)
				TEMP = ContactTop->next;
			else
				break;

			if (ContactTop->fristName > TEMP->fristName)
			{
				TEMP = new Contactnode;
				TEMP->fristName = ContactTop->fristName; 
				TEMP->lastName = ContactTop->lastName;
				TEMP->email = ContactTop->email; 
				TEMP->job = ContactTop->job;
				TEMP->phone = ContactTop->phone;
		
				ContactTop->phone = (ContactTop->next)->phone;
				ContactTop->fristName = (ContactTop->next)->fristName;
				ContactTop->lastName = (ContactTop->next)->lastName;
				ContactTop->email = (ContactTop->next)->email;
				ContactTop->job = (ContactTop->next)->job;

				(ContactTop->next)->phone = TEMP->phone;
				(ContactTop->next)->fristName = TEMP->fristName;
				(ContactTop->next)->lastName = TEMP->lastName;
				(ContactTop->next)->email = TEMP->email;
				(ContactTop->next)->job = TEMP->job;
			}
			ContactTop = ContactTop->next;
		}
		ContactTop = ContactTopBack;
		temp = temp->next;
	}

	
}
/*
	sort and update file 
*/
void Contactnode::sortAndSavaFile() {
	sort();
	ofstream dataFile;
	dataFile.open(filename);
	while (ContactTop != NULL)
	{
		if (ContactTop->fristName.length() > 0) {
			dataFile << ContactTop->fristName << endl;
			dataFile << ContactTop->lastName << endl;
			dataFile << ContactTop->email << endl;
			dataFile << ContactTop->phone << endl;
			dataFile << ContactTop->job << endl;
			ContactTop = ContactTop->next;
		}
		else {
			ContactTop = ContactTop->next;
		}
		
	}
	ContactTop = ContactTopBack;
}