#include <stdio.h>

int main(){

    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        printf("digite o valor da posicao [%i] \n", i);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 5; i++){
        if(arr[i] % 2 == 0){
            printf("arr[%d] - (%d) eh par e seu endereco eh %p \n", i, arr[i], &arr[i]);
        }
    }

    return 0;
}