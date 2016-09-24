#include <iostream>

using namespace std;

/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

size_t sum_even_fib_terms(int end) {
    size_t sum = 0;
    size_t prev = 1;
    size_t curr = 2;

    while (curr < end) {
        if (curr % 2 == 0) {
            sum += curr;
        }
        size_t next = prev + curr;
        prev = curr;
        curr = next;
    }

    return sum;
}

void p2() {
    cout << "sum of even first 10 fib terms:" << sum_even_fib_terms(90) <<endl;
    cout << "sum of even first 10 fib terms:" << sum_even_fib_terms(4000000) <<endl;
}

