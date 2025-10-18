import socket
import json

def main():
    with open('config.json') as f:
        try:
            config = json.load(f)
            
        except Exception as e:
            print("Error parsing json:")
            print(e)

    # TODO: run main loop:


        # TODO: accept new connections

        # TODO: receive messages

if __name__=='__main__':
    main()