# Practical-01: Process Execution & Hardware Resource Abstraction

## Objective
1. Develop a C program to accept a user command, create a child process via fork(), execute it using exec(), synchronize using wait(), and display parent and child PIDs[cite: 1].
2. Investigate the relationship between hardware resources and operating system services using Linux terminal commands (uname, lscpu, lsblk, ps, top).

---

## Part 1: C Program (fork, exec, wait)

### Description
The program takes an input command from the user, spawns a duplicate process using fork(), replaces the child process's image with the requested command using execvp(), displays the respective process IDs, and ensures the parent waits safely using wait().

### Source Code Reference
* Location: SRC/Program.c

---

## Part 2: Hardware-OS Investigation Report

### 1. Introduction
An Operating System acts as an intermediary between user-space applications and underlying hardware. It abstracts complex physical components—such as microprocessors, RAM chips, and storage platters—into clean, manageable services like processes, virtual memory, and file systems.

### 2. CPU and Kernel Abstraction (uname and lscpu)
* **uname -a **: Inspects the kernel version and machine architecture. The OS kernel provides a uniform system call interface, hiding hardware-level discrepancies from applications.
* **lscpu **: Details the CPU architecture, cores, and threads. The OS abstracts these physical computing elements into logical execution units, scheduling tasks dynamically to maximize efficiency.

### 3. Storage Abstraction (lsblk)
* **lsblk **: Displays block storage devices and partitions. Physical storage consists of raw sectors, tracks, and heads; the OS abstracts this through the Virtual File System (VFS) and block device drivers, turning raw hardware blocks into structured files and directories.

### 4. Process and Memory Management (ps and top)
* **ps  / top **: Monitor active processes, CPU load, and memory consumption. The OS provides **Virtual Memory** via the Memory Management Unit (MMU), isolating each process's address space while scheduling CPU time-slices so multiple applications share physical resources seamlessly.
