#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <sodium.h>

#define FUC_END 7007

void bubble_sort(int list[], int n) {
	int i, j, temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] < list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void reverse_bubble_sort(int list[], int n) {
	int i, j, temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}	
		}
	}
}

void fill_rand_array(int list[], int max, int range) {

	int i, temp;

	for (i = 0; i < max; i++) {
		temp = randombytes_uniform(range) + 1;
		list[i] = temp;
	}
}

int dup_array_fill_rand(int list[], int max, int range) {

	int i = 0, j, k, temp;
	for (i = 0; i < max; i++) {
		for (k = 1; k <= max; k++) {
			if (list[k] == list[i]) {
				temp = list[i];
				do { list[i] = randombytes_uniform(range) + 1; } while (temp != list[k]);
			}
			for (j = max; j >= 0; j--) {
				if (list[j] == list[i]) {
					temp = list[i];
					do { list[i] = randombytes_uniform(range) + 1; } while (temp != list[j]);
				}
			}
		}
	}
	return FUC_END;
}

void print_result(int i, int max, int *parr[]) {
	printf("\t========== 중복 원소 교체 전 Bubble Sorting 결과 ==========");
	for (i = 0; i < max; i++) { if (i % 5 == 0) { printf("\n\t"); } printf("parr[%d] = %d ,", i, parr[i]); }
	printf("\n\t============================================================\n\n");
}

void print_sort_result(int i, int max, int* parr[]) {
	printf("\t========== 중복 원소 교체 후 Bubble Sorting 결과 ==========");
	for (i = 0; i < max; i++) { if (i % 5 == 0) { printf("\n\t"); } printf("parr[%d] = %d ,", i, parr[i]); }
	printf("\n\t============================================================\n\n");
}

int main(void) {

	int *parr;
	int i, max, range;
	int fuctionresult;
	char keyinput;

	printf("\t로또 숫자 추첨 프로그램...\n");
	printf("\t시작하려면 아무키나 누르세요 ...\n");
	
	keyinput = getch();

	printf("\t만들 배열의 원소 수 입력... >> : ");
	scanf("%d", &max);
	printf("\n");

	printf("\t배열 원소의 숫자 범위 입력... >> : ");
	scanf("%d", &range);
	printf("\n");

	parr = (int*)malloc(sizeof(int) * max);
	fill_rand_array(parr, max, range);

	bubble_sort(parr, max);
	print_result(0, max, parr);

	reverse_bubble_sort(parr, max);
	print_result(0, max, parr);
	
	do { fuctionresult = dup_array_fill_rand(parr, max, range); } while (fuctionresult != FUC_END);

	bubble_sort(parr, max);
	print_sort_result(0, max, parr);

	reverse_bubble_sort(parr, max);
	print_sort_result(0, max, parr);

	
	return 0;
}