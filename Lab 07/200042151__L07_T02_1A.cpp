#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void merge(vector<int>& nums, int l, int m, int h, int& cnt){
        int j = m+1;
        for(int i=l; i<=m; i++){
            while(j<=h && nums[i] > 2*(long long)nums[j]){//reverse condition
                j++;
            }
            cnt += j-(m+1);
        }
        int size = h-l+1;
        vector<int> temp(size, 0);//temporary array for merging
        int left = l, right = m+1, k=0;
        while(left<=m && right<=h){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=m){
            temp[k++] = nums[left++]; 
        }
        while(right<=h){
            temp[k++] = nums[right++]; 
        }
        int n=0;
        for(int i=l; i<=h; i++){//copying the merged array
            nums[i] = temp[n++];
        }
    }

    void mergeSort(vector<int>& nums, int l, int h, int& cnt){
        if(l >= h){
            return;//base condition
        }
        int m = (l + h) >> 1;
        mergeSort(nums, l, m, cnt); //merge sorting the left portion
        mergeSort(nums, m+1, h, cnt);//merge sorting the right portion
        merge(nums, l, m, h, cnt);
    }
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        mergeSort(nums, 0, nums.size()-1, cnt);
        return cnt;
    }
};