# 项目文档

## char** getLines(const char *filename, int *count)
- 接受两个参数
    - 第一个参数为需要打开的文件名称（及相对路径）
    - 第二个参数为程序获取到的文件行数（实际上为文件行数-1，因为统计的是换行符数量。）
- 返回一个动态数组，不要忘记释放内存
- 调用示例
```
int main() {
    int count;
    const char *filename = "data.txt"; 
    // 假设文件名为 data.txt

    char **lines = getLines(filename, &count); 

    printf("File contents:\n");
    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]); 
        // 在执行内存释放的时候，因为这个数组是字符串数组，所以要进行逐行释放内存

    }
    free(lines); 
    // 把每一行的内存都释放掉后，再释放数组本体的内存
    return 0;
}

```