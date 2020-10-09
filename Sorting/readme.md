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
