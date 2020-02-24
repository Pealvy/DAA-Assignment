#include <iostream> 
#include <time.h>
#include <chrono>

using namespace std; 
using namespace std::chrono;

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1= m- l + 1; 
	int n2 = r - m; 

	//Create temporary arrays
	int L[n1], R[n2]; 

	// copy data to temp arrays L[] and R[] 
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m+ 1 + j]; 

	// Merge the temp arrays into list
	
	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	// copy the remaining elements of L[]
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	// Copy the remaining elements of R[]
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 


void mergeSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int m= low+(high-1)/2; 

		// Sort the first and second halves 
		mergeSort(arr, low, m); 
		mergeSort(arr, mid + 1, high); 

		merge(arr, low, m, high); 
	} 
} 

void displayArray(int A[], int size) 
{ 
	
	for (int i=0; i < size; i++) 
		cout<< A[i]<<"  "; 
	cout<<"\n";
} 

int main() 
{ 
    int n;
    cout<<"Enter size of array to be sorted\n;
    cin>>n;
    
    int arrToBeSorted[n];
    
    srand(time(0));
    cout<<"Random array of integers generated! (1-100)"<<endl;
    for (int i=0; i < n; i++){
        arrToBeSorted[i] = (rand() % 100) + 1;
    }

	cout<<" Your array is : \n"; 
	displayArray(arrToBeSorted, n); 
	
    auto init = high_resolution_clock::now(); 

	mergeSort(arrToBeSorted, 0, n - 1); 
	
    auto end = high_resolution_clock::now();

	cout<<"\nSorted array is \n"; 
	displayArray(arrToBeSorted, n);
	
	// now display the execution time
	auto duration = duration_cast<microseconds>(end - init); 
    cout << "Time taken by function (Execution Time): "
         << duration.count() << " microseconds" << endl;
	
	return 0; 
} 