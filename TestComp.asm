; ============================================================
;  Code assembleur 8086 — programme : TestComp
;  Généré par le compilateur MiniAlgo
;  Format : NASM, .COM DOS 16 bits (org 100h)
;
;  Pour assembler :
;    nasm -f bin TestComp.asm -o TestComp.com
; ============================================================

    bits 16
    org  100h

    jmp  _start            ; sauter la section data


; ============================================================
; Section DATA — variables, temporaires, buffers
; ============================================================

    ; Variables du programme
X            dd  0.0        ; FLOAT
MAX          dw  10         ; CONST INTEGER
PI           dd  3.14         ; CONST FLOAT
A            dw  0          ; INTEGER
B            dw  0          ; INTEGER
C            dw  0          ; INTEGER
F            times 10 dw 0    ; INTEGER[10]
T            times 5 dw 0    ; INTEGER[5]

    ; Temporaires générés par le compilateur
T0           dw  0          ; temporaire
T1           dw  0          ; temporaire
T2           dw  0          ; temporaire
T3           dw  0          ; temporaire
T            dw  0          ; temporaire

    ; Buffers entrée/sortie
_obuf        times 24 db '$' ; tampon affichage (sortie)
_ibuf        db  255         ; capacité buffer lecture
             db  0           ; longueur réelle (rempli par DOS)
             times 253 db 0  ; données lues
_newline     db  13, 10, '$' ; retour chariot + saut de ligne

_err_divz    db  'ERREUR: division par zero', 13, 10, '$'

; ============================================================
; Routines utilitaires
; ============================================================

; --------------------------------------------------------
; _write_int : affiche AX (entier signé 16 bits)
;   Altère : AX BX CX DX SI  (sauvegarde sur pile)
; --------------------------------------------------------
_write_int:
    push bx
    push cx
    push dx
    push si
    mov  si, _obuf
    cmp  ax, 0
    jge  .wi_pos
    mov  byte [si], '-'
    inc  si
    neg  ax
.wi_pos:
    xor  cx, cx
    mov  bx, 10
.wi_loop:
    xor  dx, dx
    div  bx
    push dx
    inc  cx
    test ax, ax
    jnz  .wi_loop
.wi_build:
    pop  dx
    add  dl, '0'
    mov  [si], dl
    inc  si
    loop .wi_build
    mov  byte [si], '$'
    mov  dx, _obuf
    mov  ah, 09h
    int  21h
    mov  dx, _newline
    mov  ah, 09h
    int  21h
    pop  si
    pop  dx
    pop  cx
    pop  bx
    ret

; --------------------------------------------------------
; _read_int  : lit un entier signé 16 bits depuis stdin
;   Retour   : AX = valeur lue
;   Altère   : AX BX CX DX SI
; --------------------------------------------------------
_read_int:
    push bx
    push cx
    push dx
    push si
    mov  dx, _ibuf
    mov  ah, 0Ah
    int  21h
    mov  si, _ibuf + 2      ; début des données lues
    xor  ax, ax             ; accumulateur
    xor  cx, cx             ; signe (0=positif)
    cmp  byte [si], '-'
    jne  .ri_digit
    mov  cx, 1              ; signe négatif
    inc  si
.ri_digit:
    mov  bl, [si]
    cmp  bl, 13             ; CR = fin de saisie
    je   .ri_done
    cmp  bl, 10             ; LF
    je   .ri_done
    sub  bl, '0'
    jb   .ri_done           ; caractère invalide
    cmp  bl, 9
    ja   .ri_done
    mov  bh, 0
    mov  dx, 10
    push bx
    mul  dx                 ; AX = AX * 10
    pop  bx
    add  ax, bx
    inc  si
    jmp  .ri_digit
.ri_done:
    test cx, cx
    jz   .ri_end
    neg  ax                 ; appliquer signe négatif
.ri_end:
    pop  si
    pop  dx
    pop  cx
    pop  bx
    ret

; ============================================================
;  Corps du programme : TestComp
; ============================================================
_start:
    finit                  ; initialiser le coprocesseur FPU

    ; (0) ASGN    5          -          A         
    mov  word [A], 5

    ; (1) ASGN    3          -          B         
    mov  word [B], 3

    ; (2) ADD     A          B          T0        
    mov  ax, word [A]
    mov  bx, word [B]
    add  ax, bx
    mov  word [T0], ax

    ; (3) ASGN    T0         -          C         
    mov  ax, word [T0]
    mov  word [C], ax

    ; (4) ASGN    PI         -          X         
    fld  dword [PI]
    fstp dword [X]

    ; (5) GT      A          B          T1        
    mov  ax, word [A]
    mov  bx, word [B]
    cmp  ax, bx
    jg  .cmp_t_T1_5
    mov  word [T1], 0
    jmp  .cmp_e_T1_5
.cmp_t_T1_5:
    mov  word [T1], 1
.cmp_e_T1_5:

    ; (6) IFZ                -          L0        
    mov  ax, word []
    test ax, ax
    jz   L0

    ; (7) WRITE   A          -          -         
    mov  ax, word [A]
    call _write_int

    ; (8) GOTO    -          -          L1        
    jmp  L1

    ; (9) WRITE   B          -          -         
    mov  ax, word [B]
    call _write_int

    ; (10) LABEL   -          -          L1        
L1:

    ; (11) ASGN    0          -          C         
    mov  word [C], 0

    ; (12) LABEL   -          -          L2        
L2:

    ; (13) LE      C          1          T2        
    mov  ax, word [C]
    mov  bx, 1
    cmp  ax, bx
    jle  .cmp_t_T2_13
    mov  word [T2], 0
    jmp  .cmp_e_T2_13
.cmp_t_T2_13:
    mov  word [T2], 1
.cmp_e_T2_13:

    ; (14) IFZ     T2         -          L3        
    mov  ax, word [T2]
    test ax, ax
    jz   L3

    ; (15) ADD     C          1          T3        
    mov  ax, word [C]
    mov  bx, 1
    add  ax, bx
    mov  word [T3], ax

    ; (16) TASGN   T          C          T3        
    mov  bx, word [C]
    mov  si, bx
    shl  si, 1
    mov  ax, word [T3]
    mov  word [T + si], ax

    ; (17) READ    -          -          C         
    call _read_int       ; résultat dans AX
    mov  word [C], ax

    ; (18) WRITE   C          -          -         
    mov  ax, word [C]
    call _write_int

    ; (19) WRITE   A          -          -         
    mov  ax, word [A]
    call _write_int

    ; (20) HALT    -          -          -         
    ; Fin du programme
    mov  ah, 4Ch
    mov  al, 0
    int  21h


; Fin du fichier assembleur
