#include <stdio.h>
struct Class{
	char name[20];
	int max;
	};//此处创建一个名为class的结构体，其中name为教室名称，max表示可容纳的最大人数
struct Class cl[100];//暂定不超过100个教室，可能需要用动态内存分配进行后续修改
void search(int time, int volume){//该函数表示查询可用教室
	FILE *fp;
	int i=0;//一个暂时的变量，用于遍历每个教室
	int flag=0;//一个暂时的变量，用于标记符合需求的教室
	fp = fopen("classroom_info.txt","r");
       if(fp == NULL) return;//检查文件是否为空
	while(fp != EOF){
		fscanf(fp,"%s %d",cl[i].name,&cl[i].max);
		i++;
	}//读取每个教室，并将其写入结构体中，此处可能需要用换行来进行进一步修正
	int n=i;
	for(i=0;i<=n;i++){//遍历每一个教室
		if(volume<=cl[i].max){//若最大容量合格，则输出；后续需要判断教室是否被预定
			flag++;
			printf("%d %s\n",flag,cl[i].name);
			}
		}
	if(flag==0) printf("No classroom available! Do you want to continue(Y/N)");
	}//表示没找到合格教室，询问用户是否继续

/*int main(int argc, char *argv[])
{
    //a为系统当前时间，b为等待用户传入所需教室的最大人数 search(a,b);
    return 0;
}*/

