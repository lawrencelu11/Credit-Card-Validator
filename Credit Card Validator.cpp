#include <iostream>

using namespace std;

int main()
{

    int cardNum[16];
    int digit, digit2, firstDig, secondDig, totalDig, checkSum;
    int sum = 0;

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
        digit2 = cardNum[j] * 2;
        cardNum[j] = digit2;
        if(cardNum[j] > 9 && cardNum[j] < 100)
        {
            firstDig = cardNum[j] / 10;
            secondDig = cardNum[j] % 10;
            totalDig = firstDig + secondDig;
            cardNum[j] = totalDig;
        }
        sum += cardNum[j];
    }

    checkSum = sum + cardNum[16];

    if(checkSum % 10 == 0)
    {
        cout << "\nCredit card is valid!\n";
    }else{
        cout << "\nCredit card is not valid\n";
    }

    return 0;
}
