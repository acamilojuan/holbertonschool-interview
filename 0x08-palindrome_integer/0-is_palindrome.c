#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or not a given
 * unsigned integer is a palindrome
 * @n: is a integer
 * Return: 1 if n is palindrome and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	int reversed = 0;
	int original = n;
	int reminder;

	while (n != 0)
	{
		reminder = n % 10;
		reversed = reversed * 10 + reminder;

		n /= 10;
	}

	if (reversed == original)
		return (1);

	return (0);
}
