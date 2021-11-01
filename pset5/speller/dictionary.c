// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// size of the dictionary to be loaded
int d_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // hash word to obtain hash value
    int hash_value = hash(word);

    // access linked list at that index in hash table
    node *n = table[hash_value];

    // traverse linked list
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
    FILE *dict_pointer = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // initialize word array
    char next_word[LENGTH + 1];

    // read strings from file
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        // create new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // copy word into node
        strcpy(n->word, next_word);

        // hash word to obtain hash value
        int hash_value = hash(next_word);

        // insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        d_size++;
    }
    // close file
    fclose(dict_pointer);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return d_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // iterate over hash table and free all nodes
    for (int i = 0; i < N; i++)
    {
        // assign cursor
        node *cursor = table[i];

        // loop trough linked list
        while (cursor != NULL)
        {
            // make tmp = cursor
            node *tmp = cursor;
            // point cursor to the next elemen
            cursor = cursor->next;
            // free temp
            free(tmp);
        }

        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
