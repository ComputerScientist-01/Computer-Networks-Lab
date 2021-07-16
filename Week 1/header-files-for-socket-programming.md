1. `stdio.h`   
   Has standard input and output library providing simple and efficient buffered stream IO interface.

2. `unistd.h`  
   It is a POSIX standard for open system interface. [Portable Operating System Interface].Fork() pipe() , Object.clone()

3. `string.h`    
   This header file is used to perform string manipulation operations on NULL terminated strings.

4. `stdlib.h`  
   This header file contains the utility functions such as string conversion routines, memory allocation routines, random number generator, etc.

5. `sys/types.h`   
   Defines the data type of socket address structure in unsigned long.  
   The `sys/types.h` header includes definitions for at least the following types:
   
   1. ` blkcnt_t` 
      Used for file block counts 
   
   2. `blksize_t`
      Used for block sizes 
   
   3. `clock_t`    
      Used for system times in clock ticks or CLOCKS_PER_SEC   
   
   4. `clockid_t`  
      Used for clock ID type in the clock and timer functions. 
   
   5. `dev_t` 
      Used for device IDs. 
   
   6. `fsblkcnt_t` 
      Used for file system block counts   
   
   7. `fsfilcnt_t` 
      Used for file system file counts 

6. `sys/socket.h`   
The socket functions can be defined as taking pointers to the generic socket address structure called sockaddr.   

7. `netinet/in.h`    
Defines the IPv4 socket address structure commonly called Internet socket address structure called sockaddr_in.   

1. `netdb.h`  
Defines the structure hostent for using the system call gethostbyname to get the network host entry.  

9. `time.h`   
Has structures and functions to get the system date and time and to perform time manipulation functions. We use the function ctime(), that is defined in this header file , to calculate the current date and time.  

10. `sys/stat.h`   
Contains the structure stat to test a descriptor to see if it is of a specified type. Also it is used to display file or file system status.stat() updates any
time related fields.when copying from 1 file to another.    

11. `sys/ioctl.h`   
Macros and defines used in specifying an ioctl request are located in this header file. We use the function ioctl() that is defined in this header file. ioctl() function is used to perform ARP cache operations.   

12. `pcap.h`  
Has function definitions that are required for packet capturing. Some of the functions are pcap_lookupdev(),pcap_open_live() and pcap_loop().pcap_lookupdev() is used to initialize the network device.The device to be sniffed is opened using the pcap_open_live(). Pcap loop() determines the number of packets to be sniffed.

13. `net/if_arp.h`  
Contains the definitions for Address Resolution Protocol. We use this to manipulate the ARP request structure and its data members  

14. `errno.h`     
It sets an error number when an error and that error can be displayed using perror function. It has symbolic error names. The error number is never set to zero by any library function.   

15. `arpa/inet.h`   
This is used to convert internet addresses between ASCII strings and network byte ordered binary values (values that are stored in socket address structures). It is used for inet_aton, inet_addr, inet_ntoa functions. 