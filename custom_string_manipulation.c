#include "main.h"
​
/**
 * string_compare - Compare two strings up to a specified number of characters
 * @string_one: First string
 * @string_two: Second string
 * @n: Number of characters to compare
 *
 * Return: Negative value if string_one is less than string_two,
 *         Positive value if string_one is greater than string_two,
 *         0 if both strings are equal
 */
int string_compare(const char *string_one, const char *string_two, size_t n)
{
	size_t i;
​
	for (i = 0; i < n; i++)
	{
		if (string_one[i] != string_two[i])
			return (string_one[i] - string_two[i]);
		else if (string_one[i] == '\0')
			return (0);
	}
	return (0);
}
​
/**
 * string_copy - Copy a string from source to destination
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destination string
 */
char *string_copy(char *dest, const char *src)
{
	size_t i = 0;
​
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
​
/**
 * string_length - Calculate the length of a string
 * @str: Input string
 *
 * Return: Length of the string
 */
size_t string_length(const char *str)
{
	size_t len = 0;
​
	while (str[len] != '\0')
		len++;
	return (len);
}
​
/**
 * string_concat - Concatenate two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destination string
 */
char *string_concat(char *dest, const char *src)
{
	size_t dest_len = string_length(dest);
	size_t i = 0;
​
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
