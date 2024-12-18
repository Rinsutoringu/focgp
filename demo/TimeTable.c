#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int TimeTable(int n){
	int Rchioce;
	int hour;
	int i=1;
	struct tm *tblock;
	time_t current_time;
	time(&current_time);
	tblock = localtime(&current_time);
	if(n!=1){
		hour=9;
	}
	else{
		hour=tblock->tm_hour+1;
		i=1;
           }
	if(hour>=16){
		printf("%d. Exit\n",i);
	}
	else{
		int h=hour;
	for(;h<=16;h++){
		if(hour<=12){
			printf("%d. %d:00 am - %d:50 am\n",i,h,h);
			i++;
		}
		else{
			printf("%d. %d:00 pm - %d:50 pm\n",i,h-12,h-12);
			i++;
		}
	}
		printf("%d. Exit\n",i);
	}
		Rchioce=i;
		while(1){
			int chioce;
		printf("=================\n");
		printf("Please make a choice :");
		scanf("%d",&chioce);
		if(chioce==Rchioce){
			printf("Successfully exited!\n");
			exit(0);
		}
		if(chioce>=1&&chioce<Rchioce){
			printf("You have successfully order!\n");
			printf("=================\n");
			if(hour<=9){
			int j=chioce+8;
			return j;
			}
			else{
				int j=hour+chioce-1;
				return j;
			}
		}
			else{
				printf("Invalid operation! Please try again:\n");
				}
		}
}

