#include <stdio.h>

int sum(int a){
    if(a>0){
        return sum(a-1)+a;
    }else{
        return 0;           //Neu de return 1 thi thua 
    }
}
int main(){
    printf("Tong cac so tu 1 den 100 la: %d \n", sum(5));
}