#%%
import socket

#tcp 클라이언트 객체 
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

#%%
print('try to connect server...')
client_socket.connect(("127.0.0.1",8282))
print('connected')
# %%

print('sending message')
client_socket.sendall('안녕'.encode())
print('send message ok')

# %%

print('wait message')
data = client_socket.recv(1024)
print(f'recevied : {data.decode()}')

client_socket.close()

# %%
