//д�������ӻ��߸��ǵ��ļ���
#include <stdio.h>
#include <stdlib.h>
int i=0;
int main()
{
	FILE* fpI=NULL;
	
	char c[1000],a,ch;
	printf("���븲��ԭ����������\n------y  or  n------\n");
	scanf("%c",&a);
	
	if((fpI=fopen("D:\\A.txt","r"))==NULL)
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
	if(a=='n')
	{
		while((ch=fgetc(fpI))!=EOF)
		{	
			c[i]=ch;
			
			printf("%c",c[i]);
			++i;
		}
	}
	printf("���������ݵ�����ļ���:\n");
	if((fpI=fopen("D:\\A.txt","w"))==NULL)
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
	for(;i<100;i++)
	{
		scanf("%c",&c[i]);
		if(c[i]=='q')
		{
			c[i]='\0';
			break;
		}
	}
    fprintf(fpI,"%s",c);
    fclose(fpI);
	return 0;
}