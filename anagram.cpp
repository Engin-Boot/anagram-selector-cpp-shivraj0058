#include "anagram.h"
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    string s1 = word1;
    string s2 = word2;
    s1.erase(remove_if(s1.begin(), s1.end(),
        [](char c) { return !isalpha(c); }), s1.end());

    s2.erase(remove_if(s2.begin(), s2.end(),
        [](char c) { return !isalpha(c); }), s2.end());
    if (s1.length() != s2.length())
    {
        return false;
    }
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2)
        return true;
    return false;
}

std::vector<std::string> Anagram::SelectAnagrams(
        const std::string& word,
        const std::vector<std::string>& candidates) {
    //Fill the correct implementation here
    int candidates_size = candidates.size();
    vector<string> Anagrams;
    for (int i = 0; i < candidates_size; i++)
    {
        if (WordPairIsAnagram(word, candidates[i]))
            Anagrams.push_back(candidates[i]);
    }
    return Anagrams;
}
