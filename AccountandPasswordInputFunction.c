#include <stdio.h>
#include <string.h>
/*�����ʶ���˺������
˼·�ǣ����ļ�������˺ź�����ֱ𴢴���һ����ά������ߣ���ͨ�����ϵ�����Ͷ�ά������Ľ��бȽ�
�Ӷ������˺������ʶ��
������������ϸ��ע��*/
int main() {
	char account[255];
	char passwords[255];//�������������洢�û�������˺�����
	char stuAccount[100][20];
	char stuPass[100][20];//�������Ƕ�ά���飬�����洢�ļ��е��˺ź������
    FILE *fp;
	fp=fopen("account.txt","r");
	if(fp==NULL){
		printf("Sorry!\n");
		return 0;
	}
	int j=0;
    while (j<100&&fscanf(fp,"%s %s", stuAccount[j],stuPass[j])!=EOF){
        j++;
    }//�������int j=0����ߣ�������ʵ���ļ�����˺����������һ����ά�������,������бȽ�
	fclose(fp);//�ر��ļ�
	int i=0;
	while(i<3){//������������ʶ�������˺�����Ĵ���������3��֮��͹ر�
	printf("Please enter your account : ");
	scanf("%s",account);
	printf("Please enter your passwords : ");
	scanf("%s",passwords);
		for(int k=0;k<j;k++){
		if(strcmp(account,stuAccount[k])==0&&strcmp(passwords,stuPass[k])==0){
			printf("thank\n");
				return 0;//���if���ǵ��˺����붼��ȷ��ʱ�򣬽�����һ��������
				//��һ��ҪҪ�νӵ���һ������
           }
		}
		i++;
		int q=3-i;
		printf("Abnormal account or password, try again!You still have %d chance left.\n",q);
		}//�⼸����������ʾ��ʣ�¼��λ�����Խ��������˺����룬ͬʱ�������
		printf("The maximum number of times has been used up!\n");
		return 0;//��3�λ��ᶼ����֮��ֹͣ��������� �ر�
}


