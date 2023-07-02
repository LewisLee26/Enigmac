#include <string>
#include "enigma.hpp"

Rotor::Rotor(std::string characterPairsInput, int rotorPositionInput) : Connector(characterPairsInput) {
    checkStringLength(characterPairsInput);
    rotorPosition = rotorPositionInput;
}
char Rotor::getCharacterPair(char characterInput, bool forward){
    int index;
    if (forward){
        index = alphabet.find(characterInput);
        return getCharacterPairs().at((26+index - rotorPosition) % 26);
    }else{
        index = getCharacterPairs().find(characterInput);
        return alphabet.at((index + rotorPosition) % 26);
    }
}
int Rotor::getRotorPosition(){
    return rotorPosition;
}
void Rotor::setRotorPosition(int positionInput){
    rotorPosition = positionInput % 26;
}
void Rotor::incrementRotorPosition(){
    rotorPosition++;
}