#include <stdio.h>
//Xem lai phan truyen mang vao ham void , cach truyen con tro 

void input_Sort(int a[],int n){
    for(int i = 0 ; i < n; i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

void bubble_Sort(int a[],int n){
    int temp;
    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0 ; j< n - 1 - i; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display_Sort(int a[],int n){
    printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++){
        printf("%d, ",a[i]);
    }
}

int main(){
    int a[100];
    int n;
    printf("Nhap so phan tu mang: ");
    scanf("%d",&n);

    input_Sort(a,n);
    bubble_Sort(a,n);
    display_Sort(a,n);

    return 0;
}