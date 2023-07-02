#include <iostream>
#include <string>
#include "enigma.hpp"

const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";


Connector::Connector(std::string characterPairsInput){
    characterPairs = characterPairsInput;
}
void Connector::setCharacterPairs(char characterPairsInput[26]){
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

const std::string rotors[8] = {
        "ekmflgdqvzntowyhxuspaibrcj",
        "ajdksiruxblhwtmcqgznpyfvoe",
        "bdfhjlcprtxvznyeiwgakmusqo",
        "esovpzjayquirhxlnftgkdcmwb",
        "vzbrgityupsdnhlxawmjqofeck",
        "jpgvoumfyqbenhzrdkasxlictw",
        "nzjhgrcxmyswboufaivlpekqdt",
        "fkqhtlxocbjspdzramewniuygv"
};

const std::string reflectors[3] = {
        "ejmzalyxvbwfcrquontspikhgd",
        "nzjhgrcxmyswboufaivlpekqdt",
        "fkqhtlxocbjspdzramewniuygv"
};

char rotorPass(Rotor rotorSlots[3], char currentChar, bool forward){
    for (int j = 0; j < 3; j++){
        currentChar = rotorSlots[j].getCharacterPair(currentChar, forward);
    }
    return currentChar;
}

std::string enigma(std::string textInput, Rotor rotorSlot1, Rotor rotorSlot2, Rotor rotorSlot3, Plugboard plugboard, Connector reflector){
    // standardize the text, change umlauts to ae, ue, oe ect
    char currentChar;
    std::string outputString;
    Rotor rotorSlots[3] = {rotorSlot3, rotorSlot2, rotorSlot1};
    for (int i = 0; i < textInput.length(); i++){
        rotorSlots[0] = rotorSlot3;
        rotorSlots[2] = rotorSlot1;
        currentChar = plugboard.getCharacterPair(textInput.at(i));
        currentChar = rotorPass(rotorSlots, currentChar, true);
        currentChar = reflector.getCharacterPair(currentChar);
        rotorSlots[0] = rotorSlot1;
        rotorSlots[2] = rotorSlot3;
        currentChar = rotorPass(rotorSlots, currentChar, false);
        currentChar = plugboard.getCharacterPair(currentChar);

        // not getting appended correctly
        outputString.append(1,currentChar);
        rotorSlot1.incrementRotorPosition();
        if (rotorSlot1.getRotorPosition() == 26){
            rotorSlot1.setRotorPosition(0);
            rotorSlot2.incrementRotorPosition();
            if (rotorSlot2.getRotorPosition() == 26){
                rotorSlot2.setRotorPosition(0);
                rotorSlot3.incrementRotorPosition();
                if (rotorSlot3.getRotorPosition() == 26){
                    rotorSlot3.setRotorPosition(0);
                }
            }
        }
    }

    return outputString;
}
