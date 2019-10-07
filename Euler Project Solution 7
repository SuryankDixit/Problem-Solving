/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

// Prime numbers are of the form 6k-1 and 6k+1


#include <iostream>
#include <cmath>
using namespace std;

bool
isPrime (long int n)
{

  for (int i = 2; i <= sqrt (n); i++)
    {
      if (n % i == 0)
	return false;
    }
  return true;
}

int main ()
{
  int count = 2;
  int n = 0;
  while (count < 10001)
    {
      n += 6;   
      if (isPrime (n - 1))
	{
	  count++;
	  if (count == 10001)
	    {
	      cout << n - 1;
	      break;
	    }
	}
      if (isPrime (n + 1))
	{
	  count++;
	  if (count == 10001)
	    {
	      cout << n + 1;
	      break;
	    }
	}
    }
  return 0;
}
