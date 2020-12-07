#include <stdio.h>
int main(void){
    int tmp[10] = {0,0,0,0,1};
    int i;
    for (i = 0; !tmp[1+i]; i++){
        printf("0\n");
    }
    printf("%d\n", i);
    return 0;
}