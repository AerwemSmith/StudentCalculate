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
	printf("\t\t****Сѧ���������Զ����ɳ���****\n");
	printf("\n1.---������������Ŀ������---\n");
	scanf("%d", &n);
	printf("\n---2.��ѡ���������---\n\t(1)�ӷ�   (2)����    (3)�˷�   (4)����    (5)�������\n");
	scanf("%d", &symbol);
	printf("\n---3.���������ɵ������(��ʮλ������λ����)---\n");
	scanf("%d", &Maxnum);
	printf("\n---4.��ѡ���Ƿ����С��---\n\t##(1)��  (2)��##\n");
	scanf("%d", &fl);
	printf("\n---5.��ѡ���Ƿ��������---\n\t##(1)��  (2)��##\n");
	scanf("%d", &kuohao);
	printf("\n---6.��ѡ���ӡ��ʽ---\n\t##(1)��Ļ   (2)�ļ�##\n");
	scanf("%d", &file);
	if (file == 2)
		printf("\n�������ı��ļ�result.txt");
	p = fopen("E:\\text\\result.txt", "w");
	printf("\n\n");
	if (symbol != 5)
	{
		if (fl == 1)
			Integrate();  //�����㣨��С����
		else
			Decimal();  //�����㣨��С����
	}
	else
	{
		if (fl == 1)
			MixIntegrate();  //������㣨��С�����������ţ�
		else
			MixDecimal(); //������㣨��С�����������ţ�
	}
	fclose(p);
	printf("\n�Ƿ������������иó���?   <1>��   <2>�˳�\n");
	scanf("%d", &fa);
	if (fa == 1)
	{
		system("cls");  //��������������
		main();
	}
}

void DecimalAnswer(double y[])   //С�������
{
	int i;
	if (file == 1)
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1;i < n + 1;i++)
			printf("(%d) %.2f\n", i, y[i]);
	}
	else
	{
		fprintf(p, "\n��ȷ�𰸣�\n");
		for (i = 1;i < n + 1;i++)
			fprintf(p, "(%d) %.2f\n", i, y[i]);
	}
}

void IntegrateAnswer(int y[])       //���������
{
	int i;
	if (file == 1)      //������ļ�
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1;i < n + 1;i++)
			printf("(%d) %d\n", i, y[i]);
	}
	else         //�������Ļ
	{
		fprintf(p, "\n��ȷ�𰸣�\n");
		for (i = 1;i < n + 1;i++)
			fprintf(p, "(%d) %d\n", i, y[i]);
	}
}

void Integrate()  //�����㣬��������������
{
	int i, a, b, x[1000];
	char c;
	for (i = 1;i < n + 1;i++)
	{
		a = rand() % Maxnum;    //�������ȡ
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
	IntegrateAnswer(x);   //����������
}

void Decimal()  //С����һ����������
{
	int i;
	double x[1000], a, b;
	char c;
	for (i = 1;i < n + 1;i++)
	{
		a = rand() % (Maxnum * 100) / 100.00;   //�漴С����ȡ
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
	 DecimalAnswer(x);   //����������
}

void MixDecimal()  //С���������
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
			if (kuohao == 1)   //������
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
	 DecimalAnswer(x);   //����������
}

void  MixIntegrate()  //���λ������
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
			if (kuohao == 1)   //������
				x[i] = a - b * c;
			else             //������
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
		if (file == 1)   //�������Ļ
		{
			if (kuohao == 1)
				printf("(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			else
				printf("(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
		}
		else //������ļ�
		{
			if (kuohao == 1)
				fprintf(p, "(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			else
				fprintf(p, "(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
		}
	}
	IntegrateAnswer(x);   //����������
}

