#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i;
    // Convert the key to uppercase
    for (i = 0; key[i] != '\0'; i++) {
        key[i] = toupper(key[i]);
    }
    // Encrypt the plaintext
    while (*plaintext) {
        char currentChar = toupper(*plaintext);
        if (isalpha(currentChar)) {
            *ciphertext = key[currentChar - 'A'];
        } else {
            *ciphertext = *plaintext;
        }
        plaintext++;
        ciphertext++;
    }
    *ciphertext = '\0';  // Null-terminate the ciphertext string
}

void decrypt(char *ciphertext, char *key, char *decryptedText) {
    char reverseKey[26];
    int i;
    // Create reverse key for decryption
    for (i = 0; i < 26; i++) {
        reverseKey[key[i] - 'A'] = 'A' + i;
    }

    // Decrypt the ciphertext
    while (*ciphertext) {
        char currentChar = toupper(*ciphertext);
        if (isalpha(currentChar)) {
            *decryptedText = reverseKey[currentChar - 'A'];
        } else {
            *decryptedText = *ciphertext;
        }
        ciphertext++;
        decryptedText++;
    }
    *decryptedText = '\0';  // Null-terminate the decrypted text string
}

int main() {
    char plaintext[100];
    char key[] = "zyxwvutsrqponmlkjihgfedcba"; // Example key for simple substitution
    char ciphertext[100];
    char decryptedText[100];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext); // Reads a single word (up to space)

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}

