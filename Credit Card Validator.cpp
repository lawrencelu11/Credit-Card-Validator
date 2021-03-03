#include <iostream>
#include <string>

using namespace std;

void setDigits(int (&digits)[16]);
void getIssuer(int digits[16]);
void checkSum(int digits[16]);
void displayDigits(int digits[16]);

int main()
{
    int digits[16];
    setDigits(digits);
    displayDigits(digits);
    getIssuer(digits);
    checkSum(digits);
    return 0;
}

void setDigits(int (&digits)[16])
{
    long long digit;
    cout << "Enter your credit card number: ";
    cin >> digit;
    for(int i = 16; i >= 1; i--)
    {
        digits[i] = digit % 10;
        digit /= 10;
    }
    cout << "\n";

}

void getIssuer(int digits[16])
{
    string cardIssuer = "";

    if(digits[1] == 4)
    {
        cardIssuer = "Visa";
    }else if(digits[1] == 5 && digits[2] <= 5 && digits[2] >= 1)
    {
        cardIssuer = "MasterCard";
    }else if(digits[1] == 3 && digits[2] == 6 || digits[2] == 8)
    {
        cardIssuer = "DinersClub";
    }else if((digits[1] == 6 && digits[2] == 0 && digits[3] == 1 && digits[4] == 1) || (digits[1] == 6 && digits[2] == 5))
    {
        cardIssuer = "Discover";
    }else if(digits[1] == 3 && digits[2] == 5)
    {
        cardIssuer = "Japan Credit Bureau";
    }else if(digits[1] == 3 && digits[2] == 4 || digits[2] == 7)
    {
        cardIssuer = "American Express";
    }
    else{
        cout << "No issuer found!\n";
    }
    cout << "Card Issuer: " << cardIssuer;
    cout << "\n";
}

void checkSum(int digits[16])
{
    int newDigit, firstDigit, secondDigit, totalDigit, result, sum = 0;
    for(int i = 1; i <= 15; i+=2)
    {
        newDigit = digits[i] * 2;
        digits[i] = newDigit;
        if(digits[i] > 9 && digits[i] < 100)
        {
            firstDigit = digits[i] / 10;
            secondDigit = digits[i] % 10;
            totalDigit = firstDigit + secondDigit;
            digits[i] = totalDigit;
        }
        sum += digits[i];
    }
    result = sum + digits[16];
    if(result % 10 == 0)
    {
        cout << "Credit card is valid\n";
    }else{
        cout << "Credit card is not valid\n";
    }
}

void displayDigits(int digits[16])
{
    for(int i = 1; i <= 4; i++)
    {
        cout << digits[i];
    }
    cout << "-";
    
    for(int i = 5; i <= 8; i++)
    {
        cout << digits[i];
    }
    cout << "-";
    
    for(int i = 9; i <= 12; i++)
    {
        cout << digits[i];
    }
    cout << "-";
    
    for(int i = 13; i <= 16; i++)
    {
        cout << digits[i];
    }
    cout << "\n";
}


