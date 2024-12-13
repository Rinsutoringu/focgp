#include <stdio.h>
#include <time.h>
void TimeTable(int n){
	int chioce;
	int i=1;
	if(n!=1){
		printf("1. 9:00 am - 9:50 am\n");
		printf("2. 10:00 am - 10:50 am\n");
		printf("3. 11:00 am - 11:50 am\n");
		printf("4. 12:00 am - 12:50 am\n");
		printf("5. 1:00 pm - 1:50 pm\n");
		printf("6. 2:00 pm - 2:50 pm\n");
		printf("7. 3:00 pm - 3:50 pm\n");
		printf("8. 4:00 pm - 4:50 pm\n");
		printf("9. Exit\n");
}
else{
	struct tm *tblock;
	time_t current_time;
	time(&current_time);
	tblock = localtime(&current_time);
		int hour=tblock->tm_hour;
		if(hour>12){
			int a=hour-12;
			int b=a;
			for(;i<=a;i++){
				printf("%d .%d:00 pm - %d:50 pm\n",i,b,b);
				b++;
			}
			printf("%d .Exit\n",a+1);
		}
		if(hour<9){
		printf("1. 9:00 am - 9:50 am\n");
		printf("2. 10:00 am - 10:50 am\n");
		printf("3. 11:00 am - 11:50 am\n");
		printf("4. 12:00 am - 12:50 am\n");
		printf("5. 1:00 pm - 1:50 pm\n");
		printf("6. 2:00 pm - 2:50 pm\n");
		printf("7. 3:00 pm - 3:50 pm\n");
		printf("8. 4:00 pm - 4:50 pm\n");
		printf("9. Exit\n");
		}
        if(hour>=9&&hour<=12){
          int a=13-hour;
			int b=hour;
			for(;i<=a;i++){
				printf("%d. %d:00 am - %d:50 am\n",i,b,b);
				b++;
			}
		printf("%d. 1:00 pm - 1:50 pm\n",i++);
		printf("%d. 2:00 pm - 2:50 pm\n",i++);
		printf("%d. 3:00 pm - 3:50 pm\n",i++);
		printf("%d. 4:00 pm - 4:50 pm\n",i++);
		printf("%d. Exit\n",i);
	}
	}
		while(1){
		printf("Please make a choice :");
		scanf("%d",&chioce);
		if(chioce==9||chioce==i){
			printf("You have successfully exited!\n");
				return;
		}
		if(chioce>=1&&chioce<i){
			printf("You have successfully!\n");
			printf("Input the size of classroom: \n");
				return;
		}
			else{
				printf("Invalid operation! Please try again:\n");
				}
		}
	return ;
}


	

