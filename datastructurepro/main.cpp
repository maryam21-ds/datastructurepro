#include<iostream>
#include "FavoriteMessagesManager.h"
using namespace std;



int main() {
    FavoriteMessagesManager manager;
    const string filename = "favorites.txt";

    stack<string> existingMessages;

    // Push messages (top of stack is last message shown)
    existingMessages.push("Hi there!");
    existingMessages.push("Don't forget to email.");
    existingMessages.push("Welcome back!");
    existingMessages.push("Meeting at 10 AM");

    // Load previous favorites from file
    manager.loadFromFile(filename);

    int choice;
    string message;

    do {
        cout << "\n--- Favorite Messages Menu ---\n";
        cout << "1. Add a message to favorites\n";
        cout << "2. Remove the oldest favorite message\n";
        cout << "3. View all favorite messages\n";
        cout << "4. Exit\n";
        cout << "Enter your choice  ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character
      
        switch (choice) {
            
        case 1:
            manager.addToFavorites(existingMessages);
            break;

        case 2:
            manager.removeOldestFavorite();
            break;

        case 3:
            manager.viewAllFavorites();
            break;

        case 4:
            manager.saveToFile(filename);
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}