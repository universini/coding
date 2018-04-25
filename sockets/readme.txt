Steps:

1. start server in background which will be listening to client requests
   gcc -o server server.c (this will create "server" executable)
   ./server &

2. connect client by building client
   gcc -o client client.c
   ./client 127.0.0.1 (if server address if not localhost, mention here)

3. server sends current time and client reads it from socket and prints it

