### What is this?

This is a simplistic example of using pthreads in C.

All it does is:

1. Define an array of 9 numbers
2. Create three threads
3. Thread one is responsible for adding numbers 0-2 in the array
4. Thread two is responsible for adding numbers 3-5 in the array
5. Thread three is responsible for adding numbers 6-9 in the array
6. Then we wait for each of the threads to finish and add the sum.

Like I said, this is hyper-simplistic, but you can extrapolate from here if you wanted to build more complex multi-threaded programs.
