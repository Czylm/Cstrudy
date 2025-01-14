#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

class Solution {
public:

    int quicksort(vector<int> &nums,int l,int r){
        int key = nums[l];
        while(l < r){
            while(l < r && key < nums[r]) r --;
            nums[l] = nums[r];
            while(l < r && key > nums[r]) l ++;
            nums[r] = nums[l];
        }
        nums[r] = key;
        return r;
    }
    int select(vector<int>& nums,int l,int r,int k){
        if(l == r){
            return nums[l];
        }
        int pos = quicksort(nums,l,r);
        int index = r - pos + 1;
        if(index == pos){
            return nums[pos];
        }
        else if(index < k){
            return select(nums,l,pos-1,k-index);
        }
        else{
            return select(nums,pos+1,r,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0,r = nums.size() - 1;
        return select(nums,l,r,k);
        // 大根堆 O(nlogk)
        // priority_queue<int,vector<int>,less<int>> q;
        // for(auto x : nums){
        //     q.push(x);
        // }
        // int cnt = 0;
        // while(!q.empty()){
        //     int t = q.top();
        //     q.pop();
        //     cnt ++;
        //     if(cnt == k){
        //         cout << t << endl;
        //         return t;
        //     }
        // }
        // return 0;
    }
};

int main()
{
    Solution s;
 
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    s.findKthLargest(a,n);

    system("pause");
    return 0;
}