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
    int byteFrequency[byteCount] = { 0 };

    char byte;
    while (file.get(byte)) {
        byteFrequency[static_cast<unsigned char>(byte)]++;
    }

    file.close();

    int maxFrequency = 0;
    for (int i = 0; i < byteCount; ++i) {
        if (byteFrequency[i] > maxFrequency) {
            maxFrequency = byteFrequency[i];
        }
    }

    // Print the top border
    cout << "+";
    for (int i = 0; i < byteCount * 2; ++i) {
        cout << "-";
    }
    cout << "+" << endl;

    for (int row = maxFrequency; row > 0; --row) {
        cout << "|";
        for (int i = 0; i < byteCount; ++i) {
            if (byteFrequency[i] >= row) {
                cout << "# ";
            }
            else {
                cout << "  "; // Two spaces for characters without frequency
            }
        }
        cout << "|" << endl;
    }

    // Print the bottom border
    cout << "+";
    for (int i = 0; i < byteCount * 2; ++i) {
        cout << "-";
    }
    cout << "+" << endl;

    // Print characters on the x-axis
    cout << "|";
    for (int i = 0; i < byteCount; ++i) {
        char character = static_cast<char>(i);
        cout << character << ' ';
    }
    cout << "|" << endl;

    return 0;
}
