TITLE code.asm
DATA SEGMENT
  ; --- Variables issues de la TS ---
  ; --- Variables et Temporaires de la TS ---
  T12 DW ?
  T13 DW ?
  T14 DW ?
  T15 DW ?
  T16 DW ?
  T17 DW ?
  T18 DW ?
  T19 DW ?
  a DW ?
  b DW ?
  c DW ?
  i DW ?
  j DW ?
  n DW ?
  T1 DW ?
  p DW ?
  T2 DW ?
  T3 DW ?
  T4 DW ?
  T5 DW ?
  T6 DW ?
  T7 DW ?
  T8 DW ?
  T9 DW ?
  x DW ?
  y DW ?
  z DW ?
  T10 DW ?
  T11 DW ?
DATA ENDS

STACK SEGMENT
  DW 128 DUP(0)
STACK ENDS

CODE SEGMENT
  ASSUME CS:CODE, DS:DATA, SS:STACK

START:
  MOV AX, DATA
  MOV DS, AX

L0: MOV AX, 10
  MOV x, AX
L1: MOV AX, x
  ADD AX, 5
  MOV T8, AX
L2: MOV AX, T8
  MOV a, AX
L3: MOV AX, 20
  MOV x, AX
L4: MOV AX, x
  ADD AX, 5
  MOV T9, AX
L5: MOV AX, T9
  MOV b, AX
L6: MOV AX, 0
  MOV i, AX
L7: MOV AX, 10
  MOV x, AX
L8: MOV AX, i
  CMP AX, p
  JL VRAI_8
  MOV T10, 0
  JMP FIN_CMP_8
VRAI_8: MOV T10, 1
FIN_CMP_8: NOP
L9: MOV AX, T10
  CMP AX, 0
  JE L15
L10: MOV AX, x
  ADD AX, i
  MOV T12, AX
L11: MOV AX, T12
  MOV y, AX
L12: MOV AX, i
  ADD AX, 1
  MOV T13, AX
L13: MOV AX, T13
  MOV i, AX
L14: JMP L8
L15: MOV AX, a
  CMP AX, 100
  JL VRAI_15
  MOV T14, 0
  JMP FIN_CMP_15
VRAI_15: MOV T14, 1
FIN_CMP_15: NOP
L16: MOV AX, T14
  CMP AX, 0
  JE L19
L17: MOV AX, 1
  MOV x, AX
L18: JMP L20
L19: MOV AX, 2
  MOV y, AX
L20: MOV AX, x
  ADD AX, 10
  MOV T15, AX
L21: MOV AX, T15
  MOV z, AX
L22: MOV AX, 0
  MOV j, AX
L23: MOV AX, 10
  MOV c, AX
L24: MOV AX, j
  CMP AX, 5
  JL VRAI_24
  MOV T16, 0
  JMP FIN_CMP_24
VRAI_24: MOV T16, 1
FIN_CMP_24: NOP
L25: MOV AX, T16
  CMP AX, 0
  JE L31
L26: MOV AX, c
  ADD AX, j
  MOV T18, AX
L27: MOV AX, T18
  MOV a, AX
L28: MOV AX, j
  ADD AX, 1
  MOV T19, AX
L29: MOV AX, T19
  MOV j, AX
L30: JMP L24
L31:   ; Appel affichage pour z
L32:   ; Appel affichage pour y
L33:   ; Appel affichage pour a
L34:   ; Appel affichage pour b

  MOV AH, 4Ch
  INT 21h
CODE ENDS
END START
