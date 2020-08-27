#%%
#load module
import sys
import numpy as np

#%%
_test_np = np.arange(1,10,1)
print(_test_np)
# %%
print(type(_test_np))
# %%
list1 = [value for value in _test_np]
print(type(list1))
# %%
list2 = []
for value in _test_np :
  list2.append(value)
print(list2)

# %%
list3 = [value for value in _test_np if value%2]
print(list3)
# %%
array1 = (np.random.rand(5)*10).astype(np.int32)
array2 = (np.random.rand(5)*10).astype(np.int32)

print(array1)
print(array2)


# %%

print([_v for _v in zip(array1,array2)])

# %%
print([_v for _v in zip(array1,array2) if _v[0] >= 5 ])
# %%
