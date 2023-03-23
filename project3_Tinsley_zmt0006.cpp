/* Zach Tinsley
 * Auburn ID - zmt0006@auburn.edu
 * project3_Tinsley_zmt0006.cpp
 * HINTS : 
 *  Project3.pdf (how to implement read file and setup functions)
 *  Project3_hints.pdf 
 *  Zoom Lecture (I followed Dr. Li's debriefing of the project
 *      and how he recomends to implement each function)
 *  I used cplusplus.com to understand .push(), .push_back(), and .front() functions 
 *      for a vector.
 *  I used https://stackoverflow.com/questions/19602407/read-integers-from-a-file-into-a-vector-in-c
 *      to understand how to implement the read_file(string) function.
 * Compile : g++ project2_Tinsley_zmt0006.cpp
 * Run : ./a.out
 */ 


#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
/* declare your user-defined functions */
bool check_file(string);

/* 
* Reads a file and puts int contents into a vector 
* Param: string (filename)
*/
vector<int> read_file(string);

/*
* Writes the ints of a vector into a file
* Param: string (name of output file)
* Param: vector<int> (the vector of numbers to be written to output file)
*/
void write_file(string, vector<int>);

/*
* Merges two vectors of ints into one 
* Returned vector is both param vectors put together 
*   from low to high
* Param: vector<int> first vector to me merged
* Param: vector<int> second vector to me merged
* Return: returns sorted vector
*/
vector<int> merge(vector<int>, vector<int>);

/*
* Display the values of a given vector.
*
* Param: file Name of file to display. (string)
* Param: v Vector containing values to display. (vector<int>)
*/
void to_string(string, vector<int>);

/*
* Display the values of a given vector.
*
* Param: file Name of file to display. (string)
* Param: v Vector containing values to display. (vector<int>)
*/
void to_string_v3(vector<int> v);

/*
* Merge the numbers in two specified files and write all the numbers
* to a specified third file sorted in ascending order.
*
* Return: 1 Program completed successfully. (int)
*/
int main() {
    /* declare your variables */
    string file1;
    string file2;
    string file3;
    cout << "***  Welcome to Zach's sorting program ***\n";
    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> numbers3;
    /* Get name of file one. */
    do {
        /* user friendly interfaces */
        ifstream inStream;
        cout << "Enter the first input file name: ";
        cin >> file1;
        

        bool checkFile1 = check_file(file1);
        if (checkFile1 == false) {
            exit(1);
        }

    } while (cin.fail() || !check_file(file1));
    /* Get and display numbers from file one. */
    numbers1 = read_file(file1);
    to_string(file1, numbers1);

    
    /* Get name of file two. */
    do {
        /* user friendly interfaces */
        ifstream inStream;
        int data;
        cout << "Enter the first second input file name: ";
        cin >> file2;
        

        bool checkFile2 = check_file(file2);
        if (checkFile2 == false) {
            exit(1);
        }
    } while (cin.fail() || !check_file(file2));
    /* Get and display numbers from file two. */
    numbers2 = read_file(file2);
    to_string(file2, numbers2);
    /* Combine vectors and display the sorted result. */
    numbers3 = merge(numbers1, numbers2);
    to_string_v3(numbers3);
    
    

    /* Get name of output file. */

    do {
        /* user friendly interfaces */
        cout << "Enter the output file name: ";
        cin >> file3;
    } while (cin.fail());
    
    /* Write combined vector to output file. */
    write_file(file3, numbers3);
    cout << "*** Please check the new file - " << file3 << " ***" << endl;
    cout << "*** Goodbye. ***";
    return 1;
}
bool check_file(string file) {
    /* Input file stream. (ifstream) */
    ifstream stream;
    /* Check whether file exists. */
    stream.open(file.c_str());
    if (stream.fail()) {
        cout << "Input file opening failed." << endl;
        return false;
    }
    stream.close();
    return true;
}

vector<int> read_file(string file) {
    /* Input file stream. (ifstream) */
    ifstream stream;
    /* Vector containing numbers from file. (vector<int>) */
    vector<int> v;
    /* Integer read from file. (int) */
    int i;
    /* Add each number in the file to a vector. */
    stream.open(file.c_str());
    if (stream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    
    while (stream.good()) {
        while (stream >> i) {
            v.push_back(i);
        }
        break;
    }
    stream.close();
    return v;
}

void write_file(string file, vector<int> v) {
    /* Output file stream. (ofstream) */
    ofstream stream;
    
    /* Add each number in the file to a vector. */
    stream.open(file.c_str());
    for (int i = 0; i < v.size(); i++) {
        stream << v.at(i) << endl;
    }
    stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> v3;
    /* Compare both vectors. */
    while (v1.size() > 0 && v2.size() > 0) {
        if (v1.front() > v2.front()) {
            v3.push_back(v2.front());
            v2.erase(v2.begin());
        } else {
            v3.push_back(v1.front());
            v1.erase(v1.begin());
        }
    }

    /* Add any remaining numbers from vector one. */
    if (v1.size() > 0) {
        while (v1.size() > 0) {
            v3.push_back(v1.front());
            v1.erase(v1.begin());
        }
        
    }

    /* Add any remaining numbers from vector two. */
    if (v2.size() > 0) {
        while (v2.size() > 0) {
            v3.push_back(v2.front());
            v2.erase(v2.begin());
        }
    }

    return v3;
}

void to_string(string file, vector<int> v) {
    /* Display the numbers contained in a vector. */
    cout << "The list of " << v.size() << " numbers in file " << file << " is:\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    cout << "\n";
}

void to_string_v3(vector<int> v) {
    /* Display the numbers contained in a vector. */
    cout << "The sorted list of " << v.size() << " numbers is: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}