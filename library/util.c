#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "util.h"

const char *b64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int hex_to_bytes(const char *hex_string, unsigned char *byte_array, size_t byte_array_length)
{
    size_t hex_len = strlen(hex_string);

    if (hex_len % 2 != 0)
        return -1;     //Hex string must have even digits to be valid

    if (hex_len / 2 > byte_array_length)
        return -2;  //Hex string must be able to fit inside byte_array

    size_t total_bytes_written = 0;
    for (size_t i = 0; i < hex_len; i += 2)
    {
        unsigned int val = 0;
        size_t bytes_written = 0;
        bytes_written = sscanf(&hex_string[i], "%2x", &val);

        if (bytes_written != 1) return -3; //Error converting to bytes
        else total_bytes_written += bytes_written;

        byte_array[i / 2] = val;
    }
    
    return (int)total_bytes_written;
}

size_t get_b64_len(size_t input_len)
{
    size_t ret = input_len;

    if (input_len % 3 != 0)
        ret += 3 - (input_len % 3);     //If not a multiple of 3, round up to nearest one.
    
    ret /= 3;
    ret *= 4;
    return ret;
}

char *bytes_to_b64(const unsigned char *byte_array, size_t byte_array_len)
{
    size_t b64_len = get_b64_len(byte_array_len);
    char *b64_string = (char *)malloc(b64_len * sizeof(char) + 1);  //+ 1 to house the null byte terminator
    b64_string[b64_len] = '\0';         //Null terminate the string
    size_t i = 0, j = 0, v = 0;

    for (i = 0, j = 0; i < byte_array_len; i+= 3, j += 4)
    {
        v = byte_array[i];
        v = i + 1 < byte_array_len ? v << 8 | byte_array[i + 1] : v << 8;
        v = i + 2 < byte_array_len ? v << 8 | byte_array[i + 2] : v << 8;   

        b64_string[j] = b64_chars[(v >> 18) & 0x3F];    //Not 100% happy. Why have to & with 0x3F (to get rid of leading zeros?)
        b64_string[j + 1] = b64_chars[(v >> 12) & 0x3F];

        if (i+1 < byte_array_len) {
	        b64_string[j+2] = b64_chars[(v >> 6) & 0x3F];
        } else {
	        b64_string[j+2] = '=';
        }

        if (i+2 < byte_array_len) {
	        b64_string[j+3] = b64_chars[v & 0x3F];
        } else {
	        b64_string[j+3] = '=';
        }
    }
    return b64_string;
}

int hex_to_b64(const char *hex_string, char **b64_string)
{
    size_t hex_str_len = strlen(hex_string);
    size_t byte_arr_size = hex_str_len / 2;
    unsigned char *byte_arr = (unsigned char *)malloc(byte_arr_size * sizeof(char));

    int res = 0;    //If positive it contains the number of bytes written, if negative it is an error code
    res = hex_to_bytes(hex_string, byte_arr, byte_arr_size);

    if ((res < 0))                  //If an error occured, return the error code
    {
        free(byte_arr);
        return res; 
    }

    if ((int)byte_arr_size != res)  //Error: bytes written and array size do not match
    {
        free(byte_arr);
        return -4;
    }

    *b64_string = bytes_to_b64(byte_arr, byte_arr_size);

    free(byte_arr);
    return res;
}
