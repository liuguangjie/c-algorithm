#include <stdio.h>

void hanoi(int n, char from, char in, char to)
{
    if (n == 1) {
        printf("盘子1从 %c 处,到 %c 处\n", from, to);
    } else {
        hanoi(n-1, from, to, in);
        printf("盘子%d从 %c 处,到 %c 处 经过 %c 处 \n",n, from, to, in);
        hanoi(n-1, in, from, to);
    }

}

int main() 
{
    hanoi(3, 'A', 'B', 'C');

    return 0;
}