# Enigma C

This is a simulation for the Enigma Machine written in C.
This code is designed to be a higher performance alternative to Enigma Machine simulations to be run in python with ctypes.  

## How to use
This is how to load the function into python with ctypes.
``` python
import ctypes
import ctypes.util

# path to the enigma.dll
enigma_lib = ctypes.CDLL(r'enigma.dll')

# Define the argument and return types for the run_enigma function
enigma_lib.run_enigma.argtypes = [
    ctypes.c_int,                 # reflector
    ctypes.POINTER(ctypes.c_int), # wheel_order
    ctypes.c_char_p,              # ring_setting
    ctypes.c_char_p,              # wheel_pos
    ctypes.c_char_p,              # plugboard_pairs
    ctypes.c_uint,                # plaintextsize
    ctypes.c_char_p               # from
]
enigma_lib.run_enigma.restype = ctypes.c_char_p

def run_enigma(reflector, wheel_order, ring_setting, wheel_pos, plugboard_pairs, plaintextsize, from_str):
    return enigma_lib.run_enigma(
        reflector,
        (ctypes.c_int * len(wheel_order))(*wheel_order),
        ctypes.create_string_buffer(ring_setting.encode()),
        ctypes.create_string_buffer(wheel_pos.encode()),
        ctypes.create_string_buffer(plugboard_pairs.encode()),
        plaintextsize,
        ctypes.create_string_buffer(from_str.encode())
    ).decode()
```

## Settings 
This simulation has 5 rotors and three reflectors based on the Enigma I model 
### Rotors 
| Python Rotor Index | C Rotor Constants | Rotor Strings |
|--------------------|-------------------|---------------|
| 0 | ROTOR_I | EKMFLGDQVZNTOWYHXUSPAIBRCJ |
| 1 | ROTOR_II | AJDKSIRUXBLHWTMCQGZNPYFVOE |
| 2 | ROTOR_III | BDFHJLCPRTXVZNYEIWGAKMUSQO |
| 3 | ROTOR_IV | ESOVPZJAYQUIRHXLNFTGKDCMWB |
| 4 | ROTOR_V | VZBRGITYUPSDNHLXAWMJQOFECK |

### Reflectors 
| Python Reflector Index | C Relfector Constants | Relfector Strings |
|--------------------|-------------------|---------------|
| 0 | REFLECTOR_A | EJMZALYXVBWFCRQUONTSPIKHGD |
| 1 | REFLECTOR_B | YRUHQSLDPXNGOKMIEBFZCWVJAT |
| 2 | REFELCTOR_C | FVPJIAOYEDRZXWGCTKUQSBNMHL |

## To Do 
- Add in more enigma machine rotors and reflectors (low priority)
- Add multithreading?