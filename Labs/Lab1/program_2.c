# include <stdio.h>
int main()
{
    int num1, num2, num3;
    int sum , product, smallest, largest = 0;
    float average = 0 ;

    printf("Enter three different imtegers: ");
    scanf("%d %d %d", &num1, &num2, &num3);


    sum = num1 + num2 + num3;

    average = sum / 3.0;

    product = num1 * num2 * num3;

    largest = num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);

    smallest =num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3);
    
    printf("\nSum is %d\n ",sum);
    printf("\nAverage is %0.3f\n ", average);
    printf("\nProduct is %d\n ", product);
    printf("\nSmallest is %d\n ", smallest);
    printf("\nLargest is %d\n ", largest);

    return 0;
}