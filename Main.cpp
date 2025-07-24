#include <iostream>
using namespace std;


int text;
string binaryreverse;
string binary;
char choice;


int main() {
    cout << "Please choose a conversion type:" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Text to Binary" << endl;
    cin >>choice;
    if (choice== '1'){
        // Prompt the user for an integer input
        cout << "Please enter the count for conversion:";
        cin >>text;

        //Convert the integer to binary
        while (text != 1) {
            binaryreverse = binaryreverse+to_string(text%2);
            text=text/2;
        }
        binaryreverse = binaryreverse + to_string(text);

        // Reverse the string to get the correct binary representation
        for (int i= binaryreverse.length() - 1; i >= 0; i--) {
            binary = binary + binaryreverse[i];
        }

        // Add leading zeros to make it 8 bits if necessary
        binary.length()<8? binary.insert(0, 8 - binary.length(), '0') : binary;

        // Output the binary representation
        cout << "The binary representation is: " << binary << endl;
    }
    else if (choice=='2') {
        // Prompt the user for a string input
        cout << "Please enter the text for conversion:";
    }

}