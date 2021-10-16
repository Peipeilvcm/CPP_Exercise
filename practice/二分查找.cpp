#include<stdio.h>

using namespace std;

/*
���ҵ�һ��Ŀ��ֵ���±� 
*/

template<typename T>
int binarySearch(T arr[], int n, T target)
{
	if( n == 0)
	{
		return -1;
	}
	
	int l = 0, r = n - 1;
	
	while(l + 1 < r)
	{
		int mid = l + (r - l)/2;
		if(arr[mid] == target)
		{
			//l = mid; �����һ��Ŀ��ֵ���±� 
			r = mid;	//�ҵ�һ�� 
		}
		else if(arr[mid] < target)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	if(arr[l] == target)
	{
		return l;
	}
	if(arr[r] == target)
	{
		return r;
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 7, 8,9,10,12};
	
	printf("%d\n",binarySearch(a, 15, 5));
	return 0;
} 

int binarySearch(const vector<int>& arr, int key){
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while(left<=right){
		mid = left + (right - left) / 2;
		if(key < arr[mid]){
			right = mid - 1;
		}else if(key > arr[mid]){
			left = mid + 1;
		}else{
			return mid;
		}
	}

	return -1;
}

// �������һ��С��key��Ԫ��
int binarySearch_1(const vector<int>& arr, int key){
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while(left<=right){
		mid = left + (right - left) / 2;
		if(key <= arr[mid]){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return right;
}

// ���ҵ�һ�����ڵ���key  !!!!!!!!!!!!!!!!!!!!!!!!!! ���������������������������
int binarySearch_2(const vector<int>& arr, int key){
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while(left<=right){
		mid = left + (right - left) / 2;
		if(key <= arr[mid]){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

// ���һ��С�ڵ���key��Ԫ��
int binarySearch_3(const vector<int>& arr, int key){
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while(left<=right){
		mid = left + (right - left) / 2;
		if(key < arr[mid]){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return right;
}

// ���ҵ�һ������key
int binarySearch_4(const vector<int>& arr, int key){
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while(left<=right){
		mid = left + (right - left) / 2;
		if(key < arr[mid]){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

// ���ҵ�һ������key��
int binarySearch_5(const vector<int>& arr, int key){
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while(left<=right){
		mid = left + (right - left) / 2;
		if(key <= arr[mid]){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	// right �ǵ�һ�����ڵ���key��
	if(left < arr.size() && arr[left] == key){
		return left;
	}

	return -1;
}

// �������һ������key
int binarySearch_6(const vector<int>& arr, int key){
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while(left<=right){
		mid = left + (right - left) / 2;
		if(key < arr[mid]){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	// right �����һ��С�ڵ���key��
	if(right >= 0 && arr[right] == key){
		return right;
	}
	return -1;
}