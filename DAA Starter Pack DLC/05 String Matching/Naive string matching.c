// naive string mathcing algo working with time complexity of O(mn)
#include <stdio.h>
#include <string.h>

void naive_search(char text[], char pattern[]){
    int n = strlen(text); // len of text
    int m = strlen(pattern); // len of pattern
    int found = 0;

    for(int i = 0; i<= n-m; i++){
        int j;
        for(j=0 ; j<m ; j++){
            if(text[i+j] != pattern[j]){
                break;
            }
        }
        if (j == m){
            printf("\nPattern found at index %d",i);
            found = 1;
        }
    }

    if(!found){
        printf("\nThe pattern was not found :(");
    }
}


int main(){
    
    char text[100];
    printf("Enter the text: ");
    scanf("%[^\n]%*c", text);

    int n;
    printf("Enter the size of set Pattern: ");
    scanf("%d", &n);

    int pattern[100];
    printf("Enter distinct integers space seperated pattern: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pattern[i]);
    }
    // Convert into string
    char patternStr[n + 1];
    for (int i = 0; i < n; i++) {
        patternStr[i] = pattern[i] + '0';
    }
    patternStr[n] = '\0';

    naive_search(text,patternStr);
    printf("\n22BCE3789 - Deep Mukesh Jiwan 2024");
    return 0;
}
