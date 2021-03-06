/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    /* Your code goes here! */
    ifstream words(word_list_fname);
    
    std::vector<StringTriple> v;
    string word;
    if(words.is_open()){
    	while(getline(words,word)){
    		if(word.length() == 5)
    		{
    			string tmp3 = word.substr(2,word.length()-2);
    			string tmp2 = word.substr(0,1);
                string tmp1 = word.substr(1,word.length()-1);
    			tmp2.append(tmp3);
    			if(d.homophones(tmp1,tmp2))
    				v.push_back(make_tuple(word,tmp1,tmp2));
    		}
    	}

    }
    return v;
}
