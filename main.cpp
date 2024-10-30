// COMSC-210 | 210-lab-25 | Daniil Malakhov
// IDE used: Codeblocks
#include <iostream>
#include <chrono>
#include <list>
#include <set>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int main() {

    ifstream inputFile("codes.txt");

    if(!inputFile.is_open())
    {
        cout << "Error! Can't open File!";
    }

    vector<int> timeRead;
    vector<int> timeSort;
    vector<int> timeInsert;
    vector<int> timeDelete;

    vector<string> vec;
    list<string> lis;
    set<string> se;

    // reads all the codes in text files into vector, list, and set
    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            string temp;
            while(getline(inputFile, temp))
                vec.push_back(temp);
        }
        if (i == 1)
        {

            string temp;
            while(getline(inputFile, temp))
                lis.push_back(temp);
        }
        if (i == 2)
        {

            string temp;
            while(getline(inputFile, temp))
                se.insert(temp);
        }

        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<microseconds>(end - start);

        timeRead.push_back(duration.count());
        inputFile.clear();
        inputFile.seekg(0);
    }

    // sorts the vectors and list
    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            sort(vec.begin(), vec.end());
        }
        if (i == 1)
        {

            lis.sort();
        }
        if (i == 2)
        {
            timeSort.push_back(-1);
        }

        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<microseconds>(end - start);

        timeSort.push_back(duration.count());
    }

    // inserts an element into middle of vector, list, set
    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            vec.insert(vec.begin() + 10000, "TESTCODE");
        }
        if (i == 1)
        {
            auto it = lis.begin();
            advance(it, 10000);
            lis.insert(it, "TESTCODE");
        }
        if (i == 2)
        {
            se.insert("TESTCODE");
        }

        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<microseconds>(end - start);

        timeInsert.push_back(duration.count());
    }

    // deletes an element from vector, list and set
    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            auto it = vec.begin();
            advance(it, 10001);
            vec.erase(it);
        }
        if (i == 1)
        {
            auto it1 = lis.begin();
            advance(it1, 10005);
            lis.erase(it1);

        }
        if (i == 2)
        {
            auto it = se.begin();
            advance(it, 10001);
            se.erase(it);
        }

        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<microseconds>(end - start);

        timeDelete.push_back(duration.count());
    }

    cout << setw(10) << right << "Operation" << setw(10) << right << "Vector" << setw(10) << right << "List" << setw(10) << right << "Set" << endl;
    cout << setw(10) << right << "Read" << setw(10) << right << timeRead[0] << setw(10) << right << timeRead[1] << setw(10) << right << timeRead[2] << endl;
    cout << setw(10) << right << "Sort" << setw(10) << right << timeSort[0] << setw(10) << right << timeSort[1] << setw(10) << right << timeSort[2] << endl;
    cout << setw(10) << right << "Insert" << setw(10) << right << timeInsert[0] << setw(10) << right << timeInsert[1] << setw(10) << right << timeInsert[2] << endl;
    cout << setw(10) << right << "Delete" << setw(10) << right << timeDelete[0] << setw(10) << right << timeDelete[1] << setw(10) << right << timeDelete[2] << endl;



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
