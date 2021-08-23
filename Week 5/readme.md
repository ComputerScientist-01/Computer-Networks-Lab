# Week 5 : CONCURRENT TCP/IP DAY-TIME SERVER

## GIVEN REQUIREMENTS:

There are two hosts, Client and Server. The Client requests the concurrent server for the
date and time. The Server sends the date and time, which the Client accepts and prints.

## TECHNICAL OBJECTIVE:

To implement a TCP/IP day time server (concurrent server) that handles multiple client
requests. Once the client establishes connection with the server, the server sends its day-time details to the
client which the client prints in its console.

## METHODOLOGY:

### Server:

1. Include the necessary header files.
2. Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
3. Initialize server address to 0 using the bzero function.
4. Assign the sin_family to AF_INET, sin_addr to INADDR_ANY, sin_port to statically
   assigned port number.
5. Bind the local host address to socket using the bind function.
6. Within a for loop, accept connection request from the client using accept function.
7. Use the fork system call to spawn the processes.
8. Calculate the current date and time using the ctime() function. Change the format so that it
   is appropriate for human readable form and send the date and time to the client using the
   write function.

### Client:

1. Include the necessary header files.
2. Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
3. Initialize server address to 0 using the bzero function.
4. Assign the sin_family to AF_INET.
5. Get the server IP address from the console.
6. Using gethostbyname function assign it to a hostent structure, and assign it to sin_addr of
   the server address structure.
7. Request a connection from the server using the connect function.
8. Within an infinite loop, receive the date and time from the server using the read function
   and print the date and time on the console.
