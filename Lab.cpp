#include <iostream>
#include <fstream>

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


}


void generateLogHistogram(const int byteFrequency[], int ratio) {
	int maxFrequency = 0;
	for (int i = 0; i < byteCount; ++i) {
		if (byteFrequency[i] > maxFrequency) {
			maxFrequency = byteFrequency[i];
		}
	}

	// Calculate the maximum log frequency
	double maxLogFrequency = 0.0;
	for (int i = 0; i < byteCount; ++i) {
		double logValue = log(static_cast<double>(byteFrequency[i]) + 1.0); // Adding 1 to avoid log(0)
		if (logValue > maxLogFrequency) {
			maxLogFrequency = logValue;
		}
	}

	// Calculate the scaling factor based on the maximum log frequency
	double scale = (maxLogFrequency > 0.0) ? static_cast<double>(ratio) / maxLogFrequency : 1.0;

	// Print the top border
	cout << "+";
	for (int i = 0; i < byteCount * 2; ++i) {
		cout << "-";
	}
	cout << "+" << endl;

	for (int row = ratio; row > 0; --row) {
		cout << "|";
		for (int i = 0; i < byteCount; ++i) {
			double logValue = log(static_cast<double>(byteFrequency[i]) + 1.0);
			int scaledValue = static_cast<int>(logValue * scale);
			if (scaledValue >= row) {
				std::cout << "* ";
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

}

int main() {

		
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
	generateHistogram(byteFrequency, 20);
	//generateLogHistogram(byteFrequency, 20);
	PrintCharacter();
	printAllASCIICharacters();

	cout << endl;

	int minFrequency = INT_MAX; // Initialize to a large value

	for (int i = 0; i < byteCount; ++i) {
		if (byteFrequency[i] > 0 && byteFrequency[i] < minFrequency) {
			minFrequency = byteFrequency[i];
		}
	}

	int maxFrequency = 0;
	char maxOccurringChar = '\0'; // Initialize to null character

	for (int i = 0; i < byteCount; ++i) {
		if (byteFrequency[i] > maxFrequency) {
			maxFrequency = byteFrequency[i];
			maxOccurringChar = static_cast<char>(i); // Convert index to character
		}
	}
	int sumFrequency = 0;

	for (int i = 0; i < byteCount; ++i) {
		sumFrequency += byteFrequency[i];
	}

	double averageValue = static_cast<double>(sumFrequency) / 256.0;


	cout << "MIN:" << minFrequency << " Max  (" << maxOccurringChar << "):" << maxFrequency << " AVG:" << averageValue << endl; //Min:NNNNNNNNN Max (CCC):NNNNNNNNN AVG:XXXXXXXXX DEV:XXXXXXXXX


	return 0;

}

	
	
