#include <stdio.h>
#define MAX 100

int checkString(char *srt1, char *str2)
{
    
}

int main()
{
    char str1[MAX], str2[MAX];

    printf("Digite a primeira string: \n");
    fgets(str1, sizeof(str1), stdin);
    printf("Digite a segunda string: \n");
    fgets(str2, sizeof(str2), stdin);

    int result = checkString(&str1, &str2);

    return 0;
}