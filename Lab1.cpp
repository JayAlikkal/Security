#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "test.txt"; // Replace with the path to your text file
    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    const int byteCount = 256;
    int byteFrequency[byteCount] = {0};

    char byte;
    while (file.get(byte)) {
        byteFrequency[static_cast<unsigned char>(byte)]++;
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
