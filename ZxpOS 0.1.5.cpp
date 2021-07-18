#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include<time.h> 
#include <sstream>
using namespace std;
int main(){
	int t = 0;
	printf("欢迎！Copyright ———— Zxp 2021\n");
	while (t != 1) {
		int r = 0;
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
		if (r == 4) {
			int num = 0;
			srand((unsigned int)time(NULL));
			printf("请输入难度：1、 入手（1 ～ 10）2、简单（1 ～ 50） 3、微难（1 ～ 100） 4、难 （1 ～ 1000） 5、非常非常非常非常非常非常难（1 ～ 100000000）>");
			int sr = 0;
			scanf("%d", &sr);
			if (sr == 1) {
				num = rand() % 10 + 1;
			} else if (sr == 2) {
				int num = rand() % 50 + 2;
			} else if (sr == 3) {
				int num = rand() % 100 + 2;
			} else if (sr == 4) {
				int num = rand() % 1000 + 2;
			} else if (sr == 5) {
				int num = rand() % 100000000 + 2;
			}
			int val = 0;//初始化玩家的输入数据
			
			while (1) {//写一个死循环，当猜对了利用break退出
				cout << "请输入1 ~ " << "你选的等级括号里的数字"<<"中的某一个数字>";
				cin >> val;
				cout << "玩家的输入数据是：" << val << endl;
				if (val > num) {
					cout << "猜测过大" << endl;
				}
				else if (val < num) {
					cout << "猜测过小" << endl;
				}
				else {
					cout << "恭喜你猜对了" << endl;
					break;//猜对了退出死循环
				}
			}
			
		}
		if (r >= 5) {
			printf("没有%d\n", r);
		}
	}
}