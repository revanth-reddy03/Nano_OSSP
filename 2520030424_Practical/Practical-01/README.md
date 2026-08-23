PRACTICAL 1
Roll Number: 2520030182
Name: P. Venkata Sri Sai Madhurima

1. C Program: Linux Command Execution
Develop a C program that demonstrates how a Linux operating system executes a command entered by a user.

Requirements
Accept a Linux command as input.
Create a child process using fork().
Execute the command in the child process using an appropriate exec() system call.
Allow the parent process to wait for the child using wait().
Display the Process ID (PID) of both parent and child processes.
2. Investigation Using Linux Terminal Commands
Using Linux terminal commands (uname, lscpu, lsblk, ps, top), investigate the relationship between hardware resources and operating system services. Prepare a report explaining how the OS abstracts CPU, memory, storage, and I/O devices.

Commands Used
uname
lscpu
lsblk
ps
top
Investigation: Relationship Between Hardware Resources and OS Services
By this process we understand how OS controls hardware.
uname displays kernel and system information.
lscpu shows CPU details such as cores and architecture.
lsblk gives information on disks.
ps is actually a static command and gives us the current process which is running.
top is dynamic; it shows all the processes and gets refreshed every 5 seconds.
By observing all these commands, we know that the OS is an interface between the user and hardware.

How the OS Abstracts Hardware
CPU: OS abstracts CPU by Process Scheduling.
Memory: OS abstracts memory by Memory Management.
Storage: OS abstracts storage by File Management.
I/O: OS abstracts I/O by I/O Management.
