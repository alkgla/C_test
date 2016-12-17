#include <iostream>
using namespace std;
class Test{
public:
	explicit Test (int a):aInt(a){};
//	Test (char a):aChar(a){};
	int aInt;
	char aChar;
};

int main()
{
	Test a1(3);
	Test a2('2');

	Test a3=12;//->cannot convert from 'const int' to 'class Test'	
	Test a4='3';//->cannot convert from 'const int' to 'class Test'
}

/*
#include <stdio.h>
int main(){
unsigned  int a = 1;
double b = 1.0;
while(a < 300000000) {
	if(a != b) puts("something wrong with this computer");
	a += 1;
	b += 1.0;
}
printf("%.23f\n",(b-a));
printf("Hello World!\n");
}*/