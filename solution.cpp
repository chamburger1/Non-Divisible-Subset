#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int findSubset( map<int, int> x, int k){
//matching pair of remainders that add to k they get voided for future iterations
    map<int, int> usedindex; 
    
//this is for an even number ex. k=4 half would be 2, so if you have 2 numbers with 2 remainder 
//those added together will give 4 so can only take one in the subset
    int half;
    if(k%2==0)
        half=k/2; 
                
    int max=0;
   
    for(auto i: x){
        //for when its 0 or half can only add 1, ex 4%4=0 8%4=0 but together then will be 12 which is 12%0 and does not fit
        //requirements and 6%4=2 10%4=2 but 10+6=16 16%4=0 can only take one number with remainder of half or 0 
        if(i.first==0||i.first==half) 
            max+=1;
            
        //check if match for pair of remainders that when added will give divisible njumber ex 3+1 =4 
        else if(x.count(k-i.first)>0){
        
            //take higher of numbers with matching remainders, skips over second part of pair on future iterations        
            if(x.at(k-i.first)>i.second && usedindex.count(k-i.first)<1){    
                max+=y.at(k-i.first);      
                usedindex.insert(pair<int, int>(k-i.first, 1));
                usedindex.insert(pair<int, int>(i.first, 1));
            }
            else if(x.at(k-i.first)<i.second&&usedindex.count(i.first)<1){
                max+=i.second;     
                usedindex.insert(pair<int, int>(i.first, 1));       
                usedindex.insert(pair<int, int>(k-i.first, 1));        
            }
        }
        
        //means there's no other remainder to cancel out, add that remainder count to max 
        else if(x.count(k-i.first)<1){  
            max+=i.second;
        }      
    }
    return max;
}  

int main() {
    map<int, int> setmembers;

    int N, div, x;
    cin>>N>>div;
    
    for(int i=0; i<N; i++){
        cin>>x;
        long int rem;
        rem=x%div;
        
        if(!setmembers.insert(pair<int, int>(rem, 1)).second){ 
            setmembers.at(rem)++;
        }  
    }
    cout<<findSubset(setmembers, div);

return 0;
}
