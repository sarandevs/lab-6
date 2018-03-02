#include <iostream>
using namespace std;

//Note: This function doesn't run in all compilers because it shows the error 'Control may reach end of non-void function'. I haven't been able to completely remove the error.

/*Binary search function that takes in array, array size and element to be searched and returns index where it is found.
This function takes in an array that is already sorted in ascending order.*/
int binarySearch(int arr[], int key, int leftIndex, int rightIndex) {
	int mid = (leftIndex + rightIndex)/2;
    //When to stop the recursive function
	if (leftIndex > rightIndex) {
        //If the key has not been found after searching through the whole array...
		return -1;
	}
	else {
		if (arr[mid] == key) {
            //If it has been found...
			return mid;
		}
		else if (arr[mid] < key) {
			//Searching the upper half of the array
			binarySearch(arr, key, mid + 1, rightIndex);
		}
		else {
			//Searching the upper half of the array
			binarySearch(arr, key, leftIndex, mid - 1);
		}
	}
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int key = 3;
	cout << binarySearch(arr, key, 0, 8);
	cout << endl;
	return 0;
}

