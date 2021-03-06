// MellingerHelping.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int CommaForNamePosition(std::string line)
{
	return line.find(',');
}

int CommaForAverageValuePosition(string line)
{
	int namePos = CommaForNamePosition(line);
	return line.find(',', namePos);
}

string GetAverageValueFromFileLine(string line)
{
	int posForName = CommaForNamePosition(line);
	int posForAverage = CommaForAverageValuePosition(line);
	string rawAverageValue = line.substr(posForName, posForAverage);
	return rawAverageValue;
}

string GetValueBetweenCommas(string line, int position)
{
	if (line[position] == ',')
		position++;
	int nextCommaPosition = line.find(',', position);
	string result = line.substr(position, nextCommaPosition);
	return result;
}

string GetScoresForLine(string lineWithScores)
{
	int initialPos = 0;
	while (true)
	{
		if (initialPos >= lineWithScores.length())
		{
			break;
		}
		cout<< GetValueBetweenCommas(lineWithScores, initialPos);
		initialPos = lineWithScores.find(',', initialPos + 1) + 1;
	}
	return "";
}


int main() {
	string line;	//Variable for line of string in TestData
	ifstream readData("TestFile.txt");	//Decalre that TestData is open for input
	ofstream writeData("WrittenData.txt"); //Declare that WrittenData is open for output
	if (readData.is_open())	//Checks if TestData is open and allows program to continue running
	{
		while (getline(readData, line))
		{
			double scoreTotal = 0;
			double examCount = 0;
			double position = 0;
			double newPosition = 0;
			double lineLength = 0;
			string name = "";

			//cout << line << '\n'; //Testing if lines are being output
			position = CommaForNamePosition(line);
			name = line.substr(0, position);

			int pos = CommaForAverageValuePosition(line);
			double average = line.find(',', pos + 1);

			string x = line.substr(pos + 2, line.length());
			GetScoresForLine(x);
		}
		readData.close();
		writeData.close();

		char q;	//Enable command prompt to stay up till a key is entered
		cout << "Enter q to quit: ";
		cin >> q;
	}
	else cout << "Unable to open file"; //If (readData.is_open()) is false, this will be displayed
	return 0;
}
