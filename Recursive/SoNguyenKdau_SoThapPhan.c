    #include <stdint.h>
    #include <stdio.h>

    char* Pt;                   // global pointer

    void OutDec(uint32_t n) {
        if (n > 1) {
            OutDec(n / 10);    //Recursive 
        }
        *Pt = (n % 10)+ '0';
        Pt++;
    }

    void Dec2String(uint32_t n, char* p) {
        Pt = p;
        // Call recursive function to convert and output decimal
        OutDec(n);
        // Add null-termination
        *Pt = 0;
    }

    int main() {
        uint32_t number = 0;    // Replace with your desired number
        char buffer[20];        // Adjust the size based on your needs

        // Convert the number to a string
        Dec2String(number, buffer);

        // Now, 'buffer' contains the decimal representation of 'number'
        printf("Decimal representation: %s\n", buffer);

        return 0;
    }
