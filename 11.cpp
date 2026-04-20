#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

struct Question {
    string text;
    string options[4];
    char correctOption;
};

void runQuiz() {
    vector<Question> quizBank = {
        {"What is the size of int in C++?", {"1 byte", "2 bytes", "4 bytes", "8 bytes"}, 'C'},
        {"Which operator is used to deallocate memory?", {"free", "delete", "remove", "destruct"}, 'B'},
        {"Which header file is used for file handling?", {"iostream", "fstream", "file", "stdio"}, 'B'},
        {"Is C++ a type-safe language?", {"Yes", "No", "Partially", "None"}, 'A'}
    };

    // Task 2: Randomize Questions
    auto rng = default_random_engine(time(0));
    shuffle(quizBank.begin(), quizBank.end(), rng);

    double score = 0.0;
    ofstream detailsFile("attempt_details.txt", ios::app);
    ofstream resultsFile("final_results.txt", ios::app);

    cout << "--- Welcome to the C++ Quiz ---" << endl;
    cout << "(Correct: +1 | Wrong: -0.5)" << endl << endl;

    for (int i = 0; i < quizBank.size(); i++) {
        cout << "Q" << (i + 1) << ": " << quizBank[i].text << endl;
        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ") " << quizBank[i].options[j] << endl;
        }

        char userChoice;
        cout << "Your Answer: ";
        cin >> userChoice;
        userChoice = toupper(userChoice);

        double marksForThisQuest = 0.0;
        if (userChoice == quizBank[i].correctOption) {
            marksForThisQuest = 1.0;
            cout << "Correct!" << endl;
        } else {
            marksForThisQuest = -0.5;
            cout << "Wrong! The correct answer was " << quizBank[i].correctOption << endl;
        }
        score += marksForThisQuest;

        // Task 3: Store Attempt Details
        if (detailsFile.is_open()) {
            detailsFile << "Q: " << quizBank[i].text << " | Awarded: " << marksForThisQuest << endl;
        }
    }

    cout << "\nQuiz Finished! Your Final Score: " << score << endl;

    // Store Final Result
    if (resultsFile.is_open()) {
        resultsFile << "Final Score: " << score << "/ " << quizBank.size() << endl;
    }

    detailsFile.close();
    resultsFile.close();
}

int main() {
    runQuiz();
    return 0;
}