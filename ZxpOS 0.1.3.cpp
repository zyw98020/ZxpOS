#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include<time.h> 
#include <sstream>
using namespace std;
int main(){
	int t;
	printf("欢迎！Copyright ———— Zxp 2021\n");
	while (t != 1) {
		int r;
		printf(">");
		scanf("%d", &r);
		if (r == 1) {
			printf("正在关机中\n");
			printf("Bye！");
			return 0;
		}
		if (r == 2) {
			int a,b;
			printf("输入第1个数>>>");
			cin >> a;
			printf("输入第2个数>>>");
			cin >> b;
			cout << a<< " + " << b<< " = " << a  + b<<endl;
			cout << a<< " - " << b<< " = " << a  - b<<endl;
			cout << a<< " * " << b<< " = " << a  * b<<endl;
			cout << a<< " / " << b<< " = " << a  / b<<endl;
		}
		if (r == 3) {
			time_t now = time(NULL);
			tm* tm_t = localtime(&now);
			std::stringstream ss;
			ss << "年:" << tm_t->tm_year + 1900 << " 月:" << tm_t->tm_mon + 1 << " 日:" << tm_t->tm_mday
			<< " 点:" << tm_t->tm_hour << " 分钟:" << tm_t->tm_min << " 秒钟:" << tm_t->tm_sec;
			
			std::cout << ss.str();
			printf("\n");
		}
	}
}