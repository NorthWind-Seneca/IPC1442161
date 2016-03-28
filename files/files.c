#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_RECORDS 100

struct DataRecord
{
	int i;
	double d;
	char c;
};

/*
Reads a single record from a file. Returns 1 on success, 0 otherwise.
*/
int readRecord(FILE* fp, struct DataRecord* dest);

/*
Writes a single record to a file. Returns 1 on success, 0 otherwise.
*/
int writeRecord(FILE* fp, const struct DataRecord* src);

/*
Reads all records from a file. Returns number of records read.
*/
int readData(struct DataRecord destArray[]);

/*
Writes an array of records to file. Returns number of records written.
*/
int writeData(const struct DataRecord srcArray[], int numRecords);

int main()
{
	struct DataRecord records[MAX_RECORDS];
	int numRecords = 0, i;

	numRecords = readData(records);

	for (i = 0; i < numRecords; i++)
	{
		records[i].i *= 2;
	}

	writeData(records, numRecords);

	// To stop vs from exiting immediately...
	getchar();
	return 0;
}

int readRecord(FILE* fp, struct DataRecord* dest)
{
	// Reading 3 vars through fscanf. Therefore on success, it should return 3.
	return 3 == fscanf(
		fp, "%d %lf %c", &dest->i, &dest->d, &dest->c);
}

int writeRecord(FILE* fp, const struct DataRecord* src)
{
	// If fprintf fails, it will return 0 or less. Therefore detect this and return true when it returns value above 0.
	return 0 < fprintf(
		fp, "%d %lf %c\n", src->i, src->d, src->c);
}

int readData(struct DataRecord destArray[])
{
	FILE* fp = NULL;
	int numRecords = 0;

	fp = fopen("data.txt", "r");

	// Always make sure fopen succeeded. fopen returns NULL on failure.
	if (!fp)
	{
		printf("Could not open file for reading.\n");
	}
	else
	{
		// Otherwise...
		while (numRecords < MAX_RECORDS &&
			readRecord(fp, &destArray[numRecords]))
		{
			numRecords++;
		}
	}

	// Always close files when done with them and set pointer to NULL
	fclose(fp);
	fp = NULL;

	return numRecords;
}

int writeData(const struct DataRecord srcArray[], int numRecords)
{
	FILE* fp = NULL;
	int i = 0;

	fp = fopen("data.txt", "w");
	if (!fp)
	{
		printf("Could not open file for writing\n");
	}
	else
	{
		for (i = 0; i < numRecords &&
			writeRecord(fp, &srcArray[i]); i++);
	}

	fclose(fp);
	fp = NULL;

	return i;
}
