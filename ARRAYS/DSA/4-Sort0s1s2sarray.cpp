
void sort012(int v[], int n)
{
    int index= 0;
	    for(int i=0;i<n;i++){
	        if(v[i]==0){
	            swap(v[i],v[index]);
	            index++;
	        }
	    }
	    index=n-1;
	    for(int i=n-1;i>=0;i--){
	        if(v[i]==2){
	            swap(v[i],v[index]);
	            index--;
	        }
	        if(v[i]==0)
	            break;
	    }
}