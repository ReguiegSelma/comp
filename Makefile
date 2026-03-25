# ============================================================
#  Makefile — Compilateur MiniAlgo (toutes phases)
#
#  Dépendances système requises :
#    flex, bison, gcc
#  Optionnel pour assembler le .asm généré :
#    nasm
#
#  Utilisation :
#    make            → construit le compilateur
#    make test       → compile test.algo (toutes les phases)
#    make asm        → assemble le .asm généré (si nasm présent)
#    make clean      → supprime les fichiers générés
# ============================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -g

TARGET  = minialgo

# Fichiers générés par Flex/Bison
LEX_C   = lex.yy.c
PAR_C   = parser.tab.c
PAR_H   = parser.tab.h

# Fichiers sources C du projet
SRCS_C  = symtable.c quadruplets.c optimiseur.c codegen86.c

.PHONY: all test asm clean

# ---- Construction du compilateur ----
all: $(TARGET)

# 1. Bison génère parser.tab.c et parser.tab.h à partir de parser.y
$(PAR_C) $(PAR_H): parser.y
	bison -d -Wcounterexamples parser.y

# 2. Flex génère lex.yy.c à partir de lexer.l
#    Le -I. permet de trouver parser.tab.h dans le répertoire courant
$(LEX_C): lexer.l $(PAR_H)
	flex lexer.l

# 3. Compilation finale : tous les .c ensemble
$(TARGET): $(PAR_C) $(LEX_C) $(SRCS_C)
	$(CC) $(CFLAGS) -o $@ $(PAR_C) $(LEX_C) $(SRCS_C) -lfl -lm

# ---- Test avec le programme exemple ----
test: $(TARGET)
	@echo ""
	@echo "====== Test : compilation de test.algo ======"
	@echo ""
	./$(TARGET) test.algo

# ---- Assemblage du fichier .asm généré (nécessite nasm) ----
asm: test
	@if command -v nasm > /dev/null 2>&1; then \
	    echo "Assemblage de Test.asm..."; \
	    nasm -f bin Test.asm -o Test.com && echo "Binaire : Test.com"; \
	else \
	    echo "nasm non installe -- skip."; \
	fi

# ---- Nettoyage ----
clean:
	rm -f $(TARGET) $(LEX_C) $(PAR_C) $(PAR_H) *.o *.asm *.com
