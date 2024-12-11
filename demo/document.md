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


## void cutStr(char *str, char **cutout)
- 接受两个参数
    - 第一个参数为分割前的原始字符串
    - 第二个参数为一个字符串数组，用于存储分割后的字符串
- 调用示例
```
int main(int argc, char const *argv[])
{
    char str[] = "wpr 121";
    // 创建了一个内容为"wpr 121"的数组
    char *cutout[2];
    // 创建了一个大小为2的字符串型数组
    cutStr(str, cutout);
    printf("cutout[0] = %s\n", cutout[0]);
    printf("cutout[1] = %s\n", cutout[1]);
    return 0;
}
```


## void search(int time, int volume)
- 接受两个参数
  - 第一个参数为系统当前时间
  - 第二个参数为用户所需的最大人数
- 调用示例
```
int main(int argc, char const *argv[])
{
    search(time.hour, max);
}
``

int userlogin (int n)
 -不需要任何参数进去
-只需要一个命令去执行即可
-按照我自己的测试就是：
int a;
a=userlogin(1);
--（1）用来执行用户登录的指令
-之后会自动跳出登录界面
——登录成功返回值a=1；
——登录失败返回值a=0；
通过a的值来判断是非登录成功

int TimeAndOrder(int n)
-同样的不需要任何参数进去
同上：
int b;
b=int TimeAndOrder(1) ;
--(1)用来执行命令
——之后就会自动跳出时间表 同时供用户输入指令进行选择
b会返回 1 2 3 4 其中任意一个值（若用户输入其他数字则会让他重新输入一次）
通过返回的值进行下一步操作（这是不是要跟下一个人讲一讲）？





