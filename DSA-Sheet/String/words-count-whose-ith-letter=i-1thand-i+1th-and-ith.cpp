
#include<bits/stdc++.h> 
using namespace std; 
  

int countWords(char str[], int len) 
{ 
    int count = 1; 
  
    if (len == 1) 
        return count; 
  
    // Checking for first letter. 
    if (str[0] == str[1]) 
        count *= 1; 
    else
        count *= 2; 
  
    for (int j=1; j<len-1; j++) 
    { 
        // If all three letters are same. 
        if (str[j] == str[j-1] && str[j] == str[j+1]) 
            count *= 1; 
  
        // If two letter are distinct. 
        else if (str[j] == str[j-1] || 
                 str[j] == str[j+1] || 
                 str[j-1] == str[j+1]) 
            count *= 2; 
  
        // If all three letter are distinct. 
        else
            count *= 3; 
    } 
  
    // Checking for last letter. 
    if (str[len - 1] == str[len - 2]) 
        count *= 1; 
    else
        count *= 2; 
  
    return count; 
} 

int main() 
{ 
    char str[] = "abbc"; 
    int len = strlen(str); 
  
    cout << countWords(str, len) << endl; 
    return 0; 
} 