#include <stdio.h>

int func(const char *str);

int main(int argc, char *argv[])
{

    if (argc == 2) {
        printf("Result is %d\n", func(argv[1]) + 5);
    
        return 0;
    }
    
    printf("Wrong number of parmeters\nUsage: %s <number>", argv[0]);
    
    return 1;
}

int func(const char *str)
{
    int i;
    int sign;
    long value;
    long prev;

    i = 0;
    sign = 1;
    value = 0;

    while (((str[i] <= 13 && str[i] >= 9) || str[i] == 32) && str[i] != '\0') {
        i++;
    }

    if (str[i] == '-') {
        sign = -1;
	    i++;
	}
    else if (str[i] == '+') {
        sign = 1;
	    i++;
	}

    while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0') {
        prev = value;
        value = value * 10 + sign * (str[i] - '0');

        if (sign == 1 && prev > value) {
            return 255;
        }
        else if (sign == -1 && prev < value) {
            return 0;
        }
        i++;
    }

    return value;
}