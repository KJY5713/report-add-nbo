
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint32_t swap(uint32_t n) {
	uint32_t n1 = (n & 0xff000000) >> 24;
	uint32_t n2 = (n & 0x00ff0000) >> 8;
	uint32_t n3 = (n & 0x0000ff00) << 8;
	uint32_t n4 = (n & 0x000000ff) << 24;

	return n1 | n2 | n3 | n4;
}

int main(int argc, char** argv) {
	FILE* fp1 = fopen(argv[1], "rb");
	FILE* fp2 = fopen(argv[2], "rb");
	//FILE* fp1 = fopen("a.bin", "rb");
	//FILE* fp2 = fopen("c.bin", "rb");
	uint32_t num1, num2, result;
	
	fread(&num1, 4, 1, fp1);
	fread(&num2, 4, 1, fp2);
	//printf("%X", num1);
	//printf("%X", num2);
	//printf("\n");

	num1 = swap(num1);
	num2 = swap(num2);
	//printf("%X\n", num1);
	//printf("%X\n", num2);
	//printf("\n");

	result = num1 + num2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, result, result);
	//printf("%x", result);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

