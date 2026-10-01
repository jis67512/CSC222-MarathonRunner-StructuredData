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

int readRunnerData(Runner runners[]);

void calculateTotalsAndAverages(const Runner runners[], int runnerCount, double totals[], double averages[]);

void displayResults(const Runner runners[], int runnerCount, const double totals[], const double averages[]);

int main()
{
    Runner runners[MAX_RUNNERS];

    double totals[MAX_RUNNERS];
    double averages[MAX_RUNNERS];

    int runnerCount = readRunnerData(runners);

    if (runnerCount > 0)
    {
    calculateTotalsAndAverages(runners, runnerCount,totals ,averages);

    displayResults(runners, runnerCount, totals, averages);
    };

    return 0;
}

int readRunnerData(Runner runners[])
{
    ifstream inputFile;
    int runnerCount = 0;

    inputFile.open("runners.txt");

    if (!inputFile)
    {
        cout << "No File Found." << endl;
        return 0;
    }

    // Read the 5 7 header from the provided file
    int fileRunnerCount;
    int fileDays;

    inputFile >> fileRunnerCount >> fileDays;

    while (runnerCount < MAX_RUNNERS && inputFile >> runners[runnerCount].name)
    {
        bool completeRecord = true;

        for (int day = 0; day < NUM_DAYS; day++)
        {
            if (!(inputFile >> runners[runnerCount].miles[day]))
            {
                completeRecord = false;
                break;
            }
        }

        if (!completeRecord)
        {
            break;
        }

        runnerCount++;
    }

    inputFile.close();

    return runnerCount;
}

void calculateTotalsAndAverages(const Runner runners[], int runnerCount, double totals[], double averages[])
{
    for (int runner = 0; runner < runnerCount; runner++)
    {
        double total = 0;

        for (int day = 0; day < NUM_DAYS; day++)
        {
            total += runners[runner].miles[day];
        }

        totals[runner] = total;
        averages[runner] = total / NUM_DAYS;
    }
}

void displayResults(const Runner runners[], int runnerCount, const double totals[], const double averages[])
{
    cout << fixed << setprecision(2);

    cout << left << setw(12) << "Runner";

    for (int day = 0; day < NUM_DAYS; day++)
    {
        cout << right << setw(8) << ("Day " + to_string(day + 1));
    }

    cout << setw(10) << "Total" << setw(10) << "Average" << endl;

    for (int runner = 0; runner < runnerCount; runner++)
    {
        cout << left << setw(12) << runners[runner].name;

        for (int day = 0; day < NUM_DAYS; day++)
        {
            cout << right << setw(8) << runners[runner].miles[day];
        }

        cout << setw(10) << totals[runner] << setw(10) << averages[runner] << endl;
    }
}