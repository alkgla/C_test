//���ڴ�(����Ĵ�1)
#include <iostream>
using namespace std;
int main(){
	char word[100];
	char *p=word;
	int max=0,flag,i,j;
	cin>>p;
	int len=strlen(word);
	//˼·1��
	for (i=0;i<len;i++)  
    {  

		for (j=i;j<len;j++)
		{	
            flag = 1;  
            for (int k=i;k<=j;k++) 
			{
                if (word[k] != word[i+j-k])
                    flag = 0;  
                if (flag && j-i+1>max)
					max=j-i+1;
            }  
		}
    }
	cout<<max<<endl;

	//˼·2��ö������λ�ã�Ȼ�����ڸ�λ��������չ������¼�����µõ�����Ļ��ĳ���
	max=0;
	for (i=0;i<len;i++)  
    {  
		for (j=0;i-j>=0&&i+j<len;j++)
		{
			if (word[i-j] != word[i+j])
				break;
			if(j*2+1>max)
				max=j*2;
		}
		for (j=0;i-j>=0&&i+j+1<len;j++)
		{
			if (word[i-j] != word[i+j+1])
				break;
			if(j*2+1>max)
				max=j*2+1;
		}
    }
	cout<<max<<endl;
	return 0;
}