#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "util.h"


int main(int argc, char **argv)
{
    // const char *in_hex = "deadbeef";
    // char *out_b64;

    // int result_test = hex_to_b64(in_hex, &out_b64);

    // printf("Converting \"%s\" to base64 yeilds \"%s\".\n Output code was %d\n", in_hex, out_b64, result_test);

    // free(out_b64);

    const char *cp_hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char *cp_b64;

    int result = hex_to_b64(cp_hex, &cp_b64);
    printf("Converting \"%s\" to base64 yeilds \"%s\".\n Output code was %d\n", cp_hex, cp_b64, result);
    
    free(cp_b64);
    return EXIT_SUCCESS;
}