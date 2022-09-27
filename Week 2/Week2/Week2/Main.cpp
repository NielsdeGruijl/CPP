#include "Main.h"

int main() {
    //ASimpleClass simpleClass1(4, 5);
    //printf("Summation is %d\n", simpleClass1.summation());

    // 1 - Implement a method in the ASimpleClass class named 
    // multiplication, that multiplies number1 and number 2 and returns it.

    // <---- Expected Outcome ---->
    //int r = simpleClass1.multiplication();
    //printf("Multiplication is %d\n", r);
    //This should print "Multiplication is 20"

    // 2 - Implement another constructor in ASimple class that
    // receives just one number and set it to be number1 and number2.

    // <---- Expected Outcome ---->
    //ASimpleClass simpleClass2(11);
    //printf("New constructor gives as number1 = %d and number2 = %d\n", simpleClass2.number1, simpleClass2.number2);
    //This should print "New constructor gives as number1 = 11 and number2 = 11"

    // 3 - Create a destructor for ASimple class that prints
    // the values stored in number1 and number2.

    // <---- Expected Outcome ---->
    //{
    //    ASimpleClass simpleClass3(8, 88);
    //}
    //This should print "Simple class destroyed with values 8 and 88"

    // 4 - Add a third variable (a float named "divisor"), that is private
    // and gets the value of number1/number2 in the ASimpleClass construtor.
    // Implement a get method that returns the value of divisor.

    // <---- Expected Outcome ---->
    ASimpleClass simpleClass4(6, 3);
    float divisor = simpleClass4.getDivisor();
    printf("The value of divisor is %f\n", divisor);
    //This should print "The value of divisor is 2"

    return 0;
}