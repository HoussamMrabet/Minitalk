# Minitalk Project

This project involves creating a small data exchange program using UNIX signals. The program consists of a client and a server, where the server must be started first. The client sends a string to the server, and the server displays the received string.

## Table of Contents
- [Introduction](#introduction)
- [Instructions](#instructions)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Compilation](#compilation)
- [Example](#example)
- [Bonus Features](#bonus-features)
- [Contact](#contact)

## Introduction
The project focuses on implementing a communication program using only UNIX signals (SIGUSR1 and SIGUSR2). The client takes the server's PID and a string as parameters, and the server prints the received string.

## Instructions
- The project is written in C and follows the Norm coding standards.
- The Makefile must compile the source files without relinking.
- The communication is done using only SIGUSR1 and SIGUSR2 signals.
- The server must be started before the client.
- The server displays its PID upon launch.
- The client sends the string parameter to the server.
- The server must quickly display the received string.
- Error handling and memory management are crucial.
- The code must be free of memory leaks and unexpected quits.

## Usage
1. Clone the repository: `git clone https://github.com/HoussamMrabet/Minitalk.git`
2. Navigate to the project directory: `cd minitalk`
3. Compile the program using the provided Makefile: `make`
   ```bash
   make
   libft.a created! ✅
   server created! ✅
   client created! ✅
   ```
5. Launch the server first to get the pid: `./server`
   ```bash
   ./server
   70616
   
   ```
7. In a separate terminal, launch the client with the server PID and a string: `./client <server_pid> "My message"`
   ```bash
   ./client 70616 "My message"
   ```
   ```bash
   ./server
   70616
   My message

   ```
9. for bonus part compile the program using the provided Makefile: `make bonus`
    ```bash
    make bonus
    libft.a created! ✅
    server_bonus created! ✅
    client_bonus created! ✅
    ```
11. Launch the server first to get the pid: `./server_bonus`
    ```bash
    ./server_bonus
    70616
    
    ```
13. In a separate terminal, launch the client with the server PID and a string: `./client_bonus <server_pid> "My bonus message ✅"`
    ```bash
    ./client_bonus 70616 "My bonus message ✅"
    
    ```
    ```bash
    ./server_bonus
    70616
    My bonus message ✅
    
    ```
    ```bash
    ./client_bonus 70616 "My bonus message ✅"
    [SUCCESS] Message recieved by the server.
    ```

## Dependencies
- This project relies on the [libft](https://github.com/HoussamMrabet/libft.git) library, which is a collection of custom C functions.
- The [ft_printf](https://github.com/HoussamMrabet/ft_printf.git) function is used for displaying messages.

## Compilation
To compile the project, use the provided Makefile. Run `make` for mandatory part or `make bonus` for bonus part to compile the server and client executables.

## Example
1. Launch the server:
   ```bash
   ./server
   ```

2. In a separate terminal, launch the client with the server PID and a string:
   ```bash
   ./client <server_pid> "Hello, Minitalk!"
   ```

## Bonus Features
The bonus part includes additional features that are evaluated only if the mandatory part is perfect:
- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support.

## Contact
For any inquiries or feedback, please contact [houssammrabet5@gmail.com](mailto:houssammrabet5@gmail.com).
