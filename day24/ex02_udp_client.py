#%%
import socket
from struct import *

udp_socket = socket.socket(
  socket.AF_INET,
  socket.SOCK_DGRAM
)

print('init socket')

_buf = pack("BBhf",0x01,0x00,10,3.14)
udp_socket.sendto(_buf,('192.168.0.9',8284))
print('send data')

_data,_rinfo = udp_socket.recvfrom(1024)
_res = unpack("BBHH",_data)
print(_res)

# %%
