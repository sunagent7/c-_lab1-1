#include <stdlib.h>
#include "io.h"
#include "statistics.h"

#define DATASIZE 150

int main()
{
	int dataSize;
	int frequency[10] = { 0 };
	int data[DATASIZE];

	// reading file
	readFile(&dataSize, data);

	// process responses
	mean(data, dataSize);
	median(data, dataSize);
	mode(frequency, data, dataSize);

	system("pause");
	return 0;  // indicates successful termination
}