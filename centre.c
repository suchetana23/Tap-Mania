#include <stdio.h>

int main(){
    int i,j,k;
    int rows=5;

    for (i=0;i<rows;i++){
        for (j=0;j<2*(rows-i)-1;j++){
            printf(" ");
        }
        for (k=0;k<2*i+1;k++){
            printf("%c ",'A' + k);
        }
        printf("\n");
    }
}