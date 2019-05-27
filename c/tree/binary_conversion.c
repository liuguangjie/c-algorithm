#include <stdio.h>
#include <string.h>
#include <math.h>

void decimalismTobinary(char[], int*); // 十进制 转二进制
void binaryTodecimalism(char[],int*);// 二进制转十进制
int main() 
{
    // 十进制 转二进制
    int a = 50;
    char bits[32]={'\0'};
    int len = 0;
    memset(bits,'\0',sizeof(bits));

    decimalismTobinary(bits, &a);
    printf("%s\n",bits);
    printf("=================\n");
    int sum=0;
    binaryTodecimalism(bits, &sum);
    printf("%d\n", sum);

   
    
    // printf("%d\n", sum);
    
    
    // printf("%d\n",sizeof(bits));
    //printf("%d\n", a/2);
   // printf("%c\n",1);

    return 0;
}

void decimalismTobinary(char bits[],int* a) 
{   
    int len=0;
    while (*a>0)
    {
        bits[len++] = *a%2 + '0';
        *a/=2;
    }
}

void binaryTodecimalism(char bs[] ,int* a) {

     //第一次 1*2^(有效位-1)   pow(2, 有效位-1)
    //第二次 1*2^(有效位-2)   
    // 计算有效位
    int len = 0;
    int effective = 0;
    while (len < sizeof(bs))
    {
        if (bs[len] != '\0') {
            effective++;
        }
        len++;
    }
    int i,j,sum=0;
    for (i = effective - 1; i >= 0 ; i--) 
    {   
        int k = (bs[i] - '0');
        int pow = 1;
        for (j=i; j > 0; j--) 
        {
            pow = pow * 2;
        }
        sum = sum + k*pow;
    }
    *a = sum;
}
