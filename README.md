# LinuxKernel to Application Interaction.

Pyhton file : It interacts with driver file which interun calls system calls to get the work done by the Kernel. 

C file: Contains Linux Kernel Module (LKM)

Linux Kernel Module (LKM) program that demonstrates the creation of a /proc file system entry to interact with the kernel. The module allows users to read from and write to a buffer in the kernel space through the /proc entry.

Makefile : Has two targets to execute

1. Build and Load Module (all target)
2. Clean (clean target)

