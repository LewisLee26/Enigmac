#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#pragma once

#include <string>

extern const std::string alphabet;

class Connector {
    private:
        std::string characterPairs;
    public:
        Connector(std::string characterPairsInput);
        void setCharacterPairs(char characterPairsInput[26]);
        std::string getCharacterPairs();
        void resetCharacterPairs();
        char getCharacterPair(char characterInput);
};

class Rotor: public Connector {
    private:
        int rotorPosition;
    public:
        Rotor(std::string characterPairsInput, int rotorPositionInput);
        char getCharacterPair(char characterInput, bool forward);
        int getRotorPosition();
        void setRotorPosition(int positionInput);
        void incrementRotorPosition();

};

class Plugboard: public Connector {
    public:
        Plugboard(std::string characterPairsInput);
        void swapCharacters(std::string characterPair);
        void setCharacterPairs(std::string characterPairs);
};

extern const std::string rotors[8];

extern const std::string reflectors[3];

char rotorPass(Rotor rotorSlots[3], char currentChar, bool forward);

std::string enigma(std::string textInput, Rotor rotorSlot1, Rotor rotorSlot2, Rotor rotorSlot3, Plugboard plugboard, Connector reflector);

#endif