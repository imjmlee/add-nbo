#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h> // for ntohl() function

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");

    if (!file1 || !file2) {
        printf("Error opening files.\n");
        return 1;
    }

    uint32_t num1, num2;
    if (fread(&num1, sizeof(uint32_t), 1, file1) != 1 ||
        fread(&num2, sizeof(uint32_t), 1, file2) != 1) {
        printf("Error reading files.\n");
        return 1;
    }

    fclose(file1);
    fclose(file2);

    num1 = ntohl(num1); // convert network byte order to host byte order
    num2 = ntohl(num2);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

