#include <stdio.h>
int main() {

	int time, hours, minutes, seconds;

	printf("Input seconds: ");
	scanf("%d", &time);
	
	hours = (time/3600); 
	
	minutes = (time -(3600*hours))/60;
	
	seconds = (time -(3600*hours)-(minutes*60));
	
	printf("Time is  %d: %d :%d\n",hours,minutes,seconds);
	
	return 0;
}