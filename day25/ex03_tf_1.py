#%%
#모듈 로딩
import tensorflow as tf
print(f'version : {tf.__version__}')
# %%

print('gpu ', 
'사용가능' if tf.config.experimental.list_physical_devices("GPU")  else "사용불가")

# %%
print(tf.config.list_physical_devices('GPU'))

# %%

tensor_a = tf.constant(100)
print(tensor_a)
# %%

print(tensor_a.numpy())
# %%

tensor_b = tf.constant(3)
tensor_c = tf.constant(2)
#tensor_d = tf.add(tensor_b,tensor_c)
tensor_d = tensor_b + tensor_c

print(tensor_d.numpy())

# %%

tensor_ma = tf.constant([[1,2],[3,4]])
tensor_mb = tf.constant([[2,0],[0,2]])
tensor_mc = tensor_ma * tensor_mb
print(tensor_mc.numpy())

tensor_md = tf.matmul(tensor_ma,tensor_mb)
print(tensor_md.numpy())

# %%
