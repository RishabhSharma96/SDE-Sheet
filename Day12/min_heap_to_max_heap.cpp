class Solution{
public:

    void heapify(vector<int> & arr, int n, int index){
        
            int largest = index ;
            int left = 2*index+1;
            int right = 2*index+2;
            
            if(left < n && arr[largest] < arr[left]){
                largest = left;
            }
            if(right < n && arr[largest] < arr[right]){
                largest = right;
            }
            
            if(index != largest){
                swap(arr[index] , arr[largest]);
                heapify(arr,n,largest);
            }
        
    }

    void convertMinToMaxHeap(vector<int> &arr, int n){
        
        for(int i=n/2; i>=0 ; i--){
            heapify(arr, n , i);
        }
        
    }
    
};