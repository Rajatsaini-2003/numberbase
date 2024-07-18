#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int charToValue(char c) 
{
    return isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
}
char valueToChar(int value) 
{
    return value < 10 ? '0' + value : 'A' + value - 10;
}
int toBase10(const string &num, int baseFrom) 
{
    int value = 0;
    for (char c : num)
        value = value * baseFrom + charToValue(c);
    return value;
}
string fromBase10(int num, int baseTo) 
{
    string result;
    do 
    {
        result += valueToChar(num % baseTo);
        num /= baseTo;
    }
    while (num > 0);
    reverse(result.begin(), result.end());
    return result;
}
string baseConversion(const string &num, int baseFrom, int baseTo) 
{
    return fromBase10(toBase10(num, baseFrom), baseTo);
}
int main() 
{
    string number;
    int baseFrom, baseTo;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the base of the number: ";
    cin >> baseFrom;
    cout << "Enter the base to convert to: ";
    cin >> baseTo;
    cout << "The number " << number << " in base " << baseFrom << " is " 
         << baseConversion(number, baseFrom, baseTo) << " in base " << baseTo << ".\n";
    return 0;
}