import enigmacpp
import time

rotor1 = enigmacpp.Rotor(enigmacpp.rotors[0], 0)
rotor2 = enigmacpp.Rotor(enigmacpp.rotors[1], 0)
rotor3 = enigmacpp.Rotor(enigmacpp.rotors[2], 0)
plugboard = enigmacpp.Plugboard(enigmacpp.alphabet)
reflector = enigmacpp.Connector(enigmacpp.reflectors[0])

test_string = "Hello World!"

start_time = time.time()
for i in range(1000):
    output = enigmacpp.enigma(test_string, rotor1, rotor2, rotor3, plugboard, reflector)
end_time = time.time()

print(end_time-start_time)