#include "enigma.hpp"
#include <string>
#include <iostream>

int main(){
    Rotor rotor1(rotors[0], 0);
    Rotor rotor2(rotors[1], 0);
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