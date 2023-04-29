#include <stdio.h>



int main() 
{
    float exponent;
    int iterations;
    int i = 0;
    float result = 1;  // first term of taylor series

    printf("Please enter the exponent\n");
    scanf("%f", &exponent);

    printf("Please enter the number of iterations\n");
    scanf("%d", &iterations);

    float term = exponent;

    // iterate over the number of iterations to calculate the exponential function
    for(i =  1; i <= iterations; i++)
    {
        
        result = result + term;
        term = term * (exponent / (i+1));     
        
    }

    printf("The exponential result of e^%0.2f is %0.3f \n", exponent, result);

    return 0;
}