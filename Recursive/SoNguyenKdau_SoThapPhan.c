/*Viết 2 hàm Dec2String chuyển số nguyên không dấu thành chuỗi số thập phân
            hàm Fix2String chuyển chuỗi số kí tự từ Dec2String sang định dạng số cố định 
            Ví dụ 0   0.000
                  9   0.009
                 99   0.099
                999   0.999
               1000   *.***
*/
#include <stdint.h>
#include <stdio.h>

char *Pt;
void OutDec(uint32_t n);
void Dec2String(uint32_t n, char* p);
void Fix2String(uint32_t n, char* p);

void Dec2String(uint32_t n, char* p){
    Pt = p;
    OutDec(n);
    *Pt = 0;    //add null 
}
void OutDec(uint32_t n){
    if(n==0){
        return;
    }
    OutDec(n/10);
    *Pt = (n%10) + '0';
    Pt++;
}

void Fix2String(uint32_t n, char* p){
    
}
int main(){
    uint32_t n;
    char p[100];
    printf("Nhap vao so nguyen k dau: \n");
    scanf("%d",&n);
    Dec2String(n,p);
    printf("Chuoi so thap phan la: %s\n", p);
    return 0;
}   