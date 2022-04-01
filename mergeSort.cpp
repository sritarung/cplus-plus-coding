#include<iostream>
#include<iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;




void merge(int arr[], int p, int q, int r){
    int n1= q-p+1;
    int n2= r-q;

    int L[n1],R[n2];
    for(int i=0; i<n1; i++){
        L[i]=arr[p+i];
    }

    for(int j=0; j<n2;j++){
        R[j]=arr[q+1+j];
    }

    int i,j,k;
    i=0;
    j=0;
    k=p;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;  
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[],int l, int r){
    if(l<r){
        int m= l+(r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void printArrayList(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int rArray[size];
    for(int i=0; i<size; i++)
        rArray[i]= rand()%1001;

    // cout<<"This is the Array List"<<endl;
    // printArrayList(rArray,size);
    // cout<<endl;
    
    auto start= steady_clock::now();
  
    mergeSort(rArray,0,size-1);
    auto end= steady_clock::now();

    // cout<<"This is the sorted Array List"<<endl;
    // printArrayList(rArray,size);

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time_taken*=1e-9;
    cout<<"Execution time: "<<fixed<<setprecision(20)<<time_taken<<"seconds"<<endl;
   
    return 0;
}