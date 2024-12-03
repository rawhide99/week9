#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num, count = 0;
    printf("Enter a number.\n");
    scanf("%d", &num);

    while(num > 0)
    {
        int temp = num % 2;
        num = num/2;
        if(temp == 1)
        {
            count ++;
        }
    }
    printf("The number of 1's in %d is %d.\n",  num, count);
}