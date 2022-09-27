#include <cstdio>

class ASimpleClass {
private:
    float divisor;

public:
    int number1;
    int number2;

public:
    ASimpleClass(int number1);
    ASimpleClass(int number1, int number2);
    int summation(void);
    int multiplication(void);
    int getDivisor(void);
    ~ASimpleClass();
}; //<- this semicolon is required! if you don't use it, the program will fail.


ASimpleClass::ASimpleClass(int number1) {
    this->number1 = number1;
    this->number2 = number1;
    this->divisor = number1 / number2;
}

ASimpleClass::ASimpleClass(int number1, int number2) {
    this->number1 = number1;
    this->number2 = number2;
    this->divisor = number1 / number2;
}

int ASimpleClass::summation(void) {
    return number1 + number2;
}

int ASimpleClass::multiplication(void)
{
    return number1 * number2;
}

int ASimpleClass::getDivisor(void)
{
    return divisor;
}

ASimpleClass::~ASimpleClass()
{
    printf("SimpleClass was deleted with values %d and %d\n", number1, number2);
}

