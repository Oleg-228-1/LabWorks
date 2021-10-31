#include <stdio.h>
#include <math.h>
#include <conio.h>

int my_Lenght(float a)
{
	int n = 0;
	int s;
	if (a < 0){
		n++;
	}
	for (;;)
	{
		s = a;
		if (s == 0){
			return n;
		}
		a /= 10;
		n++;
	}
}
double my_function(float x)
{
	return x*x*x / x+5;
}
void table(float x1, float x2, float delta, unsigned int n )
{
	int i, iL, XL, my_fL;
	float X = x1;
	for (i=1; i<n; i++)
	{
		iL = my_Lenght(i);
		XL = my_Lenght(X);
		my_fL = my_Lenght(my_function(X));
		printf("+---------+---------+---------+\n");
		for (int j = 0;j< 9-iL;j++)
		{
			printf(" ");
		}
		printf("%d|", i);

		for (int j = 0; j < 6 - XL; j++)
		{
			printf(" ");
		}
		printf("%f|", X);
		for (int j = 0; j < 4 - my_fL; j++)
		{
			printf(" ");
		}
		printf("%f|", my_function(X));
		printf("\n");
		X += delta;
	}
	printf("+---------+---------+---------+\n");
}
void Title()
{
	printf("*******************************\n");
	printf("*     N   *    X    *   F(X)  *\n");
	printf("*******************************\n");
}
int main()
{
	unsigned int variant=1,n;
	float x1, x2, delta,s;

	printf("Enter varint 1 or 2\n");
	scanf("%d", &variant);
	system("cls");

    if(variant==1)
    {
		printf("Enter your data,please\n");
		scanf("%f", &x1);
		scanf("%f", &x2);
		scanf("%d", &n);
		delta = (x2 - x1) / (n - 1);
		printf("x1=%f  x2=%f n=%d\n", x1, x2, n);
		n++;
    }else if(variant==2)
    {
		printf("Enter your data,please\n");
		scanf("%f", &x1);
		scanf("%f", &x2);
		scanf("%f", &delta);
		n = 2;
		s = x1;
		for (;;)
		{
			s += delta;
			if (s >= x2)
                {
				break;
				}
			n++;
		}
		printf("x1=%f  x2=%f delta=%f\n", x1, x2, delta);
	}
	Title();
	table(x1, x2, delta, n);
	return 0;
}
