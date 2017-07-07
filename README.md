C. H. 2017

Non-Divisible Subset found here https://www.hackerrank.com/challenges/non-divisible-subset

The solution works using mathematical logic of: (a+b)%k=0 then (a%k)+(b%k)=0.  

This can be further expanded to include the expression:
    Given a%k=c and b%k=d, if d+c=k than (a+b)%k=0.
    
Based on this we can conclude that numbers in the set with remainder c and d cannot be in our target subset, thus we need to take 
the larger of the c or d pair. 

The solution uses a STL map with a remainder(key), count(value starts at 1) pair to log the count of numbers with unique remainders.  

The findSubset function is O(K) based on maximum possible unique remainders.  
