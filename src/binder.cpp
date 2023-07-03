#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include "enigma.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(enigmacpp, m) {
    m.doc() = R"pbdoc(
        Enigmacpp
        -----------------------

        .. currentmodule:: enigmacpp

        .. autosummary::
           :toctree: _generate

           Connector
           Rotor
           Plugboard
    )pbdoc";

    // py::object alphabetWrapper = py::cast(alphabet);
    py::str alphabetWrapper = py::str(alphabet);
    m.attr("alphabet") = alphabetWrapper;

    py::list rotorsWrapper;
    for (const std::string& rotor : rotors) {
        rotorsWrapper.append(rotor);
    }
    m.attr("rotors") = rotorsWrapper;

    py::list reflectorsWrapper;
    for (const std::string& reflector : reflectors) {
        reflectorsWrapper.append(reflector);
    }
    m.attr("reflectors") = reflectorsWrapper;


    py::class_<Connector>(m, "Connector")
        .def(py::init<std::string>())
        .def("setCharacterPairs", &Connector::setCharacterPairs)
        .def("getCharacterPairs", &Connector::getCharacterPairs)
        .def("getCharacterPair", &Connector::getCharacterPair);

    py::class_<Rotor>(m, "Rotor")
        .def(py::init<std::string, int>())
        .def("getCharacterPair", &Rotor::getCharacterPair)
        .def("getRotorPosition", &Rotor::getRotorPosition)
        .def("setRotorPosition", &Rotor::setRotorPosition)
        .def("incrementRotorPosition", &Rotor::incrementRotorPosition);

    py::class_<Plugboard>(m, "Plugboard")
        .def(py::init<std::string>())
        .def("swapCharacters", &Plugboard::swapCharacters)
        .def("setCharacterPairs", &Plugboard::setCharacterPairs);

    m.def("enigma", &enigma);

    m.attr("__version__") = "0.0.1";

}


