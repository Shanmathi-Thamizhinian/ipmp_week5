//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long low, long long mid, long long high){
        long long cnt = 0;
        long long left = low;
        long long right = mid+1;
        vector<long long> temp;
        while(left <= mid and right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
                cnt += (mid - left) + 1;
            }
            
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i<=high; i++){
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    
    long long mergesort(long long arr[], long long low, long long high){
        long long cnt = 0;
        if(low >= high) return cnt;
        
        long long mid = (low + high) / 2;
        cnt += mergesort(arr , low , mid);
        cnt += mergesort(arr, mid+1, high);
        cnt += merge(arr , low , mid , high);
        
        return cnt;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        long long low = 0;
        return mergesort(arr, low , N-1);
    
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
