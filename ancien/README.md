# Compilateur MiniAlgo — Rapport de Projet
**Module : Compilation — Licence 3 Informatique**  
**USTHB, Faculté d'Informatique, Département IA & SIQ**  
**Année universitaire : 2025/2026**

---

## 1. Présentation générale

Ce projet implémente un compilateur complet pour le langage **MiniAlgo**, en utilisant les outils **Flex** (analyse lexicale) et **Bison** (analyse syntaxique/sémantique). Le compilateur couvre l'intégralité des phases demandées dans le sujet :

| Phase | Outil / Fichier | Statut |
|---|---|---|
| 1. Analyse lexicale | Flex — `lexer.l` | ✅ |
| 2. Analyse syntaxique | Bison — `parser.y` | ✅ |
| 3. Analyse sémantique | Bison — `parser.y` | ✅ |
| 4. Table des symboles | C — `symtable.c/h` | ✅ |
| 5. Code intermédiaire (quadruplets) | C — `quadruplets.c/h` | ✅ |
| 6. Gestion des erreurs | Flex + Bison | ✅ |
| 7. Optimisation du code intermédiaire | C — `optimiseur.c/h` | ✅ |
| 8. Génération de code 8086 | C — `codegen86.c/h` | ✅ |

---

## 2. Structure des fichiers

```
minialgo/
├── lexer.l          — Analyseur lexical (Flex)
├── parser.y         — Analyseur syntaxique + sémantique + main() (Bison)
├── symtable.h/c     — Table des symboles (table de hachage)
├── quadruplets.h/c  — Code intermédiaire (quadruplets)
├── optimiseur.h/c   — Optimisation du code intermédiaire
├── codegen86.h/c    — Générateur de code assembleur 8086 (NASM)
├── Makefile         — Script de compilation
├── test.algo        — Programme de test complet
└── README.md        — Ce document
```

---

## 3. Compilation et exécution

### Prérequis
```bash
# Installer les outils nécessaires (Ubuntu/Debian)
sudo apt install flex bison gcc
# Optionnel pour assembler le code 8086 généré
sudo apt install nasm
```

### Construire le compilateur
```bash
make
```

### Compiler un programme MiniAlgo
```bash
./minialgo test.algo
```

### Assembler le fichier .asm généré (si nasm est installé)
```bash
make asm
# ou manuellement :
nasm -f bin TestComplet.asm -o TestComplet.com
```

---

## 4. Description des phases

### 4.1 Analyse lexicale (`lexer.l`)

Le fichier Flex reconnaît tous les tokens du langage :

| Catégorie | Exemples | Token |
|---|---|---|
| Mots-clés | `PROGRAM`, `IF`, `WHILE`, `FOR`… | `TOK_PROGRAM`, `TOK_IF`… |
| Identificateurs | `A`, `Somme`, `val_1` | `TOK_IDF` |
| Constantes entières | `5`, `100`, `(-3)` | `TOK_ENTIER` |
| Constantes réelles | `3.14`, `2.7` | `TOK_REEL` |
| Opérateurs arith. | `+`, `-`, `*`, `/` | `'+'`, `'-'`… |
| Opérateurs logiques | `&&`, `\|\|`, `!` | `TOK_AND`, `TOK_OR`, `TOK_NOT` |
| Opérateurs de comp. | `>`, `<`, `>=`, `<=`, `==`, `!=` | `TOK_GT`… |
| Délimiteurs | `;`, `,`, `{`, `}`, `[`, `]` | caractères simples |
| Commentaires | `// …` et `/* … */` | ignorés |

**Erreurs lexicales détectées :**
- Identificateur de plus de 8 caractères
- Constante entière hors de [-32768, 32767]
- Caractère non reconnu

### 4.2 Analyse syntaxique (`parser.y`)

La grammaire BNF du langage MiniAlgo est implémentée dans Bison avec résolution des conflits grâce aux déclarations de précédence et d'associativité (`%left`, `%right`, `%prec`).

Structure grammaticale principale :
```
programme  → PROGRAM nom DECL déclarations ENDDECL BEGIN instructions END
déclaration → TYPE ':' liste_idf ';'
            | TYPE ':' IDF '[' ENTIER ']' ';'
            | CONST IDF '=' valeur ';'
instruction → affectation | condition | boucle_for | boucle_while | write | read
expression  → expression op expression | '(' expression ')' | IDF | littéral
```

### 4.3 Analyse sémantique

Les vérifications sémantiques effectuées durant l'analyse :

| Erreur | Exemple | Détection |
|---|---|---|
| Variable non déclarée | `A = B + 5;` (B non déclarée) | Chaque utilisation |
| Double déclaration | `INTEGER : A; INTEGER : A;` | Insertion dans TS |
| Affectation sur constante | `MAX = 5;` | Vérif. catégorie |
| Incompatibilité de type | `INTEGER A; FLOAT X; A = X;` | Vérif. types |
| Taille tableau invalide | `INTEGER : T[0];` | Déclaration |
| Accès tableau sur scalaire | `A[2]` (A est INTEGER) | Accès |
| Division par zéro (statique) | `A = B / 0;` | Expression `/` |

### 4.4 Table des symboles (`symtable.c`)

Implémentée comme une **table de hachage à chaînage externe** (64 seaux).

Structure d'une entrée :
```c
typedef struct Symbole {
    char       nom[9];       // identificateur (max 8 caractères)
    Categorie  categorie;    // VAR, TAB, CONST
    TypeDonnee type;         // INTEGER, FLOAT
    int        taille;       // 1 pour scalaire, N pour tableau
    int        adresse;      // offset mémoire (en octets)
    union { int ival; float rval; } valeur;  // valeur constante
    int        est_init;     // variable initialisée ?
    int        ligne_decl;   // ligne de déclaration
    struct Symbole *suivant; // chaînage (collisions)
} Symbole;
```

