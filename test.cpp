#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "sample.txt"; // Replace with the path to your text file
    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    const int byteCount = 256;
    int byteFrequency[byteCount] = {0};

    unsigned char byte;
    while (file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
        byteFrequency[byte]++;
    }

    file.close();

    cout << "Byte frequencies in the file:" << endl;
    for (int i = 0; i < byteCount; ++i) {
        char character = static_cast<char>(i);
        cout << character << ": " << byteFrequency[i] << " | ";

        // Display the frequency as vertical bars
        for (int j = 0; j < byteFrequency[i]; ++j) {
            cout << "#";
        }

        cout << endl;
    }

    return 0;
}
