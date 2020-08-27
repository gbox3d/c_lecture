#%%
import socket
from struct import *

udp_socket = socket.socket(
  socket.AF_INET,
  socket.SOCK_DGRAM
)

print('init socket')

_buf = pack("BBhh",0x01,0x01,10,4)
udp_socket.sendto(_buf,('192.168.0.9',8284))
print('send data')

_data,_rinfo = udp_socket.recvfrom(1024)
_res = unpack("Bh",_data)
print(_res)

# %%
