#include <iostream>
#include <cstring>
using namespace std;


char* stringAdder(const char* str1, const char* str2){ // function to add the values of large sums, basically a table addition algorithm
    int lastIndex1 = strlen(str1) - 1; // initialize value for the last index of number 1 char array
    int lastIndex2 = strlen(str2) - 1; // initialize value for the last index of number 2 char array
    int onesCarry = 0; // initialize a value to carry the one (as per table addtion)
    int placeSum = 0; // initialize a value to store the current place sum (as per table addition)
    
    int maxSize;

    if (strlen(str1) > strlen(str2)){
        int maxSize = strlen(str1) + 1; // set max size to the length of the greater string and add one for the one carry
    }
    else if (strlen(str2) > strlen(str1)){
      int maxSize = strlen(str2) + 1; // set max size to the lengh of the greater string and add one for the one carry
    }

    char* sum = new char[maxSize]; // initialize a sum character array of maxSize
    int resultIndex = maxSize - 1; // resultIndex pointer to add to array back-to-front
    sum[maxSize] = '\0'; // Add null terminating character to the end of array.

    while ( lastIndex1 >= 0 || lastIndex2 >= 0 || onesCarry > 0 ){ // conditions for addition to occur
        if (lastIndex1 >= 0){ // if the first number still has digits to account for:
            placeSum += str1[lastIndex1] - '0'; // then add them to the place sum
            lastIndex1--; // decrement value for next iteration
        }
        if (lastIndex2 >= 0){ // if the second number still has digits to account for:
            placeSum += str2[lastIndex2] - '0'; // then add them to the place sum
            lastIndex2--; // decrement value for next iteration
        }

        placeSum += onesCarry; // if there is a leading one from previous iteration, add to the place sum
        sum[resultIndex] = (placeSum % 10) + '0'; // place the single digit in the resultIndex
        onesCarry = placeSum / 10; // set onesCarry to be added into the next iteration
        placeSum = 0; // clear the values of placeSum for the next iteration
        resultIndex--; // decrement the resultIndex to continue adding to array from back-to-front
    }

    return sum + resultIndex + 1; // adjusts pointer to the start of the result
}

int main(const int argc, const char* const argv[]){
    const char* number1 = argv[1]; // take first number from command line
    const char* number2 = argv[2]; // take second number from command line
    char* sum = stringAdder(number1, number2); // pass the char arrays taken from command line to string adder function
    cout << "Sum: " << sum; // output the sum of the numbers
    return 0;
}