#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string text;
int takedecimal;
int repeat=1;
char choice;
vector<char> ascii_chars;
vector<int> decimal_values;
vector<int> binary_to_decimal(string binary) {
    int decimal_value=0;
    int part_size=8;
           
    // Remove spaces from the binary string
    for(int i=0; binary[i]; i++)
        if(binary[i] == ' '){
            binary.erase(i, 1); 
        }
    
    for(int i=0; binary.length()>i; i=i+8){
        // Extract 8 bits from the binary string
        string part= binary.substr(i, part_size);
        
        for (int j = 0; j < part.length(); j++) {
            decimal_value = decimal_value + pow(2,(part_size-1-j))*(part[j] - '0');
            }   
        
        
        // Store the decimal value in a vector
        decimal_values.push_back(decimal_value);
        decimal_value = 0;
        }

    return decimal_values;
}




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
    if (binary.length() < 16) {
        binary.insert(0, 16 - binary.length(), '0');
    }

    // Return the binary value
    return binary;
}

void contuinue_conversion(){
    cout << "Do you want to use program again? (y/n): ";
    string continue_choice;
    cin >> continue_choice;
    if (continue_choice == "y" || continue_choice == "Y") {
        repeat=1;// Restart the program
    } 
    else if (continue_choice == "n" || continue_choice == "N")
    {
        repeat=0; // Exit the program
    }
    
    else {
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        contuinue_conversion();
    }
    
}



int main() {
    while (repeat==1) {
        //Addding visible ASCII characters to the vector
        for (int i = 32; i <= 126; ++i) {
            ascii_chars.push_back(static_cast<char>(i));
        }
            
        // Prompt the user for a conversion choice  
        cout << "1. Decimal to Binary" << endl;
        cout << "2. Text to Binary" << endl;
        cout << "3. Binary to Text" << endl;
        cout << "Please choose a conversion type:";
        cin >>choice;
        if (choice== '1'){
            // Prompt the user for an integer input
            cout << "Please enter the count for conversion:";
            cin >>takedecimal;
            // Call the function to convert decimal to binary and print the result
            cout << "The binary representation is: " << decimal_to_binary(takedecimal);
            cout << endl;
            contuinue_conversion();// Ask the user if they want to continue

        }
        else if (choice=='2') {
            // Prompt the user for a string input and give the text for convert
            cout << "Please enter the text for conversion:";
            cin.ignore();
            getline(cin, text);
            string result="";
            // Find the char in the vector for which ASCII value is between 32 and 126
            for (int l=0;l<text.length();l++){
                for (int i=0;i<ascii_chars.size();i++){
                    if ( text[l] == ascii_chars[i]) {
                        // Call the function to convert each character to binary and print the result
                        result=result+decimal_to_binary(i+32)+" ";
                    }
                }
            }
            cout << result << endl;
            contuinue_conversion(); // Ask the user if they want to continue
        }
        else if (choice == '3'){
            string rawbinary;   
            // Prompt the user for a binary input
            cout << "Please enter the binary for conversion:";
            // Clear the input buffer to avoid issues with getline
            cin.ignore();
            getline(cin, rawbinary);
            // Call the function to convert binary to decimal and print the result
            vector<int> rawdecimals = binary_to_decimal(rawbinary);
            for (int i = 0; i < rawdecimals.size(); i++) {
                // Check if the decimal value is within the ASCII range
                if (rawdecimals[i] >= 32 && rawdecimals[i] <= 126) {
                    cout <<ascii_chars[rawdecimals[i]-32];   
                            
                } 
                else {
                    cout << "[This character is not in ASCII]";
                }
            }
            cout << endl;
        contuinue_conversion(); // Ask the user if they want to continue

        }

        else{
            cout << "Invalid choice. Please select a valid option." << endl;
            contuinue_conversion(); // Ask the user if they want to continue
        }

    }
    exit(0); // Exit the program
}



