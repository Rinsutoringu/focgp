/*
####################################################


这里将创建一些读写文件的示例demo，以便于查找与学习

- 在一切开始之前，我们需要先进行规划文件的具体存储内容（都有几行，都会存储什么东西？）
- 看了一下要求，我们的程序应实现自适应读取（即：无论多少个用户，程序将都可以进行妥善地读取）
- 我们的程序要读写三种txt文档
    - 1. 一个存储用户账号密码的文档
    - 2. 一个存储可用教室信息的文档
    - 3. <可用教室数量>个存储教室状态的文档

- 那么就得先把自适应文件读取的轮子造出来！

- 本文件中包含的函数实现内容为：

将某一指定文件的内容全部读取，
返回一个字符串型数组，并一并获取该字符串型数组的元素数量（行数）

####################################################
*/

#include <stdio.h>
#include <stdlib.h>

char** getLines(const char *filename, int *count) {
    *count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return NULL; // 返回NULL
    }
    // 如果打不开文件，返回NULL

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            (*count)++; 
        }
    }
    // 计算文件中的行数，即换行符的数量，存储进从主程序传入的指针count
    // （实际上读取到的是换行符的数量，所以行数要+1）

    rewind(file); 
    // 重置文件指针到文件开头，在刚才数行数的操作时，指针已经到了文件末尾。

    char **lines = (char **)malloc((*count + 1) * sizeof(char *)); 
    // 依据行数动态分配内存，计算方式为行数+1，因为最后一行没有换行符。

    if (lines == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }
    // 如果内存分配失败，返回NULL

    for (int i = 0; i < *count; i++) {
        lines[i] = (char *)malloc(256 * sizeof(char));  // 假设每行最大256个字符
        if (lines[i] == NULL) {  // 如果内存分配失败
            perror("Memory allocation failed for line"); 
            for (int j = 0; j < i; j++) {
                free(lines[j]);  // 确定内存分配出错后，释放之前分配的内存
            }
            free(lines);  // 释放行指针数组的内存
            fclose(file);  // 关闭文件
            return NULL;  // 返回NULL
        }
        fgets(lines[i], 256, file); 
        // 读取一行，最多256个字符，存储到lines[i]中
    }

    fclose(file);
    return lines; 
    // 返回读取的行
}

int main(int argc, char const *argv[]) {
    int count;
    const char *filename = "data.txt"; // 假设文件名为 data.txt
    char **lines = getLines(filename, &count); 
    
    if (lines == NULL) {
        return 1; 
    }

    printf("File contents:\n");
    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]); 
    }
    free(lines); 
    return 0;
}