// Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.
//                             4 4 4 4 4 4 4  
//                             4 3 3 3 3 3 4   
//                             4 3 2 2 2 3 4   
//                             4 3 2 1 2 3 4   
//                             4 3 2 2 2 3 4   
//                             4 3 3 3 3 3 4   
//                             4 4 4 4 4 4 4  
//******************************************************************************************************** 
#include <stdio.h>

int main() 
{
    int n;  // Số hàng và cột của mẫu số (có thể điều chỉnh theo yêu cầu)
    scanf("%d",&n);
    
    // Duyệt qua từng hàng
    for (int row_index = 0; row_index < 2*n-1; row_index++) 
    {
        // Duyệt qua từng cột
        for (int column_index = 0; column_index < 2*n-1; column_index++) 
        {
            // Tìm khoảng cách tới biên của ma trận
            int row_space = row_index;
            if (row_space >= n)
            {
              row_space = 2*n-2-row_space;
            } 
            int column_space = column_index;
            if (column_space >= n)
            {
              column_space = 2*n-2-column_space;
            } 
            // Tìm giá trị tại vị trí này
            int value = n - (row_space < column_space ? row_space : column_space);
            
            // In giá trị với một khoảng trắng
            printf("%d ", value);
        }
        // Xuống dòng sau khi hoàn thành mỗi hàng
        printf("\n");
    }
    
    return 0;
}
