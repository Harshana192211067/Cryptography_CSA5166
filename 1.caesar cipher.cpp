#include <stdio.h>
#include <ctype.h>

void caesarCipher(char* text, int k) {
    int i = 0;
    char ch;

    // Loop through each character in the text
    while (text[i] != '\0') {
        ch = text[i];

        // If the character is an uppercase letter
        if (isupper(ch)) {
            text[i] = (ch - 'A' + k) % 26 + 'A';
        }
        // If the character is a lowercase letter
        else if (islower(ch)) {
            text[i] = (ch - 'a' + k) % 26 + 'a';
        }
        // Move to the next character
        i++;
    }
}

void caesarDecipher(char* text, int k) {
    int i = 0;
    char ch;

    // Loop through each character in the text
    while (text[i] != '\0') {
        ch = text[i];

        // If the character is an uppercase letter
        if (isupper(ch)) {
            text[i] = (ch - 'A' - k + 26) % 26 + 'A'; // Add 26 to handle negative shift
        }
        // If the character is a lowercase letter
        else if (islower(ch)) {
            text[i] = (ch - 'a' - k + 26) % 26 + 'a'; // Add 26 to handle negative shift
        }
        // Move to the next character
        i++;
    }
}

int main() {
    char text[100];
    int k;

    // Input the plaintext
    printf("Enter the plaintext: ");
    gets(text); // Use fgets instead of gets for safer input

    // Input the shift value k
    printf("Enter the shift value (k): ");
    scanf("%d", &k);

    // Encrypt the text using Caesar cipher
    caesarCipher(text, k);
    printf("Ciphertext: %s\n", text);

    // Decrypt the text using Caesar cipher
    caesarDecipher(text, k);
    printf("Decrypted text: %s\n", text);

    return 0;
}

