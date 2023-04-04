// Given an array, find the majority element if it exists
//1.brute force - TC=O(n^2) nested for loop
// 2. sort array and count max TC = O(nlogn)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
   /*/ // TC - O(nlogn)
    sort(arr.begin(),arr.end());
    int mid = arr[n/2];
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==mid)
            count+=1;
    }
    if(count>n/2)
        cout<<"Majority element"<<count<<mid;
    */

   // Moore Voting Algorithm - TC = O(n)
   int majority_ele=arr[0];
   int count=1;
   for(int i=1;i<n;i++)
   {
        if(arr[i]== majority_ele)
        {
            count+=1;
        }
        else
        {
            count-=1;
        }
        if(count==0)
        {
            majority_ele=arr[i];
            count=1;
        }

   }
   count=0;
   for(int i=0;i<n;i++)
   {
        if(arr[i]==majority_ele)
            count+=1;
   }
   if (count>n/2)
    cout<<"Majority element is: "<<majority_ele<<endl;
   else
    cout<<"No majority element"<<endl;
    return 0;
}