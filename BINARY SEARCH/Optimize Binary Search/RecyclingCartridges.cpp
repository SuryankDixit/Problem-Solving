/*
You have four input parameters:

Cartridges, Dollars, recycleReward, perksCost.

One has two options:
1. Recycle one cartridge and get recycleReward amount of dollars
2. Combine one cartridge and perksCost amount to get a perk item.

we need to maximise the perk items one can buy.

ex: 10, 10, 2, 2

Initially there are 10 cartridges, 10 dollars with the person.
If the persone recycles 3 cartridges he has 7 cartridges and 16 dollars (10 initial + 3*2(recycleReward)).

we can combine 7 cartridges and 14 dollars to buy 7 perk items(as each item costs 1 cartridge and 2 dollars(perksCost)).

1<= cartridges, dollars, recycleReward, perksCost <= 10^9;
*/
#include<bits/stdc++.h>
using namespace std;

int cartridges, dollars, recycleReward, perksCost;

bool isPossible(int cartridges, int dollars, int recycleRewards, int perksCost, int noOdPerksToBuy)
{
	int extra_dollars_needed = noOdPerksToBuy*perksCost-dollars;
	if(extra_dollars_needed > cartridges*recycleReward)	
        return false;
	if(extra_dollars_needed<0)  
        extra_dollars_needed=0;

	cartridges-=(extra_dollars_needed/recycleReward)+(extra_dollars_needed%recycleReward!=0);
	
	return (cartridges>=noOdPerksToBuy)	? true : false;
}

int32_t main()
{
    cin>>cartridges >> dollars >> recycleReward >> perksCost;
    
    // it is possible to buy n perks ? 
    // for lower value of n it might be possible but for greater value
    // it might not be possible 
    // so our isPossible function should give us something like TTTTTFFFFF
    // and we need to find last True value, so we can use binary search

    int lo = 0 , hi = 1e9+1;   // assuming min and max range of number of perks we can buy
    while(lo < hi)
    {
        int mid = (lo+hi+1)/2;
        if(! isPossible(cartridges , dollars , recycleReward , perksCost , mid))
            hi = mid-1; // excluded region
        else
            lo = mid;   // included region
    }
    cout<<"The max perks which we can buys is " << lo;
}