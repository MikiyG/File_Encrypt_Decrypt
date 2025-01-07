#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt a file
void encryptFile(const string &inputFile, const string &outputFile, char key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error: Cannot open output file." << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        outFile.put(ch ^ key); // XOR encryption
    }

    inFile.close();
    outFile.close();
    cout << "File encrypted successfully!" << endl;
}

// Function to decrypt a file
void decryptFile(const string &inputFile, const string &outputFile, char key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error: Cannot open output file." << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        outFile.put(ch ^ key); // XOR decryption (same as encryption)
    }

    inFile.close();
    outFile.close();
    cout << "File decrypted successfully!" << endl;
}

int main() {
    char choice;
    string inputFile, outputFile;
    char key;

    do {
        cout << "\nFile Encryption and Decryption Menu:" << endl;
        cout << "A. Encrypt a file" << endl;
        cout << "B. Decrypt a file" << endl;
        cout << "Q. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (toupper(choice)) {
            case 'A':
                cout << "Enter the input file name to encrypt: ";
                cin >> inputFile;
                cout << "Enter the output file name for encrypted data: ";
                cin >> outputFile;
                cout << "Enter a single-character encryption key: ";
                cin >> key;
                encryptFile(inputFile, outputFile, key);
                break;

            case 'B':
                cout << "Enter the input file name to decrypt: ";
                cin >> inputFile;
                cout << "Enter the output file name for decrypted data: ";
                cin >> outputFile;
                cout << "Enter the decryption key: ";
                cin >> key;
                decryptFile(inputFile, outputFile, key);
                break;

            case 'Q':
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (toupper(choice) != 'Q');

    return 0;
}
