## Sorting Algorithm

## QuickSort
'''   
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
'''
