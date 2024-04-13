// Rabin karp algo for string matching with time complexity of O(m+n) on best, O(mn) at worst
#include <stdio.h>
#include <string.h>
#define d 256 // number of characters

void rabinkarp(char text[], char pattern[], int q){
    int n = strlen(text); // len of text
    int m = strlen(pattern); // len of pattern
    int found=0;
    int i,j; // iterators
    int p = 0; //  hash for pattern
    int t = 0; // hash for text
    int h = 1;
    int spurious = 0;
    // h = (d^m-1) mod q
    for(i=0;i<m-1;i++){
        h = (h*d) % q;
    }
    // hash the text
    for(i=0;i<m;i++){
        p = ( d * p + pattern[i]) % q; // pattern
        t = ( d * t + text[i]) % q; // text but only size of pattern is hashed.
    }
    // main algo
    for(i = 0; i<= n-m ; i++){
        if (p==t){
            // if the hash value matches, check the characters
            for(j=0 ; j<m ; j++){
                if(text[i+j]!=pattern[j]){
                    spurious++;
                    break; // break if the characters are not the same
                }
            }
            if (j == m){
            // if no flags raised till all characters parsed
            printf("\nPattern found at with shift/index: %d",i);
            found = 1;
        }
        }
        // calculate hash value for the next window in text if text not fully parsed
        if (i < n-m){
            t = ( d * (t - text[i] * h) + text[i+m]) % q;
        }
        // incase we get negative value of t, convert to positive
        if( t<0 ){
            t = (t + q);
        }
    }
    if(!found){
        printf("\nThe pattern was not found :(");
    }
    printf("\nSpurious hits were %d",spurious);
}

int main(){
    
    char text[] = " 31415926535";
    int len_text = strlen(text);
    printf("\n'%s'",text);
    printf("\nThe length of the text is: %d",len_text);

    char pattern[] = "26";
    int len_pattern = strlen(pattern);
    printf("\nThe length of the pattern '%s' is: %d",pattern,len_pattern);

    int primeQ=11;
    printf("\nUsing the prime number %d as q",primeQ);
    
    rabinkarp(text,pattern,primeQ);
    printf("\n22BCE3789 - Deep Mukesh Jiwan 2024");
    return 0;
}

