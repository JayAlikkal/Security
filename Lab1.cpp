#include <iostream>
#include <fstream>

using namespace std;

const int byteCount = 256;

// Function to generate the histogram
void generateHistogram(const int byteFrequency[]) {
    int maxFrequency = 0;
    for (int i = 0; i < byteCount; ++i) {
        if (byteFrequency[i] > maxFrequency) {
            maxFrequency = byteFrequency[i];
        }
    }

    // Calculate the scaling factor
    double scale = (maxFrequency > 0) ? static_cast<double>(20) / maxFrequency : 1.0;

    // Print the top border
    cout << "+";
    for (int i = 0; i < byteCount * 2; ++i) {
        cout << "-";
    }
    cout << "+" << endl;

    for (int row = 20; row > 0; --row) {
        cout << "|";
        for (int i = 0; i < byteCount; ++i) {
            int scaledValue = static_cast<int>(byteFrequency[i] * scale);
            if (scaledValue >= row) {
                cout << "# ";
            }
            else {
                cout << "  ";
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
}

int main() {
    string filename = "Hamlet.txt";
    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    int byteFrequency[byteCount] = { 0 };
    char byte;
    while (file.get(byte)) {
        byteFrequency[static_cast<unsigned char>(byte)]++;
    }

    file.close();

    generateHistogram(byteFrequency);

    return 0;
}
