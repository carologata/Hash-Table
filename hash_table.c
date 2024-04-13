#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 10

typedef struct s_person
{
    char *name;
    int age;
    struct s_person *next;
} t_person;

t_person *hash_table[MAX_SIZE];

unsigned int hash(char *str)
{
    int i;
    int sum;
    int index;

    i = 0;
    sum = 0;
    while (str[i])
    {
        sum += str[i];
        i++;
    }
    index = sum % MAX_SIZE;
    return (index);
}

void init_hash_table()
{
    int i;

    i = 0;
    while (i < MAX_SIZE)
    {
        hash_table[i] = NULL;
        i++;
    }
}

void insert_hash_table(t_person *person)
{
    int index;

    index = hash(person->name);
    if (hash_table[index] == NULL)
        hash_table[index] = person;
    else
    {
        person->next = hash_table[index];
        hash_table[index] = person;
    }
}

void delete_hash_table(t_person *person)
{
    int index;
    t_person *aux;
    t_person *prev;

    index = hash(person->name);
    aux = hash_table[index];
    prev = NULL;
    while (aux)
    {
        if (strcmp(aux->name, person->name) == 0)
        {
            if (prev && aux->next)
                prev->next = aux->next;
            else if (prev)
                prev->next = NULL;
            else if (aux->next)
                hash_table[index] = aux->next;
            else
                hash_table[index] = NULL;
            break;
        }
        prev = aux;
        aux = aux->next;
    }
}

int lookup_hash_table(char *name)
{
    int index;
    t_person *person;

    index = hash(name);
    person = hash_table[index];
    while (person)
    {
        if (strcmp(hash_table[index]->name, name) == 0)
            return (hash_table[index]->age);
        person = person->next;
    }
    return (-1);
}

void print_hash_table()
{
    int i;
    t_person *person;

    i = 0;
    while (i < MAX_SIZE)
    {
        person = hash_table[i];
        if (person)
        {
            printf("%d  %s ", i, person->name);
            person = person->next;
            while (person)
            {
                printf("-> %s ", person->name);
                person = person->next;
            }
            printf("\n");
        }
        else
            printf("%d  -----\n", i);
        i++;
    }
}

int main(void)
{
    t_person john = {.name = "John", .age = 25, .next = NULL};
    t_person nhoj = {.name = "nhoJ", .age = 65, .next = NULL};
    t_person anne = {.name = "Anne", .age = 12, .next = NULL};
    t_person aenn = {.name = "Aenn", .age = 18, .next = NULL};
    t_person maryanne = {.name = "Maryanne", .age = 47, .next = NULL};
    t_person jnho = {.name = "Jnho", .age = 55, .next = NULL};

    init_hash_table();

    insert_hash_table(&john);
    insert_hash_table(&nhoj);
    insert_hash_table(&anne);
    insert_hash_table(&maryanne);
    insert_hash_table(&jnho);
    insert_hash_table(&aenn);

    print_hash_table();

    printf("\n---> Remove nhoJ\n");
    delete_hash_table(&nhoj);
    print_hash_table();

    printf("\n---> Remove John\n");
    delete_hash_table(&john);
    print_hash_table();

    printf("\n---> Remove Aenn\n");
    delete_hash_table(&aenn);
    print_hash_table();

    printf("\n---> Remove Maryanne\n");
    delete_hash_table(&maryanne);
    print_hash_table();
    printf("-----------------------\n");

    printf("\n---> Insert Aenn\n");
    insert_hash_table(&aenn);
    print_hash_table();
}