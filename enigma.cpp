#include <iostream>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

class Connector {
    private:
        std::string characterPairs;
    public:
        Connector(std::string characterPairsInput){
            characterPairs = characterPairsInput;
        }
        void setCharacterPairs(char characterPairsInput[26]){
            characterPairs = characterPairsInput;
        }
        std::string getCharacterPairs(){
            return characterPairs;
        }
        void resetCharacterPairs(){
            characterPairs = alphabet;
        }
        char getCharacterPair(char characterInput){
            int index = alphabet.find(characterInput);
            return characterPairs.at(index % 26);
        }
};

class Rotor: public Connector {
    private:
        int rotorPosition;
    public:
        Rotor(std::string characterPairsInput, int rotorPositionInput) : Connector(characterPairsInput) {
            rotorPosition = rotorPositionInput;
        }
        char getCharacterPair(char characterInput, bool forward){
            int index;
            if (forward){
                index = alphabet.find(characterInput);
                return getCharacterPairs().at((26+index - rotorPosition) % 26);
            }else{
                index = getCharacterPairs().find(characterInput);
                return alphabet.at((index + rotorPosition) % 26);
            }
        }
        int getRotorPosition(){
            return rotorPosition;
        }
        void setRotorPosition(int positionInput){
            rotorPosition = positionInput % 26;
        }
        void incrementRotorPosition(){
            rotorPosition++;

        }

};

class Plugboard: public Connector {
    public:
        Plugboard(std::string characterPairsInput) : Connector(characterPairsInput) {}
        void swapCharacters(std::string characterPair){
            char tempChar = getCharacterPairs().at(alphabet.find(characterPair.at(0)));
            getCharacterPairs().at(alphabet.find(characterPair.at(0))) = getCharacterPairs().at(alphabet.find(characterPair.at(1)));
            getCharacterPairs().at(alphabet.find(characterPair.at(1))) = tempChar;
        }
        void setCharacterPairs(std::string characterPairs) {
            for (int i = 0; i < 13; i++) {
                swapCharacters({characterPairs[i * 2], characterPairs[i * 2 + 1]});
            }
        }
};

std::string rotors[8] = {
        "ekmflgdqvzntowyhxuspaibrcj",
        "ajdksiruxblhwtmcqgznpyfvoe",
        "bdfhjlcprtxvznyeiwgakmusqo",
        "esovpzjayquirhxlnftgkdcmwb",
        "vzbrgityupsdnhlxawmjqofeck",
        "jpgvoumfyqbenhzrdkasxlictw",
        "nzjhgrcxmyswboufaivlpekqdt",
        "fkqhtlxocbjspdzramewniuygv"
};

std::string reflectors[3] = {
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

int main() {
    Rotor rotor1(rotors[0], 0);
    Rotor rotor2( rotors[1], 0);
    Rotor rotor3(rotors[2], 0);
    Plugboard plugboard(alphabet);

    Connector reflector(reflectors[0]);
    // Connector reflector(alphabet);
    std::string textInput = "helloworld";
    rotor1.setRotorPosition(0);
    rotor2.setRotorPosition(0);
    rotor3.setRotorPosition(0);
    std::string encrypted = enigma(textInput, rotor1, rotor2, rotor3, plugboard, reflector);
    std::cout << encrypted << std::endl;
    rotor1.setRotorPosition(0);
    rotor2.setRotorPosition(0);
    rotor3.setRotorPosition(0);
    std::string decrypted = enigma(encrypted, rotor1, rotor2, rotor3, plugboard, reflector);
    std::cout << decrypted << std::endl;

    return 0;
}