#include <stdio.h>
#include <time.h>
int TimeTable(int n){
	int chioce;
	int Rchioce;
	if(n<1||n>4){
		return 0;
	}
	if(n!=1&&n!=4){
		printf("1. 9:00 am - 9:50 am\n");
		printf("2. 10:00 am - 10:50 am\n");
		printf("3. 11:00 am - 11:50 am\n");
		printf("4. 12:00 am - 12:50 am\n");
		printf("5. 1:00 pm - 1:50 pm\n");
		printf("6. 2:00 pm - 2:50 pm\n");
		printf("7. 3:00 pm - 3:50 pm\n");
		printf("8. 4:00 pm - 4:50 pm\n");
		printf("9. Exit\n");
		int i=9;
		Rchioce=i;
}
else{
	int i=1;
	struct tm *tblock;
	time_t current_time;
	time(&current_time);
	tblock = localtime(&current_time);
		int hour=tblock->tm_hour;
		if(hour>12){
			int a=hour-11;
			int b=16-hour;
			for(;i<=b;i++){
				printf("%d .%d:00 pm - %d:50 pm\n",i,a,a);
				a++;
			}
			printf("%d .Exit\n",i);
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
          int a=12-hour;
			int b=hour+1;
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
		Rchioce=i;
	}
		while(1){
		printf("=================\n");
		printf("Please make a choice :");
		scanf("%d",&chioce);
		if(chioce==Rchioce){
			printf("Successfully exited!\n");
				return chioce;
		}
		if(chioce>=1&&chioce<Rchioce){
			printf("You have successfully order!\n");
			printf("=================\n");
				return  chioce;
		}
			else{
				printf("Invalid operation! Please try again:\n");
				}
		}
	return chioce;
}


	

