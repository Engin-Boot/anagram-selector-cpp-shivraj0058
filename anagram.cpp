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
    string s1 = Anagram::RemoveSpace(word1);
    string s2 = Anagram::RemoveSpace(word2);
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

std::string Anagram::RemoveSpace(const string& str1)
{
    int i = 0, j = 0;
    string str;
    while (str1[i])
    {
        if (str1[i] != ' ')
            str[j++] = str1[i];
        i++;
    }
    str[j] = '\0';
    return str;
}