#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>


void Bubble(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		bool if_replaced = false;
		for (int j = 0; j < size - i - 1; ++j) {
			if (mas[j + 1] < mas[j]) {
				int tmp = mas[j];
				mas[j] = mas[j+1];
				mas[j+1] = tmp;
				if_replaced = true;
			}
		}
		if (!if_replaced) {
			break;
		}
	}
}

void SearcSort(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		int k = i;
		for (int j = i + 1; j < size; ++j) {
			if (mas[j] < mas[k]) {
				k = j;
			}
		}
		int tmp = mas[k];
		mas[k] = mas[i];
		mas[i] = tmp;
	}
}

void Insertion(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		int tmp = mas[i];
		int j;
		for (j = i - 1; j >= 0 && mas[j] > tmp; --j) {
			mas[j + 1] = mas[j];
		}
		mas[j + 1] = tmp;
	}
}


int main() {
	clock_t start, end;
	double cpu_time1;
	double cpu_time2;
	double cpu_time3;
	int size;
	printf("Vvedite dliny mass\n");
	scanf_s("%d", &size);
	int* (mas) = (int*)malloc(size * sizeof(int));
	int* (copy) = (int*)malloc(size * sizeof(int));
	srand(time(NULL));


	for (int i = 0; i < size; ++i) {
		mas[i] = rand() % 1000;
	}

	int a;
	printf("\nvvedite reshim sorta\n");
	printf("1)sort bubble\n");
	printf("2)sort search\n");
	printf("3)sort insertion\n");

	do {
		scanf_s("%d", &a);
		if (a == 1) {
			memcpy(copy, mas, sizeof(int) * size);
			/*for (int i = 0; i < size; ++i) {
				printf("%d ", mas[i]);
			}*/
			printf("\n");
			start = clock();
			Bubble(copy, size);
			end = clock();
			cpu_time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			/*for (int i = 0; i < size; ++i) {
				printf("%d ", copy[i]);
			}*/
		}
		if (a == 2) {
			memcpy(copy, mas, sizeof(int)*size);
			/*for (int i = 0; i < size; ++i) {
				printf("%d ", mas[i]);
			}*/
			start = clock();
			SearcSort(copy, size);
			end = clock();
			cpu_time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			printf("\n");
			/*for (int i = 0; i < size; ++i) {
				printf("%d ", copy[i]);
			}*/

		}
		if (a == 3) {
			memcpy(copy, mas, sizeof(int) * size);
			for (int i = 0; i < size; ++i) {
				printf("%d ", mas[i]);
			}
			start = clock();
			Insertion(copy, size);
			end = clock();
			cpu_time3 = ((double)(end - start)) / CLOCKS_PER_SEC;
			printf("\n");
			for (int i = 0; i < size; ++i) {
				printf("%d ", copy[i]);
			}
		}
		//for (int i = 0; i < size; ++i) {
			//printf("%d", mas[i]);
		//}
	} while (a != 4);


	printf("Time of bubble sort %f seconds\n", cpu_time1);
	printf("Time of search sort %f seconds\n", cpu_time2);
	printf("Time of insertion sort %f seconds\n", cpu_time3);
	if (mas) {
		free(mas);
	}

	return 0;
}