#include <stdio.h>
#include <string.h>
/*这个是识别账号密码的
思路是：把文件里面的账号和密码分别储存再一个二维数组里边，再通过不断的输入和二维数组里的进行比较
从而进行账号密码的识别
接下来会有详细的注释*/
int main() {
	char account[255];
	char passwords[255];//这两个是用来存储用户输入的账号密码
	char stuAccount[100][20];
	char stuPass[100][20];//这两个是二维数组，用来存储文件中的账号和密码的
    FILE *fp;
	fp=fopen("account.txt","r");
	if(fp==NULL){
		printf("Sorry!\n");
		return 0;
	}
	int j=0;
    while (j<100&&fscanf(fp,"%s %s", stuAccount[j],stuPass[j])!=EOF){
        j++;
    }//从上面的int j=0到这边，是用来实现文件里的账号与密码存在一个二维数组里边,方便进行比较
	fclose(fp);//关闭文件
	int i=0;
	while(i<3){//这两行是用来识别输入账号密码的次数，到达3次之后就关闭
	printf("Please enter your account : ");
	scanf("%s",account);
	printf("Please enter your passwords : ");
	scanf("%s",passwords);
		for(int k=0;k<j;k++){
		if(strcmp(account,stuAccount[k])==0&&strcmp(passwords,stuPass[k])==0){
			printf("thank\n");
				return 0;//这段if，是当账号密码都正确的时候，进行下一步操作的
				//这一段要要衔接到下一个函数
           }
		}
		i++;
		int q=3-i;
		printf("Abnormal account or password, try again!You still have %d chance left.\n",q);
		}//这几行是用来提示还剩下几次机会可以进行输入账号密码，同时输出警告
		printf("The maximum number of times has been used up!\n");
		return 0;//当3次机会都用完之后，停止这个程序并且 关闭
}


