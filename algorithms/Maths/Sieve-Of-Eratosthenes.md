# Sieve-of-eratosthenes-algorithm
Most efficient way to find prime numbers under 10 million

Following is the algorithm to find all the prime numbers less than or equal to a given integer n by Eratosthenes’ method:

   1. Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
   2. Initially, let p equal 2, the first prime number.
   3. Starting from p2, count up in increments of p and mark each of these numbers greater than or equal to p2 itself in the list.           These numbers will be p(p+1), p(p+2), p(p+3), etc..
   4. Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime), and repeat from step 3.


# Input Format
The number n will be taken by user till which we have to find all prime numbers.

# Output Format
All the prime numbers before n will be printed

# Sample Input
>50

# Sample Output
>2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
 
# Implementation
C++
Python
