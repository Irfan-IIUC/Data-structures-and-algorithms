#include<stdio.h>
#include<string.h>

int hash_table[10];

int hash_function(int k)
{
    return k%10;
}

int next_available_space(int index)
{
    while(hash_table[index] != -1)
    {
        index++;
        index = index%10;
    }

    return index;
}

int main()
{
    int keys[]= {43,135,72,23,99,19,82}, i, key_size=7, index;

    // Fill whole hash table with -1
    memset(hash_table, -1, 10 * sizeof(hash_table[0]));

    for(i=0; i<key_size; i++)
    {
        index = hash_function(keys[i]);

        // check for next available space
        int a = next_available_space(index);
        hash_table[a] = keys[i];
    }

    // display hash table
    printf("Index \t Key\n");
    for(i=0; i<10; i++)
        printf("%d \t %d\n", i, hash_table[i]);

    return 0;
}
