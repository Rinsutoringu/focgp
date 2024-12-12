#include <stdio.h>
#include <string.h>
int userlogin (int n) {
	char account[255];
	char passwords[255];
	char stuAccount[100][20];
	char stuPass[100][20];
    FILE *fp;
	fp=fopen("account.txt","r");
	if(fp==NULL){
		printf("Sorry!There is not account!\n");
		return 0;
	}
	int j=0;
    while (j<100&&fscanf(fp,"%s %s", stuAccount[j],stuPass[j])!=EOF){
        j++;
    }
	fclose(fp);
	int ErrorTimes=0;
	while(ErrorTimes<3){
	printf("Please enter your account : ");
	scanf("%s",account);
	printf("Please enter your passwords : ");
	scanf("%s",passwords);
		for(int k=0;k<j;k++){
		if(strcmp(account,stuAccount[k])==0&&strcmp(passwords,stuPass[k])==0){
			printf("Thanks,you have successfully logged in!\n");
                   return 1;		
           }
		}
		ErrorTimes++;
		int LeftTimes=3-ErrorTimes;
		if(LeftTimes>0){
		printf("Abnormal account or password, try again!You still have %d chance left.\n",LeftTimes);
		}
		}
		printf("You have failed three times!\n");
		return 0;
}
