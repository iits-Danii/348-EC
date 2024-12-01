#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

double extractor(string s);


int main() {
    string input;
    while (true) {
        
        cout << "Enter a valid floating point number (or 'END' to quit): " << endl;
        cin >> input;
        
        if (input == "END") {
            break;
        }

        double num = extractor(input);
        
        if (num != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << num << endl;
        } else {
            cout << "The input is invalid." << endl;
        }

    }
}



double extractor(string s) {
    if (s.length() > 20) {
        return -999999.99;
    } else if (s.find("+") != string::npos && s.find("-") != string::npos) {
        return -999999.99;
    } else if (s.find("+") != string::npos || s.find("-") != string::npos) {
        if (s[0] != '-' && s[0] != '+') {
            return -999999.99;
        }
    }
    
    bool is_negative = false;
    if (s[0] == '-') {
        is_negative = true;
        s.erase(0, 1);
    } else if (s[0] == '+') {
        s.erase(0, 1);
    } 

    double output = 0.0;
    int decimal_pos = -1;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.') {
            if (decimal_pos != -1) return -999999.99; //if the val of decimal_pos changes before this line is run, there is more than one '.' therefore returns error
            decimal_pos = i;
        } else if (s[i] < '0' || s[i] > '9') { //Uses ASCII comparisons as 0-9 are ordered, returns error if any other possible character is present
            return -999999.99; 
        }
    }

    if (decimal_pos == -1) {
        decimal_pos = s.length(); //sets decimal at end if there isn't one defined
    } 

    for (int i = 0; i < decimal_pos; ++i) {
        output = output * 10.0 + (s[i] - '0'); //'builds' the integer part (before the decimal) digit by digit by converting each character into a numeric value
    }

    double decimal_multiplier = 0.1;
    for (int i = decimal_pos + 1; i < s.length(); ++i) {
        output += (s[i] - '0') * decimal_multiplier;
        decimal_multiplier *= 0.1;
    }

    if (is_negative == true) {
        output *= -1;
    }

    return output;
        
    
     
}

