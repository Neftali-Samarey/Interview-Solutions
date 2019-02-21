#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minimalOperations' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY words as parameter.
 */

vector<int> minimalOperations(vector<string> words) {

    vector<int>results;
    int wordIteration = 0;
    static int dup = 0;
    int charCount = 0;
    bool sellable = false;

    // O(n^2)

    // Looping every word in the vector
    for (int x = 0; x < words.size(); x++) {
        // Now do each word, iterate per words
        if (x == wordIteration) {
            
            // cout << "Iterating each word" << endl;
            for (int i = 1; i < words[x].size(); i++) { 

             if (words[x][i] != words[x][i + 1]) {
                cout << "NO PAIR" << endl;
                sellable = true;
               
              } else {
                sellable = false;
                charCount += 1;
                cout << "PAIR, ELIMINATE" << endl;
              }
            }
            if (sellable) {
              cout << charCount << " current index: " << x << endl;
              results.insert(results.begin() + x, charCount); // Insert value
            } else {
                cout << "0 " << " current index: " << x << endl;
                results.insert(results.begin() + x, charCount); 
            }
            charCount = 0;
            sellable = false;
        }
        wordIteration += 1;
    }

  
    return results;
}
