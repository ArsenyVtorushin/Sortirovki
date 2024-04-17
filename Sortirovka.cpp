#include <iostream>
#include <cstdlib>

void FillArray(int arr[], int size);
void PrintArray(int arr[], int size);

void ShakerSort(int arr[], int size);


int FindSmallestPosition(int list[], int startPosition, int listLength);

void SelectionSort(int list[], int listLength);

void InsertionSort(int list[], int listLength);


int main()
{
	srand(time(NULL));

	int size = 15;

	int arr1[15]{};
	int arr2[15]{};
	int arr3[15]{};

	FillArray(arr1, 15);
	FillArray(arr2, 15);
	FillArray(arr3, 15);

	std::cout << "Array 1:\n";
	PrintArray(arr1, 15);
	std::cout << "\n\nArray 2:\n";
	PrintArray(arr2, 15);
	std::cout << "\n\nArray 3:\n";
	PrintArray(arr3, 15);

	std::cout << "\n\n---------------------SORTED:---------------------\n\n";

	std::cout << "Shaker Sort:\n";
	ShakerSort(arr1, 15);
	PrintArray(arr1, 15);

	std::cout << "\n\nInsertion Sort:\n";
	InsertionSort(arr2, 15);
	PrintArray(arr2, 15);

	std::cout << "\n\nSelection Sort:\n";
	SelectionSort(arr3, 15);
	PrintArray(arr3, 15);

	return 0;
}

void FillArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
	}
}
void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void ShakerSort(int arr[], int size)    // Шейкерная сортировка
{
	bool sort_or_not = true;
	int right = size - 1;
	int left = 1;
	do {
		bool sort_or_not = true;
		for (int i = left; i <= right; i++) 
		{
			if (arr[i - 1] > arr[i]) 
			{
				std::swap(arr[i - 1], arr[i]);
				sort_or_not = false;
			}
		}
		right--;
		for (int i = right; i >= left; i--) 
		{
			if (arr[i] < arr[i - 1]) 
			{
				std::swap(arr[i], arr[i - 1]);
				sort_or_not = false;
			}
		}
		left++;
	} while (sort_or_not == false);
}

int FindSmallestPosition(int list[], int startPosition, int listLength)
{
	int smallestPosition = startPosition;

	for (int i = startPosition; i < listLength; i++)
	{
		if (list[i] < list[smallestPosition])
			smallestPosition = i;
	}
	return smallestPosition;
}
void SelectionSort(int list[], int listLength) // Сортировка выбором
{
	for (int i = 0; i < listLength; i++)
	{
		int smallestPosition = FindSmallestPosition(list, i, listLength);
		std::swap(list[i], list[smallestPosition]);
	}
	return;
}

void InsertionSort(int list[], int listLength) // Сортировка вставками
{
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j] > list[j + 1])
		{
			std::swap(list[j], list[j + 1]);
			j--;
		}
	}
}