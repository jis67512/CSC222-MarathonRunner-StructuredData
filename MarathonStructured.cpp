#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_RUNNERS = 50;
const int NUM_DAYS = 7;

struct Runner
{
    string name;
    double miles[NUM_DAYS];
};

int readRunnerData(Runner runner[]);

void calculateTotalsAndAverages(const Runner runner[], int runnerCount, double totals[], double averages[]);

void displayResults(const Runner runner[], int runnerCount, const double totals[], const double average[]);

int main()
{
    Runner runners[MAX_RUNNERS];

    double totals[MAX_RUNNERS];
    double averages[MAX_RUNNERS];

    int runnerCount = readRunnerData(runners);

    calculateTotalsAndAverages(runners, runnerCount, averages);
    
    displayResults(runners, runnerCount, totals, averages);




    return 0;
}