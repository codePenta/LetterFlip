#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	false, true

} bool;

void printInput(char* inputArray);
void flipCapitals(char* inputArray);
void revert(char* inputArray);

void getUserInput(char* inputArray);
int getStringLength(char* inputArray);

bool isCharNumber(char toCheck);
bool isCharCapital(char toCheck);
bool isCharLowercase(char toCheck);

bool isNumericValue(char* toCheck, char* typeOfNumber);
bool isBinaryValue(char* toCheck, char* typeOfValue);
bool isHexValue(char* toCheck);
bool isDecimalValue(char* toCheck);

void printAnswer(char* inputArray, char* typeOfInput);

int main()
{
	char inputArray[1024] = "";
	char* typeOfInput[1] = { '\0' };

	getUserInput(inputArray);

	printInput(inputArray);
	flipCapitals(inputArray);

	printInput(inputArray);
	revert(inputArray);
	printInput(inputArray);

	if (isNumericValue(inputArray, typeOfInput))
	{
		printAnswer(inputArray, typeOfInput);
	} 
	else
	{
		printAnswer(inputArray, typeOfInput);
	} 

	return 0;
}

void printInput(char* inputArray)
{
	char input = 0;
	char c;

	printf("Input status: %s\n", inputArray);
	printf("Please press any key to continue...");

	scanf("%c", &c);
}

void flipCapitals(char* inputArray)
{
	int inputArrayLength = getStringLength(inputArray);

	for (int i = 0; i < inputArrayLength; i++) 
	{
		if (isCharCapital(inputArray[i]))
		{
			inputArray[i] += 32;
			continue;
		}

		if (isCharLowercase(inputArray[i]))
		{
			inputArray[i] -= 32;
		}
	}
}

bool isBinaryValue(char* toCheck, char* typeOfValue)
{
	int inputArrayLength = getStringLength(toCheck) - 2;

	if (toCheck[inputArrayLength + 1] != 'b')
	{
		return false;
	}

	for (int i = 1; i <= inputArrayLength; i++)
	{
		if (toCheck[i] != 48 && toCheck[i] != 49)
		{
			return false;
		}
	}

	*typeOfValue = 'b';
	return true;
}

void revert(char* inputArray)
{
	int inputArrayLength = getStringLength(inputArray) - 1;
	int stopAt = inputArrayLength / 2;

	for (int i = 0, j = inputArrayLength - i; i <= stopAt; i++, j--)
	{
		char oppositeChar = inputArray[j];
		char temp = inputArray[i];

		inputArray[i] = oppositeChar;
		inputArray[j] = temp;
	}
}

void getUserInput(char* inputArray)
{
	int inputArrayLength = getStringLength(inputArray) - 1;
	char c;

	printf("No blanks please!\n");
	printf("Input: ");
	scanf("%s", inputArray);
	scanf("%c", &c);
}

void printAnswer(char* inputArray, char* typeOfNumber)
{
	switch (*typeOfNumber)
	{
	case 't':
		printf("The text '%s' represents no numeric value\n", inputArray);
		break;
	case 'd':
		printf("The text '%s' represents a decimal value\n", inputArray);
		break;
	case 'h':
		printf("The text '%s' represents a hexadecimal value\n", inputArray);
		break;
	case 'b':
		printf("The text '%s' represents a binay value\n", inputArray);
		break;
	default:
		break;
	}
}

int getStringLength(char* inputArray)
{
	for (int i = 0; i < 1024; i++)
	{
		if (inputArray[i] == '\0')
		{
			return i;
		}
	}

	return -1;
}

bool isHexValue(char* toCheck)
{
	int toCheckLength = getStringLength(toCheck) - 1;

	if (!(toCheck[toCheckLength] == 'h' ^
		(toCheck[0] == '0' && toCheck[1] == 'x')))
	{
		return false;
	}

	for (int i = 2; i <= toCheckLength; i++)
	{
		if (i == toCheckLength && toCheck[i] == 'h')
		{
			continue;
		}

		if (!(isCharNumber(toCheck[i]) ||
			isCharInHexRange(toCheck[i])))
		{
			return false;
		}
	}
	return true;
}

bool isDecimalValue(char* toCheck)
{
	int toCheckLength = getStringLength(toCheck);

	for (int i = 0; i < toCheckLength; i++)
	{
		if (!isCharNumber(toCheck[i]))
		{
			return false;
		}
	}
	return true;
}

bool isNumericValue(char* toCheck, char* typeOfValue)
{
	if (isHexValue(toCheck))
	{
		*typeOfValue = 'h';
		return true;
	}

	if (isDecimalValue(toCheck))
	{
		*typeOfValue = 'd';
		return true;
	}

	if (isBinaryValue(toCheck, typeOfValue))
	{
		*typeOfValue = 'b';
		return true;
	}

	*typeOfValue = 't';
	return false;
}

bool isCharInHexRange(char toCheck)
{
	return	(toCheck >= 65 && toCheck <= 70) || 
			(toCheck >= 97 && toCheck <= 102);
}

bool isCharCapital(char toCheck)
{
	return toCheck >= 65 && toCheck <= 90;
}

bool isCharLowercase(char toCheck)
{
	return toCheck >= 97 && toCheck <= 122;
}

bool isCharNumber(char toCheck)
{
	return toCheck >= 48 && toCheck <= 57;
}

bool isCharBlank(char toCheck)
{
	return toCheck == 32;
}