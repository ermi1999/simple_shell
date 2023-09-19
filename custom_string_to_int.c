/**
 * is_valid_integer - Checks if a string represents a valid integer
 *
 * @str: The string to check
 *
 * Return:
 *   - 1 if the string represents a valid positive integer
 *   - -1 if the string represents a valid negative integer
 *   - 0 if the string is empty or not a valid integer
 */
int is_valid_integer(char *str)
{
	int index;

	/* Check if the string is empty */
	if (str[0] == '\0')
		return (0);

	/* Check for a leading sign (+ or -) */
	index = 0;
	if (str[0] == '+' || str[0] == '-')
		index++;

	/* Check if the remaining characters are digits */
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		index++;
	}

	/* Check if the number is negative */
	if (str[0] == '-')
		return (-1);

	return (1);
}

/**
 * string_to_int - Converts a string to an integer
 *
 * @str: The string to convert
 *
 * Return:
 *   - The integer value of the string if it is a valid integer
 *   - -1 if the string is empty or not a valid integer
 */
int string_to_int(char *str)
{
	int num;
	int validity;
	int i;

	validity = is_valid_integer(str);

	/* Check if the string is a valid integer */
	if (validity == 0 || validity == -1)
		return (-1);

	num = 0;
	i = 0;

	/* Extract the integer from the string */
	if (str[i] == '+' || str[i] == '-')
		i++;

	for (; str[i] != '\0'; ++i)
		num = num * 10 + str[i] - '0';

	/* Apply the sign if necessary */
	if (str[0] == '-')
		num = -num;

	return (num);
}
