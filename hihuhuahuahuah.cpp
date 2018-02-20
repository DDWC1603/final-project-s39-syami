
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int GetUserChoice ();

void Encryption ();
void Decryption ();

string XorString ( string source, int key );

int main ()
{

	int choice;

	while ( 1 ) {

		choice = GetUserChoice ();

		if ( choice == 1 ) Encryption ();
		else if ( choice == 2 ) Decryption ();
		else if ( choice == 3 ) break;

	}
	return 0;

}

int GetUserChoice ()
{

	int choice;

	cout << "\t\t\t\t\t\t----------------------" << endl;
	cout << "\t\t\t\t\t\tMessage Encryption" << endl;
	cout << "\t\t\t\t\t\t----------------------" << endl;
	cout << "\t\t\t\t\t\t1) Encrypt Message" << endl;
	cout << "\t\t\t\t\t\t2) Decrypt Message" << endl;
	cout << "\t\t\t\t\t\t3) Exit" << endl << endl;
	cout << "\t\t\t\t\t\tMake a selection: ";
	cin  >> choice;

	if ( choice != 1 && choice != 2 && choice != 3 ) {

		cout << endl;
		cout << "\t\t\t\t\t\tPlease enter 1, 2, or 3" << endl;
		cout << "\t\t\t\t\t\tPress enter to exit...";

		cin.get ();
		return 3;

	}

	return choice;

}

string XorString ( string source, int key )
{

	for ( unsigned int loop = 0; loop < source.size (); loop ++ ) {

		source [loop] ^= key;

	}

	return source;

}

void Encryption ()
{

	char file_name [255];

	string message;
	string encrypted_message;

	int key;

	cout << endl;
	cout << "\t\t\t\t\t\tEnter file name: ";
	cin  >> file_name;

	cout << "\t\t\t\t\t\tEnter secret key: ";
	cin  >> key;

	cout << "\t\t\t\t\t\tEnter your secret message." << endl;
	cout << "\t\t\t\t\t\tMessage: ";

	cin.ignore ( 255, '\n' );

	getline ( cin, message );

	encrypted_message = XorString ( message, key );

	ofstream file ( file_name );

	file << encrypted_message;

	file.close ();

	cout << "\t\t\t\t\t\t\t||Done... ||" << endl << endl;

}

void Decryption ()
{

	char file_name [255];

	string message;

	int key;

	cout << endl;
	cout << "\t\t\t\t\t\tEnter file name: ";
	cin  >> file_name;

	cout << "\t\t\t\t\t\tEnter secret key: ";
	cin  >> key;

	ifstream file ( file_name );

	if ( !file.is_open () ) {

		cout << "\t\t\t\t\t\tFailed to load " << file_name << "!" << endl;
		cout << "\t\t\t\t\t\tPress enter to exit...";

		cin.get ();

		exit ( EXIT_FAILURE );

	}

	getline ( file, message );

	file.close ();

	cout << "\t\t\t\t\t\tMessage: " << XorString ( message, key ) << endl;

	cout << "\t\t\t\t\t\t\t||Done... ||" << endl ;

}
