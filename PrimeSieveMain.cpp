#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.

int markMultiples(vector<bool> &arr, int a, int n) {
    int i = 2, num;
    while ((num = i * a) <= n) {
        arr[ num - 1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
    return a;
}

// A function to print all prime numbers smaller than n

int sieve(int n) {
    // There are no prime numbers smaller than 2
    if (n >= 2) {
        // Create an array of size n and initialize all elements as 0
        vector<bool> arr(n);
        vector<int> primes(n);
        int count = 0;
        vector<int> factors(n);
        //        memset(arr, 0, sizeof(arr));

        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i = 1; i < n; ++i) {
            if (arr[i] == 0) {
                count++;
                //(i+1) is prime, print it and mark its multiples
                //put primes into array of primes
                primes[i] = markMultiples(arr, i+1, n);
                printf("%d ", primes[i]);
                if(n%primes[i]==0){
                    factors[i]=primes[i];
//                    printf("->%d ", factors[i]);
                }
            }
        }
        printf("\n%d contains %d primes.\n", n, count);
    }
    return n;
}

void divisors(int n){
    int count = 0;
    sieve(n);
    for(int i = 1; i <= n; i++){
        if(n%i==0){
            count++;
            printf("%d ", i);
        }
    }
    printf("\n%d has %d divisors", n, count);
}


// Driver Program to test above function

int main() {
    int n = 24;

    printf("Following are the prime numbers below %d\n", n);
    //sieve(n);
    divisors(n);
    return 0;
}