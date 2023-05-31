.include "/home/narendra/arduino/assembly/7447/io/codes/m328pdef.inc"
 ldi r26 ,0b00000101;
 out TCCR0B,r26
 ldi r16,0b00001000;3 pin y out
 out DDRD,r16
 ldi r16,0b11111111;
 out PORTD,r16
 ldi r30,0b00000000 ;q1
 ldi r31,0b00000000 ;q2
start:
     ldi r19,0b00000001;8 pin out
     out DDRB,r19
     ldi r20,0b00000000;8 pin
     out DDRB,r20
     out PORTB,r19 ;8 PIN HIGH
     rcall delay
	 in r17,PIND
	 out PORTB,r20 ;8 pin low
	 rcall delay; add delay to provide time for input
	 ; call delay function using rcall 
	 bst r17,7
	 bld r23,0
	mov r21,r30 ;p
	mov r22,r31 ;q 
	mov r29,r23 ;x
	
	and r21,r29 ;px
	mov r16,r21 ; y=px
	lsl r16
	lsl r16
	lsl r16
	out PORTD,r16
	rcall delay ;add delay
	lsr r16
	lsr r16
	lsr r16
	com r22 ;!q
	and r22 ,r29 ;!qx
	mov r24, r22 ; d1=!qx
  
  mov r25,r29 ;d2 ;x
  mov r30,r24 ;d1=q1
  mov r31,r25 ;d2=q2
  rjmp start
  
 ;place delay function or rotuine here

 delay:
 ldi r27,0b01000000;  ;64 times 1 sec delay
 PAUSE:
 lp2:
   in r26,TIFR0 ; tifr is timer interupt flag
   ldi r28,0b00000010
   and r26,r28 ;need second bit
   BREQ PAUSE
   out TIFR0,r28 ;set tifr flag high
   dec r27
   brne lp2
   ret
 
