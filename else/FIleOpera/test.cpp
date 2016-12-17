
#include <iostream>
#include <fstream>//引入输入输出文件流对象需要的头文件
using namespace std;
int main(){
	int nyear,nmonth,ndate;
	ifstream fin("D:\\A.txt");//尝试打开Date.txt，并将其连接到输入流fin
	if(!fin.bad()){//判断是否成功打开
		fin.ignore(256,'\n');//忽略第一行的内容
		fin>>nyear>>nmonth>>ndate;//读取记录的数据
		cout<<"文件中的日期是"<<nyear<<"-"<<nmonth<<"-"<<ndate<<endl;
		fin.close();
	}
	else {
		cout<<"无法打开文件并进行读取"<<endl;
	}
	cout<<"请输入当前日期"<<endl;
	cin>>nyear>>nmonth>>ndate;
	ofstream fout("D:\\A.txt");
	if(!fout.bad()){
		fout<<"用户输入的日期是：\n"
			<<nyear<<" "<<nmonth<<" "<<ndate<<endl;
		fout.close();
	}
	else{
		cout<<"无法打开文件并进行写入"<<endl;
	}
	return 0;
}