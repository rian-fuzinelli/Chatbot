#include "ChatBot.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <ctime>

using namespace std;

ChatBot::ChatBot(const string& name) : nameBot(name) {
    initializeAnswers();
}

string ChatBot::forLowercase(string text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string ChatBot::cleanInput(string input) {
    string result;
    for (char c : input) {
        if (isalnum(c) || isspace(c)) {
            result += c;
        }
    }
    return forLowercase(result);
}

void ChatBot::addToHistory(const string& user, const string& message) {
    time_t now = time(nullptr);
    string timestamp = ctime(&now);
    timestamp = timestamp.substr(0, timestamp.length() - 1); // Remove \n
    history.push_back("[" + timestamp + "] " + user + ": " + message);
}

void ChatBot::initializeAnswers() {
    answers["hello"] = "Hello! How can I help you?";
    answers["hi"] = "Hi! I'm here to answer all your questions!";
    answers["how are you"] = "I'm really well. What about you?";
    answers["whats your name"] = "My name is " + nameBot + ", your AI";
    answers["bye"] = "Bye! Talking to you was a great pleasure!";
    answers["what do you do"] = "I'm a ChatBot created to answer some of your questions";
}

string ChatBot::processInput(const string& userInput) {
    string clean = cleanInput(userInput);
    addToHistory("User", userInput);

    for (const auto& par : answers) {
        if (clean.find(par.first) != string::npos) {
            addToHistory(nameBot, par.second);
            return par.second;
        }
    }

    string defaultAnswer = "Sorry, I didn't understand. Can you rephrase the question?";
    addToHistory(nameBot, defaultAnswer);
    return defaultAnswer;
}

void ChatBot::showHistory() {
    cout << "\n=== Talking History ===\n";
    for (const string& message : history) {
        cout << message << endl;
    }
}

void ChatBot::start() {
    string input;
    cout << "Be welcome, I'm " + nameBot + ". Type 'exit' to finish or 'history' to see the chat.\n" << endl;

    while (true) {
        cout << "You: ";
        getline(cin, input);

        if (forLowercase(input) == "exit") {
            cout << nameBot << ": Bye! I hope to see you again!" << endl;
            break;
        }
        else if (forLowercase(input) == "history") {
            showHistory();
        }
        else {
            cout << nameBot << ": " << processInput(input) << endl;
        }
    }
}