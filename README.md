# Dictionary Code Compressor

By Sasha Morgan

##Project Description

This program compresses and decrompress data, while utilizing the Treap Data Structure.

In compression mode (without the -d flag), the program reads the input text file, which consists of space separated words with no punctuation, and for each unique word assigns it an unsigned 32 bit integer > 0, storing the resulting key and value in a TreapBST. It then serializes the dictionary into a binary file as a series of integer-string pairs, packed back-to-back, writing a zero integer to indicate the end of the dictionary. The strings are written as c-style strings, one byte at a time with a terminating null (0 char). It then converts the input text file into a sequence of integers, with each word replaced by it's corresponding integer, and appended to the binary file.

In decompression mode (with the -d flag), the program reads a binary file as produced above and reverses the process, writing a text file. In a round trip from input text file to compressed binary file, back to output text file, the input and output should be identical. The size of the text file compared to the binary file determines the compression ratio.
