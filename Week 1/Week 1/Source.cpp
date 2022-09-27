#include <iostream>;
#include <cstdio>;
#include <string>;

//============Non-Array Questions

//int main()
//{
//	int a;
//	 
//	printf("Enter value for a: ");
//	scanf_s("%d", &a);
//
//	if (a % 2 != 0)
//	{
//		printf("%d is an even number\n", a);
//	}
//  else
//  {
//		printf("%d is an odd number\n", a);
//	}
//	
//	//===========================
//
//	int b, c;
//	printf("Enter values for b and c respectively: ");
//	scanf_s("%d %d", &b, &c);
//	
//	if (b > c)
//	{
//		printf("The highest value is %d\n", b);
//	}
//	else
//	{
//		printf("Highest value is %d\n", c);
//	}
//
//	//===========================
//
//	int d, e, f;
//	printf("Enter values for d, e and f respectively: ");
//	scanf_s("%d %d %d", &d, &e, &f);
//	printf("The average value is: %d\n", (d + e + f) / 3);
//
//	//===========================
//
//	int g, h, i, j;
//	printf("Enter values for g, h, i and j respectively: ");
//	scanf_s("%d %d %d %d", &g, &h, &i, &j);
//	printf("The summation of these numbers is %d\n", g + h + i + j);
//
//	return 0;
//}

//============Non-Array Loop Questions

//int main()
//{
//	int a;
//	printf("Enter value for a: ");
//	scanf_s("%d", &a);
//
//	for (int i = 0; i < a; i++)
//	{
//		printf("Hello World\n");
//	}
//
//	//===========================
//
//	int b, c;
//	printf("Enter values for b and c respectively: ");
//	scanf_s("%d %d", &b, &c);
//
//	for (int i = 0; i < c; i++)
//	{
//		printf("%d\n", b);
//	}
//
//	//===========================
//
//	int d;
//	printf("Enter value for d: ");
//	scanf_s("%d", &d);
//
//	if (d == 2 || d == 3)
//		printf("%d is a prime number\n", d);
//
//	if (d <= 1 || d % 2 == 0 || d % 3 == 0)
//		return 0;
//
//	for (int i = 5; i * i <= d; i += 6)
//	{
//		if (d % i == 0 || d % (i + 2) == 0)
//			return 0;
//	}
//
//	printf("%d is a prime number\n", d);
//
//	//===========================
//
//	int e;
//	printf("Enter value for e: ");
//	scanf_s("%d", &e);
//	
//	for (int i = e - 1; i > 0; i--)
//	{
//		e *= i;
//		
//		printf("%d\n", e);
//	}
//
//	printf("Factorial of e is %d\n", e);
//
//	return 0;
//}

//============Array questions

//int main()
//{
//	int a;
//	int arrayPos = 0;
//	int divisorsOfA[10];
//
//	printf("Enter value for a: ");
//	scanf_s("%d", &a);
//
//	for (int i = 1; i <= a; i++)
//	{
//		if (a % i == 0) 
//		{
//			divisorsOfA[arrayPos] = i;
//			arrayPos++;
//		}
//	}
//
//	for (int i = 0; i < arrayPos; i++)
//	{
//		printf("%d is a divisor of %d\n", divisorsOfA[i], a);
//	}
//
//	//===========================
//
//	int b, c;
//	int arrayPos = 0;
//	int divisorsOfBC[10];
//	int smallerInt;
//
//	printf("Enter values for b and c respectively: ");
//	scanf_s("%d %d", &b, &c);
//
//	if (b < c) {
//		smallerInt = b;
//	}
//	else {
//		smallerInt = c;
//	}
//
//	for (int i = 1; i <= smallerInt; i++) 
//	{
//		if (b % i == 0 && c % i == 0)
//		{
//			divisorsOfBC[arrayPos] = i;
//			arrayPos++;
//		}
//
//	}
//	
//	for (int i = 0; i < arrayPos; i++)
//	{
//		printf("%d is a divisor of %d and %d\n", divisorsOfBC[i], b, c);
//	}
//
//	//===========================
//
//	int d;
//	int biggestInt = 0, smallestInt = 100;
//	int arrayPos = 0;
//	int arrayIntA[10];
//
//	printf("Enter a value for d: ");
//	scanf_s("%d", &d);
//	printf("Enter %d different values\n", d);
//
//	for (int i = 0; i < d; i++)
//	{
//		arrayPos = i;
//		printf("Please enter a value: ");
//		scanf_s("%d", &arrayIntA[arrayPos]);
//	}
//
//	for (int i = 0; i <= arrayPos; i++)
//	{
//		if (arrayIntA[i] > biggestInt)
//		{
//			biggestInt = arrayIntA[i];
//		}
//
//		if (arrayIntA[i] < smallestInt)
//		{
//			smallestInt = arrayIntA[i];
//		}
//	}
//
//	printf("%d is the smallest number and %d is the biggest number", smallestInt, biggestInt);
//
//	//===========================
//
//	int e, f;
//	int arrayPos = 0;
//	int arrayIntB[10];
//
//	printf("Enter values for e and f respectively: ");
//	scanf_s("%d %d", &e, &f);
//	printf("Enter %d different values\n", e);
//
//	for (int i = 0; i < e; i++)
//	{
//		arrayPos = i;
//		printf("Please enter a value: ");
//		scanf_s("%d", &arrayIntB[arrayPos]);
//	}
//
//	printf("All multiplied values in arrayInt: \n");
//	for (int i = 0; i <= arrayPos; i++)
//	{
//		arrayIntB[i] *= f;
//		printf("%d\n", arrayIntB[i]);
//	}
//
//
//	return 0;
//}


//============Array questions with strings

int main()
{
	char stringBufferA[256];
	printf("Enter a first string: ");
	scanf_s("%*s", stringBufferA);

	char stringBufferB[256];
	printf("Enter a second string: ");
	scanf_s("%*s", stringBufferB);

	std::string equal = "equal";
	std::string notEqual = "not equal";

	if (stringBufferA == stringBufferB)
	{
		printf("%s", equal.c_str());
	}
	else
	{
		printf("%s", notEqual.c_str());
	}

	return 0;
}
	