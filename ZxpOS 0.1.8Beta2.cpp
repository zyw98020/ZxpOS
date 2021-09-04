#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <sstream>
#include <vector>
using namespace std;
int a[10][10];

bool m = 1;
int cheng(int x,int y)
{
	int ans = 1;
	for ( int i = 1;i <= y;i++ )
		{
			ans *= x;
		}
	return ans;
}

void print()
{
	for( int i = 1;i <= 5;i++ )
		{
			for( int j = 1;j <= 5;j++ )
				{
					bool b = 0 + rand() %10;
					if( a[i][j] == 0 && b == 0 )
						{
							a[i][j] = cheng ( 2 , 1 + rand() %3 );
						}
					cout << a[i][j] <<"   ";
				}
			cout << endl;
			cout << endl;
		}
}

void print2()
{
	cout << endl;
	cout << endl;
	for( int i = 1;i <= 5;i++ )
		{
			for( int j = 1;j <= 5;j++ )
				{
					if( a[i][j] == 0 )
						{
							int c = 0 + rand() %10;
							if( c < 3 )
								{
									a[i][j] = cheng( 2 , 1 + rand() %3);
								}
						}
				}
		}
	for( int i = 1;i <= 5;i++ )
		{
			for( int j = 1;j <= 5;j++ )
				{
					cout << a[i][j];
					if( a[i][j] < 10 )
						{
							cout <<"    ";
						}
					else if( a[i][j] < 100 )
						{
							cout<<"   ";
						}
					else if( a[i][j] < 1000 )
						{
							cout<<"  ";
						}
					else
						{
							cout<<" ";
						}
				}
			cout << endl;
			cout << endl;
		}
	
}

int ctrl()
{
	char ctrl;
	cout <<"上移：w，下移：s，左移：a，右移：d，停止游戏：z"<< endl;
	cin >> ctrl;
	if( ctrl=='w' )
		{
			for( int i = 1;i <= 5;i++ )
				{
					for( int j = 1;j <= 5;j++ )
						{
							if( a[i][j] == a[i-1][j] )
								{
									a[i-1][j] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i-2][j] && a[i-1][j] == 0 )
								{
									a[i-2][j] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i-3][j] && a[i-2][j] == 0 )
								{
									a[i-3][j] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i-1][j] == 0 && i > 1 )
								{
									a[i-1][j] = a[i][j];
									a[i][j] = 0;
								}
						}
				}
		}
	if( ctrl == 's' )
		{
			for( int i = 1;i <= 5;i++ )
				{
					for( int j = 1;j <= 5;j++ )
						{
							if( a[i][j] == a[i+1][j] )
								{
									a[i+1][j] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i+2][j] && a[i+1][j] == 0 )
								{
									a[i+2][j] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i+3][j] && a[i+2][j] == 0 )
								{
									a[i+3][j] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i+1][j] == 0 && i < 5 )
								{
									a[i+1][j] = a[i][j];
									a[i][j] = 0;
								}
						}
				}
		}
	if( ctrl == 'a' )
		{
			for( int i = 1;i <= 5;i++ )
				{
					for( int j = 1;j <= 5;j++ )
						{
							if( a[i][j] == a[i][j-1] )
								{
									a[i][j-1] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i][j-2] && a[i][j-1] == 0 )
								{
									a[i][j-2] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i][j-3] && a[i][j-2] == 0 )
								{
									a[i][j-3] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j-1] == 0 && j > 1 )
								{
									a[i][j-1] = a[i][j];
									a[i][j] = 0;
								}
						}
				}
		}
	if( ctrl == 'd' )
		{
			for( int i = 1;i <= 5;i++ )
				{
					for( int j = 1;j <= 5;j++ )
						{
							if( a[i][j] == a[i][j+1] ) 
								{
									a[i][j+1] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i][j+2] && a[i][j+1] == 0 )
								{
									a[i][j+2] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j] == a[i][j+3] && a[i][j+2] == 0 )
								{
									a[i][j+3] += a[i][j];
									a[i][j] = 0;
								}
							else if( a[i][j+1] == 0 && j < 5 )
								{
									a[i][j+1] = a[i][j];
									a[i][j] = 0;
								}
						}
				}
		}
	if( ctrl == 'z' )
		{
			m = 0;
		}
	
	return m;
}
class qipan
{
public:
	qipan() {}
	~qipan() {};
	
	
	//向上下左右，斜的方向
	char  left(int x, int y)
	{//检查是否合适
		if (x >= 1 && x <= hight&& y - 1 >= 1 && y - 1 <= width)
			{
				return q[x][y - 1];
			}
		else {
			return 'F';
		}
		
	}
	char  right(int x, int y)
	{
		if (x >= 1 && x <= hight&&y + 1 >= 1 && y + 1 <= width)
			{
				return q[x][y + 1];
			}
		else {
			return 'F';
		}
		
	}
	char  up(int x, int y)
	{
		if (x - 1 >= 1 && x - 1 <= hight && y >= 1 && y <= width)
			{
				return q[x - 1][y];
			}
		else {
			return 'F';
		}
		
	}
	char down(int x, int y)
	{
		if (x + 1 >= 1 && x + 1 <= hight && y >= 1 && y <= width)
			{
				return q[x + 1][y];
			}
		else {
			return 'F';
		}
		
	}
	char left_up(int x, int y)
	{
		if (x - 1 >= 1 && x - 1 <= hight && y - 1 >= 1 && y - 1 <= width)
			{
				return q[x - 1][y - 1];
			}
		else {
			return 'F';
		}
		
	}
	char  left_down(int x, int y)
	{
		if (x + 1 >= 1 && x + 1 <= hight && y - 1 >= 1 && y - 1 <= width)
			{
				return q[x + 1][y - 1];
			}
		else {
			return 'F';
		}
		
	}
	char right_up(int x, int y)
	{
		if (x - 1 >= 1 && x - 1 <= hight && y + 1 >= 1 && y + 1 <= width)
			{
				return q[x - 1][y + 1];
				
			}
		else {
			return 'F';
		}
		
		
	}
	char right_down(int x, int y)
	{
		if (x + 1 >= 1 && x + 1 <= hight && y + 1 >= 1 && y + 1 <= width)
			{
				return q[x + 1][y + 1];
			}
		else {
			return 'F';
		}
	}
	
