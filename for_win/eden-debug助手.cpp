#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cmath>
#include <fstream>
#define MAX_N 1000
#define MAX_CHAR_N 1000

using std::cin;
using std::cout;
using std::string;
using std::endl;

void deleteShu();
void UI();
void addSeNUM();

int main(int argc, const char * argv[]) {
    UI();
    char func = '\0';
    cin >> func;
    switch (func) {
        case '1':
            cout << "delete the first char of the line!" << endl;
            cout << "input EOF to end your input!" << endl << endl;
            deleteShu();
            break;
        case '2':
            cout << "add sequence number at the beginning of the line!" << endl;
            cout << "input EOF to end your input!" << endl << endl;
            addSeNUM();
        default:
            break;
    }
    return 0;
}

void deleteShu() {
    
//    char _in[MAX_N][MAX_CHAR_N];
//    int count = 0;
//    bool start;
//    FILE * pFile;

//    size_t lineLength = 0;  // gcc
//    char *oneLine = NULL;  // gcc
    char *oneLine = reinterpret_cast<char *>(malloc(sizeof(*oneLine) * MAX_CHAR_N));  // vs
    memset(oneLine, 0, sizeof(*oneLine) * MAX_CHAR_N);  // vs
    FILE * pFile = NULL;
    pFile = fopen ("result.txt", "a+");
    if (pFile) {
//        while (getline(&oneLine, &lineLength, stdin) != EOF) {  // gcc
        while (fgets(oneLine, sizeof(*oneLine) * MAX_CHAR_N, stdin)) {  // vs
            if (0 == strncmp(oneLine, "    |", sizeof(char) * 5)) {
                fprintf(pFile, "%s", oneLine + 5), fflush(pFile);
            }
        }
        fputs("\n\n", pFile), fflush(pFile);
    } else {
        std::cerr << "Failed to write." << std::endl;
    }
    free(oneLine);
    oneLine = NULL;
    fclose(pFile);
    pFile = NULL;
    return;

/* use c++ streams */
//    using std::ios;
//    std::ofstream output("result.txt", ios::out|ios::app);
//    string oneLine;
//    if (output.is_open()) {
//        while (std::getline(std::cin, oneLine)) {
//            if (oneLine.find("    |") == 0) {
//                output << oneLine.substr(5) << std::endl;
//            }
//        }
//        output << '\n' << std::endl;
//    } else {
//        std::cerr << "Failed to write." << std::endl;
//    }
//    output.close();
/* end */

//    while (getchar() != EOF) {
//        gets(_in[count]);
//        count++;
//    }
//    for (int i = 0; i < count; i++) {
//        start = false;
//        int length = strlen(_in[i]);
//        for (int k = 0; k < length; k++) {
//            if (_in[i][k] == '|' && start == false) {
//                start = true;
//            }
//            else if (start == true) {
//                fprintf (pFile, "%c", _in[i][k]);
//            }
//        }
//        fprintf (pFile, "\n");
//    }
//
//    fclose (pFile);
//    pFile = NULL;
}


void addSeNUM() {
    char _in[MAX_N][MAX_CHAR_N] = {0};
    //    size_t lineLength = 0;  // gcc
    size_t linenum = 0;
    //    char *oneLine = NULL;  // gcc
    char *oneLine = reinterpret_cast<char *>(malloc(sizeof(*oneLine) * MAX_CHAR_N));  // vs
    memset(oneLine, 0, sizeof(*oneLine) * MAX_CHAR_N);  // vs
//    while (getline(&oneLine, &lineLength, stdin) != EOF) {  // gcc
    while (fgets(oneLine, sizeof(*oneLine) * MAX_CHAR_N, stdin)) {  // vs
        if (linenum == MAX_N) {
            std::cerr << "  \nError: There have been too many lines to handle." << std::endl;
            break;
        }
        if (0 == strncmp(oneLine, "   ", sizeof(char) * 3)) {
            snprintf(_in[linenum], sizeof(_in[linenum]), "%03lu%s", linenum + 1, oneLine + 3);
            ++linenum;
        }
    }
    std::cout << '\n' << std::endl;
    for (size_t line = 0; line != linenum; ++line) std::cout << _in[line] << std::flush;
    std::cout << '\n' << std::endl;
    free(oneLine);
    oneLine = NULL;
    return;

/* write the result into a file */
//    //    size_t lineLength = 0;  // gcc
//    size_t linenum = 0;
//    //    char *oneLine = NULL;  // gcc
//    char *oneLine = reinterpret_cast<char *>(malloc(sizeof(*oneLine) * MAX_CHAR_N));  // vs
//    memset(oneLine, 0, sizeof(*oneLine) * MAX_CHAR_N);  // vs
//    FILE * pFile = NULL;
//    pFile = fopen ("result.txt", "a+");
//    if (pFile) {
//        //    while (getline(&oneLine, &lineLength, stdin) != EOF) {  // gcc
//        while (fgets(oneLine, sizeof(*oneLine) * MAX_CHAR_N, stdin)) {  // vs
//            if (linenum == MAX_N) std::cerr << "\n  Warning: There have been too many lines." << std::endl;
//            if (0 == strncmp(oneLine, "   ", sizeof(char) * 3)) {
//                fprintf(pFile, "%03lu%s", linenum + 1, oneLine + 3), fflush(pFile);
//                ++linenum;
//            }
//        }
//        fputs("\n\n", pFile), fflush(pFile);
//    } else {
//        std::cerr << "Failed to write." << std::endl;
//    }
//    free(oneLine);
//    oneLine = NULL;
//    fclose(pFile);
//    pFile = NULL;
//    return;
/* end */

//    int count = 0;
//    bool start;
//    while (getchar() != EOF) {
//        gets(_in[count]);
//        count++;
//    }
//    int seqMax = count;
//    int countS = 0;
//    int zeroOutNum;
//    while (seqMax) {
//        countS++;
//        seqMax /= 10;
//    }
//    for (int i = 0; i < count; i++) {
//        for (int j = 1; j < countS; j++) {
//            zeroOutNum = pow(10, j);
//            if (i + 1 < zeroOutNum) {
//                for (int l = 0; l < countS - j; l++) {
//                    cout << '0';
//                }
//                break;
//            }
//        }
//        cout << i + 1 << '|';
//        start = false;
//        int length = strlen(_in[i]);
//        for (int k = 0; k < length; k++) {
//            if (_in[i][k] == '|' && start == false) {
//                start = true;
//            }
//            else if (start == true) {
//                cout << _in[i][k];
//            }
//        }
//        cout << endl;
//    }
}

void UI() {
    cout << "created by Mr.Gu" << endl;
    cout << "please enter what service you want:" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1.delete the '|' and ' 'at the beginning of the line." << endl << endl;
    cout << "2.add sequence number at the beginning of the line." << endl << endl;
    cout << "3.input anything else to quit." << endl << endl;
    cout << "--------------------------------------" << endl;
}

