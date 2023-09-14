#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int byteCount = 256;

// Function to generate the histogram
void generateHistogram(const int byteFrequency[], int ratio) {
    int maxFrequency = 0;
    for (int i = 0; i < byteCount; ++i) {
        if (byteFrequency[i] > maxFrequency) {
            maxFrequency = byteFrequency[i];
        }
    }

    // Calculate the scaling factor
    double scale = (maxFrequency > 0) ? static_cast<double>(ratio) / maxFrequency : 1.0;

    // Print the top border
    cout << "+";
    for (int i = 0; i < byteCount * 2; ++i) {
        cout << "-";
    }
    cout << "+" << endl;

    for (int row = ratio; row > 0; --row) {
        cout << "|";
        for (int i = 0; i < byteCount; ++i) {
            int scaledValue = static_cast<int>(byteFrequency[i] * scale);
            if (scaledValue >= row) {
                cout << "* ";
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


}

void PrintCharacter() {
    // Print characters on the x-axis
    cout << "|";
    for (int i = 0; i < byteCount; ++i) {
        char character = static_cast<char>(i);
        if (character > 33 && character < 127) {
            cout << character;
        }
        else {
            cout << " ";
        }
    }
    cout << "|" << endl;
}


void printAllASCIICharacters() {
    int counter = 0;
    for (int i = 0; i <= 255; ++i) {
        // Calculate ASCII value digits
        int hundreds = i / 100;
        if (hundreds == 0) {
            cout << " ";
        }
        else {
            std::cout << hundreds;
        }
       
    }cout << endl;
    for (int i = 0; i <= 255; ++i) {
        // Calculate ASCII value digits
        int tens = (i / 10) % 10;

        // Print hundreds, tens, and ones vertically
        std::cout << tens;
    }cout << endl;
    for (int i = 0; i <= 255; ++i) {
        // Calculate ASCII value digits
        int ones = i % 10;

        // Print hundreds, tens, and ones vertically
        std::cout << ones;
        counter++;
    }cout << endl;
    for (int i = 0; i <= 255; ++i) {
        // Print the character
        char character = static_cast<char>(i);
        if (character > 33 && character < 127) {
            cout << character;
        }
        else {
            cout << " ";
        }
    }cout << endl;

    cout << counter;
   
}




int main(int argc, char* argv[]) {

    int ratio = 20;
  

    string flag = "-a"; // Get the flag from the command-line argument (if provided)
    string filename = "Hamlet.txt"; // Get the filename from the command-line argument

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

    if (flag == "-a") {
        // shows ASCII characters (if printable) along the X-axis
        printAllASCIICharacters();
    }
    else if (flag == "-g") {
        // show no graph
        cout << "stat";
    }
    else if (flag == "-n") {
        // shows 0-255 along the X-axis (in three rows)
    }
    else if (flag.substr(0, 2) == "-r") {
        //set the sacle of histagram to the value after -r example -r54
        int setratio = atoi(flag.substr(2).c_str());
        generateHistogram(byteFrequency, setratio);
        PrintCharacter();
    }
    else {
        // If no flag is provided, generate the histogram
        generateHistogram(byteFrequency, ratio);
    }

    return 0;
}