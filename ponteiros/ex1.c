#include <stdio.h>

int main()
{

    int value1 = 12, value2 = 11;

    int *v1 = &value1;
    int *v2 = &value2;

    if (*v1 > *v2)
    {
        printf("v1: %p", &v1);
    }
    else
    {
        printf("v2: %p", &v2);
    }

    return 0;
}