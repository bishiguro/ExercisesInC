## Sprint 2 Reflection

My team feels that during Sprint 2 we worked toward our learning goals by building up our knowledge of the C socket library, forking and child processes, and file IO.  We successfully completed our MVP, which is a working FTP server and client.  

We may have had more success this sprint by asking for help from the teaching team earlier when we ran into issues integrating our server and client.  We also could have more efficiently allocated our team resources.  Next sprint, instead of debugging issues individually, which led us to step on each other's toes and try the same solutions multiple times, we plan to debug in pairs and compare notes throughout the process.  Although we are not technically behind, integrating our FTP server and client took much more time than we expected.  To address that, we are setting internal deadlines for ourselves for completing our HTTP server and the HTTP client, and allocating more time for integration before the end of the sprint.

### Head First C exercises

Exercise 02.5: https://github.com/bishiguro/ExercisesInC/blob/master/exercises/ex02.5/find_track.c  
Exercise 03: https://github.com/bishiguro/ExercisesInC/blob/master/exercises/ex03/tee.c  
Exercise 04 (in progress): https://github.com/bishiguro/ExercisesInC/tree/master/exercises/ex04

### ThinkOS Reading Questions

Ch 3-4: https://github.com/bishiguro/ExercisesInC/blob/master/reading_questions/thinkos.md  

### Exam question(s) and solution

Question: How does the operating system take advantage of the fact that accessing main memory is significantly faster than accessing persistent storage?  Explain at least three methods used by the OS.

Solution: The OS takes advantage of main memory's faster access time with prefetching, buffering, and caching.  Prefetching predicts which blocks a process will need to access and loads them into memory before they are requested.  This will ideally reduce the number of disk accesses required when the program is running.  Buffering stores data in memory while writing to a file, rather than writing to the disk at each change.  This results in needing only one disk access after file editing is complete.  The OS also caches copies of recently used blocks in memory so that they can be accessed more quickly by a program if they are needed again.