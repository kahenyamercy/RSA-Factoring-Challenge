# RSA-Factoring-Challenge
TASK 0
Problem Statement:
You need to write a program that reads a file containing natural numbers and prints the factorization of each number as a product of two smaller numbers.

Step 1: Understanding the Input:
You'll receive a file as input (<file>), and this file will contain one natural number per line. Each number needs to be factorized.

Step 2: Factorization:
Factorization involves finding two smaller numbers (p and q) such that their product equals the given number (n). The goal is to break down the input number into two smaller factors.

Step 3: Output Format:
For each input number, you need to print its factorization in the format n=p*q. Here, n is the input number, and p and q are the two smaller factors you found in step 2.

Step 4: Handling Prime Numbers:
If a given number cannot be factorized into two smaller numbers (i.e., it's a prime number), you should indicate that in the output by printing that the number is prime.

Step 5: Reading from the File:
You'll need to read each line of the input file and convert the line's content to an integer, which will represent the number you want to factorize.

Step 6: Creating a Function for Factorization:
You'll need a function that takes an integer as input and performs the factorization. If you find two smaller factors, you'll print the factorization. If not, you'll print that the number is prime.

Step 7: Putting It All Together:
Your program should loop through the file, read each line, call the factorization function, and print the result according to the output format.
