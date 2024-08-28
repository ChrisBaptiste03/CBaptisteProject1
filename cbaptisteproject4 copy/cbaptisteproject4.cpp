#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
/*
Student Name: Chris Baptiste 
Course: C++ (COP2334)
Date: March 14, 2024
Due Date: March 24, 2024

Problem Statement: In this program design we are creating a golfer report for three golfers. Every game they play and earn point's that record will be plotted down.
And this program will open the file read the numbers and output it to the output file giving the golfers there final results from there game
*/

// Function section 
bool openInputFile(ifstream &inputfileStream) { // This bool section make sure if this file that is opening the input file is true or false.
    string inputFileName;
    string fileName;
    cout << "Enter input file name: ";
    cin >> fileName;
    inputfileStream.open(fileName); // This open the inputfilestream from entering the inputfile.txt from file
    return inputfileStream.is_open();
}

bool openOutputFile(ofstream &outputFile) { // This bool section make sure if this file that is opening the output file is true or false.
    string fileName;
    cout << "Enter output file name: ";
    cin >> fileName;
    outputFile.open(fileName); // This open the outputfile from entering the outputfile.txt from file
    return outputFile.is_open();
}

void writeHeader(ofstream &outputFile, int numGolfers, int numScores) { // This section here give out each golfers reports and number from there score they have done added to the outputfile.txt
    outputFile << "********************" << endl;
    outputFile << "GOLFER REPORT" << endl;
    outputFile << "********************" << endl;
    outputFile << endl;
    outputFile << "Number of golfers processed: " << numGolfers << endl;
    outputFile << "Number of scores processed: " << numScores << endl;
    outputFile << endl;
    outputFile << "========================================" << endl;
}
// This section here outputs the message to the output file with the golfer name and there score. For who score who.
void writeGolferInfo(ofstream &outputFile, const string &name, double averageScore) {
    outputFile << "Player: " << name << " Average Score: " << fixed << setprecision(2) << averageScore << endl;
}

bool isValidScore(int score) { // This section indicate the score between 50 to 130 with a bool statement added to it. To make sure the scores are between
// those numbers.
    return (score >= 50 && score <= 130); // Has to be between these two numbers if it's not then it will not continue the program.
}
// The setMaxScore give out the total score that the golfers have all together into one to output there numbers into one.
void setMaxScore(int score, int &maxScore) {
    if (score > maxScore) {
        maxScore = score;
    }
}
//This section here takes in the inputfile.txt and take those numbers of each golfer have and determine if each number is vaild and not vaild in the program. 
void process_input_data(ifstream &inputfileStream, ofstream &outputFile) {
    int numGolfers, numScores;
    inputfileStream >> numGolfers >> numScores;
    writeHeader(outputFile, numGolfers, numScores);
    // The for loop helps loop how many times the number of golfers they are take in and when that loop ends is when the loop doesn't read no more golfers from the inputfile.
    for (int i = 0; i < numGolfers; ++i) {
        string firstName; // Taking the three golfers names from the inputfile. 
        inputfileStream >> firstName; // Input file entering into the firstName. 
        int totalScores = 0;
        int validScores = 0;
        int maxScore = 0;
        
        for (int j = 0; j < numScores; ++j) {
            int score;
            inputfileStream >> score;
            //
            if (isValidScore(score)) { 
                totalScores += score;
                validScores++;
                setMaxScore(score, maxScore);
            } else {
                cout << firstName << " score of " << score << " is not a valid." << endl;
            }
        }
        //
        double averageScore = (totalScores - maxScore) / static_cast<double>(validScores - 1); // This section here average the total score we get from the golfers numbers then subtract that from the maxscore we 
                                                                                              // have gotten from the for loops. 
        writeGolferInfo(outputFile, firstName, averageScore); // The golfer info will have the output file, the golfer name and the average to output the message I have created under voidGolferinfo
    }
}

int main() {
    ifstream inputFile; // This inputfile calls in the inputfilestream from the function
    ofstream outputFile; // this outputfile calls in the outputfile function
    //This section connects to the function 
    if (openInputFile(inputFile) && openOutputFile(outputFile)) {
        process_input_data(inputFile, outputFile);
        inputFile.close(); // This closes the input file after openning it to gather the information from the file.
        outputFile.close(); // This closes the outputfile after entering the inputfile into it.
        cout << "Check the output file to see file results from each golfer score." << endl;
    } else {
        cout << "Error opening the files." << endl; // This message will output this if the user incorrecly open the input and output file.
    }
    // Exit Successfully
    return 0;
}
