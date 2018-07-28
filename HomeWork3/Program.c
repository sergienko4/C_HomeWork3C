#include<stdio.h>
#include<stdlib.h>

void init(void ***arr, int row, int colom);
void print(int *arr, int rows, int colloms);
void swapRows(int *arr, int rowsNumber);
void swapColloms(int **arr, int collomNumber);
void freeArr(int ** arr, int rows);

void main() {
	int **arr;
	int rows, colloms, option = 1;



	do {
		printf("Enter the number of rows\n");
		scanf_s("%d", &rows);
	} while (!rows > 0);


	do {
		printf("Enter the number of colloms\n");
		scanf_s("%d", &colloms);
	} while (!colloms > 0 && colloms);


	// arr of pointers
	init(&arr, rows, colloms);
	print(arr, rows, colloms);

	while (option != 0)
	{
		printf("\n Menu option: \n To swapColloms: 1 \n To rows: 2, To exit: 0\n");

		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			swapColloms(arr, colloms);
			print(arr, rows, colloms);
			break;

		case 2:
			swapRows(arr, rows);
			print(arr, rows, colloms);
			break;

		default:
			option = 0;

			break;
		}
	}
}


void freeArr(int ** arr, int rows) {
	int i = 0;
	for (i; i < rows; i++)
	{
		free(*arr[i]);
	}
	free(arr);
}
void init(int ***arr, int row, int colom) {
	int i, j;

	// create array of pointers
	*arr = (int**)calloc(row, sizeof(int *));

	// create matrics
	for (i = 0; i < colom; i++)
	{
		*(*arr + i) = (int*)calloc(row, sizeof(int));
	}

	// set value
	for (i = 0; i < row; i++) {
		for (j = 0; j < row; j++) {
			*(*(*arr + i) + j) = (i + 1)*(j + 1);
		}
	}
}
void swapRows(int *arr, int rowsNumber) {
	int *temp;
	int source, target;

	do {
		printf("Enter the number of source\n");
		scanf_s("%d", &source);

		printf("Enter the number of target\n ");
		scanf_s("%d", &target);

	} while (!(source > 0 && target > 0 && source < rowsNumber && target < rowsNumber));

	source--;
	target--;
	temp = arr[source];
	arr[source] = arr[target];
	arr[target] = temp;


}
void swapColloms(int **arr, int collomNumber)
{
	int temp, i, source, target;

	do {
		printf("Enter the number of source\n");
		scanf_s("%d", &source);

		printf("Enter the number of target\n ");
		scanf_s("%d", &target);

	} while (!(source > 0 && target > 0 && source < collomNumber && target < collomNumber));

	source--;
	target--;


	for (i = 0; i < collomNumber; i++)
	{
		temp = arr[i][source];
		arr[i][source] = arr[i][target];
		arr[i][target] = temp;

	}


}
void print(int **array, int rows, int colloms) {
	int i = 0, j = 0;

	printf("Matrix: \n");
	for (i; i < rows; i++)
	{
		for (j = 0; j < colloms; j++)
		{
			printf("%3d,", array[i][j]);
		}
		printf("\n");
	}
}