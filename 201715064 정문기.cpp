#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int binary_search(int key, int list[], int low, int high) {
	int middle;
	while (low <= high) { 				// ���� Ű���� ���� ������
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle; 	// Ž�� ����
		else if (key < list[middle])
			high = middle - 1; 	// ������ �κи���Ʈ Ž��
		else
			low = middle + 1; 	// ���� �κи���Ʈ Ž��
	}
	//�Ʒ��� �ϼ��Ͻÿ�.
	//location is the index of the first element greater than or equal to key
	return low;

}

void prob_2() {
	int i, j, n = 20, m = 10;
	int arr[] = { 1, 5, 7, 9, 8, 2, 4, 6, 0, 1, 5, 13, 7, 9, 8, 12, 4, 6, 10, 3 };
	int small[11], size;

	small[0] = arr[0];

	size = 1;
	for (i = 1; i < n; i++) {
		if (size <= m)
			j = size - 1;
		else
			j = m - 1;
		//�Ʒ��� �ϼ��Ͻÿ�.
		while (j >= 0 && arr[i] < small[j]) {
			small[j + 1] = small[j];
			j--;
		}

		small[j + 1] = arr[i];
		size++;
	}


	printf("2-1��\n");
	for (i = 0; i < m; i++)
		printf("%d ", small[i]);
	printf("\n");

	int key, high, location;

	for (i = 1; i < n; i++) {
		key = arr[i];
		if (i > m)
			high = m - 1;
		else
			high = i - 1;
		location = binary_search(key, arr, 0, high);
		if (location < m) {
			//�Ʒ��� �ϼ��Ͻÿ�.
			for (j = i; j > location; j--) {
				arr[j] = arr[j - 1];
			}
			arr[location] = key;


		}
	}

		printf("2-2��\n");
		for (i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
	
}

void prob_3() {
	int n = 5;
	int i, j, k;

	char str[] = "01234";
	printf("\n3��\n");
	//�Ʒ��� �ϼ��Ͻÿ�.

	for (i = 0; i < n-2; i++) 
		for (j = i+1; j < n-1; j++) 
			for (k = j + 1; k < n; k++) {
				printf("%c%c%c", str[i], str[j], str[k]);


				printf(", ");
			}
		
	



	printf("\n");
}
void prob_6() {
	int i, n = 10;
	int max, min;
	int arr[] = { 1, 5, 3, 7, 9, 8, 2, 4, 6, 0 };

	if (arr[0] < arr[1]) {
		min = arr[0]; max = arr[1];
	}
	else {
		min = arr[1]; max = arr[0];
	}
	for (i = 2; i <= n - 1; i += 2) {// �Է� 2���� 3�� ��
		//�Ʒ��� �ϼ��Ͻÿ�.
		if (arr[i] < arr[i + 1]) {
			if (arr[i] < min) min = arr[i];
			if (arr[i + 1] > max) max = arr[i + 1];
		}
		else {
			if (arr[i + 1] < min) min = arr[i + 1];
			if (arr[i] > max) max = arr[i];
		}
	}



	printf("\n6��\n");
	printf("min:%d, max:%d\n", min, max);
}

int main(void)
{
	//2��
	prob_2();

	//3��
	prob_3();

	//6��
	prob_6();

	return 0;
}
/*���� ���
2-1��
0 1 1 2 3 4 4 5 5 6
2-2��
0 1 1 2 3 4 4 5 5 6

3��
012, 013, 014, 023, 024, 034, 123, 124, 134, 234,

6��
min:0, max:9
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*�������
* 2-1��
0 1 1 2 3 4 4 5 5 6
2-2��
0 1 1 2 3 4 4 5 5 6

3��
012, 013, 014, 023, 024, 034, 123, 124, 134, 234,

6��
min:0, max:9

C:\Users\USER\source\repos\���� 2\x64\Debug\���� 2.exe(���μ��� 6680��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
������� ������ �� �ܼ��� �ڵ����� �������� [����] -> [�ɼ�] -> [�����] > [������� �����Ǹ� �ڵ����� �ܼ� �ݱ�]�� ����ϵ��� �����մϴ�.
�� â�� �������� �ƹ� Ű�� ��������...


*/