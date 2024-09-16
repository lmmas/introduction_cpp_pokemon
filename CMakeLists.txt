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
        GameState.cpp
        GameState.h
        Game.cpp
        Game.h
        LoadingState.cpp
        LoadingState.h
        InitState.cpp
        InitState.h
        ExploreSafelyState.cpp
        ExploreSafelyState.h
        ExploreGrassState.cpp
        ExploreGrassState.h
        WildFightState.cpp
        WildFightState.h
        UtilityFunctions.cpp
        UtilityFunctions.h
        GameOverState.cpp
        GameOverState.h)
