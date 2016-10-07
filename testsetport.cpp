// Matthew Colemere - testsetport for portsetter.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Declare local variables
    int pass = 0;
    int fail = 0;
    int statusCode = 0;
    string testCase = "";
    bool positiveEn = true;
    bool positiveEs = true;
    bool negative = true;
    vector<string> tests;
    
    ifstream in("happyPathOne.txt");
    if (in.fail()) {
        cout << "Could not open the file happyPathOne.txt!" << endl;
        cout << "Please pick a correct file!" << endl;
    }
    
    string line = "";
    while (!in.eof()) {
        getline(in, line);
        tests.push_back(line);
    }
    in.close();
    
    cout << "Testing first batch of cases in english!" << endl;

    // Test first batch of tests in english
    for (int i = 0; i < tests.size(); ++i) {
        testCase = tests[i];
        statusCode = system(testCase.c_str()) / 256;
        testCase.erase(0,18);
        cout << endl << "setport" + testCase << endl;
        if (statusCode != 0) {
            cout << "Case Tested: setport " + testCase + " ...Test Failed" << endl << endl;
            ++fail;
            positiveEn = false;
        }
        else {
            cout << "Case Tested: setport " + testCase + " ...Test Passed!" << endl << endl;
            ++pass;
        }
    }
    
    if (positiveEn == true) cout << "All of the English positive tests passed!" << endl << endl;
    else cout << "Some of the English positive tests failed!" << endl << endl;
    
    // Change language to spanish and run more tests
    setenv("LANGUAGE", "es", 1);
    tests.clear();
    
    in.open("happyPathTwo.txt");
    if (in.fail()) {
        cout << "Could not open the file happyPathTwo.txt!" << endl;
        cout << "Please pick a correct file!" << endl;
    }
    
    line = "";
    while (!in.eof()) {
        getline(in, line);
        tests.push_back(line);
    }
    in.close();
    
    cout << "Testing second batch of tests in Spanish!" << endl;
    
    // Test second batch of tests in spanish
    for (int i = 0; i < tests.size(); ++i) {
        testCase = tests[i];
        statusCode = system(testCase.c_str()) / 256;
        testCase.erase(0,18);
        cout << endl << "setport" + testCase << endl;
        if (statusCode != 0) {
            cout << "Case Tested: setport " + testCase + " ...Test Failed" << endl << endl;
            ++fail;
            positiveEs = false;
        }
        else {
            cout << "Case Tested: setport " + testCase + " ...Test Passed!" << endl << endl;
            ++pass;
        }
    }
    
    if (positiveEs == true) cout << "All of the Spanish positive tests passed!" << endl << endl;
    else cout << "Some of the Spanish positive tests failed!" << endl << endl;
    
    // Switch to negative tests
    // Change language back to invalid language code and run negative tests
    setenv("LANGUAGE", "it", 1);
    tests.clear();
    
    in.open("sadPath.txt");
    if (in.fail()) {
        cout << "Could not open the file sadPath.txt!" << endl;
        cout << "Please pick a correct file!" << endl;
    }
    
    line = "";
    while (!in.eof()) {
        getline(in, line);
        tests.push_back(line);
    }
    in.close();
    
    cout << "Testing negative cases in bad language code." << endl;
    
    for (int i = 0; i < tests.size(); ++i) {
        testCase = tests[i];
        statusCode = system(testCase.c_str()) / 256;
        testCase.erase(0,18);
        cout << endl << "setport" + testCase << endl;
        if (statusCode == 0) {
            cout << "Case Tested: setport " + testCase + " ...Test Failed" << endl << endl;
            ++fail;
            negative = false;
        }
        else {
            cout << "Case Tested: setport " + testCase + " ...Test Passed!" << endl << endl;
            ++pass;
        }
    }
    
    if (negative == true) cout << "All of the negative cases passed!" << endl << endl;
    else cout << "Some of the negative positive tests failed!" << endl << endl;
    
    if (negative == true && positiveEn == true && positiveEs == true) {
        cout << "All of the Test Cases were handled correctly, "<< endl;
        cout << "including the changing of languages!" << endl;
    }
    else cout << "Not all of the tests were handled correctly!" << endl;
}
