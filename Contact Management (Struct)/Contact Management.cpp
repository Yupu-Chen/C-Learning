#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void showMenu()
{
	cout << "*********************************" << endl;
	cout << "***** 1. Add contact ************" << endl;
	cout << "***** 2. Show contact ***********" << endl;
	cout << "***** 3. Delete contact *********" << endl;
	cout << "***** 4. Find contact ***********" << endl;
	cout << "***** 5. Change contact *********" << endl;
	cout << "***** 6. Clear all contacts *****" << endl;
	cout << "***** 0. Exit *******************" << endl;
	cout << "*********************************" << endl;

}

struct Person
{
	string name;
	int gender; //1 Male 2 Female
	int age;
	string phone;
	string address;
};

#define MAX 1000

struct addressBooks
{
	struct Person personArr[MAX];
	int size;

};

void displayPerson(struct addressBooks AddBooks)
{	
	if (AddBooks.size == 0)
	{
		cout << "No contact" << endl;
	}
	else
	{
		for (int i = 0; i < AddBooks.size; i++)
		{
			cout << "The " << i + 1 << " contact: " << endl;
			cout << AddBooks.personArr[i].name << "\t";
			/*if (AddBooks.personArr[i].gender == 1)
			{
				cout << "Male" << endl;
			}
			else
			{
				cout << "Female" << endl;
			}*/
			cout <<( AddBooks.personArr[i].gender == 1 ? "Male" : "Female" )<< "\t";
			cout << AddBooks.personArr[i].age << "\t";
			cout << AddBooks.personArr[i].phone<< "\t";
			cout << AddBooks.personArr[i].address<< endl;
		}
	}
	system("pause");
	system("cls");
}

void addPerson(addressBooks* abs)
{
	if (abs->size == MAX) // check if it is within the size
	{
		cout << "The address book is full" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		string name; // enter the name
		cout << "Please enter the name: " << endl;
		getline(cin, name); // getline() ends with \n so that it can catch space 
		abs->personArr[abs->size].name = name;



		int gender;
		cout << "Please enter the gender: " << endl;
		while (true)
		{	
			cout << "1 --- Male" << endl;
			cout << "2 --- Female" << endl;
			cin >> gender;

			if (gender == 1 || gender == 2)
			{
				abs->personArr[abs->size].gender = gender;
				break;
			}
			else
			{
				cout << "Invalid. Please try again." << endl;
			}
		}


		int age = 0;
		cout << "Please enter the age: " << endl;
		cin >> age;
		abs->personArr[abs->size].age = age;


		string phone;
		cout << "Please enter the phone number: " << endl;
		cin >> phone;
		abs->personArr[abs->size].phone = phone;


		string address;
		cin.ignore();
		cout << "Please enter the address: " << endl;
		getline(cin, address);
		abs->personArr[abs->size].address = address;


		abs->size++;
		cout << "Add success" << endl;

		system("pause");
		system("cls");
	}
}


int exist(addressBooks* AddBooks, string name)
{
	for (int i = 0; i < AddBooks->size; i++)
	{
		if (AddBooks->personArr[i].name == name) // if the person's name is the same as we enter
		{
			return i;
		}
	}
	return -1; // if not found
}

void deletePerson(addressBooks* abs)
{
	cout << "Please enter the name" << endl;
	string name;
	getline(cin, name);

	int ret = exist(abs, name); // -1 or index

	if (ret != -1)
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->size--;
		cout << "Success" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Person not found" << endl;
		system("pause");
		system("cls");
	}
}

void findPerson(addressBooks abs)
{
	cout << "Please enter the name" << endl;
	string name;
	getline(cin, name);
	int ret = exist(&abs, name);
	if (ret != -1)
	{
		cout << "Name: " << abs.personArr[ret].name <<"\t";
		cout << "Gneder: " << (abs.personArr[ret].gender == 1 ? "Male" : "Female") <<"\t";
		cout << "Age: " << abs.personArr[ret].age <<"\t";
		cout << "Phone: " << abs.personArr[ret].phone <<"\t";
		cout << "Address: " << abs.personArr[ret].address << endl;

		system("pause");
		system("cls");
	}

	else
	{
		cout << "Person not found" << endl;
		system("pause");
		system("cls");
	}
}

int main()
{
	int choice;

	struct addressBooks AddBook1;
	AddBook1.size = 0;

	

	while (true)
	{
		showMenu();
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			addPerson(&AddBook1);
			break;
		case 2:
			displayPerson(AddBook1);
			break;
		case 3:
			deletePerson(&AddBook1);
			break;
		case 4:
			findPerson(AddBook1);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "See you again" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}
	return 0;
}
