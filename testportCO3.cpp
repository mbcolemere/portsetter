// Matthew Colemere - Septemeber 13, 2016 - testport.cpp
#include <string>
#include <iostream>
using namespace std;

// Declare const variables
const int POS_CASE = 5;
const int NEG_CASE = 13;

int main() {
    // Declare two variables for pass and fail count
    int pass = 0;
    int fail = 0;
    bool positive = false;
    // Testing positive cases
    cout << "First we will test the positive cases!" << endl << endl;
    // Test Case 1
    int statuscode = system("./portsetter.cpp.o -?") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -? ...Test failed!" << endl << endl; 
        ++fail;
    }
    else { 
        cout << "Case Tested: setport -? ...Test passed!" << endl << endl;
        ++pass;
    }
    // Test Case 2
    statuscode = system("./portsetter.cpp.o -v") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -v ...Test failed!" << endl << endl; 
        ++fail;
    }
    else { 
        cout << "Case Tested: setport -v ...Test passed!" << endl << endl;
        ++pass;
    }
    // Test Case 3
    statuscode = system("./portsetter.cpp.o -p -e") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p -e ...Test failed!" << endl << endl; 
        ++fail;
    }
    else { 
        cout << "Case Tested: setport -p -e ...Test passed!" << endl << endl;
        ++pass;
    }
    // Test Case 4
    statuscode = system("./portsetter.cpp.o -p 4040") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p 4040 ...Test failed!" << endl << endl; 
        ++fail;
    }
    else { 
        cout << "Case Tested: setport -p 4040 ...Test passed!" << endl << endl;
        ++pass;
    }
    // Test Case 5
    statuscode = system("./portsetter.cpp.o -!") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -! ...Test failed!" << endl << endl; 
        ++fail;
    }
    else { 
        cout << "Case Tested: setport -! ...Test passed!" << endl << endl;
        ++pass;
    }
    // Check if all the Positive Cases passed
    if (pass == POS_CASE) {positive = true;}
    else {positive = false;}
    // Reset pass/fail values, to test for negative cases.
    pass = 0;
    fail = 0;
    // Testing Negative Cases (should fail)
    cout << "Now we will test the negative cases!" << endl << endl;
    // Test Case 6
    statuscode = system("./portsetter.cpp.o help") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport help ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport help ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 7
    statuscode = system("./portsetter.cpp.o --?") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport --? ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport --? ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 8
    statuscode = system("./portsetter.cpp.o --!") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport --! ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport --! ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 9
    statuscode = system("./portsetter.cpp.o -h --help") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -h --help ...Test passed" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -h --help ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 10
    statuscode = system("./portsetter.cpp.o -p p") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p p ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -p p ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 11
    statuscode = system("./portsetter.cpp.o -p --port 9") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p --port 9 ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -p --port 9 ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 12
    statuscode = system("./portsetter.cpp.o -p 77 33") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p 77 33 ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -p 77 33 ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 13
    statuscode = system("./portsetter.cpp.o -p -21") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p -21 ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -p -21 ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 14
    statuscode = system("./portsetter.cpp.o -p 0") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p 0 ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -p 0 ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 15
    statuscode = system("./portsetter.cpp.o --port") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport --port ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport --port ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 16
    statuscode = system("./portsetter.cpp.o -p 90642") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -p 90642 ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -p 90642 ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 17
    statuscode = system("./portsetter.cpp.o -x 45321") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -x 45321 ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -x 45321 ...Test failed!" << endl << endl;
        ++fail;
    }
    // Test Case 18
    statuscode = system("./portsetter.cpp.o -P 714") / 256;
    if (statuscode != 0) { 
        cout << "Case Tested: setport -P 714 ...Test passed!" << endl << endl; 
        ++pass;
    }
    else { 
        cout << "Case Tested: setport -P 714 ...Test failed!" << endl << endl;
        ++fail;
    }
    // Output if tests were handled correctly.
    if (positive == true) {cout << "All of the positive tests were handled correctly and passed!" <<  endl;}
    else {cout << "Not all of the positive tests passed as they should." << endl;}
    if (pass == NEG_CASE) {cout << "All of the negative tests were handles correctly and passed!" << endl;}
    else {cout << "Not all of the negative tests passed as they should" << endl;}
    cout << "Thank you for testing with us. Come again!" << endl;
}