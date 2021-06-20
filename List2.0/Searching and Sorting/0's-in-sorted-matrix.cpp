// https://practice.geeksforgeeks.org/problems/count-zeros-in-a-sorted-matrix/1

int countZeros(vector<vector<int>>A)
	{
		int cnt=0;
		for(int i=0;i<A.size();i++){
		    int idx = lower_bound(A[i].begin(),A[i].end(),1)-A[i].begin();
		    cnt += idx;
		}
		return cnt;
	}