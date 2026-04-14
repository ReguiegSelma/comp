#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"

extern int nb_lignes;
extern int nb_erreurs;

typedef struct StrEntry
{
    char *lexeme;
    struct StrEntry *next;
} StrEntry;

typedef struct
{
    Symbole **buckets;
    size_t capacity;
    size_t count;
} TS_ID;

typedef struct
{
    StrEntry **buckets;
    size_t capacity;
    size_t count;
} TS_STR;

static TS_ID ts_id = {NULL, 0, 0};
static TS_STR ts_kw = {NULL, 0, 0};
static TS_STR ts_sep = {NULL, 0, 0};

static unsigned long hash_str(const char *s)
{
    unsigned long h = 5381;
    int c;
    while ((c = *s++))
    {
        h = ((h << 5) + h) + (unsigned long)c;
    }
    return h;
}

static void ts_id_init_if_needed()
{
    if (ts_id.capacity == 0)
    {
        ts_id.capacity = 53;
        ts_id.count = 0;
        ts_id.buckets = (Symbole **)calloc(ts_id.capacity, sizeof(Symbole *));
    }
}

static void ts_str_init_if_needed(TS_STR *t)
{
    if (t->capacity == 0)
    {
        t->capacity = 53;
        t->count = 0;
        t->buckets = (StrEntry **)calloc(t->capacity, sizeof(StrEntry *));
    }
}

static void ts_id_rehash(size_t new_cap)
{
    Symbole **old = ts_id.buckets;
    size_t old_cap = ts_id.capacity;

    ts_id.buckets = (Symbole **)calloc(new_cap, sizeof(Symbole *));
    ts_id.capacity = new_cap;
    ts_id.count = 0;

    for (size_t i = 0; i < old_cap; i++)
    {
        Symbole *cur = old[i];
        while (cur)
        {
            Symbole *next = cur->next;
            unsigned long h = hash_str(cur->name) % ts_id.capacity;
            cur->next = ts_id.buckets[h];
            ts_id.buckets[h] = cur;
            ts_id.count++;
            cur = next;
        }
    }
    free(old);
}

static void ts_str_rehash(TS_STR *t, size_t new_cap)
{
    StrEntry **old = t->buckets;
    size_t old_cap = t->capacity;

    t->buckets = (StrEntry **)calloc(new_cap, sizeof(StrEntry *));
    t->capacity = new_cap;
    t->count = 0;

    for (size_t i = 0; i < old_cap; i++)
    {
        StrEntry *cur = old[i];
        while (cur)
        {
            StrEntry *next = cur->next;
            unsigned long h = hash_str(cur->lexeme) % t->capacity;
            cur->next = t->buckets[h];
            t->buckets[h] = cur;
            t->count++;
            cur = next;
        }
    }
    free(old);
}

static void ts_str_insert(TS_STR *t, const char *lexeme)
{
    ts_str_init_if_needed(t);
    unsigned long h = hash_str(lexeme) % t->capacity;
    for (StrEntry *cur = t->buckets[h]; cur; cur = cur->next)
    {
        if (strcmp(cur->lexeme, lexeme) == 0)
            return;
    }
    StrEntry *e = (StrEntry *)malloc(sizeof(StrEntry));
    e->lexeme = strdup(lexeme);
    e->next = t->buckets[h];
    t->buckets[h] = e;
    t->count++;

    if (t->count * 4 >= t->capacity * 3)
    {
        ts_str_rehash(t, t->capacity * 2 + 1);
    }
}

void inserer(const char *name, const char *type, int isConst, int isTab, int size)
{
    ts_id_init_if_needed();
    unsigned long h = hash_str(name) % ts_id.capacity;
    for (Symbole *cur = ts_id.buckets[h]; cur; cur = cur->next)
    {
        if (strcmp(cur->name, name) == 0)
        {
            printf("Erreur Semantique: ligne %d, Double declaration de '%s'\n", nb_lignes, name);
            nb_erreurs++;
            return;
        }
    }
    Symbole *s = (Symbole *)malloc(sizeof(Symbole));
    strcpy(s->name, name);
    strcpy(s->type, type);
    s->estConstante = isConst;
    s->estTableau = isTab;
    s->taille = size;
    s->valeur = 0;
    s->a_une_valeur = 0;

    s->next = ts_id.buckets[h];
    ts_id.buckets[h] = s;
    ts_id.count++;

    if (ts_id.count * 4 >= ts_id.capacity * 3)
    {
        ts_id_rehash(ts_id.capacity * 2 + 1);
    }
}

Symbole *rechercher(const char *name)
{
    if (ts_id.capacity == 0)
        return NULL;
    unsigned long h = hash_str(name) % ts_id.capacity;
    for (Symbole *cur = ts_id.buckets[h]; cur; cur = cur->next)
    {
        if (strcmp(cur->name, name) == 0)
            return cur;
    }
    return NULL;
}

void inserer_kw(const char *lexeme)
{
    ts_str_insert(&ts_kw, lexeme);
}

void inserer_sep(const char *lexeme)
{
    ts_str_insert(&ts_sep, lexeme);
}

void afficher_ts_ids()
{
    printf("\n--- TS IDENTIFIANTS ---\n");
    if (ts_id.capacity == 0 || ts_id.count == 0)
    {
        printf("(vide)\n");
        return;
    }
    printf("%-15s | %-10s | %-5s | %-5s | %-6s | %-10s\n", "Nom", "Type", "Const", "Tab", "Taille", "Val_Init");
    printf("--------------------------------------------------------------------------\n");
    for (size_t i = 0; i < ts_id.capacity; i++)
    {
        for (Symbole *cur = ts_id.buckets[i]; cur; cur = cur->next)
        {
            if (cur->a_une_valeur)
            {
                printf("%-15s | %-10s | %-5d | %-5d | %-6d | %-10.2f\n",
                       cur->name, cur->type, cur->estConstante, cur->estTableau, cur->taille, cur->valeur);
            }
            else
            {
                printf("%-15s | %-10s | %-5d | %-5d | %-6d | %-10s\n",
                       cur->name, cur->type, cur->estConstante, cur->estTableau, cur->taille, "N/A");
            }
        }
    }
}

static void afficher_ts_str(const char *titre, const TS_STR *t)
{
    printf("\n--- %s ---\n", titre);
    if (t->capacity == 0 || t->count == 0)
    {
        printf("(vide)\n");
        return;
    }
    for (size_t i = 0; i < t->capacity; i++)
    {
        for (StrEntry *cur = t->buckets[i]; cur; cur = cur->next)
        {
            printf("%s\n", cur->lexeme);
        }
    }
}

void afficher_ts_kw()
{
    afficher_ts_str("TS MOTS-CLES", &ts_kw);
}

void afficher_ts_sep()
{
    afficher_ts_str("TS SEPARATEURS", &ts_sep);
}
