#include "anagram.h"
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    string s1 = EraseSpace(word1);
    string s2 = EraseSpace(word2);
    if (s1.length() != s2.length())
    {
        return false;
    }
    TransformString(s1);
    TransformString(s2);
    if (s1 == s2)
        return true;
    return false;
}

std::string Anagram::TransformString(string word)
{
    std::string str=word;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    sort(str.begin(), str.end());
    return str;
}

std::string Anagram::EraseSpace(std::string word)
{
    std::string str=word;
    str.erase(remove_if(str.begin(), str.end(),
        [](char c) { return !isalpha(c); }), str.end());
    return str;
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
