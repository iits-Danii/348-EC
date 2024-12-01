#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

double extractor(string s);
int contains_alp(string s);

int main() {
    string input;
    while (true) {
        
        cout << "Enter a valid floating point number (or /'END/' to quit): " << endl;
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
    char sign = "+";
    if (s.length() > 20) {
        return -999999.99;
    } else if (contains_alp(s) > 0) {
        return -999999.99;
    } else if (s.find("+") != string::npos && s.find("-") != string::npos) {
        return -999999.99;
    } else if (s.find("+") != string::npos && s.at(0) != "+") {
        return -999999.99;
    } else if (s.find("-") != string::npos && s.at(0) != "-") {
        return -999999.99;
    } else {
        if (s.find("+") != string::npos || s.find("-") != string::npos) {
            sign = s.at(0);
            s.erase(s.begin());
        stringstream ss(s);
        double output;
        ss >> output;
        if (sign == "-") {
            output *= -1;
        }
        return output;
        }
    }
     
}


int contains_alp(string s) {
    return count_if(s.begin(), s.end(), ::isalnum);
}