#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Tokenize text into words (lowercased, no punctuation)
vector<string> tokenize(const string& text) {
    vector<string> words; //vector that stores words
    string word;//temporary string for each word
    for (char ch : text) { //for loop that converts to lowercase and checks if letter or number
        if (isalnum(ch)) {
            word += tolower(ch);
        } else if (!word.empty()) {
            words.push_back(word); //add word to vector
            word.clear();
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

// Count word occurrences
map<string, int> countWords(const vector<string>& words) {
    map<string, int> wordCounts; //map to store word frequency
    for (const auto& word : words) { // iterate through each word in the vector
        wordCounts[word]++;
    }
    return wordCounts;
}

// Find the longest word
string longestWord(const vector<string>& words) {
    return *max_element(words.begin(), words.end(), //find longest word in the vector
                        [](const string& a, const string& b) {
                            return a.size() < b.size();
                        });
}

int main() {
    ifstream file("sample.txt");//open file
    
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    vector<string> words = tokenize(content); //tokenize file into individual words
    map<string, int> wordCounts = countWords(words);

    cout << "Word Frequency: " << endl; //show word frequency
    for (const auto& [word, count] : wordCounts) {
        cout << word << ": " << count << endl;
    }

    cout << "\nLongest Word: " << longestWord(words) << endl; //show longest word
    return 0;
}
