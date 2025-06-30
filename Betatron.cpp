//
// Created by richa on 30/03/2024.
//

#include "Betatron.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Betatron::memory_dump() {
    char prev = std::cout.fill('0');
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 9; col++) {
            std::cout << std::setw(4) << memory[10 * row + col] << " ";
        }
        std::cout << std::setw(4) << memory[10 * row + 9] << std::endl;
    }
    std::cout.fill(prev);
}


void Betatron::read_program() {
    for (int i = 0; i < 100; i++) memory[i]=0;

    std::string line;
    int memcounter = 1;
    while (std::getline(std::cin, line) && line.find("RUN") != 0) {
        int command = std::stoi(line);
        memory[memcounter++] = command;
    }
//    memory_dump();
}

void Betatron::run_program()
{
    program_counter = 1; // Start at the first line of the program

    while (true) {
        int instruction = memory[program_counter++];
        int opcode = instruction / 100;
        int operand = instruction % 100;

        switch (opcode) {
            case 0: // SKIP
                break; // No operation
            case 10: // INPUT
                if(operand == 0) {
                    std::cin >> accumulator;
                } else {
                    std::cin >> memory[operand];
                }
                break;
            case 20: // OUTPUT
                if(operand == 0) {
                    std::cout << accumulator << std::endl;
                } else {
                    std::cout << memory[operand] << std::endl;
                }
                break;
            case 30: // INC
                accumulator++;
                break;
            case 31: // DEC
                accumulator--;
                break;
            case 40: // ADD
                accumulator += memory[operand];
                break;
            case 41: // SUB
                accumulator -= memory[operand];
                break;
            case 50: // LOAD
                accumulator = memory[operand];
                break;
            case 60: // STORE
                memory[operand] = accumulator;
                break;
            case 70: // JUMP
                program_counter = operand;
                break;
            case 71: // JUMPPOS
                if (accumulator > 0) program_counter = operand;
                break;
            case 72: // JUMPZERO
                if (accumulator == 0) program_counter = operand;
                break;
            case 99: // HALT
                return; // Stop execution
            default:
                std::cerr << "Invalid opcode: " << opcode << std::endl;
        }
    }
}

