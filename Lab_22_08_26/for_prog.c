int main(void)
{
    int sum=0;
    int i;
    for(i=1; i<=10; i++)
    {
        sum=sum+i;
    }
    return 0;
}


/*
   0:   b480            push    {r7}
   2:   b083            sub     sp, #12
   4:   af00            add     r7, sp, #0
    int sum=0;
   6:   2300            movs    r3, #0
   8:   607b            str     r3, [r7, #4]
    int i;
    for(i=1; i<=10; i++)
   a:   2301            movs    r3, #1
   c:   603b            str     r3, [r7, #0]
   e:   e006            b.n     1e <main+0x1e>   -> here the i=0, it is an unconditional jump statement so it jumps to '1e' to check the condition if i<=10
    {
        sum=sum+i;
  10:   687a            ldr     r2, [r7, #4]
  12:   683b            ldr     r3, [r7, #0]
  14:   4413            add     r3, r2
  16:   607b            str     r3, [r7, #4]
    for(i=1; i<=10; i++)
  18:   683b            ldr     r3, [r7, #0]
  1a:   3301            adds    r3, #1
  1c:   603b            str     r3, [r7, #0]
  1e:   683b            ldr     r3, [r7, #0]     -> the condition checking starts here
  20:   2b0a            cmp     r3, #10          -> the condition is checked
  22:   ddf5            ble.n   10 <main+0x10>   -> branch if less than or equal to then it jumps to line '10' and execution start, this process will continue untill the iteration fails
    }
    return 0;
  24:   2300            movs    r3, #0
  26:   4618            mov     r0, r3
  28:   370c            adds    r7, #12
  2a:   46bd            mov     sp, r7
  2c:   bc80            pop     {r7}
  2e:   4770            bx      lr
*/