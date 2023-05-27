#include <iostream>
#include <sstream>
#include <windows.h>
#include <vector>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

void svenska() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
}

struct Color {
	string redString;
	string greenString;
	string blueString;
	string name;

	int red;
	int green;
	int blue;
	Color(int r, int g, int b, const string& n) // konstruktor;
		: red(r), green(g), blue(b), name(n) {};
	Color() {};


};
Color colorArr[] = {
	{ 192, 192, 192, "Silver" },
	{ 0, 0, 0, "Black" },
	{ 128, 128, 0, "Olive" },
	{ 154, 205, 0, "Yellow green" },
	{ 255, 222, 173, "Navajo white" },
	{ 176, 224, 230, "Powder blue" }
};

void colorDistance(int red, int green, int blue) {
	float distance = 5000;
	float distanceCl;
	int redMatch;
	int greenMatch;
	int blueMatch;
	string nameMatch;
	for (int i = 0; i < 6; i++) {
		int redDiff = red - colorArr[i].red;
		int greenDiff = green - colorArr[i].green;
		int blueDiff = blue - colorArr[i].blue;

		distanceCl = sqrt(redDiff * redDiff + greenDiff * greenDiff + blueDiff * blueDiff);
		if (distanceCl < distance) {
			distance = distanceCl;
			redMatch = colorArr[i].red;
			greenMatch = colorArr[i].green;
			blueMatch = colorArr[i].blue;
			nameMatch = colorArr[i].name;
		}
		else {
			continue;
		}

	}
		
	cout << "Närmast matchande färg är:  " << nameMatch << "  (" << redMatch << "," << greenMatch << "," << blueMatch <<")  " << "#" << hex << redMatch  << hex << greenMatch << hex << blueMatch << endl;
	
}





int main() {
	Color colorStruct;
	svenska();
	bool run = true;
	while (run) {
		string color;
		cout << "Ange önskad färg (R, G, B) som tre heltal 0-255 med mellanslag mellan: ";
		getline(cin, color);

		stringstream ss(color);
		ss >> colorStruct.redString;
		ss >> colorStruct.greenString;
		ss >> colorStruct.blueString;

		colorStruct.red = stoi(colorStruct.redString);
		colorStruct.green = stoi(colorStruct.greenString);
		colorStruct.blue = stoi(colorStruct.blueString);

		colorDistance(colorStruct.red, colorStruct.green, colorStruct.blue);
		cout << "\n";
	}

}