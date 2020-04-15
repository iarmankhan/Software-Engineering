#include<stdio.h>

void main(){
    int n, i, j, f = 0;
    printf("Enter size: ");
    scanf("%d", &n);

    for(i = 0; i<n; i++){
        for(j = 0;j<=i;j++){
            f++;
            if(i%2 != 0){
                printf("%d", f);
            }else{
                printf("%d", (f+i-j*2));
            }
        }
        printf("\n\n");
    }
}