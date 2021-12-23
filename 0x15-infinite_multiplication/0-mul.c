#include <stdio.h>
#include "holberton.h"

/**
 * Perror - print Error and exit
 * Return: 0.
 */
void Perror(void)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}

/**
 * check - checks if argument is valid
 * @argv: the argument
 * Return: returns the length of argument
 */
int check(char *argv)
{
int i;
for (i = 0; argv[i]; i++)
{
if (argv[i] < '0' || argv[i] > '9')
Perror();
}
return (i);
}

/**
 * res - allocates a memory malloc
 * @length: the length
 * Return: pointer
 */
char *res(int length)
{
char *p;
int i;
p = malloc(sizeof(char) * (length + 1));
if (!p)
Perror();
for (i = 0; i < length; i++)
{
p[i] = '0';
}
p[i] = '\0';
return (p);
}

/**
 * insertion - insert in array
 * @result: the array
 * @x: the product
 * @position: the position
 */
void insertion(char *result, int x, int position)
{
x = x + (result[position] - '0');
while (x > 0)
{
result[position] = (x % 10) + '0';
x /= 10;
if (x == 0)
break;
position--;
x += (result[position] - '0');
}
}

/**
 * main - Main function
 * @argc : number of arguments
 * @argv: array of pointers to arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
int m, j, i, l1, l2;
char *result, *u, *v;
if (argc != 3)
Perror();
l1 = check(argv[1]);
l2 = check(argv[2]);
result = res(l1 + l2);
u = argv[1];
v = argv[2];
for (m = l2 - 1; m >= 0; m--)
{
for (j = l1 - 1; j >= 0; j--)
{
insertion(result, ((u[m] - '0') * (v[j] - '0')), m + j + 1);
}
}
for (i = 0; result[i] == '0' && result[i + 1]; i++)
{
;
}
printf("%s\n", &result[i]);
free(result);
return (0);
}
