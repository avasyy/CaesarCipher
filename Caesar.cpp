//
// Created by yuriy on 14.08.18.
//

#include "Caesar.h"

/* function for encrypt available text */

std::string encrypt(std::string text, int key)
{
    std::string result = "";                                    // string for save result of encrypting
    std::vector<std::string> words;                             // vector for save words from text

    boost::split(words, text, boost::is_any_of("\t "));         // cutting text on pieces by deliminator

    for (int i=0 ;i < words.size(); i++) {
        std::string word = words[i];                            // string for save word from vector
        for (int j = 0; j < word.length(); j++) {
            char symbol = word[j];                              // variable for save char from vector

            // if symbol is not a letter we can add it to result string

            if (!isalpha(word[j]))
                result += symbol;

            // if symbol it's a letter in upper register we are using next formula

            else if (isupper(word[j]))
            {
                symbol += key;

                if (symbol > 'Z')
                    symbol = symbol -'Z' + 'A' - 1;

                result += symbol;
            }

            // if symbol it's a letter in lower register we are using another formula

            else if (islower(word[j]))
            {
                symbol += key;

                if (symbol > 'z')
                    symbol = symbol - 'z' + 'a' - 1;

                result += symbol;
            }
        }


        result += " ";                                          // adding space-symbol to a result
    }

    return result;
}

/* function for decrypt encrypted text */

std::string decrypt(std::string text, int key)
{
    std::string result = "";                                    // string for save result of decrypting
    std::vector<std::string> words;                             // vector for save words from text

    boost::split(words, text, boost::is_any_of("\t "));         // cutting text on pieces by deliminator

    for (int i=0; i < words.size(); i++) {
        std::string word = words[i];
        for (int j = 0; j < word.length(); j++) {
            char symbol = word[j];

            // if symbol is not a letter we can add it to result string

            if (!isalpha(word[j]))
                result += symbol;

            // if symbol it's a letter in upper register we are using next formula

            else if (isupper(word[j]))
            {
                symbol -= key;

                if (symbol > 'Z')
                    symbol = symbol +'Z' - 'A' + 1;

                if (symbol < 'A')
                    symbol = 'Z' - 'A' + symbol + 1;

                result += symbol;
            }

            // if symbol it's a letter in lower register we are using another formula

            else if (islower(word[j]))
            {
                symbol -= key;

                if (symbol > 'z')
                    symbol = symbol + 'z' - 'a' + 1;

                if (symbol < 'a')
                    symbol = 'z' - 'a' + symbol + 1;

                result += symbol;
            }
        }
        result += " ";                                      // adding space-symbol to a result
    }

    return result;
}