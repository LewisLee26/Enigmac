#include <string>
#include "enigma.hpp"

Connector::Connector(std::string characterPairsInput){
    checkStringLength(characterPairsInput);
    characterPairs = characterPairsInput;
}
void Connector::setCharacterPairs(std::string characterPairsInput){
    checkStringLength(characterPairsInput);
    characterPairs = characterPairsInput;
}
std::string Connector::getCharacterPairs(){
    return characterPairs;
}
void Connector::resetCharacterPairs(){
    characterPairs = alphabet;
}
char Connector::getCharacterPair(char characterInput){
    int index = alphabet.find(characterInput);
    return characterPairs.at(index % 26);
}