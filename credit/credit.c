#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

// American express 15 digits 34 37
// Mastercard 16 digits 51 52 53 54 55
// Visa 13 or 16 digits and starts with 4

bool checksum (long , int);
int getFirstDigitsOfANumber(long creditNumber, int length);

int main(void)
{
    long creditNumber = get_long("Number: ");
    int length = (int) log10(creditNumber) + 1;

    bool checkResult = checksum(creditNumber, length);

    if (checkResult ==  false)
    {
        printf("INVALID\n");
        exit(1);
    }

    int firstDigits = getFirstDigitsOfANumber(creditNumber, length);

    if (firstDigits == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }else if ((firstDigits > 50 && firstDigits < 56) && length == 16)
    {
        printf("MASTERCARD\n");
    }else if ((firstDigits == 34 || firstDigits == 37) && length == 15)
    {
        printf("AMEX\n");
    }else
    {
        printf("INVALID\n");
    }



}

bool checksum(long creditNumber, int length)
{
    int checksum = 0;

    for (int i = 1; i <= length; i += 2)
    {
        int splitNum = (creditNumber /  (long)pow(10, i) % 10) * 2;

        if (splitNum < 10)
        {
            checksum += splitNum;
        }else
        {
            checksum += splitNum / 10 + splitNum % 10;
        }

    }

    checksum += creditNumber % 10;

    for (int i = 2; i <= length; i+= 2) {
        checksum += creditNumber / (long)pow(10, i) % 10;
    }

    return (checksum % 10 == 0)
    ? true
    : false;
}

int getFirstDigitsOfANumber(long creditNumber, int length) {
    int firstDigits = creditNumber / (long)pow(10, length - 1) % 10;

    if (firstDigits != 4)
    {
        firstDigits = firstDigits * 10 + (creditNumber / (long)pow(10, length - 2)) % 10;
    }

    return firstDigits;

}