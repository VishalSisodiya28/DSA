#include<bits/stdc++.h>
using namespace std;

//brute force
/*

class Solution{
    public:
        int n=nums1.size(),m=nums2.size();
        int arr[m+n],i=0,j=0,iter=0;

        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                arr[iter++]=nums1[i++];
            }
            else{
                arr[iter++]=nums2[j++];
            }
        }
        while(i<n){
            arr[iter++]=nums1[i++];
        }
        while(j<m){
            arr[iter++]=nums2[j++];
        }

        if((n+m)%2==0){
            return (arr[(n+m)/2]+arr[(n+m)/2-1])/2.0;
        }

        return (float)arr[(n+m)/2]; 
       
};

*/

//Better Approach 
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {    
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, k = 0;
        int idx1, idx2, e1 = 0, e2 = 0;
        int v = m + n;

        if (v % 2 == 0) {
            idx1 = v / 2 - 1;
            idx2 = v / 2; 
        } else {
            idx1 = idx2 = v / 2;
        }

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                if (idx1 == k) e1 = nums1[i];
                if (idx2 == k) e2 = nums1[i];
                i++;
            } else {
                if (idx1 == k) e1 = nums2[j];
                if (idx2 == k) e2 = nums2[j];
                j++;
            }
            k++;
        }

        while (i < n) {
            if (idx1 == k) e1 = nums1[i];
            if (idx2 == k) e2 = nums1[i];
            i++;
            k++;
        }

        while (j < m) {
            if (idx1 == k) e1 = nums2[j];
            if (idx2 == k) e2 = nums2[j];
            j++;
            k++;
        }

        if (v % 2 == 0) {
            return (e1 + e2) / 2.0;
        }

        return (double) e2;
    }
};

*/ 
class Solution {
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        
        if(n1>n2) return findMedianSortedArrays(arr2, arr1); //because we will always do for small array to optimize time complexity
        
        int low=0;
        int high=arr1.size();    //means size of small array - because we can only take this much elements from array1

        int left = (n1+n2+1)/2;  //this much array left half contain the element (for both case - Odd/Even it works)   

        while(low<=high){
            int mid1 = low +(high-low)/2; // from mid1 next part will be started
            int mid2 = left - mid1;

            int l1 = (mid1-1 >= 0) ? arr1[mid1-1] : INT_MIN;
            int l2 = (mid2-1 >= 0) ? arr2[mid2-1] : INT_MIN;
            int r1 = (mid1 < n1)   ? arr1[mid1]   : INT_MAX;
            int r2 = (mid2 < n2)   ? arr2[mid2]   : INT_MAX;

            if(l1 <= r2 && l2 <= r1){ //then only it is valid or sorted combination
                if((n1+n2)%2==1){ //in case of odd number of elements
                    return max(l1,l2);
                }else{   //even number of elements
                    return ((double)(max(l1,l2) + min(r1,r2)))/2.0;
                }
            }else if(l1 > r2){   //move to left
                high = mid1 - 1;
            }else{
                low = mid1 + 1;
            }
        }
        return 0;
    }
};

int main(){    
    Solution obj;

    vector<int> nums1 = {1,2,3,4,5}, nums2 = {6,7,8,9};

    cout<<obj.findMedianSortedArrays(nums1, nums2);
    
    return 0;

}

