#include <stdio.h>
#include <time.h>
#include "search_room.h"
struct Date{
	int month;
	int day;
	int year;
	};//此处创建一个名为Date的结构体，其中month表示月份，day表示日期，year表示年份;
struct Date Today;
struct tm *tblock;
void search_room(int volume){//该函数表示查询可用教室
	FILE *fp;
	time_t current_time;
	time(&current_time);
	tblock = localtime(&current_time);
	int hour=tblock->tm_hour;
	Today.year=tblock->tm_year+1900;
	Today.month=tblock->tm_mon+1;
	Today.day=tblock->tm_mday;
	int i=0;//一个暂时的变量，用于遍历每个教室
	int flag=-1;//一个暂时的变量，用于标记符合需求的教室
	int number=0;//一个暂时的变量，用于标记当前房间最小容量
	struct Class cl[100];//创建一个名为cl的结构体数组，其中max表示教室最大容量，name表示教室名字
	fp = fopen("classroom_info.txt","r");
       if(fp == NULL) return;//检查文件是否为空
	while(fp != EOF){
		fscanf(fp,"%s %d",cl[i].name,&cl[i].max);
		i++;
	}
	int n=i;
	for(i=0;i<=n;i++){//遍历每一个教室
		if(volume<=cl[i].max && NotReserved()){//若最大容量合格，则输出；后续需要判断教室是否被预定
		if(cl[i].max<number){
			number = cl[i].max;
			flag = i;	
		}
			}
		}
	if(flag==-1) printf("No classroom available! Do you want to continue(Y/N)");
	else printf("The classroom you can use is %s",cl[flag].name);
	}//表示没找到合格教室，询问用户是否继续

/*int main(int argc, char *argv[])
{
    //a为系统当前时间，b为等待用户传入所需教室的最大人数 search(a);
    return 0;
}*/

