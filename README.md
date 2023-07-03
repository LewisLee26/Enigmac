# Enigmapy

## Functions 
### Enigma
Enigma is a function that takes a string and a set of enigma settings which outputs an encoded string(in uppercase). To decode a string, use the encoded string as the text input along with the same enigma settings used to encode it.
#### Arguments 
- **Text Input:** A alphabetical string (ä = ae, ü = ue, ö = oe, ß = ss).
- **Rotor Slot 1:** A Rotor object
- **Rotor Slot 2:** A Rotor object
- **Rotor Slot 3:** A Rotor object
- **Plugboard:** A Plugboard object
- **Reflector:** A Reflector object


## Constants 
### Rotor Dictionary
This is an array of strings each of which represent the standard rotors used by the Germans during WWII. Each string is 26 characters long and each character represents a connection. The character at index 0 of the string is connected to 'a', the character at index 0 of the string is connected to 'b', ect.
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
This is an array of strings each of which represent the standard reflectors used by the Germans during WWII. Each string is 26 characters long and each character represents a connection. The character at index 0 of the string is connected to 'a', the character at index 0 of the string is connected to 'b', ect.
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

This class takes a string of length 26 as a argument. This string is used to represent the connections. The character at index 0 of the string is connected to 'a', the character at index 0 of the string is connected to 'b', ect. 
#### Methods
- **getCharacterPair()**
- **getRotorPosition()**
- **setRotorPosition()**
- **incrementRotorPosition()**

### Plugboard
The Plugboard class is used to initialise plugboard.

This class takes a string of length 26 as a argument. This string is used to represent the connections. The character at index 0 of the string is connected to 'a', the character at index 0 of the string is connected to 'b', ect. 
#### Methods
- **swapCharacters**
- **setCharacterPairs()**

### Connector
The Connector class is the parent class for the Rotor and Plugboard classes. The Connector class is used to initialise reflectors.

This class takes a string of length 26 as a argument. This string is used to represent the connections. The character at index 0 of the string is connected to 'a', the character at index 0 of the string is connected to 'b', ect. 
#### Methods
- **setCharacterPairs()**
- **getCharacterPairs()**
- **resetCharacterPairs()**
- **getCharacterPair()**