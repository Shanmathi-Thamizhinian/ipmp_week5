class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int low=0,i=0,high=n-1;
        while(i<n && i<=high){
            if(arr[i]==0){
                swap(arr[i],arr[low]);
                low++;
                i++;
            }
            else if(arr[i]==1){
                i++;
            }
            else{
                swap(arr[i],arr[high]);
                high--;
            }
                
        }

    }
};