Fonction de hachage utilisée : **djb2** (`h = h*33 + c`)

### 4.5 Code intermédiaire — Quadruplets (`quadruplets.c`)

Chaque instruction est traduite en une liste de **quadruplets** de la forme :
```
(opérateur, arg1, arg2, résultat)
```

Exemples pour `A = (B + 5) * C` :
```
(ADD,  B,  5,  T0)    →  T0 = B + 5
(MUL,  T0, C,  T1)    →  T1 = T0 * C
(ASGN, T1, -,  A )    →  A  = T1
```

Exemples pour `IF (A > B) { WRITE(A); } ELSE { WRITE(B); }` :
```
(GT,    A,  B,  T2)   →  T2 = (A > B)
(IFZ,   T2, -,  L0)   →  si T2==0 aller à L0
(WRITE, A,  -,  - )   →  afficher A
(GOTO,  -,  -,  L1)   →  aller à L1
(LABEL, -,  -,  L0)   →  étiquette L0
(WRITE, B,  -,  - )   →  afficher B
(LABEL, -,  -,  L1)   →  étiquette L1
```

### 4.6 Optimisation du code intermédiaire (`optimiseur.c`)

Cinq passes d'optimisation sont appliquées dans l'ordre :

1. **Simplification algébrique** : `X + 0 → X`, `X * 1 → X`, `X * 0 → 0`…
2. **Pliage de constantes** : `T1 = 3 + 5` → `T1 = 8` (calculé à la compilation)
3. **Propagation de copies** : si `T1 = A` et `T2 = T1 + B`, remplacé par `T2 = A + B`
4. **Élimination du code mort** : suppression des `ASGN` vers des temporaires jamais relus
5. **Élimination des sauts inutiles** : `GOTO L` suivi immédiatement de `LABEL L` → supprimé

### 4.7 Génération de code 8086 (`codegen86.c`)

Le code généré est au format **NASM**, programme `.COM` DOS 16 bits (`org 100h`).

**Conventions de génération :**
- `INTEGER` → `DW` (mot 16 bits)
- `FLOAT` → `DD` (32 bits, traité via le coprocesseur FPU x87)
- Temporaires → variables `DW` dans la section data
- Tableaux → zone `times N dw 0` ou `times N dd 0.0`

**Appels DOS utilisés :**
- `INT 21h AH=09h` — afficher une chaîne terminée par `$`
- `INT 21h AH=0Ah` — lire une ligne depuis stdin (instruction `READ`)
- `INT 21h AH=4Ch` — quitter le programme

**Routines utilitaires générées automatiquement :**
- `_write_int` — convertit un entier 16 bits en chaîne ASCII et l'affiche
- `_read_int`  — lit une ligne ASCII et la convertit en entier 16 bits signé

**Vérification division par zéro à l'exécution :**
```asm
test bx, bx
jnz  .div_ok_N
mov  dx, _err_divz
mov  ah, 09h
int  21h
mov  ah, 4Ch
mov  al, 1         ; code d'erreur 1
int  21h
.div_ok_N:
idiv bx
```

---

## 5. Format des messages d'erreur

Tous les messages suivent le format imposé par le sujet :

```
Erreur Lexicale   : ligne X , colonne Y , element "Z" — description
Erreur Syntaxique : ligne X , colonne Y , element "Z" — description
Erreur Semantique : ligne X , element "Z" — description
```

Exemples :
```
Erreur Lexicale   : ligne 3 , colonne 12 , element "variable_tres_longue" — identificateur trop long (max 8 caracteres)
Erreur Semantique : ligne 7 , element "B" — variable non declaree
Erreur Semantique : ligne 9 , element "/" — division par zero (operande constant)
```

---

## 6. Exemple d'exécution complète

Pour le programme `test.algo` :

```
=== Compilation MiniAlgo : test.algo ===

===== TABLE DES SYMBOLES =====
Nom        Categ.   Type     Taille  Adresse  Ligne
----------------------------------------------
A          VAR      INTEGER  1       0        4
B          VAR      INTEGER  1       2        4
...

===== CODE INTERMÉDIAIRE (quadruplets) =====
Idx   Op      Arg1       Arg2       Res
--------------------------------------------
0     ASGN    5          -          A
1     ASGN    3          -          B
2     ADD     A          B          T0
3     ASGN    T0         -          C
...

===== OPTIMISATION DU CODE INTERMÉDIAIRE =====
[Optimisation] Simplification algebrique : 0 quadruplet(s) modifie(s)
[Optimisation] Pliage de constantes : 0 quadruplet(s) modifie(s)
[Optimisation] Propagation de copies : 3 occurrence(s) remplacee(s)
[Optimisation] Code mort : 2 quadruplet(s) supprime(s)
[Optimisation] Sauts inutiles : 0 quadruplet(s) supprime(s)
-----------------------------------------------
Total : 2 quadruplet(s) supprimes, 28 quadruplet(s) restant(s)

[Génération 8086] 28 quadruplet(s) traduits → TestComplet.asm
[Génération] Fichier assembleur : TestComplet.asm

Compilation reussie -- aucune erreur.
```

---

## 7. Limitations connues

- L'affichage des FLOAT se fait avec troncature en entier (limitation de l'affichage DOS 16 bits sans bibliothèque flottante).
- L'instruction `READ` lit uniquement des entiers.
- La détection de division par zéro sur des variables (valeurs dynamiques) est effectuée à l'exécution, pas à la compilation.
- Les actions milieu-règle Bison pour IF/ELSE utilisent une transmission de contexte par chaîne encodée (`"idx|label"`) qui est robuste mais non réentrant.
