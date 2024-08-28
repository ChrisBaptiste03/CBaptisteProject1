#include <iostream>
#include <string>
using namespace std;
/*
Student Name: Chris Baptiste 
Course: C++ 2334 Programming 

Problem Statement: This program design is going to encrypt a password you will enter to generate differnt passoword for your computer login
*/

// Creating this section to send the generated password to see if the password is valid or not vaild. Also this is the function area
bool isValidPassword(const string & password) {
return password.length() >= 12; // This equal if the password is true 
return password.length() <= 12; // This equal is the password is false 
}

// This section outputs the the correct key being inputed into the password making it true 
bool isVaildKey(int key) {
    return key >= 1 && key <= 20;
}

// This section is where the shift ciper will be created to output the numbers from the ASCll table.
string encrypt( const string & password, int key) {
    string encryptedPassword;
for( char c : password) {
if(c >= '!' && c <= '~') {
    char shiftedChar = c + key;
    if(shiftedChar > '~') {
        shiftedChar = '!' + (shiftedChar - '~' - 1);
    }
    encryptedPassword += shiftedChar;
}
else {
    encryptedPassword += c;
}
}
return encryptedPassword;
}


int main() {
 string Password;
int key;

// Ask for the password in this section
// Hint Example of a password to use: i@qf&6_XUEyC , 2aCjGTEg^7<a
do{
    cout << "Enter the password: ";
    getline(cin, Password);
   if (!isValidPassword(Password)) {
    cout << "The password must be at least 12 characters long.\n"; 
   }
}
while (!isValidPassword(Password));

 // Asking for the key. If it is not true it will ask you again to type the correct number
 do{
    cout << "Enter the key (1-20): ";
    cin >> key;
    if(!isVaildKey(key)) {
        cout << "The key must be between 1 and 20, you entered is " << key << ".\n"; // This section outputs the false statement showing the person didn't put the key correctly
    }
 }
 while (!isVaildKey(key));

 
//Encrypt password section
string encryptPassword = encrypt(Password, key);

// This is the results section putting everything togther to output that password
cout << "Your password is " << Password 
     << ", the encrypted version of your password is " << encryptPassword 
     << " with a key of " << key << ".\n";

// Exit successfully
return 0;
}



