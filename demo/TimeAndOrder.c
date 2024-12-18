﻿#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct date{
	int month;
	int day;
	int year;
};
struct date findNextDay(struct date today);
struct date afterTomorrow(struct date today);
int TimeAndOrder(int n) {
	int a;
    struct date today,next,next1;
	struct tm *tblock;
	time_t current_time;
	time(&current_time);
	tblock = localtime(&current_time);
	int hour=tblock->tm_hour;
	today.year=tblock->tm_year+1900;
	today.month=tblock->tm_mon+1;
	today.day=tblock->tm_mday;
	next=findNextDay(today);
	next1=afterTomorrow(today);
	printf("1. %d.%d.%d\n",today.year, today.month, today.day);
	printf("2. %d.%d.%d\n",next.year,next.month,next.day);
	printf("3. %d.%d.%d\n",next1.year,next1.month,next1.day);
	printf("4. Exit\n");
	printf("=================\n");
	while(1){
	int choose;
	printf("Please select the date you want to book(Number): ");
	scanf("%d",&choose);
		char file_name[100];
	switch(choose){
			case(1):
				printf("=================\n");
			printf("OK!Please reserve a room :\n");
			sprintf(file_name, "%d.%d.%d.txt",today.year, today.month, today.day);
			FILE *fp=fopen(file_name,"w");
			fclose(fp);
			return 1;
			break;
		    case(2):
				printf("=================\n");
			printf("OK!Please reserve a room :\n");
			sprintf(file_name, "%d.%d.%d.txt",next.year,next.month,next.day);
			FILE *fp2=fopen(file_name,"w");
			fclose(fp2);
			return 2;
			break;
		    case(3):
			sprintf(file_name, "%d.%d.%d.txt",next1.year,next1.month,next1.day);
			FILE *fp3=fopen(file_name,"w");
			fclose(fp3);       
				printf("=================\n");
			printf("OK!Please reserve a room :\n");
			return 3;
			break;
			case(4):
				printf("=================\n");
			printf("Successfully exited!\n");
			exit(0);
			break;
		    default:
				printf("=================\n");
			printf("Invalid operation! Please try again!\n");
	}
	}
}
struct date findNextDay(struct date today){
	struct date tomorrow;
	tomorrow=today;
	int DayInmonth[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if((today.year%4 ==0&&today.year%100!=0)||(today.year%400==0)){
		DayInmonth[2]=29;
		}
	tomorrow.day++;
	if(tomorrow.day>DayInmonth[today.month]){
		tomorrow.day=1;
		tomorrow.month++;
		if(tomorrow.month>12){
			tomorrow.year++;
			tomorrow.month=1;
		}
	}
	return tomorrow;
}
struct date afterTomorrow(struct date today){
	struct date afterTomorrow;
	afterTomorrow=today;
	int DayInmonth[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if((today.year%4==0&&today.year%100!=0)||(today.year%400==0)){
		DayInmonth[2]=29;
		}
	afterTomorrow.day=afterTomorrow.day+2;
	if(afterTomorrow.day>DayInmonth[today.month]){
		afterTomorrow.day=1;
		afterTomorrow.month++;
		if(afterTomorrow.month>12){
			afterTomorrow.year++;
			afterTomorrow.month=1;
		}
	}
	return afterTomorrow;
}
