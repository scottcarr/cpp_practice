#include <iostream>

using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
 */

size_t sum_multiples_of_3_and_5(int end) {
    size_t sum = 0;
    for (size_t i = 0; i < end; ++i) {
        if (i % 3 == 0) {
            sum += i;
        } else if (i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

void p1() {
    cout << "sum of multiples of 3 or 5 below 10 is:" << sum_multiples_of_3_and_5(10) << endl;
    cout << "sum of multiples of 3 or 5 below 1000 is:" << sum_multiples_of_3_and_5(1000) << endl;
}
