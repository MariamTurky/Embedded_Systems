# include <stdio.h>
int main()
{
    float initial_velocity, acceleration, time, final_velocity, distance;

    printf("Please enter the initial velocity\nu =");
    scanf("%f", &initial_velocity);

    printf("Please enter the acceleration\na =");
    scanf("%f", &acceleration);

    printf("Please enter the time\nt =");
    scanf("%f",&time);

    final_velocity = initial_velocity + (acceleration * time);

    distance = (initial_velocity * time) + (0.5 * acceleration * time * time);

    printf("\nFinal velocity = %0.2f\n ", final_velocity);

    printf("\nDistance = %0.2f\n ", distance);

    return 0;
}