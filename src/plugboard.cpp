#include <iostream>
#include <string>
#include "enigma.hpp"

Plugboard::Plugboard(std::string characterPairsInput) : Connector(characterPairsInput) {}
void Plugboard::swapCharacters(std::string characterPair){
    char tempChar = getCharacterPairs().at(alphabet.find(characterPair.at(0)));
    getCharacterPairs().at(alphabet.find(characterPair.at(0))) = getCharacterPairs().at(alphabet.find(characterPair.at(1)));
    getCharacterPairs().at(alphabet.find(characterPair.at(1))) = tempChar;
}
void Plugboard::setCharacterPairs(std::string characterPairs) {
    for (int i = 0; i < 13; i++) {
        Plugboard::swapCharacters({characterPairs[i * 2], characterPairs[i * 2 + 1]});
    }
}