#include <iostream>
#include <time.h>
 
using namespace std;
 
 void linearSearch(int a[], int n, int key){
     int isFound = 0, i;
     
     	for(i=0; i<n; i++){
		    if(a[i]==key){
			    isFound=1;
			    break;
		    }
	    }
	
	    if(isFound)
		    cout<<"\nElement is found at position "<<i;
	    else
		    cout<<"\nElement not found";
		
 }
 
 void minAndMax(int a[], int n){
    
    a[n];
    int max = a[0];
    int min = a[0];

  for (int i = 0; i < n; i++){
      if (a[i] > max)
        {
          max = a[i];
        }
      else if (a[i] < min)
        {
          min = a[i];
        }
    }
  cout <<"\nThe maximum element is :"<<max << endl;
  cout <<"\nThe minimum element is :"<<min << endl;
 }
 
int main()
{
    srand(time(0));
	int n,x,i;
	
	cout<<"Enter size of Array (The elements would be generated randomly, 1-100):\t";
	cin>>n;
	
	int a[n];
	
	for(i=0; i<n; i++)
		a[i] = (rand() % 100) + 1;
		
	for(i=0; i<n; i++)
	    cout<<a[i]<<" ";
	
	cout<<"\nEnter element to search:\t";
	cin>>x;
	
    linearSearch(a, n, x);
    minAndMax(a, n);
    
	return 0;
}