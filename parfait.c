

#include "bv.h"
#include "sieve.h"
# include    <stdio.h>
#include <stdlib.h>



void factorization(int n)//n is the number that factorization will factorize
{
    for (int i = 1; i < n; i++)//The loop runs from 1 to the number
    {
        if (n % i == 0)//If it divides, then its a factor
        {
            printf("%d ", i);//It prints out the factor
        }
    }
}

int main(void)
{
    int n = 100000;//The program will go to 100,000 numbers

    bitV *v = newVec(n);//Creating the bit vector
    sieve(v);//Passing the vecot pointer to the sieve file

    int *primes = malloc(sizeof(int) * n);//Creates a dynamic array for primes
    int primeInc = 0;//The array incrementation for the primes. Calls prime incrementation.
    for (int i = 2; i <= n; i++)//The loop goes to n, which is 100,000
    {
        int x = valBit(v, i);//It gets the bit for the specific i
        if (x)// If the valBit is one, then it is a prime
        {
            primes[primeInc] = i;//It adds that number to the primes array.
            primeInc++;//It increments.
            printf("%d P\n", i);//Puts p next to the number, if it is prime
        } else
        {
            printf("%d C: ", i);//Prints the composite number
            int number = i;//Number is temperary variable for the current number.
            int x = 0;//x is used for incrementation of prime numbers
            int p = primes[x];//p is the first prime number
            while (number > 1) {
                if (number % p == 0)//if the number is divisible by the current prime number
                {
                    number = number / p;//The number is divided by the prime number
                    printf("%d ", p);//It prints out the prime factorization numbers.
                } else
                {//the current number is not divisible by the prime number
                    x++;//incremates
                    p = primes[x];//p becomes the next prime number.
                }
            }
            printf("\n");//New line after detecting the prime number

            //This is used for detecting perfect numbers
            int total=0;//Counting the total of the factors
            for(int k=1;k<i;k++)//It loops to the current number
            {
                if(i%k==0){//If it factorizes, then its added to the total
                    total+=k;
                }
            }
            if (total==i)//if the total of factor is the number, then it is a perfect number
            {
                printf("%d E: ",i);//prints out the perfect number with E
                factorization(i);//Calls the method factorization, which prints out the factors of that number
                printf("\n");//new line
            }
        }
    }
    return 0;
}
