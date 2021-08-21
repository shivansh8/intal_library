# intal_library
Developing a C library for the integers of arbitrary length (intal).
intal: An intal is a nonnegative integer of arbitrary length, but it is sufficient for your implementation to support up to 1000 decimal digits. The integer is stored as a null-terminated string of ASCII characters. An intal is represented as a string of decimal digits ('0' thru '9') that are stored in the big-endian style. That is, the most significant digit is at the head of the string. An integer 25, for example, is stored in a string s as '2' at s[0], '5' at s[1], and null char at s[2]. <br />

The functions include arithmetic operations, power and gcd between 2 intals, fibonacci , factorial and binary coefficient returning intals and finding maximum,minimum,searching,sorting  and a coin row problem on a array of intals.


How to run: gcc -Wall library.c intal_sampletest.c -o lib.out <br />
            ./lib.out
