#include <stdio.h>

int main(void) {
	int integer;
	float real_number;
	char letter;
	char string=0;

	printf("Input integer, real number, letter, string type characters!!\n");
	scanf_s("%d %f %c", &integer, &real_number, &letter, sizeof(letter));
	printf("%d %f %c ", integer, real_number, letter);

	while (string != '\n') {
		scanf_s("%c", &string, sizeof(string));
		printf("%c", string);
	}
	return 0;
}
