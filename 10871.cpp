#include <iostream>

int main() {

    int N,X;
    int input;
    scanf("%d %d",&N,&X);


    for(int i=1; i<=N; i++)
    {
        scanf(" %d ",&input);

        if(input<X)
        {
            printf("%d ",input);
        }

    }

    return 0;

}