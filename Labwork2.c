#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

float my_function(float x){
    return exp(x);
}
float my_max(float first_parametr, float second_parametr)
    {
        int max;
        if(first_parametr>second_parametr)
            max=first_parametr;
        else
            max=second_parametr;
        return max;
    }
float left_rectangle(float a, float b, int n){
    float h;
    h=(b-a)/(n);
    float syma = 0;
    for(int i=0; i<=n-1; i++)
        {
        syma+=h*my_function(a+i*h);
        }
    return syma;
}
float right_rectangle(float a, float b, int n){
    float h;
    h=(b-a)/(n);
    float syma = 0;
    for(int i=0; i<=n; i++)
        {
        syma+=h*my_function(a+i*h);
        }
    return syma;
}
float trapezia(float a, float b, int n){
    float h;
    h=(b-a)/(n);
    float syma = my_function(a)+my_function(b);
    for(int i=1; i<=n-1; i++)
        {
        syma+=2*my_function(a+i*h);
        }
    syma*=h/2;
    return syma;
}

float parabol(float a, float b, int n){
    float h;
    h=(b-a)/(n);
    float syma = my_function(a)+my_function(b);
    int k;
    for(int i=1; i<=n-1; i++)
        {
        k=2+2*(i%2);
        syma+=k*my_function(a+i*h);
        }
    syma*=h/3;
    return syma;
}

void Var1(float a,float b,float p, unsigned int n){
    unsigned int i=0;
    float d;
        i+=2;
        d=fabs(left_rectangle(a,b,i)-left_rectangle(a, b, i+2));
    if(d>p)
        {
        i+=2;
        }

        d=fabs(left_rectangle(a,b,i)-left_rectangle(a, b, i+2));
    printf("**********************************************************\n");
    printf("|         1|%10.8f|%10.8f|%10.8f|%10.8f|%u|\n", left_rectangle(a,b,n), left_rectangle(a,b,10), left_rectangle(a,b,100), left_rectangle(a,b,1000), i);
    printf("**********************************************************\n");
}
void Var2(float a,float b,float p, unsigned int n){
    unsigned int i=0;
    float d;
     if(d>p)
        {
        i+=2;
        d=fabs(right_rectangle(a,b,i)-right_rectangle(a, b, i+2));
        }

    printf("**********************************************************\n");
    printf("|         2|%10.8f|%10.8f|%10.8f|%10.8f|%u|\n", right_rectangle(a,b,n), right_rectangle(a,b,10), right_rectangle(a,b,100), right_rectangle(a,b,1000), i);
    printf("**********************************************************\n");
}
void Var3(float a,float b,float p, unsigned int n){
    unsigned int i=0;
    float d;
     if(d>p)
        {
        i+=2;
        d=fabs(trapezia(a,b,i)-trapezia(a, b, i+2));
        }

    printf("**********************************************************\n");
    printf("|         3|%10.8f|%10.8f|%10.8f|%10.8f|%u|\n", trapezia(a,b,n), trapezia(a,b,10), trapezia(a,b,100), trapezia(a,b,1000), i);
    printf("**********************************************************\n");
}

void Var4(float a,float b,float p, unsigned int n){
    unsigned int i=0;
    float d;
     if(d>p)
        {
        i+=2;
        d=fabs(parabol(a,b,i)-parabol(a, b, i+2));
        }

    printf("**********************************************************\n");
    printf("|         4|%10.8f|%10.8f|%10.8f|%10.8f|%u|\n", parabol(a,b,n), parabol(a,b,10), parabol(a,b,100), parabol(a,b,1000), i);
    printf("**********************************************************\n");
}
int main()
{
    float a, b, p, h;
    unsigned int n, variant, i;
        do{
    printf("Enter your variant (1-left_rectangle, 2-right_rectangle, 3-Trapezia, 4-Parabol):");
    scanf("%u",&variant);
        } while(variant>4 || variant<1);

    printf("Enter lower limit:");
    scanf("%f",&a);
    printf("Enter upper limit:");
    scanf("%f",&b);
    printf("Enter allowable error:");
    scanf("%f",&p);
    printf("Enter number of intervals:");
    scanf("%u",&n);

    printf("\n**********************************************************\n");
    printf("| Method   |     N    |   N=10   |   N=100  |  N=1000  |n|\n");
    printf("**********************************************************\n");

          if(variant==1){
            Var1(a,b,p,n);
    }else if(variant==2){
            Var2(a,b,p,n);
    }else if(variant==3){
            Var3(a,b,p,n);
    }else if(variant==4){
            Var4(a,b,p,n);
    }
    return 0;
}
