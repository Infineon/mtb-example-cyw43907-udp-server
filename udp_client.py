#******************************************************************************
# File Name:   udp_client.py
#
# Description: A simple python based UDP client.
# 
#********************************************************************************
# $ Copyright 2021-2023 Cypress Semiconductor $.
#********************************************************************************

#!/usr/bin/env python
import socket
import optparse
import time
import sys


BUFFER_SIZE = 1024

# IP details for the UDP server
DEFAULT_IP   = '192.168.0.119'   # IP address of the UDP server
DEFAULT_PORT = 50007            # Port of the UDP server

START_MSG="A"

def udp_client( server_ip, server_port):
	print("================================================================================")
	print("UDP Client")
	print("================================================================================")
	print("Sending data to UDP Server with IP Address:",server_ip, " Port:",server_port)
    
	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	s.sendto(bytes(START_MSG, "utf-8"), (server_ip, server_port))
	
	while True:
		print("================================================================================")        
		data = s.recv(BUFFER_SIZE);
		print("Command from Server:")
		if data.decode('utf-8') == '0':
			print("LED OFF")
			message = 'LED OFF ACK'
			s.sendto(message.encode('utf-8'), (server_ip, server_port))
		if data.decode('utf-8') == '1':
			print("LED ON")
			message = 'LED ON ACK'
			s.sendto(message.encode('utf-8'), (server_ip, server_port))
		print("Acknowledgement sent to server")        
	
if __name__ == '__main__':
    parser = optparse.OptionParser()
    parser.add_option("-p", "--port", dest="port", type="int", default=DEFAULT_PORT, help="Port to listen on [default: %default].")
    parser.add_option("--hostname", dest="hostname", default=DEFAULT_IP, help="Hostname or IP address of the server to connect to.")
    (options, args) = parser.parse_args()
    #start udp client
    udp_client(options.hostname, options.port)
