cmake_minimum_required(VERSION 3.29)
project(introduction_cpp_pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(introduction_cpp_pokemon main.cpp
        Pokemon.cpp
        SetOfPokemon.cpp
        SetOfPokemon.hpp
        main.cpp
        Pokedex.cpp
        Pokedex.h
        PokemonParty.cpp
        PokemonParty.h
        Pokeball.cpp
        Pokeball.h
        PlayerState.cpp
        PlayerState.h)
