#ifndef CHATBOT_H
#define CHATBOT_H
#include <map>
#include <string>
#include <vector>

using namespace std;

class ChatBot {
private:
    map<string, string> answers;
    vector<string> history;
    string nameBot;

    string upperMessage(string text);
    string cleanInput(string input);
    void addToHistory(const string& user, string& message);
    void initializeAnswers();

};



#endif //CHATBOT_H

