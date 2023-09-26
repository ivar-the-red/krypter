#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "util.h"


int main(int argc, char **argv)
{
    // const char *input_hex = "deadbeef";

    // printf("Bytes allocated to array for \"%s\" = %d\n", "deadbeef", hex_to_b64("deadbeef"));

    // unsigned char byte_arr[4];
    // size_t byte_arr_size = sizeof(byte_arr) / sizeof(byte_arr[0]);

    // int num_bytes = 0;
    // num_bytes = hex_to_bytes(input_hex, byte_arr, byte_arr_size);

    // printf("There were %d bytes written.\n", num_bytes);

    // printf("Bytes needed for %d is %zu.\n", 8, get_b64_len(8));
    // printf("Bytes needed for %d is %zu.\n", 16, get_b64_len(16));

    // char *b64_result = bytes_to_b64(byte_arr, byte_arr_size);

    // printf("Converting \"%s\" to base64 yeilds \"%s\".\n", input_hex, b64_result);

    // //Cryptopals data
    // const char *cp_hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    // unsigned char cp_byte_array[48];
    // size_t cp_byte_arr_size = sizeof(cp_byte_array) / sizeof(cp_byte_array[0]);
    // printf("cp_byte_array_size =  %zu\n", cp_byte_arr_size);
    // int bytes_written = 0;

    // bytes_written = hex_to_bytes(cp_hex, cp_byte_array, cp_byte_arr_size);
    // printf("Translating from hex wrote %d bytes.\n", bytes_written);
    // char *cp_b64_result = bytes_to_b64(cp_byte_array, cp_byte_arr_size);

    // printf("Converting \"%s\" to base64 yeilds \"%s\".\n", cp_hex, cp_b64_result); //WRONG RESULT - DEBUG

    const char *in_hex = "deadbeef";
    char *out_b64, *cp_b64;

    int result = hex_to_b64(in_hex, &out_b64);

    printf("Converting \"%s\" to base64 yeilds \"%s\".\n Output code was %d\n", in_hex, out_b64, result);

    const char *cp_hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

    result = hex_to_b64(cp_hex, &cp_b64);
    printf("Converting \"%s\" to base64 yeilds \"%s\".\n Output code was %d\n", cp_hex, cp_b64, result);
    
    free(out_b64);
    return EXIT_SUCCESS;
}