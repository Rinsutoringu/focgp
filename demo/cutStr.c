/*
####################################################


这里将创建一些读写文件的示例demo，以便于查找与学习

- 搞定了文件读写函数 接下来要做个分割函数
- 简单来说就是xxxx空格yyyy，输出为一个xxxx变量和一个yyyy变量

准备好的话就开始吧❤
####################################################
*/
//实现一个函数，输入一个带有空格的字符串，
// 在函数中把这个字符串从空格处分割并去掉空格，
// 输出一个由两个字符串组成的数组

#include<stdio.h>
#include <string.h>

void cutStr(char *str, char **cutout){
    // 先获取输入字符串的长度以便于变量
    cutout[0] = strtok(str, " ");
    cutout[1] = strtok(NULL, " ");
}



int main(int argc, char const *argv[])
{
    char str[] = "wpr 121";
    char *cutout[2];
    cutStr(str, cutout);
    printf("cutout[0] = %s\n", cutout[0]);
    printf("cutout[1] = %s\n", cutout[1]);
    return 0;
}
