//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void heapify(int arr[], int i, int n){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && arr[l]>arr[largest]) largest=l;
        if(r<n && arr[r]>arr[largest]) largest=r;
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr, largest, n);
        }
    }
    
    void heapSort(int arr[], int n){
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,i,n);
        }
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,0,i);
        }
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n=r+1;
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,i,n);
        }
        heapSort(arr,n);

        return arr[k-1];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
