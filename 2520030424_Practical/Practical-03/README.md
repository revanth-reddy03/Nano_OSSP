# Practical 3: Zombie Processes in C

## Objective
The goal of this practical is to investigate operating system process states by intentionally creating a zombie process (a terminated child whose parent has not yet read its exit status) and then learning how to properly eliminate it using process synchronization (wait).

## Project Structure
* src/Program.c - Source code implementing the zombie process creation.
* outputs/Command.txt - Text file containing the terminal output and process status logs.
* Output.png - Screenshot showing the zombie process in the process table (ps aux).
* ReadMe.md - Documentation for the practical.
