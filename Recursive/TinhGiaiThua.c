#include <stdio.h>

int Giaithua(int a){
        if(a>0){
                return Giaithua(a-1)*a;
        }else{
                return 1;
        }
}

int main(){
        printf("Giai thua: %d \n",Giaithua(5));
        return 0;
}