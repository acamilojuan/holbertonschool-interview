#include <stdio.h>
#include <stdlib.h>


/**
 * is_palindrome- if number palindrome
 * @n: unsigned long number
 * Return: 1 palindrome, 0 not
 */
int is_palindrome(unsigned long n)
{
	unsigned long original_n = 0;
	unsigned long reversed_n = 0;
	unsigned long temp = 0;
	

	original_n = n;
	while (n != 0)
	{
		temp % 10;
		reversed_n = reversed_n * 10 + temp;
		n = n / 10;
	}

	if (original_n == reversed_n)
		return (1);

	return (0);
}
