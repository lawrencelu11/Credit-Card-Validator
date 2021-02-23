#include <iostream>

using namespace std;

void validateCard();

int main()
{
    validateCard();
    return 0;
}

void validateCard()
{
    int cardNum[16];
    int digit, digit2, firstDig, secondDig, totalDig, checkSum;
    int sum = 0;

    // For loop iterates each inputted digit the user enters and assigned to its respective element in the array
    cout << "Enter your credit card number.\n";
    for(int i = 1; i <= 16; i++)
    {
        cin >> digit;

        if(digit < 10)
        {
            cardNum[i] = digit;

        }else{
            cout << "Must be a number and less than 10. You are where you left off, try again.\n";
            continue;
        }
    }


    for(int j = 1; j <= 15; j+=2)
    {
        digit2 = cardNum[j] * 2; //Starting from the first digit, every second digit is multiple by two
        cardNum[j] = digit2;
        if(cardNum[j] > 9 && cardNum[j] < 100) // Checks if the multiplied digit is a two digit number, if so, add both those digits together and make that the new digit.
        {
            firstDig = cardNum[j] / 10;        // Stores the first digit
            secondDig = cardNum[j] % 10;       // Stores second digit
            totalDig = firstDig + secondDig;   // Add both digits
            cardNum[j] = totalDig;             // The resulting digit is assigned as a digit in the array
        }
        sum += cardNum[j];    // 15 digits are added together
    }

    checkSum = sum + cardNum[16]; // The sum is added by the last digit.

    if(checkSum % 10 == 0)  // If the number is evenly a multiple of 10, then the credit card is valid.
    {
        cout << "\nCredit card is valid!\n";
    }else{
        cout << "\nCredit card is not valid\n";
    }
}
