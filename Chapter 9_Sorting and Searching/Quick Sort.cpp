#include<iostream>
#include<vector>
using namespace std;

class solution_quick_sort{

public:
	void quickSort(vector<int> &arr, int low, int high){
		if(low > high) return;
		int pivot = arr[low];

		int i = low; 
		int j = high;
		while(i != j){
			while(arr[j] >= pivot && i < j)
				j--;
			while(arr[i] <= pivot && i < j)
				i++;

			// swap
			if(i < j)
				swap(arr, i, j);
		}
		arr[low] = arr[i];
		arr[i] = pivot;

		quickSort(arr, low, i-1);
		quickSort(arr, i+1, high);
	}

	void swap(vector<int> &arr, int i, int j){
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};


int main(){
	solution_quick_sort *obj = new solution_quick_sort();
	int a[] = {3,1,5,6,9,10,8,4,2,7};
	vector<int> arr;
	arr.assign(a, a+10);
	obj->quickSort(arr, 0, arr.size()-1);
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}