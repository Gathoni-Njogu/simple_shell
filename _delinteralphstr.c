#include "shell.h"

/**
 * is_interv - fxn that returns true if shell is interactive
 * @info: the struct address
 *
 * Return: 1 if interactive, 0 if not
 */
int is_interv(info_m *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimtr - fxn checks if character is a delimeter
 * @b: the character to check
 * @delimtr: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delimtr(char b, char *delimtr)
{
	while (*delimtr)
		if (*delimtr++ == b)
			return (1);
	return (0);
}

/**
 *is_alphatic - fxn that checks if char is alphabetic
 *@chr: The char to input
 *Return: 1 if char is alphabetic, 0 if not
 */

int is_alphatic(int chr)
{
	if ((chr >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *str_int - fxn that converts a string to an integer
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int str_int(char *str)
{
	int t, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (t = 0;  str[t] != '\0' && flag != 2; t++)
	{
		if (str[t] == '-')
			sign *= -1;

		if (str[t] >= '0' && str[t] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[t] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

