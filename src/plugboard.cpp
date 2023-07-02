#include <iostream>
#include <string>
#include "enigma.hpp"

Plugboard::Plugboard(std::string characterPairsInput) : Connector(characterPairsInput) {
    checkStringLength(characterPairsInput);
}
void Plugboard::swapCharacters(std::string characterPair){
    char tempChar = getCharacterPairs().at(alphabet.find(characterPair.at(0)));
    getCharacterPairs().at(alphabet.find(characterPair.at(0))) = getCharacterPairs().at(alphabet.find(characterPair.at(1)));
    getCharacterPairs().at(alphabet.find(characterPair.at(1))) = tempChar;
}
void Plugboard::setCharacterPairs(std::string characterPairsInput) {
    checkStringLength(characterPairsInput);
    for (int i = 0; i < 13; i++) {
        Plugboard::swapCharacters({characterPairsInput[i * 2], characterPairsInput[i * 2 + 1]});
    }
}