#%%
#load module
import sys
import numpy as np


# %%
#초기화 예
array_1 = np.arange(0,10,1)
print(array_1)
# %%
print(array_1[:])
print(array_1[1:7])

# %%
array_2 = np.zeros(10)
print(array_2)
# %%
array_3 = np.zeros(10,dtype=np.int32)
print(array_3)
# %%
array_4 = np.ones(10,dtype=np.int32)
print(array_4)
# %%
array_5 = np.ones(10,dtype=np.int32) * 3
print(array_5)
# %%
array_6 = np.random.rand(10)
print((array_6*100).astype(np.int32))
# %%
array_7 = (array_6*100).astype(np.int32)
print(array_7)
print(np.sort(array_7))

#%%
array_8 = (array_6*100).astype(np.int32)
print(array_8)
print(np.argsort(array_8))


# %%
x1 = np.array([
  [1,9],
  [0,8],
  [6,3],
  [3,4],
  [4,1]
])

print(x1[:,0])
print(x1[:,1])


print(x1[:,0].argsort())
print(x1[:,1].argsort())

#%%
sort_indexs = x1[:,0].argsort()
# print(x1[sort_indexs[0]])

for i in sort_indexs:
  print(x1[i])











# %%
