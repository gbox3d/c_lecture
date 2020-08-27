#%%
#load module
import sys
import numpy as np

print(f'numpy version {np.__version__}')

# %%
data1 = [1,2,3,4,5]
print(type(data1))
# %%
array_1 = np.array(data1)
print(type(array_1))

# %%
print(f'data type : {array_1.dtype}')
# %%
print(array_1.shape)
# %%
data2 = [[1,2],[3,4],[5,6]]
array_2 = np.array(data2)
print(array_2.shape)
# %%

data3 = [1.1,3.3,2.2]
array_3 = np.array(data3)
print(array_3.dtype)
_array_3 = array_3.astype(np.int32)
print(_array_3)
# %%

data4 = np.array([1,2,3,4,5])
_data4 = data4 * 10
print(_data4)

# %%
print(data4[0:2] * 10)

# %%
data5 = np.array(['a','b','c','d','e'])
print(data5)
data5[data4 > 2] = '-'
print(data5)
# %%
_a1 = np.array([1,2,3,4,5,6,7,8,9])
_a2 = np.array([11,12,13,14,15])
print(_a1)
_a1[2:5] = _a2[1:4]
print(_a1)
