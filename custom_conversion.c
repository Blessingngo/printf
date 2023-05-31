#include <stdio.h>
/**
 * Converts an unsigned int to a binary string representation and prints it.
 *
 * @param num: The unsigned int to convert to binary.
 */

void print_binary(unsigned int num)
{
	if (num == 0)
{
	printf("0");
	return (0);
}
	unsigned int temp = num;
	int num_digits = 0;

	while (temp > 0)
{
	temp >>= 1;
	num_digits++;
}
	char binary_string[num_digits + 1];

	binary_string[num_digits] = '\0';
	for (int i = num_digits - 1; i >= 0; i--)
{
	binary_string[i] = (num & 1) ? '1' : '0';
	num >>= 1;
}
	printf("%s", binary_string);
}
/**
 * The main function that demonstrates the usage of the custom specifier.
 *
 * @Return 0 on successful execution.
 */
int main(void)
{
	unsigned int num = 42;

	printf("Binary representation: %b\n", num);
	return (0);
}
