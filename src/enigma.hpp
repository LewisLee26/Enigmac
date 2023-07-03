#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#pragma once

#include <string>

extern const std::string alphabet;

void checkStringLength(std::string stringInput, int num = 26);

class Connector {
    private:
        std::string characterPairs;
    public:
        Connector(std::string characterPairsInput);
        void setCharacterPairs(std::string characterPairsInput);
        std::string getCharacterPairs();
        char getCharacterPair(char characterInput);
};

class Rotor: public Connector {
    private:
        int rotorPosition;
    public:
        Rotor(std::string characterPairsInput, int rotorPositionInput = 0);
        char getCharacterPair(char characterInput, bool forward);
        int getRotorPosition();
        void setRotorPosition(int positionInput);
        void incrementRotorPosition();

};

class Plugboard: public Connector {
    public:
        Plugboard(std::string characterPairsInput = alphabet);
        void swapCharacters(std::string characterPair);
        void setCharacterPairs(std::string characterPairsInput);
};

extern const std::string rotors[10];

extern const std::string reflectors[5];

char rotorPass(Rotor rotorSlots[3], char currentChar, bool forward);

std::string enigma(std::string textInput, Rotor rotorSlot1, Rotor rotorSlot2, Rotor rotorSlot3, Plugboard plugboard, Connector reflector);

#endif