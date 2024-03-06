#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <openssl/md5.h>

void md5_hash(const uint8_t *data, size_t length, uint8_t hash[MD5_DIGEST_LENGTH]) {
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, data, length);
    MD5_Final(hash, &ctx);
}

int main() {
    const char *input = "Hello, MD5!";
    uint8_t hash[MD5_DIGEST_LENGTH];

    md5_hash((const uint8_t*)input, strlen(input), hash);

    printf("Input: %s\n", input);
    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
