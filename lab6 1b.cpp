#include <iostream>
#include "linkedList.cpp"
using namespace std;

//Function that outputs the node pointer corresponding to an index in a linked list, provided the list has that many elements
node *point(linkedList list, int index) {
	node *temp = list.head;
	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	return temp;
}

//Binary search function for a linked list. Can act only on a linked list that is already ordered ascendingly
int binarySearch(linkedList list, int key, int leftIndex, int rightIndex) {
	int mid = (leftIndex + rightIndex)/2;
	//When to stop the recursive function
	if (leftIndex > rightIndex) {
		//If the key has not been found after searching through the whole linked list...
		return -1;
	}
	else {
		if (point(list, mid)->data == key) {
			//If it has been found...
			return mid;
		}
		else if (point(list, mid)->data < key) {
			//Searching the upper half of the linked list
			binarySearch(list, key, mid + 1, rightIndex);
		}
		else {
			//Searching the upper half of the linked list
			binarySearch(list, key, leftIndex, mid - 1);
		}
	}
}

int main() {
	linkedList newList;
	newList.Insert(1);
	newList.Insert(4);
	newList.Insert(7);
	newList.Insert(10);
	newList.Insert(13);
	int key = 4;
	cout << binarySearch(newList, key, 1, 5);
	cout << endl;
	return 0;
}
