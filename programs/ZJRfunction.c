#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct {
    char classroomId[10];
    char timeSlot[100];
    char username[100];
    int booked;
} BookingStatus;
void BookingDate(int returnValue,char *dateStr){
    if(returnValue==1){
        getCurrentDate(*dateStr);
    }
    else if (returnValue==2)
    {
        getTomorrowDate(*dateStr);
    }
    else if (returnValue==3)
    {
        getAfterTomorrowDate(*dateStr);
    } 
}
void getCurrentDate(char *dateStr) {// 获取当前日期并格式化为指定格式
    time_t currentTime;
    struct tm *dateInfo;
    time(&currentTime);
    dateInfo = localtime(&currentTime);
    strftime(dateStr, 11, "%d/%m/%Y", dateInfo);
}
// 获取明天的日期并格式化为指定格式
void getTomorrowDate(char *dateStr) {
    time_t currentTime;
    struct tm *dateInfo;
    time(&currentTime);
    dateInfo = localtime(&currentTime);
    dateInfo->tm_mday++;
    mktime(dateInfo);
    strftime(dateStr, 11, "%d/%m/%Y", dateInfo);
}
// 获取后天的日期并格式化为指定格式
void getAfterTomorrowDate(char *dateStr) {
    time_t currentTime;
    struct tm *dateInfo;
    time(&currentTime);
    dateInfo = localtime(&currentTime);
    dateInfo->tm_mday += 2;
    mktime(dateInfo);
    
// 检查教室在指定日期和时间段是否已被预订
int isClassroomBooked(char *classroomId, char *date, char *timeSlot) {
    char fileName[20];
    sprintf(fileName, "%s.txt", classroomId);
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        return 0;//未被预订
    }
    BookingStatus booking;
    while (fscanf(fp, "%s %s %s %d", booking.classroomId, booking.timeSlot, booking.username, &booking.booked) == 4) {
        if (strcmp(booking.classroomId, classroomId) == 0 && strcmp(booking.timeSlot, timeSlot) == 0 && booking.booked) {
            fclose(fp);
            return 1;//已被预订
        }
    }

    fclose(fp);
    return 0;//未被预订
}


// 清除文件内今天以前的预订信息
void clearPastBookings() {
    char currentDate[11];
    getCurrentDate(currentDate);

    for (int i = 1; i <= 12; i++) {
        char fileName[20];
        sprintf(fileName, "C%d.txt", i);
        FILE *fp = fopen(fileName, "r");
        if (fp == NULL) {
            continue;
        }
        char tempFileName[20];
        sprintf(tempFileName, "temp_C%d.txt", i);
        FILE *tempFp = fopen(tempFileName, "w");
        if (tempFp == NULL) {
            fclose(fp);
            perror(tempFileName);
            return;
        }
        BookingStatus booking;
        while (fscanf(fp, "%s %s %d %s", booking.date, booking.timeSlot, &booking.booked, booking.username) == 4) {
            // 明确日期比较逻辑，只保留今天和以后的预订信息
            if (strcmp(booking.date, currentDate) >= 0) {
                fprintf(tempFp, "%s %s 1 %s\n", booking.date, booking.timeSlot, booking.username);
            }
        }
        fclose(fp);
        fclose(tempFp);
        remove(fileName);//删除原文件
        rename(tempFileName, fileName);//将临时文件的名字改为原文件的名字
    }
}
void writeBOOKing(char *classroomId, char *date, char *timeSlot, char *username) {
    BookingStatus booking;
    strcpy(booking.classroomId, classroomId);
    strcpy(booking.timeSlot, timeSlot);
    strcpy(booking.username, username);
    booking.booked = 1;
    char fileName[20];
    sprintf(fileName, "%s.txt", classroomId);
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        perror(fileName);
        return;
    }
    // 修改写入格式
    fprintf(fp, "%s %s %d %s\n", date, booking.timeSlot,booking.booked, booking.username);
    fclose(fp);
}