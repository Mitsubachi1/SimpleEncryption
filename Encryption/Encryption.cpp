#include <iostream>
#include <fstream>
using namespace std;
void copyWithEncryption(string file);
void copyWithDecryption(string file);
int main() {
	int choice;
	string file;
	//main menu
	cout << "Welcome to my first encryption software.\n"
		<< "Main Menu:\n"
		<< "1) Encrypt\n"
		<< "2) Decrypt\n";
	cin >> choice;
	//switch statement used for menu
	switch (choice) {
	case 1:
		cout << "Enter file you wish to encrypt: ";
		cin >> file;
		copyWithEncryption(file);
		break;
	case 2:
		cout << "Enter file you wish to decrypt: ";
		cin >> file;
		copyWithDecryption(file);
		break;
	default:
		cout << "Invalid option. Please choose a valid option\n\n";
		main();
		break;
	}
	
	

}
//copies an unencrypted file and encrypts it
void copyWithEncryption(string file) {	
	char letters;
	char ch;
	int key;
	
	ifstream unencrypted(file); //opens specified file from menu
	cout << "Enter key for encryption: ";
	cin >> key;
	cout << "Save file as: "; //prompts uses the name to save the file as
	cin >> file; //variable is changed to allow saving file with a different name
	ofstream encrypted(file); //creates and opens file to store encrypted text
	cout << "Encrypted text: ";
	
while (!unencrypted.eof() && unencrypted >> letters){
	if (char ch = 20) {
		encrypted << " ";

	}
	else {
		ch = ((int)letters + key); //shifts characters ASCII values
		encrypted << ch; //outputs shifted values into destination file 
		cout << ch; //debug purposes
	}
}


	unencrypted.close();
	encrypted.close();

}

//copies an encrypted file and decrypts it
void copyWithDecryption(string file) {
	char letters;
	char ch;
	int key;
	
	ifstream encrypted(file); //opens specified file from menu
	cout << "Enter key: ";
	cin >> key;
	cout << "Save file as: "; //prompts uses the name to save the file as
	cin >> file; //variable is changed to allow saving file with a different name
	ofstream decrypted(file); //creates and opens file to store decrypted text
	
	while (!encrypted.eof() && encrypted >> letters) {
		ch = ((int)letters - key); //shifts characters ASCII values
		decrypted << ch; //outputs shifted values into destination file 
	cout << ch;
		
	}
	
 //debug purposes
	encrypted.close();
	decrypted.close();

}