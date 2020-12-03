#include<stdio.h>
#include<string.h>
void prefixSuffixArray(char* pat, int M, int* pps) {
    int length = 0;
    pps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            pps[i] = length;
            i++;
        } 
        else {
            if (length != 0)
                length = pps[length - 1];
            else {
                pps[i] = 0;
                i++;
            }
        }
    }
}
void KMPAlgorithm(char* text, char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int pps[M];
    prefixSuffixArray(pattern, M, pps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("String matched at index %d\n", i - j);
            j = pps[j - 1];
         }
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = pps[j - 1];
            else
                i = i + 1;
        }
    }
}
void main() {
    char text[20];
    char pattern[10];
    printf("Enter some string: \n");
    scanf("%s",text);
    printf("Enter string to find: \n");
    scanf("%s",pattern);
    printf("String is matched at the following index : \n");
    KMPAlgorithm(text, pattern);
}
