#include "FavoriteMessagesManager.h"
#include<fstream>
#include <iostream>
using namespace std;

void FavoriteMessagesManager::addToFavorites(stack<string> existingMessages) {
    if (existingMessages.empty()) {
        cout << "No existing messages available.\n";
        return;
    }

    vector<string> reversedMessages;
    while (!existingMessages.empty()) {
        reversedMessages.push_back(existingMessages.top());
        existingMessages.pop();
    }

      reverse(reversedMessages.begin(), reversedMessages.end());

    cout << "\nSelect a message to add to favorites:\n";
    for (size_t i = 0; i < reversedMessages.size(); ++i) {
        cout << i + 1 << ". " << reversedMessages[i] << "\n";
    }

     cout << "Enter the number: ";
    int selection;
    cin >> selection;

    if (selection >= 1 && selection <= reversedMessages.size()) {
        favoriteMessages.push(reversedMessages[selection - 1]);
        cout << "Message added to favorites!\n";
    }
    else {
        cout << "Invalid selection.\n";
    }
}

void FavoriteMessagesManager::removeOldestFavorite() {
    if (!favoriteMessages.empty()) {
        favoriteMessages.pop();
        cout << "Oldest favorite message removed.\n";
    }
    else {
        cout << "No favorite messages to remove.\n";
    }
}

void FavoriteMessagesManager::viewAllFavorites() const {
    if (favoriteMessages.empty()) {
        cout << "No favorite messages.\n";
        return;
    }

    queue<string> tempQueue = favoriteMessages;
    cout << "Favorite Messages:\n";

    while (!tempQueue.empty()) {
        cout << "- " << tempQueue.front() << "\n";
        tempQueue.pop();
    }
}

void FavoriteMessagesManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    queue<string> tempQueue = favoriteMessages;
    while (!tempQueue.empty()) {
        outFile << tempQueue.front() << "\n";
        tempQueue.pop();
    }

    outFile.close();
    cout << "Favorites saved to file.\n";
}

void FavoriteMessagesManager::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    // Clear current favorites
    favoriteMessages = queue<string>();

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            favoriteMessages.push(line);
        }
    }

    inFile.close();
    cout << "Favorites loaded from file.\n";
}