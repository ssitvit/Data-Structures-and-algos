#include<stdio.h>
int n, prime, current_size=0;
int hash1(int key)
{
    return key%n;
}

int hash2(int key)
{
    return prime-key%prime;
}

int isfull(int current_size){
    if (current_size==n)
        return 1;
    else
        return 0;
}

void insert(int hashTable[n], int key)
{
    if (isfull(current_size)){
        printf("Table full, cannot insert more elements\n");
        return;
    }
    int index = hash1(key);
    if (hashTable[index]!=-1)
    {
        int index2 = hash2(key);
        int i = 1;
        while(1)
        {
            int new_index = (index+i*index2)%n;
            if (hashTable[new_index] == -1)
            {
                hashTable[new_index] = key;
                break;
            }
            i++;
        }
    }
    else
        hashTable[index] = key;
    current_size++;
}

void search(int hashTable[n], int key)
{
    int ind1 = hash1(key);
    int ind2 = hash2(key);
    int i = 0;
    while (hashTable[(ind1 + i * ind2) % n] != key) {
        if (hashTable[(ind1 + i * ind2) % n] == -1) {
            printf("%d does not exist\n", key);
            return;
        }
        i++;
    }
    printf("%d found\n", key);
}

void display(int hashTable[n])
{
    int i;
    for(i=0;i<n;i++){
        if (hashTable[i]!=-1)
            printf("%d=%d\n", i, hashTable[i]);
        else
            printf("%d=\n", i);
    }
}

void delete(int hashTable[n], int key){
    int ind1 = hash1(key);
    int ind2 = hash2(key);
    int i = 0;
    while (hashTable[(ind1 + i * ind2) % n] != key) {
        if (hashTable[(ind1 + i * ind2) % n] == -1) {
            printf("%d does not exist\n", key);
            return;
        }
        i++;
    }
    hashTable[(ind1 + i*ind2) % n] = -1;
    printf("%d deleted successfully\n", key);
    current_size--;
}
void main()
{
    printf("***************Hash Table with Double Hashing to Avoid Collision***************\n");
    int ch, input, i;
    printf("Enter the size of the hash table: ");
    scanf("%d", &n);
    printf("Enter value of prime: ");
    scanf("%d", &prime);
    int hashTable[n];
    for(i=0;i<n;i++)
        hashTable[i] = -1;
    printf("1 for insertion\n2 for search\n3 for displaying the hash table\n4 to delete\n5 to exit\nEnter your choice:  ");
    scanf("%d", &ch);
    while (ch!=5)
    {
        switch (ch){
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &input);
            insert(hashTable, input);
            break;
        case 2:
            printf("Enter the value to be searched: ");
            scanf("%d", &input);
            search(hashTable, input);
            break;
        case 3:
            display(hashTable);
            break;
        case 4:
            printf("Enter element to be deleted: ");
            scanf("%d", &input);
            delete(hashTable, input);
            break;
        }
        printf("Enter your choice: ");
        scanf("%d", &ch);
    }

}
