#%%
import socket

#socket.socket(socket.AF_INET,socket.SOCK_STREAM)
udp_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
udp_socket.bind(('127.0.0.1',8284))

print('bind port 8284')

_data , _rinfo = udp_socket.recvfrom(1024)

print(f'received : {_rinfo[0]}:{_rinfo[1]} : {_data.decode()}')


# %%
