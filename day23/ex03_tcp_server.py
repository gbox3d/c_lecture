#%%
import socket

#tcp 서버 객체 
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

server_socket.bind( ("127.0.0.1",8282) )
server_socket.listen(5)

print('wait connect')
clent_socket,addr = server_socket.accept()
print(f'connected {addr}')

print('wait data')
data = clent_socket.recv(1024)
print(f'received : {addr} : {data.decode()}')

clent_socket.sendall('bye'.encode())
clent_socket.close()


# %%
