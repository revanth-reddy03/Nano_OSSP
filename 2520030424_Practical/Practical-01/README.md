# Practical-01: Linux Process Creation and OS Resource Abstraction

## Aim

To develop a C program that demonstrates how a Linux operating system executes a command entered by a user using process creation and system calls.

The experiment also investigates the relationship between hardware resources and operating system services using Linux commands such as `uname`, `lscpu`, `lsblk`, `ps`, and `top`.

---

## Objectives

1. Accept a Linux command as input from the user.
2. Create a child process using `fork()`.
3. Execute the command in the child process using `execvp()`.
4. Make the parent process wait for the child using `waitpid()`.
5. Display the Process ID (PID) of both parent and child processes.
6. Study CPU, memory, storage, and process information using Linux commands.
7. Understand how the operating system abstracts hardware resources.

---

## Software Requirements

* Linux Operating System
* GCC Compiler
* Linux Terminal
* C Programming Language

---

# Part A – Process Creation and Command Execution

## System Calls Used

### 1. `fork()`

`fork()` creates a new child process from the existing parent process.

The child receives a separate Process ID (PID).

```c
pid_t pid = fork();
```

---

### 2. `execvp()`

`execvp()` replaces the child process with the program specified by the user.

```c
execvp(args[0], args);
```

For example, if the user enters:

```text
ls
```

the child process executes the Linux `ls` command.

---

### 3. `getpid()`

`getpid()` returns the PID of the current process.

```c
getpid()
```

---

### 4. `getppid()`

`getppid()` returns the PID of the parent process.

```c
getppid()
```

---

### 5. `waitpid()`

`waitpid()` makes the parent process wait until the child process finishes execution.

```c
waitpid(pid, &status, 0);
```

---

## Program Execution Flow

```text
              Start
                |
                v
       Read Linux command
                |
                v
             fork()
            /      \
           /        \
      Child          Parent
        |               |
        v               v
    Display PID     Display PID
        |               |
        v               |
     execvp()            |
        |                |
        v                v
 Execute command     waitpid()
        |                |
        v                |
 Command finishes       |
        \               /
         \             /
          v           v
             Finish
```

---

## Sample Execution

Example command:

```text
Enter a Linux command: ls
```

Sample output:

```text
Parent Process
Parent PID : 4521
Child PID  : 4522

Child Process
Child PID  : 4522
Parent PID : 4521
Executing command: ls

README.md  program  screenshots  src  outputs

Child process has completed.
Child exit status: 0
```

> The PID values will be different on every execution.

---

# Part B – Investigating Hardware and OS Services

The following Linux commands are used to investigate hardware resources and operating system services.

---

## 1. uname

Command:

```bash
uname -a
```

Purpose:

`uname` displays information about the Linux operating system and kernel.

It can provide information such as:

* Kernel name
* Hostname
* Kernel version
* Machine architecture
* Operating system

Example:

```text
Linux mycomputer 6.x.x #1 SMP x86_64 GNU/Linux
```

### OS Abstraction

The operating system provides a common software interface to applications without requiring applications to directly understand the hardware architecture.

---

## 2. lscpu

Command:

```bash
lscpu
```

Purpose:

`lscpu` displays CPU information.

Important information includes:

* CPU architecture
* CPU model
* Number of CPUs
* Number of cores
* Number of threads
* CPU frequency

Example:

```text
Architecture:        x86_64
CPU(s):              8
Core(s) per socket:  4
Thread(s) per core:  2
```

### OS Abstraction of CPU

The operating system abstracts the CPU through process and thread scheduling.

Applications do not directly control the CPU. Instead, the OS scheduler decides which process or thread receives CPU time.

---

## 3. lsblk

Command:

```bash
lsblk
```

Purpose:

`lsblk` displays information about block storage devices.

It can show:

* Hard disks
* SSDs
* Partitions
* Storage sizes
* Mount points

Example:

```text
NAME        SIZE TYPE MOUNTPOINT
sda         500G disk
├─sda1      100G part /
└─sda2      400G part /home
```

### OS Abstraction of Storage

The operating system provides file systems and file-related system calls such as:

```text
open()
read()
write()
close()
```

Applications normally interact with files rather than directly controlling disk hardware.

---

## 4. ps

Command:

```bash
ps
```

For more detailed information:

```bash
ps aux
```

Purpose:

`ps` displays currently running processes.

Information may include:

* PID
* CPU usage
* Memory usage
* Process owner
* Process status
* Command name

Example:

```text
PID    USER     %CPU   %MEM   COMMAND
1234   user      0.0    0.1   bash
1250   user      0.2    0.5   program
```

### OS Abstraction of Processes

The operating system represents running programs as processes.

Each process has a unique PID.

The OS manages:

* Process creation
* Process scheduling
* Process termination
* Memory allocation
* CPU allocation

---

## 5. top

Command:

```bash
top
```

Purpose:

`top` provides a real-time view of system activity.

It displays:

* CPU utilization
* Memory utilization
* Running processes
* Process IDs
* Load average
* Process CPU usage
* Process memory usage

Press:

```text
q
```

to exit `top`.

### OS Abstraction

The operating system monitors and manages system resources and provides this information through system interfaces and utilities.

---

# Relationship Between Hardware and Operating System

| Hardware Resource | Linux Command  | OS Service/Abstraction               |
| ----------------- | -------------- | ------------------------------------ |
| CPU               | `lscpu`        | Process scheduling                   |
| Memory            | `top`          | Virtual memory and memory management |
| Storage           | `lsblk`        | File systems and storage management  |
| Processes         | `ps`           | Process management                   |
| System/Kernel     | `uname`        | Kernel and hardware interface        |
| I/O Devices       | `top`, `lsblk` | Device drivers and I/O management    |

---

# How Linux Abstracts Hardware

## CPU

Applications do not directly access the CPU.

The Linux kernel uses a scheduler to allocate CPU time among processes and threads.

```text
Application
     |
     v
Operating System
     |
     v
CPU Scheduler
     |
     v
CPU
```

---

## Memory

The operating system manages physical memory and provides virtual memory to processes.

Each process gets its own virtual address space.

```text
Application
     |
     v
Virtual Memory
     |
     v
Linux Memory Manager
     |
     v
Physical RAM
```

This provides isolation between processes and improves memory utilization.

---

## Storage

Applications normally use files and directories instead of directly accessing disk sectors.

```text
Application
     |
     v
File System
     |
     v
Linux Kernel
     |
     v
Storage Device
```

Linux uses system calls such as `open()`, `read()`, `write()`, and `close()` to provide controlled access to files.

---

## I/O Devices

Linux uses device drivers to communicate with hardware devices.

Examples include:

* Keyboard
* Mouse
* Display
* Network adapter
* USB devices
* Storage devices

Applications communicate with the operating system instead of directly controlling hardware.

---

# Result

The C program successfully demonstrates Linux process creation and command execution using `fork()`, `execvp()`, and `waitpid()`.

The experiment also demonstrates that the Linux operating system acts as an abstraction layer between applications and hardware resources. CPU, memory, storage, and I/O devices are managed by the operating system through scheduling, virtual memory, file systems, device drivers, and system calls.

Thus, Linux provides applications with a controlled and simplified interface for using hardware resources.
