// gcc -g main.c -o exe -lpthread
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

int sum1 = 0;
int sum2 = 0;
int sum3 = 0;

int numbers[9] = {1,5,6,  7,9,4, 10,66,44}; // 152

void *add(void *value)
{
	if (value == 1) {
		for (int i = 0; i < 3; i++) {
			sum1 += numbers[i];
		}
	} else if (value == 2) {
		for (int i = 3; i < 6; i++) {
			sum2 += numbers[i];
		}
	} else if (value == 3) {
		for (int i = 6; i < 9; i++) {
			sum3 += numbers[i];
		}
	}

	return NULL;
}

int main() 
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	int one = 1;
	int two = 2;
	int three = 3;

	pthread_create(&thread1, NULL, &add, (void*)one);
	pthread_create(&thread2, NULL, &add, (void*)two);
	pthread_create(&thread3, NULL, &add, (void*)three);

	int sum = 0;

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	sum = sum1 + sum2 + sum3;

	printf("SUM: %d\n", sum);

	assert(sum == 152);

	return 0;
}
