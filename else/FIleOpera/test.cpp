
#include <iostream>
#include <fstream>//������������ļ���������Ҫ��ͷ�ļ�
using namespace std;
int main(){
	int nyear,nmonth,ndate;
	ifstream fin("D:\\A.txt");//���Դ�Date.txt�����������ӵ�������fin
	if(!fin.bad()){//�ж��Ƿ�ɹ���
		fin.ignore(256,'\n');//���Ե�һ�е�����
		fin>>nyear>>nmonth>>ndate;//��ȡ��¼������
		cout<<"�ļ��е�������"<<nyear<<"-"<<nmonth<<"-"<<ndate<<endl;
		fin.close();
	}
	else {
		cout<<"�޷����ļ������ж�ȡ"<<endl;
	}
	cout<<"�����뵱ǰ����"<<endl;
	cin>>nyear>>nmonth>>ndate;
	ofstream fout("D:\\A.txt");
	if(!fout.bad()){
		fout<<"�û�����������ǣ�\n"
			<<nyear<<" "<<nmonth<<" "<<ndate<<endl;
		fout.close();
	}
	else{
		cout<<"�޷����ļ�������д��"<<endl;
	}
	return 0;
}