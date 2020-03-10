// selection sort

#include<iostream.h>
#include<conio.h>
void main()
{
    clrscr();
    int size, values, arr[15], i, j, temp, index, small, count=0;

    cout<<"Enter the array Size : " <<endl;
    cin>>size;

    cout<<"Enter the values in the array : " <<endl;
    cin<<values;

    for(i=0; i<size; i++)
        cin>>arr[i];

    for(i=0; i<(size-1); i++)
    {
        small = arr[i];
        for(j=(i+1); j<size; j++)
        {
            if(small>arr[j])
            {
                small = arr[j];
                count++;
                index = j;
            }
        }
        if(count!=0)
        {
            temp = arr[i];
            arr[i] = small;
            arr[index] = temp;
        }
        count=0;
    }
    cout<<"The Array after sorting is :" <<endl;
    for(i=0; i<size; i++)
        cout<<arr[i]<<" ";
    getch();
}
