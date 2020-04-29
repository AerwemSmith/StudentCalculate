#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<iostream>
using namespace std;

void DecimalAnswer(double y[]);
void IntegrateAnswer(int y[]);
void Integrate();
void Decimal();
void MixDecimal();
void MixIntegrate();

FILE *p;
int n, Maxnum, symbol, fa, fl, kuohao, file;

int main()
{
	printf("\t\t****小学四则运算自动生成程序****\n");
	printf("\n1.---请输入生成题目的数量---\n");
	scanf("%d", &n);
	printf("\n---2.请选择运算符号---\n\t(1)加法   (2)减法    (3)乘法   (4)除法    (5)混合运算\n");
	scanf("%d", &symbol);
	printf("\n---3.请输入生成的最大数(如十位数，百位数等)---\n");
	scanf("%d", &Maxnum);
	printf("\n---4.请选择是否带有小数---\n\t##(1)否  (2)是##\n");
	scanf("%d", &fl);
	printf("\n---5.请选择是否带有括号---\n\t##(1)否  (2)是##\n");
	scanf("%d", &kuohao);
	printf("\n---6.请选择打印方式---\n\t##(1)屏幕   (2)文件##\n");
	scanf("%d", &file);
	if (file == 2)
		printf("\n已生成文本文件result.txt");
	p = fopen("E:\\text\\result.txt", "w");
	printf("\n\n");
	if (symbol != 5)
	{
		if (fl == 1)
			Integrate();  //简单运算（无小数）
		else
			Decimal();  //简单运算（有小数）
	}
	else
	{
		if (fl == 1)
			MixIntegrate();  //混合运算（无小数、有无括号）
		else
			MixDecimal(); //混合运算（有小数、有无括号）
	}
	fclose(p);
	printf("\n是否重新运行运行该程序?   <1>是   <2>退出\n");
	scanf("%d", &fa);
	if (fa == 1)
	{
		system("cls");  //清屏，重新运行
		main();
	}
}

void DecimalAnswer(double y[])   //小数运算答案
{
	int i;
	if (file == 1)
	{
		printf("\n正确答案：\n");
		for (i = 1;i < n + 1;i++)
			printf("(%d) %.2f\n", i, y[i]);
	}
	else
	{
		fprintf(p, "\n正确答案：\n");
		for (i = 1;i < n + 1;i++)
			fprintf(p, "(%d) %.2f\n", i, y[i]);
	}
}

void IntegrateAnswer(int y[])       //整数运算答案
{
	int i;
	if (file == 1)      //输出到文件
	{
		printf("\n正确答案：\n");
		for (i = 1;i < n + 1;i++)
			printf("(%d) %d\n", i, y[i]);
	}
	else         //输出到屏幕
	{
		fprintf(p, "\n正确答案：\n");
		for (i = 1;i < n + 1;i++)
			fprintf(p, "(%d) %d\n", i, y[i]);
	}
}

void Integrate()  //简单运算，整数的四则运算
{
	int i, a, b, x[1000];
	char c;
	for (i = 1;i < n + 1;i++)
	{
		a = rand() % Maxnum;    //随机数获取
		b = rand() % Maxnum;
		if (symbol == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (symbol == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (symbol == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (symbol == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % Maxnum;
			}
			x[i] = a / b;
		}
		if (file == 1)
			printf("(%d) %d%c%d=\n", i, a, c, b);
		else
			fprintf(p, "(%d) %d%c%d=\n", i, a, c, b);
	}
	IntegrateAnswer(x);   //保存运算结果
}

void Decimal()  //小数的一般四则运算
{
	int i;
	double x[1000], a, b;
	char c;
	for (i = 1;i < n + 1;i++)
	{
		a = rand() % (Maxnum * 100) / 100.00;   //随即小数获取
		b = rand() % (Maxnum * 100) / 100.00;
		if (symbol == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (symbol == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (symbol == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (symbol == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % (Maxnum * 100) / 100.00 + 1;
			}
			x[i] = a / b;
		}
		if (file == 1)
			printf("(%d) %.2f%c%.2f=\n", i, a, c, b);
		else
			fprintf(p, "(%d) %.2f%c%.2f=\n", i, a, c, b);
	}
	 DecimalAnswer(x);   //保存运算结果
}

void MixDecimal()  //小数混合运算
{
	int i;
	double x[1000], a, b, c;
	char d, e;
	for (i = 1;i < n + 1;i++)
	{
		a = rand() % (Maxnum * 100) / 100.00 + 1;
		b = rand() % (Maxnum * 100) / 100.00 + 1;
		c = rand() % (Maxnum * 100) / 100.00 + 1;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (kuohao == 1)   //有括号
				x[i] = a - b * c;
			else
				x[i] = (a - b) * c;
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (b == 0)
			{
				c = rand() % (Maxnum * 100) / 100.00 + 1;
			}
			if (kuohao == 1)
				x[i] = a + b / c;
			else
				x[i] = (a + b) / c;
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (b == 0)
			{
				b = rand() % (Maxnum * 100) / 100.00 + 1;
			}
			if (kuohao == 1)
				x[i] = a - b / c;
			else
				x[i] = (a - b) / c;
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (kuohao == 1)
				x[i] = a + b * c;
			else
				x[i] = (a + b) * c;
		}
		if (file == 1)
		{
			if (kuohao == 1)
				printf("(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			else
				printf("(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
		}
		else
		{
			if (kuohao == 1)
				fprintf(p, "(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			else
				fprintf(p, "(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
		}
	}
	 DecimalAnswer(x);   //保存运算结果
}

void  MixIntegrate()  //整形混合运算
{
	int i, a, b, c;
	int x[1000];
	char d, e;
	for (i = 1;i < n + 1;i++)
	{
		a = rand() % Maxnum;
		b = rand() % Maxnum;
		c = rand() % Maxnum;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (kuohao == 1)   //无括号
				x[i] = a - b * c;
			else             //有括号
				x[i] = (a - b) * c;
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (c == 0)
			{
				c = rand() % Maxnum;
			}
			if (kuohao == 1)
				x[i] = a + b / c;
			else
				x[i] = (a + b) / c;
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (c == 0)
			{
				c = rand() % Maxnum;
			}
			if (kuohao == 1)
				x[i] = a - b / c;
			else
				x[i] = (a - b) / c;
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (kuohao == 1)
				x[i] = a + b * c;
			else
				x[i] = (a + b) * c;
		}
		if (file == 1)   //输出到屏幕
		{
			if (kuohao == 1)
				printf("(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			else
				printf("(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
		}
		else //输出到文件
		{
			if (kuohao == 1)
				fprintf(p, "(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			else
				fprintf(p, "(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
		}
	}
	IntegrateAnswer(x);   //保存运算结果
}

