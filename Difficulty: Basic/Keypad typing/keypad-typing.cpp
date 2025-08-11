// User function template for C++

// Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n) {
    // code here
    string result = "";
    for (char c : s) {
        if (c >= 'a' && c <= 'c') result += '2';
        else if (c >= 'd' && c <= 'f') result += '3';
        else if (c >= 'g' && c <= 'i') result += '4';
        else if (c >= 'j' && c <= 'l') result += '5';
        else if (c >= 'm' && c <= 'o') result += '6';
        else if (c >= 'p' && c <= 's') result += '7';
        else if (c >= 't' && c <= 'v') result += '8';
        else if (c >= 'w' && c <= 'z') result += '9';
    }
    return result;
    
}
