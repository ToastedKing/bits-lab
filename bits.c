/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
       int eightBit = 0x55; // makes a even 8 bit
       int sixTeenBit = eightBit << 8; // makes room for an 16 bit number
       int sixTeenBitnew = sixTeenBit + eightBit; // takes the 4 bit and expans it to an 8 bit
       int thrityTwoBit = sixTeenBitnew << 16; // makes room for an 32 bit
       int thrityTwoBitnew = thrityTwoBit + sixTeenBitnew; // takes the 16 bit to expamd it to a 32 bit 
       return thrityTwoBitnew; // return all even bit set to 1
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /*  int sum = x + y;
  int neg_over = x < 0 && y < 0 && sum >= 0; 
  int pos_over = x > = 0 && y >= 0 && sum < 0;
 return !neg_over && !pos_over; 
  */
  int sum =  x + y; // ads x and y
  int checkNeg = (~1 + 1); // makes a -1 to compare
  int checkSum = (sum >> 31 & checkNeg); // checks if sum is negative
  int checkX = (x >> 31 & checkNeg); // checks if x is negative
  int checkY = (y >> 31 & checkNeg); // checks if y is negative
  int posOver = (checkX & checkY) & !(checkSum); // checks if the out come is positive and over flow
  int negOver =  (!checkX & !checkY) & (checkSum); // checks if the out come is negative and over flow
  int compare =  !(posOver | negOver); // checks to see if there is over flow in the two 
  return compare; // returns result
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int zeroX = ((~(!!x)) << 31) >> 31; // makes x into 0 
  int oneX = (~(!x) << 31) >> 31;  // makes x into 1
  return (y & oneX) | (z & zeroX); // checks if x is 0 then return z. or if x is 1 return y
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {

  int mask = x >> 31; // checks the sign of x
  int pos = (x & ~mask); // compares x with the mask flipped 
  int neg = ((~x + 1) & mask); // compares the opposite x with the mask 
  int compare = (pos | neg); // compares to see which one is positive
  return compare; // returns result
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {  
  int compare = ( x >> 16) ^ x; // compares the upper half of x with the lower half
  compare = (compare >> 8 ) ^ compare; 
  compare = (compare >> 4) ^ compare;
  compare = (compare >> 2) ^ compare;
  compare = (compare >> 1) ^ compare;
  return (compare & 1); // returns 1 if x contains an odd number of 0's
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
  int lShift = x<<16; // shifts 16 to the left
  int rShift = lShift>>16; // shifts right 16 bits
  int isShort = rShift^x; // copmares the new bits with original x
  return !isShort; // returns 1 if x is with in range and 0 if x is out of range
  
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  return ((x << 31) >> 31); // shifts 31 to the left then right witch pads with the least sig dig
}
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  int eightBit = 0xAA; // makes a base case of odd bits
  int sixTeenBit = eightBit << 8; // shifts 8 bits to make it 16 bits
  int sixTeenBitNew = sixTeenBit + eightBit;// add previous odd bits into original bits
  int thrityTwoBit = sixTeenBitNew << 16;// shifts 16 to make it 32 bits
  int thrityTwoBitNew = thrityTwoBit + sixTeenBitNew;  // adds previous odd bits ito original bits
  return thrityTwoBitNew; 

}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int signX = x >> 31; // checks sign of x
  int signY = y >> 31;// checks sign of y

  int checkSign = signX & !signY; // checks signs
  int negCheck = !(signX ^ signY);  // checks for negative signs
  int signSum  = (x + ~y) >> 31; // checks the sign of the sum
  int checkNegSum = (negCheck & signSum); // checks if either one is negative
  int caseCheck = (checkSign | checkNegSum); // checks if y is greater
  return !caseCheck;  
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int topStart =  0x39; // max range
  int bottomStart = 0x30; // lowest range
  int upperBound =  ((topStart + (~x + 1))) >> 31; // checks if x is under the max range 
  int lowerBound =  (( x + (~bottomStart + 1 ))) >>  31; // checks if x is over the lowest range
  int compare =  (upperBound | lowerBound);  // checks if it is in range
  return (compare + 1); // returns true 
  }
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  int userInput = x; 
  int inverse = ~userInput + 1; // opposite of user input 
  int compare = inverse & userInput; // compares the inverse and the userinput
  return compare; // returns lest bit pos
  

 }
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
  int neg = 1 << 31; // mask with 1st bit negative
  int shiftX = (x >> 1) | x; // shift first bit and compares it with itself
  shiftX = (shiftX >> 2) | shiftX; // shifts 2 bits and compares it with itself 
  shiftX = (shiftX >> 4) | shiftX; // shifts 4 bits and compares it with itslef
  shiftX = (shiftX >> 8) | shiftX; // shifts 8 bits and compares it with itslef
  shiftX = (shiftX >> 16) | shiftX; // shifts 16 bits and compares it with itslef
  return (((~shiftX >> 1) ^ neg) & shiftX); // checks if it negative and compare it with itslef
  
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN (not a number), return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  
  int mask = 1 << 31; // makes a negative mask
  int neg = uf | mask; // returns a negative value no matter the agrument
  int nan = ((1 << 31) >> 9); // mask of not a number
  int num = (nan & neg); // forces nan to be negative
  if (num == nan) { // checks to see if it is in range
    return uf; // returns argument if it is NaN 
  } 
  else {
    return (neg ^ mask); // return abs of uf
  }
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  unsigned  sign = (uf  >> 31) & 1; // isolates sign and checks the sign

  int exp = (uf >> 23) & 0xFF; // isolates exponent
  int man = (uf & 0x7FFFFF); // isolates man

 
  int biasCompare = exp - 127; // makes new exponent with the diffrence of the bias


  if (exp == 0xFF || biasCompare > 0x20) { // checks if not a number and over flow
    return 0x80000000u;
  }


  if (biasCompare < 0 ){ // exponenet is less then bias (to the negative power)
    return 0 ;
  }


  if (biasCompare  == 0){ // power = 0 
    if (sign == 1){ // check sign
      return (~1) + 1;
    }
    return 1; 
  }


  if (man == 0 && biasCompare > 0){ // 1 to any power 
    if (sign == 1){ // checks sign
      return (~1) + 1;
    }
    return 1;
  }  
  
  if (biasCompare == 0 && man ==  0){ // no bits 
    return 0;
  }


  if (sign == 1 ){ // checks sign
    return ~(man << biasCompare ) + 1; // converts to base 10 integer 
  }


  return man << biasCompare; // converts to base 10 integer
}

/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int sign = (uf >> 31) << 31; // isolates sign
  int exp = (uf >> 23) & 0xFF; // checks if exp all 1's
  int man = (uf & 0x7FFFFF); // checks if man is all 1's but the first bit
  if (exp == 0xFF){ // if not a number return value
    return uf;
  }
  else if (exp > 1) { // exponent is more than 1 
    exp = (exp - 1); // lowers the power of the exponent ( / by 2) 
    return (sign | (exp << 23) | man); // returns half of the float
  }
  else {
    if (exp == 1){ 
      man = man | 1 << 23; // moves man into the eponent slot. adds a 1 to the faraction (normolizes)  
    }
    if ((man & 3) == 3 ) { 
      man++; // adds 1 to the man 
    }
    man = man >> 1; // divids the man by half ( / by 2)
    return sign | man; // returns half of the man
  }
  
}
