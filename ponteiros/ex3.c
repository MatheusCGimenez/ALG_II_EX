#include <stdio.h>

int main()
{

    float arr[10] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};

    for (int i = 0; i < 10; i++)
    {
        printf("[%d] - %p \n", i, &arr[i]);
    }

    return 0;
}