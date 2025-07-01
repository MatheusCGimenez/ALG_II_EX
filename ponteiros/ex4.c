#include <stdio.h>

int main()
{

    float arr[3][3] = {
        {1.1, 1.2, 1.3},
        {2.1, 2.2, 2.3},
        {3.1, 3.2, 3.3}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%d][%d] - %p \n", i, j, &arr[i][j]);
        }
    }

    return 0;
}