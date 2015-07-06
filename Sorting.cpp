#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int* a, unsigned int size){
	cout << "[";
	for(int i =0; i < size; i++){
		cout << a[i];
		if (i == size-1){
			cout << "]" << endl;
		}else{
			cout << ", ";
		}
	}
}

bool checkSort(int* a, unsigned int size){
	int max = a[0];
	for(int i = 1; i < size; i++){
		if(a[i]<max){
			return false;
		}else if(a[i]>max){
			max = a[i];
		}
	}
	return true;
}

void mergeSort(int* a, unsigned int start , unsigned int end){
	if(end-start <= 1){
		return;
	}
	unsigned int mid = (end + start)/2;
	int* left = new int[mid-start];
	int* right = new int[end-mid];
	for (int i = start; i < end; i++){
		if(i < mid){
			left[i-start] = a[i];
		}else{
			right[i-mid] = a[i];
		}
	}
	mergeSort(left,0,mid-start);
	mergeSort(right,0,end-mid);
	unsigned int ri = 0;
	unsigned int li = 0;
	unsigned int i = 0;
	while(li < (mid-start) && ri < (end-mid)){
		if(left[li] < right[ri]){
			a[i] = left[li];
			li++;
		}else{
			a[i] = right[ri];
			ri++;
		}
		i++;
	}
	while(li < (mid-start)){
		a[i] = left[li];
		i++; li++;
	}
	while(ri < (end-mid)){
		a[i] = right[ri];
		i++; ri++;
	}

	delete[] left;
	delete[] right;
}

void quickSort(int* a, unsigned int lo , unsigned int hi){
	if(lo >= hi){
		return;
	}
	unsigned int pivotIndex = (hi+lo-1)/2;
	int pivotValue = a[pivotIndex];
	int temp;
	a[pivotIndex] = a[hi-1];
	a[hi-1] = pivotValue;
	unsigned int storeIndex = lo;
	for (int i = lo; i < hi-1; i++){
		if(a[i]<pivotValue){
			temp = a[i];
			a[i] = a[storeIndex];
			a[storeIndex] = temp;
			storeIndex++;
		}
	}
	a[hi-1] = a[storeIndex];
	a[storeIndex] = pivotValue;
	quickSort(a,lo,storeIndex);
	quickSort(a,storeIndex+1,hi);
}

void insertionSort(int* a, unsigned int size){
	int cur;
	int j;
	for(int i = 1; i < size; i++){
		cur = a[i];
		j = i-1;
		while (j >= 0 && a[j] > cur){
			a[j+1] = a[j];
			j -= 1;
		}
		a[j+1] = cur;
	}
}

void bubbleSort(int* a, unsigned int size){
	bool sorted = false;
	int maxidx = size-1;
	int temp;
	while(!sorted){
		sorted = true;
		for(int i = 0; i < maxidx; i++){
			if(a[i]>a[i+1]){
				sorted = false;

				temp = a[i+1];
				a[i+1] = a[i];
				a[i] = temp;
			}
		}
		maxidx--;
	}
}

int main(){
	unsigned int size = 1000;
	int* a = new int[size];
	srand(time(0));
	for(int i=0; i < size; i++){
		a[i] = rand() % 1000;
	}
	if(checkSort(a,size)){
		cout << "Sorted" << endl;
	}else{
		cout << "Not Sorted" << endl;
	}
	// printArray(a,size);
	//insertionSort(a,size);
	//bubbleSort(a,size);
	//mergeSort(a,0,size);
	quickSort(a,0,size);
	if(checkSort(a,size)){
		cout << "Sorted" << endl;
	}else{
		cout << "Not Sorted" << endl;
	}
	// printArray(a,size);
	delete[] a;
	return 0;
}