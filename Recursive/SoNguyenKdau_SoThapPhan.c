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

void OutDec(uint32_t n){
    if( n == 0 ){
        return ;
    }
    OutDec(n / 10) ;           //đệ quy     
    *Pt = (n % 10) + '0' ;
    Pt++ ;
}

void Dec2String(uint32_t n, char* p){
    Pt = p;
    OutDec(n);
    *Pt = 0;                //thêm kí tự rỗng ở cuối
}


void Fix2String(uint32_t n, char *str) {
    if (n > 9999) {
        str[0] = '*';
        str[1] = '.';
        str[2] = '*';
        str[3] = '*';
        str[4] = '*';
        str[5] = '\0';
    } else {
        uint32_t integerPart = n / 1000;
        uint32_t decimalPart = n % 1000;

        // Convert integer part to string
        Dec2String(integerPart, str);

        // Find the length of the integer part
        int i = 0;
        if (str[i] != '\0') {
            i++;
        }else{
            str[i] = '0';
            i++;
        }

        // Add decimal point
        str[i] = '.';
        i++;

        // Add leading zeros to decimal part if necessary
        if (decimalPart < 100) {
            str[i++] = '0';
        }
        if (decimalPart < 10) {
            str[i++] = '0';
        }

        // Convert decimal part to string
        Dec2String(decimalPart, str + i);
    }
}

int main(){
    uint32_t n;
    char p[100];

    printf("Nhap vao so nguyen k dau: \n");
    scanf("%d",&n);

    Dec2String(n, p);
    printf("Chuoi so thap phan la: %s\n", p); 

    Fix2String(n, p);
    printf("So co dinh la: %s\n", p);

    return 0;
}   