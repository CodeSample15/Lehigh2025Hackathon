import socket
import uuid
import json
import threading
import time

from server import ServerState

HOST = '127.0.0.1'
PORT = 65312

running = False
threads = []

def connection_thread(conn, addr):
    with conn:
        print(f"[+] Connection started with {addr}!")

        #generate UUID and send to client
        conn.sendall(bytes(str(uuid.uuid4()), 'utf-8'))

        while running:
            data = conn.recv(1024)
            if not data:
                break

            conn.sendall(data)  

def listen_thread():
    global threads

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()

        print(f"[+] Server listening on '{HOST}:{PORT}'")
        while running:
            conn, addr = s.accept()

            threads.append(threading.Thread(target=connection_thread, args=(conn, addr)))
            threads[-1].start()


def main():
    global running

    serverState = ServerState()

    #config parsing
    with open('config.json') as f:
        try:
            config = json.load(f)
            for value in config.keys():
                pass
            
        except Exception as e:
            print("Error parsing json:")
            print(e)

    #server loop
    running = True
    
    #spin up listening thread
    lt = threading.Thread(target=listen_thread)
    lt.start()

    while True:
        try:
            time.sleep(0.1)
        except KeyboardInterrupt:
            running = False

            #do a local connection to the server (break out of blocking s.accept() in other thread)
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.connect((HOST, PORT))
            break

    lt.join() #join the listening thread

    running = False

    #cleanup threads
    print("[-] Closing threads...")
    for t in threads:
        t.join()
    print("[-] Exited")

if __name__=='__main__':
    main()