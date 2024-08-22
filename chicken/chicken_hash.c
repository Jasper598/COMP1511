////////////////////////////////////////////////////////////////////////////////
// CP1521 22T1 --- Assignment 2: `chicken', a simple file archiver            //
// <https://www.cse.unsw.edu.au/~dp1092/22T1/assignments/ass2/index.html>     //
//                                                                            //
// 2022-14-03   v1.0                                                          //
//                                                                            //
///////////////////// YOU DO NOT NEED TO MODIFY THIS FILE. /////////////////////

////////////////////////////// DO NOT CHANGE THIS FILE. //////////////////////////////
// THIS FILE IS NOT SUBMITTED AND WILL BE PROVIDED AS IS DURING TESTING AND MARKING //
////////////////////////////// DO NOT CHANGE THIS FILE. //////////////////////////////

#include <stdio.h>
#include <stdint.h>

// DO NOT CHANGE THIS FUNCTION - use it to calculate egglet hashes (subsets 1, 2, and 3)

//
// The djb2-xor hash: hash(i) = hash(i - 1) * 33 ^ str[i];
// For more information  http://www.cse.yorku.ca/~oz/hash.html
//
// egglet_hash(), given the current hash value and a byte value, returns the new hash value
// An egglet hash is calculated by calling egglet_hash once for each byte in the egglet except the last byte
// current_hash_value should be zero, for the first byte in the egglet

uint8_t egglet_hash(uint8_t current_hash_value, uint8_t byte_value) {
    return ((current_hash_value * 33) & 0xff) ^ byte_value;
}

////////////////////////////// DO NOT CHANGE THIS FILE. //////////////////////////////
// THIS FILE IS NOT SUBMITTED AND WILL BE PROVIDED AS IS DURING TESTING AND MARKING //
////////////////////////////// DO NOT CHANGE THIS FILE. //////////////////////////////
