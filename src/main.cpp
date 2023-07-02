#include "enigma.hpp"
#include <string>
#include <iostream>

int main(){
    Rotor rotor1(rotors[0]);
    Rotor rotor2(rotors[1]);
    Rotor rotor3(rotors[2]);
    Plugboard plugboard;
    Connector reflector(reflectors[0]);
    
    std::string textInput;
    std::string textInput_clean;
    while (true){
        rotor1.setRotorPosition(0);
        rotor2.setRotorPosition(0);
        rotor3.setRotorPosition(0);
        std::cout << "Input: ";
        std::getline(std::cin, textInput);
        
        if (textInput == "exit"){
            break;
        }
        
        std::cout << std::endl;
        std::string encrypted = enigma(textInput, rotor1, rotor2, rotor3, plugboard, reflector);
        std::cout << "Output: ";
        std::cout << encrypted << std::endl;
    }

    return 0;
}