// Consider it is raining. Given height of n buildings, find out how many units of water can be stored in between the buildings. Consider width of each building to be 1 unit.

#include <iostream>
using namespace std;

int main()
{
    // inputs
    int n_building;
    cin>>n_building;
    int building_height[n_building];
    for(int i=0;i<n_building;i++)
    {
        cin>>building_height[i];
    }

    cout<<endl;
    // logic
    // we will need max height of building on left and right. and then choose minimum from the two i.e min(lmax,rmax)
    // water stored = min(lmax,rmax)-height_of_building
    // brute force - O(n^2)
    /*int water_stored=0;
    int lmax=building_height[0];
    int rmax = building_height[n_building-1];
    for(int i=1;i<n_building-1;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(building_height[j]>lmax)
                lmax=building_height[j];
        }
        for(int j=i;j<n_building;j++)
        {
            if(building_height[j]>rmax)
                rmax=building_height[j];
        }
        water_stored+= min(lmax,rmax)-building_height[i];
    }*/

    // optimise
    // store lmax and rmax for each building using array
    /*int lmax[n_building];
    lmax[0]=building_height[0];
    int rmax[n_building];
    rmax[n_building-1]=building_height[n_building-1];
    int water_stored=0;
    for(int i=1;i<n_building;i++)
    {
        if(building_height[i]>lmax[i-1])
            lmax[i]=building_height[i];
        else
            lmax[i]=lmax[i-1];
    }
    
    for(int i=n_building-2;i>=0;i--)
    {
        if(building_height[i]>rmax[i+1])
            rmax[i]=building_height[i];
        else
            rmax[i]=rmax[i+1];
    }
    
    for(int i=1;i<n_building-1;i++)
    {
        water_stored += min(lmax[i],rmax[i]) - building_height[i];
    }
    cout<<water_stored<<endl;
    */
    // faster method
    int lmax[n_building];
    lmax[0]=building_height[0];
    //int rmax[n_building];
    //rmax[n_building-1]=building_height[n_building-1];
    int water_stored=0;
    for(int i=1;i<n_building;i++)
    {
        lmax[i]=max(building_height[i],lmax[i-1]);
    }
    int rmax=0;
    for(int i=n_building-1;i>=0;i--)
    {
       int t = min(lmax[i],rmax);
       rmax=max(rmax,building_height[i]);
       water_stored+=max(t - building_height[i],0);
    }
    cout<<water_stored<<endl;

    return 0;
}