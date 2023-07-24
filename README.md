# Enigmacpp

Enigmacpp is a simulation of the Enigma Machine used by the Germans in WWII written in C++ for Python. 

## Example
Here is a simple example of how to set up an enigma machine using its sub-components, encrypt, and decrypt a string:
```python
import enigmacpp

rotor1 = enigmacpp.Rotor(enigmacpp.rotors[0], 0)
rotor2 = enigmacpp.Rotor(enigmacpp.rotors[1], 0)
rotor3 = enigmacpp.Rotor(enigmacpp.rotors[2], 0)
plugboard = enigmacpp.Plugboard(enigmacpp.alphabet)
reflector = enigmacpp.Connector(enigmacpp.reflectors[0])

testString = "Hello World!"

encryptedString = enigmacpp.enigma(testString, rotor1, rotor2, rotor3, plugboard, reflector)
# This will output LKEUEHEAQE
print(encryptedString)

# You must use the same Enigma Machine settings to decode the message as you did to encode it
rotor1.setRotorPosition(0)
rotor2.setRotorPosition(0)
rotor3.setRotorPosition(0)

decryptedString = enigmacpp.enigma(encryptedString, rotor1, rotor2, rotor3, plugboard, reflector)
# This will output HELLOWORLD
print(decryptedString)
```

## Functions 
### enigma
The enigma function takes a string and a set of enigma settings as inputs and outputs an encoded string(uppercase). To decode a string, input the encoded string along with the same enigma settings used to encode it.
#### Arguments 
- **Text Input:** A alphabetical string (ä = ae, ü = ue, ö = oe, ß = ss).
- **Rotor Slot 1:** A Rotor object
- **Rotor Slot 2:** A Rotor object
- **Rotor Slot 3:** A Rotor object
- **Plugboard:** A Plugboard object
- **Reflector:** A Reflector object


## Constants 
### Rotor Dictionary
This is an array of strings each of which represent the standard rotors used by the Germans during WWII. Each string is 26 characters long and each character represents a connection. The character at index 0 of the string is connected to 'A', the character at index 0 of the string is connected to 'B', etc.
- **0(I)** = EKMFLGDQVZNTOWYHXUSPAIBRCJ
- **1(II)** = AJDKSIRUXBLHWTMCQGZNPYFVOE
- **2(III)** = BDFHJLCPRTXVZNYEIWGAKMUSQO
- **3(IV)** = ESOVPZJAYQUIRHXLNFTGKDCMWB
- **4(V)** = VZBRGITYUPSDNHLXAWMJQOFECK
- **5(VI)** = JPGVOUMFYQBENHZRDKASXLICTW
- **6(VII)** = NZJHGRCXMYSWBOUFAIVLPEKQDT
- **7(VIII)** = FKQHTLXOCBJSPDZRAMEWNIUYGV
- **8(Beta)** = LEYJVCNIXWPBQMDRTAKZGFUHOS
- **9(Gamma)** = FSOKANUERHMBTIYCWLQPZXVGJD

### Reflector Dictionary
This is an array of strings each of which represents the standard reflectors used by the Germans during WWII. Each string is 26 characters long and each character represents a connection. The character at index 0 of the string is connected to 'A', the character at index 0 of the string is connected to 'B', etc.
- **0(UKW-A)** = EJMZALYXVBWFCRQUONTSPIKHGD
- **1(UKW-B)** = YRUHQSLDPXNGOKMIEBFZCWVJAT
- **2(UKW-C)** = FVPJIAOYEDRZXWGCTKUQSBNMHL
- **3(UKW-B thin)** = ENKQAUYWJICOPBLMDXZVFTHRGS
- **4(UKW-C thin)** = RDOBJNTKVEHMLFCWZAXGYIPSUQ

### Alphabet   
This is a string of the alphabet in uppercase.


## Classes
### Rotor
The Rotor class is used to initialise rotors.

This class takes a string of length 26 as an argument. This string is used to represent the connections. The character at index 0 of the string is connected to 'A', the character at index 0 of the string is connected to 'B', etc. 
#### Methods
- **getCharacterPair()**
- **getRotorPosition()**
- **setRotorPosition()**
- **incrementRotorPosition()**

### Plugboard
The Plugboard class is used to initialise the plugboard.

This class takes a string of length 26 as an argument. This string is used to represent the connections. The character at index 0 of the string is connected to 'A', the character at index 0 of the string is connected to 'B', etc. 
#### Methods
- **swapCharacters()**
- **setCharacterPairs()**

### Connector
The Connector class is the parent class for the Rotor and Plugboard classes. The Connector class is used to initialise reflectors.

This class takes a string of length 26 as an argument. This string is used to represent the connections. The character at index 0 of the string is connected to 'A', the character at index 0 of the string is connected to 'B', etc. 
#### Methods
- **setCharacterPairs()**
- **getCharacterPairs()**
- **resetCharacterPairs()**
- **getCharacterPair()**
