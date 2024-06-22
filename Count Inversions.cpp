Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Approach -> Using Two Loops
T(n) = O(N^2)
S(n) = O(n)

Approach -> Merge Sort

long long merge(long long arr[],long long low,long long mid,long long high){
        long long count=0;
        long long left=low;
        long long right=mid+1;
        long long temp[high-low+1];
        long long k=0;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp[k++]=arr[left++];
            }
              else{
               temp[k++] = arr[right++];
                count += (mid - left + 1);
            }
        }
        
           while(left <= mid){
             temp[k++] = arr[left++];
        }
        while(right <= high){
             temp[k++] = arr[right++];
        }
        
        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
        
        return count;
    }
    long long mergeSort(long long arr[],long long low, long long high){
        long long count=0;
        if (low >= high) return count;
        long long mid= low+(high-low)/2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        long long ans=mergeSort(arr,0,n-1);
        return ans;
    }

T(N) = O(nlog n)
 S(n) = O(n) + O(n) 
