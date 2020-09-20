#include <string>
#include <vector>

namespace Anagram
{
    bool WordPairIsAnagram(const std::string& word1, const std::string& word2);
    std::string TransformString(std::string);
    std::string EraseSpace(std::string);

    std::vector<std::string> SelectAnagrams(
        const std::string& word,
        const std::vector<std::string>& candidates);
} // namespace Anagram
