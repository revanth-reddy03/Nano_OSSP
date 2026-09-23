# Process Synchronization and Zombie Processes

## 1. Process Synchronization using `wait()` and `waitpid()`

### Aim

To create multiple child processes and synchronize their completion using `wait()` and `waitpid()`, and compare their behavior.

### Important Functions

* `fork()` – Creates a child process.
* `wait()` – Waits for **any child process** to finish.
* `waitpid()` – Waits for a **specific child process**.
* `getpid()` – Returns the process ID.
* `getppid()` – Returns the parent process ID.

### Difference

| `wait()`               | `waitpid()`                   |
| ---------------------- | ----------------------------- |
| Waits for any child    | Can wait for a specific child |
| Less control           | More control                  |
| Simple synchronization | Flexible synchronization      |

### Flow
Parent continues after child completion
```

---

## 2. Zombie Process

### Aim

To create a zombie process, observe it in the process table, and eliminate it using proper synchronization.

### What is a Zombie?

A **zombie process** is a child process that has finished execution, but its parent has not yet collected its exit status using `wait()` or `waitpid()`.


### Important Functions

* `fork()` – Creates child process.
* `exit()` – Terminates the child.
* `wait()` – Collects the child's exit status and removes the zombie.
* `waitpid()` – Waits for a specific child and prevents zombie processes.

### Process Table

Zombie processes can be identified using commands such as:

```bash
ps
```

or

```bash
ps aux
```

A zombie is commonly shown with status **`Z`**.

## Easy Memory

```text
fork()   → Create child
wait()   → Wait for any child
waitpid() → Wait for specific child
exit()   → Terminate child
Z        → Zombie process
```

## Conclusion

`wait()` and `waitpid()` synchronize parent and child processes. Proper use of these functions prevents terminated child processes from remaining as zombies.
