#include<stdio.h>
#include<string.h>

int hash_table[11];

int hash_function1(int k)
{
    return k%11;
}

int hash_function2(int k)
{
    int a;

    a = 8 - (k%8);
    return a;
}

int main()
{
    int keys[]= {20,34,45,70,56}, i, key_size=5, index1, index2, ans;

    // Fill whole hash table with -1
    memset(hash_table, -1, 11 * sizeof(hash_table[0]));

    for(i=0; i<key_size; i++)
    {
        index1 = hash_function1(keys[i]);

        if(hash_table[index1] == -1)
            hash_table[index1] = keys[i];
        else
        {
            int collision=1;
            index2 = hash_function2(keys[i]);

            while(1)
            {
                ans = (index1 + (collision * index2)) % 11;

                if(hash_table[ans] == -1)
                {
                    hash_table[ans] = keys[i];
                    break;
                }

                collision++;
            }
        }
    }

    // display hash table
    printf("Index \t Key\n");
    for(i=0; i<11; i++)
        printf("%d \t %d\n", i, hash_table[i]);

    return 0;
}
