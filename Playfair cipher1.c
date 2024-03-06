#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void generatePlayfairMatrix(const char *key, char matrix[SIZE][SIZE]) {
int keyLen = strlen(key);
int i, j, k;
int isUsed[26] = {0};
for (i = 0, k = 0; i < keyLen; i++) {
if (!isUsed[key[i] - 'A']) {
matrix[k / SIZE][k % SIZE] = key[i];
isUsed[key[i] - 'A'] = 1;
k++;
}
}
for (j = 0; j < 26; j++) {
if (!isUsed[j] && j != ('J' - 'A')) {
matrix[k / SIZE][k % SIZE] = j + 'A';
k++;
}
}
}
void findPosition(const char matrix[SIZE][SIZE], char ch, int *row, int *col) {
int i, j;
for (i = 0; i < SIZE; i++) {
for (j = 0; j < SIZE; j++) {
if (matrix[i][j] == ch) {
*row = i;
*col = j;
return;
}
}
}
}
void playfairEncrypt(const char matrix[SIZE][SIZE], char plain1, char plain2, char *cipher1, char *cipher2) {
int row1, col1, row2, col2;
findPosition(matrix, plain1, &row1, &col1);
findPosition(matrix, plain2, &row2, &col2);
if (row1 == row2) {
*cipher1 = matrix[row1][(col1 + 1) % SIZE];
*cipher2 = matrix[row2][(col2 + 1) % SIZE];
}
else if (col1 == col2) {
*cipher1 = matrix[(row1 + 1) % SIZE][col1];
*cipher2 = matrix[(row2 + 1) % SIZE][col2];
}
else {
*cipher1 = matrix[row1][col2];
*cipher2 = matrix[row2][col1];
}
}

int main() {
char matrix[SIZE][SIZE];
char keyword[26];
char plaintext[100];
char ciphertext[100] = "";
int i, j;
printf("Enter the keyword (uppercase letters, no spaces): ");
scanf("%s", keyword);
for (i = 0; keyword[i]; i++)
keyword[i] = toupper(keyword[i]);
generatePlayfairMatrix(keyword, matrix);
printf("Enter the plaintext (uppercase letters, no spaces): ");
scanf("%s", plaintext);
for (i = 0; plaintext[i]; i++)
plaintext[i] = toupper(plaintext[i]);
for (i = 0; plaintext[i]; i += 2) {
char cipher1, cipher2;
if (plaintext[i + 1] == '\0') {
playfairEncrypt(matrix, plaintext[i], 'X', &cipher1, &cipher2);
}
else if (plaintext[i] == plaintext[i + 1]) {
playfairEncrypt(matrix, plaintext[i], 'X', &cipher1, &cipher2);
i--;
}
else {
playfairEncrypt(matrix, plaintext[i], plaintext[i + 1], &cipher1, &cipher2);
}
strncat(ciphertext, &cipher1, 1);
strncat(ciphertext, &cipher2, 1);
}
printf("Encrypted ciphertext: %s\n", ciphertext);
return 0;
}
