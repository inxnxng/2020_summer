#include"10.8.h"

void MakeTree(int freq[], int n){
	MinHeap heap;
	for (int i = 0; i < n; i++) {
		heap.insert(freq[i]);
	}
	for (int i = 0; i < n; i++) {
		heapNode e1 = heap.remove();
		heapNode e2 = heap.remove();
		heap.insert(e1.getKey() + e2.getKey());
		cout << "( " << e1.getKey() << " + " << e2.getKey() << " )" << endl;
	}
}


int main() {
	int frq[] = { 15,12,8,6,4 };
	MakeTree(frq, 5);
}