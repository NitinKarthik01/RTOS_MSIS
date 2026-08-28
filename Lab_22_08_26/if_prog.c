int main()
{
    int a = 5;
    int b = 10;
    if(a==0)
    {
        a = a+10;
    }
    b = a;
}


/*
   0:   b480            push    {r7}    -> pushing content of r7 to stack memory as a back up
   2:   b083            sub     sp, #12    -> we are creating space for the local variables in stack
   4:   af00            add     r7, sp, #0    -> and referring r7 to the adrees where stack pointer is there to access the created space 
    int a = 5;
   6:   2305            movs    r3, #5
   8:   607b            str     r3, [r7, #4]
    int b = 10;
   a:   230a            movs    r3, #10
   c:   603b            str     r3, [r7, #0]
    if(a==0)
   e:   687b            ldr     r3, [r7, #4]
  10:   2b00            cmp     r3, #0    -> we are comapring the value at [r7,#4] with zero
  12:   d102            bne.n   1a <main+0x1a>    -> branch if not equals to : jump to 1a
    {
        a = a+10;
  14:   687b            ldr     r3, [r7, #4]
  16:   330a            adds    r3, #10
  18:   607b            str     r3, [r7, #4]
    }
    b = a;
  1a:   687b            ldr     r3, [r7, #4]
  1c:   603b            str     r3, [r7, #0]
  1e:   2300            movs    r3, #0   -> the main function is of int, so it should return a value, so by default based on the compiler it make the register to zero now 
  20:   4618            mov     r0, r3   -> and after the retun statment executes it makes the r0 register to zero
  22:   370c            adds    r7, #12  -> it goes back again to the staring position after clearing the space 
  24:   46bd            mov     sp, r7   -> sp point to the address of r7 and access the content of r7 it initially stored as backup
  26:   bc80            pop     {r7}     -> now it pops the ocntents of r7 and places back in r7 register
  28:   4770            bx      lr       -> it goes back to the link register address( the caller of the function)
  
  */