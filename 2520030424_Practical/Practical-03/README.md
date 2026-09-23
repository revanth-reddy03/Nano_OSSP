# Practical-03: Parent and Child Process Using fork()

## Aim

To develop a C program using `fork()` to create a parent and child process and display their Process ID (PID), Parent Process ID (PPID), and process states.

## Description

The `fork()` system call is used to create a new child process from the parent process.

After `fork()`:

- The **parent process** continues its execution.
- The **child process** gets a separate PID.
- `getpid()` is used to display the PID of the current process.
- `getppid()` is used to display the PPID of the current process.

The process state can be observed using Linux commands such as `ps`.

## System Calls / Functions Used

| Function | Purpose |
|---|---|
| `fork()` | Creates a child process |
| `getpid()` | Returns the PID of the current process |
| `getppid()` | Returns the PPID of the current process |

## Program Flow

```text
             fork()
               ↓
        ┌──────┴──────┐
        ↓             ↓
     Parent          Child
        ↓             ↓
    getpid()       getpid()
    getppid()      getppid()
        ↓             ↓
     Running       Running

## Compilation
gcc practical3.c

##output
./a.out
