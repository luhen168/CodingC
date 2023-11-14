#include <stdint.h>
#include <stdio.h>

// Global pointer
char *Pt;

// Recursive helper function for Dec2String
void OutDec(uint32_t n) {
    int i = 0;
    do {
        Pt[i++] =  n % 10;
        n /= 10;
    } while (n != 0);
}

// Dec2String function
void Dec2String(uint32_t n, char *p) {
    Pt = p;
    OutDec(n);  // Save characters using the pointer Pt
    *Pt = 0;    // Add null termination
}

// Fix2String function
void Fix2String(uint32_t n, char *p) {
    char buffer[6];  // Buffer to store the fixed-point number
    uint32_t integerPart = n / 1000;
    uint32_t fractionalPart = n % 1000;

    // Check if the value is within the range 0.000 to 9.999
    if (n <= 9999) {
        sprintf(buffer, "%u.%03u ", integerPart, fractionalPart);
        strcpy(p, buffer);
    } else {
        strcpy(p, "*.***");
    }
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
        while (str[i] != '\0') {
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

int main(void) {
    char testDec[20];
    char testFix[20];

    Dec2String(9999, testDec);
    Fix2String(10000, testFix);

    // Test the functions
    // Output should be:
    // testDec: "123"
    // testFix: "0.123"
    printf("testDec: %s\n", testDec);
    printf("testFix: %s\n", testFix);
    return 0;
}
