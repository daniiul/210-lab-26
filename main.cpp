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

void readFile(int, int, int(&data)[15][4][3], vector<string>&, list<string>&, set<string>&);
void sortFile(int, int, int(&data)[15][4][3], vector<string>&, list<string>&, set<string>&);
void insertFile(int, int, int(&data)[15][4][3], vector<string>&, list<string>&, set<string>&);
void deleteFile(int, int, int(&data)[15][4][3], vector<string>&, list<string>&, set<string>&);

int main() {

    int data[15][4][3];

    vector<int> timeRead;
    vector<int> timeSort;
    vector<int> timeInsert;
    vector<int> timeDelete;

    vector<string> vec;
    list<string> lis;
    set<string> se;

    // reads all the codes in text files into vector, list, and set
    for(int i = 0; i < 15; i++)
    {
        readFile(i, 0, data, vec, lis, se);
        readFile(i, 1, data, vec, lis, se);
        readFile(i, 2, data, vec, lis, se);
    }

    // sorts the vectors and list
    for(int i = 0; i < 15; i++)
    {
        sortFile(i, 0, data, vec, lis, se);
        sortFile(i, 1, data, vec, lis, se);
        sortFile(i, 2, data, vec, lis, se);
    }

    // inserts an element into middle of vector, list, set
    for(int i = 0; i < 15; i++)
    {
        insertFile(i, 0, data, vec, lis, se);
        insertFile(i, 1, data, vec, lis, se);
        insertFile(i, 2, data, vec, lis, se);
    }

    // deletes an element from vector, list and set
    for(int i = 0; i < 15; i++)
    {
        deleteFile(i, 0, data, vec, lis, se);
        deleteFile(i, 1, data, vec, lis, se);
        deleteFile(i, 2, data, vec, lis, se);
    }

    cout << setw(10) << right << "Operation" << setw(10) << right << "Vector" << setw(10) << right << "List" << setw(10) << right << "Set" << endl;
    cout << setw(10) << right << "Read" << setw(10) << right << timeRead[0] << setw(10) << right << timeRead[1] << setw(10) << right << timeRead[2] << endl;
    cout << setw(10) << right << "Sort" << setw(10) << right << timeSort[0] << setw(10) << right << timeSort[1] << setw(10) << right << timeSort[2] << endl;
    cout << setw(10) << right << "Insert" << setw(10) << right << timeInsert[0] << setw(10) << right << timeInsert[1] << setw(10) << right << timeInsert[2] << endl;
    cout << setw(10) << right << "Delete" << setw(10) << right << timeDelete[0] << setw(10) << right << timeDelete[1] << setw(10) << right << timeDelete[2] << endl;



    return 0;
}

void readFile(int run, int i, int(&data)[15][4][3], vector<string>& vec, list<string>& lis, set<string>& se)
{

    ifstream inputFile("codes.txt");

    if(!inputFile.is_open())
    {
        cout << "Error! Can't open File!";
    }

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

    data[run][0][i] = duration.count();
    inputFile.clear();
    inputFile.seekg(0);
}

void sortFile(int run, int i, int(&data)[15][4][3], vector<string>& vec, list<string>& lis, set<string>& se)
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


    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<microseconds>(end - start);

    data[run][1][i] = duration.count();
    if (i == 2)
    {
        data[run][1][i] = -1;
    }

}

void insertFile(int run, int i, int(&data)[15][4][3], vector<string>& vec, list<string>& lis, set<string>& se)
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

    data[run][2][i] = duration.count();
}

void deleteFile(int run, int i, int(&data)[15][4][3], vector<string>& vec, list<string>& lis, set<string>& se)
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

    data[run][3][i] = duration.count();
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
