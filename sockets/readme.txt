Steps:

1. start server in background which will be listening to client requests
   gcc -o server server.c (this will create "server" executable)
   ./server &

2. connect client by building client
   gcc -o client client.c
   ./client 127.0.0.1 (if server address if not localhost, mention here)

3. server sends current time and client reads it from socket and prints it

4. tun_server.c file is not related to above client and server programs.

5. tun_server.c is a server instance using tun/tap interface for user space packet processing

