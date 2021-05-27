#include<bits/stdc++.h>

using namespace std;


void bubbleSort(vector<int> &v, int index)
{
    if(index == v.size()-1)
        return;

    for(int i=0; i<v.size()-1-index; i++)
        {
            if(v[i]>v[i+1])
                swap(v[i],v[i+1]);
        }
    bubbleSort(v,index+1);
}


void BubbleSort(vector<int> &v,int index,int i){
	if(index == v.size()-1)
		return ;

	if(i == v.size()-1-index){
		i=0;
		return BubbleSort(v,index+1,i);
	}

	if(v[i]>v[i+1]){
		swap(v[i],v[i+1]);
	}

	return BubbleSort(v,index,i+1);
}

int main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

    vector<int> v1{10,9,8,7,6,5,4,5,4,5,4};
    vector<int> v2{10,9,8,7,6,5,4,5,4,5,4};

    bubbleSort(v1,0);
    for(int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" ";

    BubbleSort(v2,0,0);
    cout<<endl;
    for(int i=0; i<v2.size(); i++)
        cout<<v2[i]<<" ";
	return 0;
}
