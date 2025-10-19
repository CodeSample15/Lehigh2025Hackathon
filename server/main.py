import socket
import uuid
import json
import threading
import time

from server import ServerState

HOST = '127.0.0.1'
HOST = '192.168.0.19'
PORT = 65312

serverState = ServerState()
running = False
threads = []

def connection_thread(conn, addr):
    with conn:
        print(f"[+] Connection started with {addr}!")

        #generate UUID and send to client
        conn_uuid = str(uuid.uuid4())
        print(f"\t- Assigning UUID: {conn_uuid}")

        conn.sendall(bytes(conn_uuid, 'utf-8'))

        while running:
            try:
                data = conn.recv(1024)
                if not data:
                    break
                print(data.decode())
                conn.sendall(b'hello, world')
            except:
                print(f"[!] Error with connection to {addr}. Closing connection.")
                conn.close()
                break

        serverState.disconnect(conn_uuid)

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

    serverState.reset()

    #config parsing
    with open('config.json') as f:
        try:
            config = json.load(f)

            for value in config['public'].keys():
                if isinstance(config['public'][value], str):
                    serverState.add_var(value, config['public'][value])
                elif isinstance(config['public'][value], dict):
                    serverState.add_obj(value, config['public'][value])
                else:
                    raise Exception(f"Unrecognized input json format: {value}")
            
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