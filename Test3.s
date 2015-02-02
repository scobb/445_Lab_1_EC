;Version 3 assembly floating point
; run with floating-point hardware active
 AREA DATA, ALIGN=2
T SPACE 4
N SPACE 4
 AREA |.text|, CODE, READONLY, ALIGN=2
 THUMB
NVIC_CPAC_R equ 0xE000ED88
 global Test3
Test3
 LDR R0, =NVIC_CPAC_R
 LDR R1, [R0] ; Read CPACR
 ORR R1, R1, #0x00F00000  ; Set bits 20-23 to enable CP10 and CP11 coprocessors
 STR R1, [R0]
 MOV R0,#0
 LDR R1,=N ;pointer to N
 LDR R2,=T ;pointer to T
 VLDR.F32 S1,=0.009768
 VLDR.F32 S2,=10
loop3 STR R0,[R1] ; N is volatile
 VMOV.F32 S0,R0
 VCVT.F32.U32 S0,S0 ; S0 has N
 VMUL.F32 S0,S0,S1 ; N*0.09768
 VADD.F32 S0,S0,S2 ; 10+N*0.0968
 VSTR.F32 S0,[R2] ; T=10+N*0.0968
 ADD R0,R0,#1
 CMP R0,#4096
 BNE loop3
 BX LR 
 END