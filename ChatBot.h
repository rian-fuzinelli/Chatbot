#ifndef CHATBOT_H
#define CHATBOT_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class ChatBot {
private:
    map<string, string> answers;
    vector<string> history;
    string nameBot;

    string forLowercase(string text);
    string cleanInput(string input);
    void addToHistory(const string& user, const string& message);
    void initializeAnswers();

public:
    ChatBot(const string& name);
    string processInput(const string& userInput);
    void showHistory();
    void start();
};

#endif // CHATBOT_H