#ifndef KRYPTER_UTIL_H
#define KRYPTER_UTIL_H

extern const char *b64_chars;

int hex_to_bytes(const char *hex_string, unsigned char *byte_array, size_t byte_array_length);
size_t get_b64_len(size_t input_len);
char *bytes_to_b64(const unsigned char *byte_array, size_t byte_array_len);
int hex_to_b64(const char *hex_string, char **b64_string);
int f_xor(const char *hex_arg1, const char *hex_arg2, char* hex_result, size_t fixed_length);

#endif /* KRYPTER_UTIL_H */