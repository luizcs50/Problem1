#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("\n\nTotal of coins given to the costumer: %i\nQuarters: %i\nDimes: %i\nNickels: %i\nPennies: %i\n", coins, quarters, dimes, nickels, pennies);
}

int get_cents(void)
{
    int centsGiven;
    do
    {
        centsGiven = get_int("Insert the number of cents: ");
    }while(centsGiven < 0);

    return centsGiven;
}

int calculate_quarters(int cents)
{
    int numOfQuartes = cents / 25;
    return numOfQuartes;
}

int calculate_dimes(int cents)
{
    int numOfDimes = cents / 10;
    return numOfDimes;
}

int calculate_nickels(int cents)
{
    int numOfNickels = cents / 5;
    return numOfNickels;
}

int calculate_pennies(int cents)
{
    int numOfPennies = cents / 1;
    return numOfPennies;
}
