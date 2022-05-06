cmake_minimum_required(VERSION 3.21)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinalProject Blackjack.cpp Deck.cpp Deck.h Card.cpp Card.h Player.cpp Player.h Human.cpp Human.h Dealer.cpp Dealer.h)
