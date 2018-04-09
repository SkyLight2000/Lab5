// Lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	SetConsoleOutputCP(1251);
	char str[50];
	char *a[20], *word[20], *t;
	int i = 0, h = 0, freq[20];
	int b, f, c, q;
	float probs[256];
	printf("Введите строку:\n");
	gets_s(str);
	c = 0;
	for (q = 0; q < strlen(str) - 1; q++)
		if ((str[q] == ' ') && (str[q + 1] != ' '))
			c = c + 1;
	if (str[0] != ' ')
		c = c + 1;
	printf("В строке %d слов\n", c);
	char delim[7] = (" .,!?/");
	t = strtok(str, delim);
	while (t != NULL) {
		a[i] = t;
		t = strtok(NULL, delim);
		i++;
	}
	for (int j = 0; j < i; j++) {
		b = 0;
		f = 0;
		for (int k = 0; k < i; k++) {
			if (strcmp(a[j], a[k]) == 0) {
				b++;
			}
		}
		for (int d = 0; d < h; d++) {
			if (strcmp(a[j], word[d]) == 0) {
				f++;
			}
		}
		if (b > 1 && f == 0) {
			word[h] = a[j];
			freq[h] = b;
			h++;
		}
	}
	for (int j = 0; j < h; j++) {
		probs[j] = (float)freq[j] / c * 100;
		printf("Слово %s поворяется %d раз(а) [%.f%%]\n", word[j], freq[j], probs[j]);
	}
	system("pause");
	return 0;
}