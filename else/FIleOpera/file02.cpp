/*若打开文件，需读写同时进行fopen("file","r+")或fopen("file","rb+")
int fgetc(FILE *stream)
  获得下一个字符(an unsigned char)流指针前移
  This function returns the character read as an unsigned char cast to an int or EOF on end of file or error
*/
/*#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	FILE* fpI=NULL;
	char c[100],ch;
	fpI=fopen("D:\\A.txt","r+");
	if(fpI==NULL)
	{
		printf("file A cannot be opened\n");
		exit(0);
	}
	for(int i=0;(ch=fgetc(fpI))!=EOF;i++)
	{
		c[i]=ch;
	}
	c[i]='\0';
	fclose(fpI);
	printf("%s\n",c);
}
*/

























/*	//FILE* fpO=NULL;
	fpO=fopen("D:\\B.txt","w");
	if(fpO==NULL)
	{
		printf("请检查");
		exit(0);
	}
	//char temp='\0';
	while(!feof(fpI))
	{
		temp=fgetc(fpI);
		if(temp!=EOF)
			fputc(temp,fpO);
	}
	fclose(fpO);
	fclose(fpI);
	getch();
	return 0;
}
*/