	void init_cur() {
		h_cur = hang;
		l_cur = lie;
		
	}
	bool win()
	{
		bool WIN = false;
		char temp = q[hang][lie];
		
		//以上为例，每次先看上面的5个，假如一样，iter++；否则 break；再加上下的方向，同样iter++；最后iter+1==5,WIN=true;并且退出
		//各个方向重复，上下左右，斜着的。
		//赢了直接退出。
		//显示是谁赢了
		
		
		//左右
		int  count_lr = 1;
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (left(h_cur, l_cur) == temp)
					count_lr++;
				else
					break;
				l_cur--;
				
			}
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (right(h_cur, l_cur) == temp)
					count_lr++;
				else
					break;
				l_cur++;
				
			}
		if (count_lr == 5)
			WIN = true;
		//上下
		int  count_ud = 1;
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (up(h_cur, l_cur) == temp)
					count_ud++;
				else
					break;
				h_cur--;
				
			}
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (down(h_cur, l_cur) == temp)
					count_ud++;
				else
					break;
				h_cur++;
				
			}
		if (count_ud == 5)
			WIN = true;
		
		
		//左斜
		int  count_lt = 1;
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (left_up(h_cur, l_cur) == temp)
					count_lt++;
				else
					break;
				h_cur--;
				l_cur--;
				
			}
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (left_down(h_cur, l_cur) == temp)
					count_lt++;
				else
					break;
				h_cur++;
				l_cur--;
				
			}
		if (count_lt == 5)
			WIN = true;
		
		//右边斜
		int  count_rt = 1;
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (right_up(h_cur, l_cur) == temp)
					count_rt++;
				else
					break;
				h_cur--;
				l_cur++;
				
			}
		init_cur();
		for (int i = 0; i < 4; i++)
			{
				
				if (right_down(h_cur, l_cur) == temp)
					count_rt++;
				else
					break;
				h_cur++;
				l_cur++;
				
			}
		if (count_rt == 5)
			WIN = true;
		
		return WIN;
	}
	
	
	void qipan_array()
	{
		for (int i = 0; i < hight; i++) {
			for (int j = 0; j < width; j++)
				q[i][j] = '+';
		}
	}
	
	
	
	void prin_qipan()
	{
		//打印二维数组；每一行要打印上行号，以及列号
		for (int i = 0; i <hight; i++)
			{
				
				for (int j = 0; j < width; j++)
					{
						cout << q[i][j] << " ";
						
					}
				cout << i;
				cout << endl;
			}
		
		for (int j = 0; j <width; j++)
			{
				cout << j << " ";
			}
		cout << endl << "________________________________" << endl;
	}
	int xiaqi(int player)
	{
		if (player == 1) {
			q[hang][lie] = 'O';
		}
		else if (player == 2)
			{
				q[hang][lie] = 'X';
			}
		else
			cout << "input player is wrong" << endl;
		return 0;
	}
	
	//初始化行列
	int gethang(int h)
	{
		
		hang = h;
		return 0;
	}
	int getlie(int l)
	{
		lie = l;
		return 0;
	}
	
	
	int h_cur;
	int l_cur;
	const int hight = 9;
	const int width = 9;
	int hang; int lie;
	char q[9][9];
};
int main(){
	int t = 0;
	printf("\a");
	printf("ZxpOS!\n");
	printf("欢迎！Copyright ———— Zxp 2021\n");
	printf("\a");
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
			int jsq = 0;
			while (jsq != 1) {
				int a ,b;
				printf("				        *********************************************\n\
				        *  1  **  2  **  3  ** +  **  - **  X  ** / *\n\
                        *  4  **  5  **  6  **  7  **  8  **  9     *\n\
                        *********************************************\n");
				printf("输入第1个数>>>");
				cin >> a;
				if (a >= 0) {
					printf("输入第2个数>>>");
					cin >> b;
					if (b >= 0){
						printf("输入符号>>>");
						char fh;
						cin >> fh;
						if (fh == '+') {
							cout << a<< " + " << b<< " = " << a  + b<<endl;
						} else if (fh == '-') {
							cout << a<< " - " << b<< " = " << a  - b<<endl;
						} else if (fh == 'X' || fh == 'x' || fh == '*') {
							cout << a<< " * " << b<< " = " << a  * b<<endl;
						} else if (fh == '/') {
							cout << a<< " / " << b<< " = " << a  / b<<endl;
						} else {
							printf("输入的不对\n");
						}
						jsq += 1;

					} else {
						printf("输入的不对\n");
					}
				} else {
					printf("输入的不对\n");
					
				}

			}
		}
		if (r == 3) {
			time_t now = time(NULL);
			tm* tm_t = localtime(&now);
			std::stringstream ss;
			ss << "年:" << tm_t->tm_year + 1900 << " 月:" << tm_t->tm_mon + 1 << " 日:" << tm_t->tm_mday
			<< tm_t->tm_hour << " ：" << tm_t->tm_min << " ：" << tm_t->tm_sec;
			
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
				int num = rand() % 50 + 1;
			} else if (sr == 3) {
				int num = rand() % 100 + 2;
			} else if (sr == 4) {
				int num = rand() % 1000 + 1;
			} else if (sr == 5) {
				int num = rand() % 100000000 + 1;
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
		if (r == 5) {
			srand((int)time(0));
			print();
			while(m)
				{
					ctrl();
					system("clear");
					print2();
				}
			cout <<"游戏结束"<< endl;
		}
		if (r == 6) {
			int hang, lie;
			qipan wzq;
			wzq.qipan_array();
			cout << "A 与B 玩五子棋（8*8）" << endl;
			cout << "________________________________" << endl;
			for (int i = 0; i < 15; i++) {
				cout << "A 输入行： ";
				cin >> hang;
				cout << "A 输入列： ";
				cin >> lie;
				if (wzq.q[hang][lie] != '+')
					cout << "输入的行列数字已经有人占据了" << endl;
				else {
					wzq.gethang(hang);
					wzq.getlie(lie);
					
					wzq.xiaqi(1);
					wzq.prin_qipan();
					if (wzq.win())
						{
							cout << "A is winner" << endl;
							break;
						}
				}
				//b 开始了
				cout << "B 输入行： ";
				cin >> hang;
				cout << "B 输入列： ";
				cin >> lie;
				if (wzq.q[hang][lie] != '+')
					cout << "输入的行列数字已经有人占据了" << endl;
				else {
					wzq.gethang(hang);
					wzq.getlie(lie);
					
					wzq.xiaqi(2);
					
					wzq.prin_qipan();
					if (wzq.win())
						{
							cout << "B is winner" << endl;
							break;
						}
				}
			}
		}
	}
}
