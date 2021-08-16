# Experiment 4

## GIVEN REQUIREMENTS:

There are two hosts, Client and Server. The Client accepts the message from the user and sends it to the Server.
The Server receives the message, prints it and echoes the message back to the Client.

---

## TECHNICAL OBJECTIVE:

To implement an UDP Echo Client-Server application,
Where the Client on establishing a connection with the Server,sends a string to the Server.
The Server reads the String, prints it and echoes it back to the Client.

---

## METHODOLOGY:

## Server:

• Include the necessary header files.

• Create a socket using socket function with family AF_INET, type as SOCK_DGRAM.

• Initialize server address to 0 using the bzero function.

• Assign the sin_family to AF_INET, sin_addr to INADDR_ANY, sin_port to SERVER_PORT, a macro defined port number.

• Bind the local host address to socket using the bind function.

• Within an infinite loop, receive message from the client using recvfrom function, print it on the console and send (echo) the message back to the client using sendto function.

---

## Client:

• Include the necessary header files.

• Create a socket using socket function with family AF_INET, type as SOCK_DGRAM.

• Initialize server address to 0 using the bzero function.

• Assign the sin_family to AF_INET.

• Get the server IP address from the console.

• Using gethostbyname function assign it to a hostent structure, and assign it to sin_addr of the server address structure.

• Within an infinite loop, read message from the console and send the message to the server using the sendto function.

• Receive the echo message using the recvfrom function and print it on the console.
