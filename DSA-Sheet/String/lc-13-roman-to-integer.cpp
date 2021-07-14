class Solution {
public:
    
    int romanToInt(string s) {
//         map<string,int> m;
//         m["I"] = 1;
//         m["V"] = 5;
//         m["X"] = 10;
//         m["L"] = 50;
//         m["C"] = 100;
//         m["D"] = 500;
//         m["M"] = 1000;
//         m["IV"] = 4;
//         m["IX"] = 9;
//         m["XL"] = 40;
//         m["XC"] = 90;
//         m["CD"] = 400;
//         m["CM"] = 900;
        
//         int sum=0;
//         for(int i=0;i<s.size();){
//             string x="";
//             x+=s[i];
//             x+=s[i+1];
//             if(m.find(x)==m.end()){
//                 x.pop_back();
//                 sum+=m[x];
//                 i++;
//             }else{
//                 sum+=m[x];
//                 i+=2;
//             }
//         }
//         return sum;
        unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
    }
};