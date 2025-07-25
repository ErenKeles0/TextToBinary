#include <iostream>
#include <string>
#include <vector>
using namespace std;

string text;
int takedecimal;;

char choice;
vector<char> ascii_chars;

string decimal_to_binary(int decimal) {
    string binaryreverse;
    string binary = "";
    //Convert the integer to binary
    while (decimal != 1) {
        binaryreverse = binaryreverse+to_string(decimal%2);
        decimal=decimal/2;
    }
    binaryreverse = binaryreverse + to_string(decimal);

    // Reverse the string to get the correct binary representation
    for (int i= binaryreverse.length() - 1; i >= 0; i--) {
        binary = binary + binaryreverse[i];
    }

    // Add leading zeros to make it 8 bits if necessary
    if (binary.length() < 8) {
        binary.insert(0, 8 - binary.length(), '0');
    }

    // Return the binary value
    return binary;
}

int main() {
    //Addding visible ASCII characters to the vector
    for (int i = 32; i <= 126; ++i) {
        ascii_chars.push_back(static_cast<char>(i));
    }
          
    // Prompt the user for a conversion choice  
    cout << "Please choose a conversion type:" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Text to Binary" << endl;
    cin >>choice;
    if (choice== '1'){
        // Prompt the user for an integer input
        cout << "Please enter the count for conversion:";
        cin >>takedecimal;
        // Call the function to convert decimal to binary and print the result
        cout << "The binary representation is: " << decimal_to_binary(takedecimal);
        cout << endl;
    }
    else if (choice=='2') {
        // Prompt the user for a string input and give the text for convert
        cout << "Please enter the text for conversion:";
        cin >> text;
        string result="";
        for (int l=0;l<text.length();l++){
            for (int i=0;i<ascii_chars.size();i++){
                if ( text[l] == ascii_chars[i]) {
                    // Call the function to convert each character to binary and print the result
                    
                    result=result+decimal_to_binary(i+32)+" ";
                    
                }
            }
        }
        cout << result << endl;
        
    }

}