## Sorting Algorithm

## QuickSort
``` 
    void Quicksort(vector<int> &nums,int l,int r){
        while(l>=r-1) return;
        
        int first = l,last =r-1,key = nums[l];
        while(first<last){
            while(last > first && nums[last] >= key){
                last--;
            }
            nums[first] = nums[last];
            while(last>first && nums[first]<=key){
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        
        Quicksort(nums,l,first);
        Quicksort(nums,first+1,r);
    }
```
## MergeSort
```
    void MergeSort(vector<int> &nums,int l,int r,vector<int> &tmp){
        
        if(l>=r-1) return;
        int mid = (l+r)/2;
        MergeSort(nums,l,mid,tmp);
        MergeSort(nums,mid,r,tmp);
        int p1=l,p2=mid,cur=l;
        
        for(int i=l;i<r;i++){
            tmp[i] = nums[i];
        }
        
        while(p1<mid || p2<r ){
            
            if(p1<mid && p2<r){
                if(tmp[p1]<=tmp[p2]){
                    nums[cur++]= tmp[p1++];
                }
                else{
                    nums[cur++] = tmp[p2++];
                }
            }
            else if(p1<mid){
                nums[cur++] = tmp[p1++];
            }
            else if(p2<r){
                nums[cur++] = tmp[p2++];
            }
            
        }
        return;
    }
 ```
 
 ## Bubble sort
 ```
     void swap(int &a,int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    void bubbleSort(vector<int>&nums){
        int n = nums.size();
        bool flag;
        for(int i=1;i<n;i++){
            flag = false;
            for(int j=1;j<n-i+1;++j){
                if(nums[j-1] > nums[j]){
                    swap(nums[j-1],nums[j]);
                    flag = true;
                }
            }
            if(!flag) break;
        }
    }
 ```
 
 ## InsertionSort
 ```
      void swap(int &a,int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
     void InsertionSort(vector<int> &nums){
        for(int i=1;i<nums.size();++i){
            for(int j=i;j>0;--j){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
    }
 ```
 
 ## Select k-largest number 
 ```
 class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        int l =0,r=nums.size();
        int mid;
        while(l<=r){
            int mid = QuickSelect(nums,l,r);
            if(mid == n-k) return nums[mid];
            else if(mid < n-k) l=mid+1;
            else if(mid > n-k) r=mid;
        }
        return nums[l];
    }
private:
    int QuickSelect(vector<int> &nums,int l,int r){
        
        if(l>=r-1) return l;
        
        int first = l,last = r-1,key = nums[first];
        while(first < last){
            while(first<last && nums[last] >= key){
                last--;
            }
            while(first<last && nums[first] <=key){
                first++;
            }

            swap(nums[first],nums[last]);
        }
        swap(nums[l],nums[first]);
        return first;
    }
};
 ```
