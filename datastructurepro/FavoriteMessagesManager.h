#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <stack>
using namespace std;
class FavoriteMessagesManager
{
private:
    queue<string> favoriteMessages;

public:
  
   
    void addToFavorites(stack<string> existingMessages);

   
    void removeOldestFavorite();

  
    void viewAllFavorites() const;

   
    void saveToFile(const string& filename) const;

    
    void loadFromFile(const string& filename);
};

