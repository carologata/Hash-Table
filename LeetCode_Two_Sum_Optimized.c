#include <stdlib.h>

typedef struct s_num
{
    int key; //num
    int value; //position in array
    struct s_num *next;
} t_num;

t_num *create_num_node(int key, int value)
{
  t_num *num;
  
  num = malloc(sizeof(t_num));
  num->key = key;
  num->value = value;
  num->next = NULL;
  
  return (num);
}

unsigned int hash(int key, int numsSize)
{
    unsigned int index;

    if(key < 0)
        key = key * (-1);
    index = key % numsSize;
    return (index);
}

void insert_hash_table(t_num **hash_table, t_num *num, int numsSize)
{
    unsigned int index;

    index = hash(num->key, numsSize);
    
    if(hash_table[index] == NULL)
      hash_table[index] = num;
    else
    {
      num->next = hash_table[index];
      hash_table[index] = num;
    }
}

int lookup_hash_table(int key, t_num **hash_table, int numsSize)
{
    unsigned int index;

    index = hash(key, numsSize);

    t_num *aux;
    aux = hash_table[index];
    while(aux)
    {
        if(aux->key == key)
            return (aux->value);
        aux = aux->next;
    }
    return (-1);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int pair;
    int pair_pos;
    int *returnNums;
    t_num **hash_table;
    t_num *num;

    *returnSize = 2;
    returnNums = malloc(sizeof(int) * 2);

    hash_table = calloc(sizeof(t_num *), numsSize);
  
    i = 0;
    while(i < numsSize)
    {
        num = create_num_node(nums[i], i);
        insert_hash_table(hash_table, num, numsSize);
        i++;
    }

    i = 0;
    while(i < numsSize)
    {
        returnNums[0] = i;
        pair = target - nums[i];
        pair_pos = lookup_hash_table(pair, hash_table, numsSize);
        if(pair_pos != -1 && pair_pos != i)
        {
            returnNums[1] = pair_pos;
            break;
        }
        i++;
    }
    return (returnNums);
}

/* #include <stdio.h>

int main(void)
{
  int i;
  int numsSize = 4;
  int nums[4] = {-3,4,3,90};
  int target;
  int returnSize;
  int *returnNums;
  
  returnSize = 0;
  target = 0;
  returnNums = twoSum(nums, numsSize, target, &returnSize);
  printf("[%d, %d]\n", returnNums[0], returnNums[1]);
} */