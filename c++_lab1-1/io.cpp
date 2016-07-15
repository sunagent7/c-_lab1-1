#include<stdio.h>
#include<assert.h>

void readFile(int *dataSize, int data[])
{
	int i;
	FILE *fp;
	char filename[30];

	printf("Input the file name: ");
	gets_s(filename);
	// we can not use "gets()" here because of "buffer overflow vulnerability"
	/*

	Since C11, gets is replaced by gets_s. The gets() function does not perform bounds checking, therefore this function is extremely vulnerable to buffer-overflows. The recommended replacements are gets_s() or fgets();

	gets_s(buf);
	fgets(buf, sizeof(buf), stdin);

	or we can just input :

	#pragma warning(disable:4996)
	or
	#define _CRT_SECURE_NO_WARNINGS

	*/

	fopen_s(&fp, filename, "rt"); //change to fopen_s
	assert(fp != 0);
	fscanf_s(fp, "%d", dataSize); //change to fscanf_s
	for (i = 0; i<*dataSize; i++)
		fscanf_s(fp, "%d", &data[i]);
	fclose(fp);
}

// output array contents (20 values per row)
void printArray(const int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 20 == 0)  // begin new line every 20 values
			printf("\n");

		printf("%2d", a[i]);

	}
}