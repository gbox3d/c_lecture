#%%
from struct import *

print(f'load struct module ')

# %%
buf = pack('hhl',1,2,3)
# %%
_data = unpack('hhl',buf)
print(_data)
# %%

_f = open('t1.bin','wb')
_f.write(buf)
_f.close()

# %%

_f = open('t2.bin','rb')
buf = _f.read()
_f.close()

print(buf)
