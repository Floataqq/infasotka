#include <stdio.h>

void func(long decimalnum);

int main(void)
{
    long decimalnum;

    printf("Enter the decimal number: ");
    scanf("%ld", &decimalnum);

    func(decimalnum);

    return 0;
}

void func(long decimalnum)
{
    long remainder, quotient;

    int octalNumber[100], i = 1, j;
    quotient = decimalnum;

    while (quotient != 0) {
        octalNumber[i++] = quotient % 8;

        quotient = quotient / 8;
    }

    for (j = i - 1; j > 0; j--) {
        printf("%d", octalNumber[j]);
    }

    printf("\n");
}
