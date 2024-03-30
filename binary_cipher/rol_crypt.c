#include "binary_cipher.h"

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    unsigned char *tmp_data = data;
    const unsigned char *tmp_key = key;

    for (size_t i = 0; i < data_len; i++)
    {
        tmp_data[i] += tmp_key[i % key_len];
    }
}
