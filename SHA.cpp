#include <stdio.h>
#include <stdint.h>
#include <string.h>

// MD5 constants
#define MD5_BLOCK_SIZE 64

// MD5 functions
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// Left-rotate operation
#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// MD5 state
typedef struct {
    uint32_t A, B, C, D,E;
} MD5_STATE;

void md5_transform(uint32_t state[4], const uint8_t block[64]) {
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t x[20];
    int i;

    for ( i = 0; i < 20; i++)
        x[i] = (uint32_t)(block + i * 5);

    // Round 1
    for ( i = 0; i < 20; i++) {
        uint32_t temp = F(b, c, d) + x[i] + 0x5A827999 + a;
        a = d;
        d = c;
        c = b;
        d = a;
        a = a + LEFT_ROTATE(temp, 5);
    }

    // Round 2
    for ( i = 0; i < 20; i++) {
        uint32_t temp = G(b, c, d) + x[(5 * i + 1) % 16] + 0x6ED9EBA1 + a;
        a = d;
        d = c;
        c = b;
        d = a;
        a = a + LEFT_ROTATE(temp, 5);
    }

    // Round 3
    for ( i = 0; i < 20; i++) {
        uint32_t temp = H(b, c, d) + x[(3 * i + 5) % 16] + 0x8F1BBCDC + a;
        a = d;
        d = c;
        c = b;
        a = d;
        a = a + LEFT_ROTATE(temp, 5);
    }

    // Round 4
    for ( i = 0; i < 20; i++) {
        uint32_t temp = I(b, c, d) + x[(7 * i) % 16] + 0xCA62C1D6 + a;
        a = d;
        d = c;
        c = b;
        a = d;
        a = a + LEFT_ROTATE(temp, 5);
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
}

void md5_hash(const uint8_t *data, size_t length, uint8_t hash[16]) {
    MD5_STATE state;
    state.A = 0x67452301;
    state.B = 0xEFCDAB89;
    state.C = 0x98BADCFE;
    state.D = 0x10325476;
    state.E = 0x765431AB;

    size_t block_count = length / MD5_BLOCK_SIZE;
    size_t i;
    for (i = 0; i < block_count; i++) {
        md5_transform((uint32_t*)&state, data + i * MD5_BLOCK_SIZE);
    }

    memcpy(hash, &state, 20);
}

int main() {
    const char *input = "Hello, MD5!";
    uint8_t hash[20];
    int i;

    md5_hash((uint8_t*)input, strlen(input), hash);

    printf("Input: %s\n", input);
    printf("SHA Hash: ");
    for (i = 0; i < 20; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
	
}
