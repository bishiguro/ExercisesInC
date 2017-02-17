## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic types.

2) Name two advantages of static typing over dynamic typing.

Errors that relate to a function's arguments and return value can be found more quickly (at compile time) and in parts of the program that never run.  Also, static typing saves space because variable names that exist at compile time are not stored in memory at run time.

3) Give an example of a static semantic error.

A function is called with the wrong number of arguments.

4) What are two reasons you might want to turn off code optimization?

Code optimization increases compilation time, and it can make it harder to debug when developing new code.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Different machine architectures generate different assembly code (ex: x86, MIPS).

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

Errors can come from the preprocessor (in the case of a directive error), the compiler (in the case of syntax errors), or the linker (in the case of function name errors), all of which generate different error messages.

7) What is a segmentation fault?

A failure mode that indicates that you have tried to read or write to an incorrect location in memory.

## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

An example of real-world virtualization is shopping on Amazon.  You can purchase an item from any seller with equal ease, regardless of the distance and work it takes behind the scenes to prepare and deliver that package to you.

2) What is the difference between a program and a process?

A process is a software object that represents a running program, and isolates it from the other running programs on the machine.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

Its primary purpose is to allow users to use complex software without having to understand its implementation. It creates the illusion of a simpler mechanism than actually exists under the hood.

4) What is the kernel?

The part of the operating system responsible for core capabilities, such as creating threads.

5) What is a daemon?

A process that runs in the background and provides operating system services.
 

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

2^6 values --> 6 bits

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 = 4294967296 characters

3) What is the difference between "memory" and "storage" as defined in Think OS?

Memory, such as Random Access Memory, holds the data of a running process and is volatile, which means that its contents are lost when the computer shuts down.  Storage, found on an HDD or SSD, holds files that a process reads or writes to and is non-volatile.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB = 2^30 bytes = 1073741824  
GB = 10^9 bytes = 1000000000  
7.11% difference

5) How does the virtual memory system help isolate processes from each other?

This systems isolates processes from each other because a process cannot generate a virtual address that maps to physical memory allocated to another process.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

My guess is that having the stack and the heap start at opposite ends allows for them to having the maximum amount of room to grow, rather than each of them being limited by a set number of memory locations.

7) What Python data structure would you use to represent a sparse array

A dictionary - the occupied indices can be mapped to their corresponding values.

8) What is a context switch?

A context switch is the operating system's way of interrupting a currently running process, saving its state so that it can be resumed later, and then running another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.
  
My results:  
Address of main is 0x4005d6  
Address of global is 0x60104c  
Address of local is 0x7ffdf66530dc  
Address of p is 0x6b6010  

Allen's results:  
Address of main is 0x40057c  
Address of global is 0x60104c  
Address of local is 0x7fffd26139c4  
Address of p is 0x1c3b010

1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

Address of main is 0x4005d6  
Address of global is 0x60104c  
Address of local is 0x7ffffbb24e04  
Address of p is 0x1812010  
Address of q is 0x18120a0  

Yes, the address of q is a higher address than that of p.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.

Address of local is 0x7ffc376033a4  
Address of local is 0x7ffc37603380

Yes, the stack grows down, allocating lower addresses.

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

void *p = malloc(10);  
void *q = malloc(10);  

Address of p is 0x908010  
Address of q is 0x908030  
Difference: 0x20

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

Files are byte-based, but the implementation of persistent storage is block-based.  The manner in which blocks are arranged and used varies.  On a HDD, blocks are arranged in sectors, which are arranged in tracks, which are in turn arranged in concentric circles on the disk.  On SSDs, blocks are numbered sequentially, and each block has a limited number of writes before becoming unreadable.  The file system does not deal directly with these abstracted-out details.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

I’m guessing that an OpenFileTableEntry would store information about the file it represents, such as file size, time of creation and last modification, read, write, and execute permissions, and file owner.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Prefetching predicts which blocks a process will need to access and loads these blocks into memory before they are requested.  Buffering stores data in memory while writing to a file, rather than writing to disk at each change.  Caching copies recently used blocks in memory so that they can be accessed more quickly by a program.  These strategies all take advantage of the fact that accessing data from memory is significantly faster than accessing data from disk.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

What likely happened is that the data was stored in a cache but not yet written to disk.  The cache would have been cleared on power-off, and the file had not yet made it to permanent storage.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

I’m not sure, but perhaps inodes are more flexible for files that grow significantly in size over time, since they can have up to three indirection blocks for storing content.

6) What is overhead?  What is fragmentation?

Overhead is the amount of space in memory that the allocator uses.  Fragmentation is the unused space in memory that results when the block allocation system leaves some blocks unused or partially used.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

A benefit of this principle is that it allows for multiple applications of the “stream of bytes” abstraction, in addition to file systems.  UNIX pipes, which allow for process communication, and UNIX sockets, which allow for network communication, are two examples of systems that use this principle.  This may be a bad idea if the operating system in question is not constructed using the UNIX “small tools” approach, which might render the API not flexible enough for a broad range of programs.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
