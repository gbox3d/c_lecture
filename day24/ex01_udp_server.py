#%%
import socket
from struct import *

udp_socket = socket.socket(
  socket.AF_INET,
  socket.SOCK_DGRAM
)

udp_socket.bind(('',8284))

print('init socket')

#%%
while True:
  print('wait request...')
  _data,_rinfo = udp_socket.recvfrom(1024)
  print(_data)
  print(_rinfo)
  _packet = unpack("BBhf",_data)
  if _packet[0] == 0x01: # 요청 코드 1 처리 
    _res = pack("BBHH",0xa1,0,300,400)
  elif _packet[0] == 0x02: # 요청 코드 2 처리 
    _res = pack("BBHH",0xa2,0,150,200)
  elif _packet[0] == 0x99: # 요청 코드 2 처리 
    break
  else :
    _res = pack("BBHH",0xff,0,0,0)
  
  udp_socket.sendto(_res,(_rinfo[0],_rinfo[1]))
  print('resonse ok')

# %%
