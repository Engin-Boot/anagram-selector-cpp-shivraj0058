#include "anagram.h"
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    if (word1.length() != word2.length())
    {
        return false;
    }
    string s1 = word1;
    string s2 = word2;
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
    vector<string> Anagrams;
    for (int i = 0; i < candidates.size(); i++)
    {
        if (WordPairIsAnagram(word, candidates[i]))
            Anagrams.push_back(candidates[i]);
    }
    return Anagrams;
}

