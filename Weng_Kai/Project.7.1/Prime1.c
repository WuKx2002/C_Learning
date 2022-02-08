#include<stdio.h>

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes);

int main(void)
{
	int prime[100] = { 2 };
	int count = 1;
	int i = 3;

	while (count < 100) {
		if (isPrime(i, prime, count)) {
			prime[count++] = i;
		}
		i++;
	}
	for (i = 0;i < 100;i++) {
		printf("%d",prime[i]);
			if ((i + 1) % 5) {
				printf("\t");
		}else{ printf("\n"); }
	}
	return 0;
}

int isPrime(int x,int knownPrimes[],int numberOfKnownPrimes)
{
	int ret = 1;
	int i;
	for (i = 0;i < numberOfKnownPrimes;i++) {
		if (x % knownPrimes[i] == 0) {
			ret = 0;
			break;
		}
	}
	return ret;
}//C ���԰��κη���ͷǿյ�ֵ�ٶ�Ϊ true������� null �ٶ�Ϊ false��
