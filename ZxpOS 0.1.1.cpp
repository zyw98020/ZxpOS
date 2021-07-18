#include <cstdio>
#include<stdlib.h>
#include <string.h>
#include <iostream>
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
	}
}