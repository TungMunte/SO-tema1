/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	// return if no memory is allocated to the destination
	if (destination == NULL)
	{
		return NULL;
	}

	// take a pointer pointing to the beginning of the destination string
	char *ptr = destination;

	// copy the C-string pointed by source into the array
	// pointed by destination
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	// include the terminating null character
	*destination = '\0';

	// the destination is returned by standard `strcpy()`
	return ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	size_t i;

	for (i = 0; i < len && source[i] != '\0'; i++)
		destination[i] = source[i];
	for (; i < len; i++)
		destination[i] = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	// Pointer should not null pointer
	if ((destination == NULL) && (source == NULL))
		return NULL;
	// Create copy of s1
	char *start = destination;
	// Find the end of the destination string
	while (*start != '\0')
	{
		start++;
	}
	// Now append the source string characters
	// until not get null character of s2
	while (*source != '\0')
	{
		*start++ = *source++;
	}
	// Append null character in the last
	*start = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	if (destination == 0 || source == 0)
	{
		return 0;
	}
	size_t i = strlen(destination);
	int a = 0;
	size_t b = i;
	while (a < len && source[a] != '\0')
	{
		destination[i++] = source[a++];
	}
	destination[i] = '\0';
	return (destination);
}

int strcmp(const char *str1, const char *str2)
{
	int i;
	for (i = 0; str1[i] && str2[i]; ++i)
	{
		if (str1[i] == str2[i] || (str1[i] ^ 32) == str2[i])
			continue;
		else
			break;
	}

	if (str1[i] == str2[i])
		return 0;

	if ((str1[i] | 32) < (str2[i] | 32))
		return -1;
	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	for (size_t i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] < str2[i]) ? -1 : 1;
		}
		if (str1[i] == '\0')
		{
			return 0;
		}
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}

	return count;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	const char *position = NULL;
	size_t i = 0;
	for (i = 0;; i++)
	{
		if ((unsigned char)str[i] == c)
		{
			position = &str[i];
			break;
		}
		if (str[i] == '\0')
			break;
	}
	return (char *)position;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	char *isCharFind = NULL;
	// handling null pointer
	if (str != NULL)
	{
		do
		{
			if (*str == (char)c)
			{
				isCharFind = str;
			}
		} while (*str++);
	}
	return isCharFind;
}

char *strstr(const char *str1, const char *str2)
{
	/* TODO: Implement strstr(). */
	char *ptr;

	ptr = str1;

	while (*ptr)
	{
		if (strncmp(ptr, str2, strlen(str2)) == 0)
			return ptr;
		ptr++;
	}
	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	/* TODO: Implement strrstr(). */
	char *r = NULL;

	if (!str2[0])
		return (char *)str1 + strlen(str1);
	while (1)
	{
		char *p = strstr(str1, str2);
		if (!p)
			return r;
		r = p;
		str1 = p + 1;
	}
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	int i;
	// cast src and dest to char*
	char *src_char = (char *)source;
	char *dest_char = (char *)destination;
	for (i = 0; i < num; i++)
		dest_char[i] = src_char[i]; // copy contents byte by byte
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char *a = destination;
	const unsigned char *b = source;
	if (a < b)
	{
		while (num--)
		{
			*a++ = *b++;
		}
	}
	else
	{
		while (num--)
		{
			a[num] = b[num];
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *a = ptr1, *b = ptr2;
	while (num && *a == *b)
	{
		++a;
		++b;
		--num;
	}
	return (*a - *b) * !!num;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	int i;
	unsigned char *p = source;
	i = 0;
	while (num > 0)
	{
		*p = value;
		p++;
		num--;
	}
	return (source);
}
