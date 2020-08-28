#%%
import tensorflow as tf
import numpy as np

print(f'tf version {tf.__version__}')

#%%
_input = np.array([[0,0],[0,1],[1,0],[1,1]]).astype(np.float64)

import ex04_tf_xor

model = ex04_tf_xor.create_model()
model.load_weights('train_data/xor.ckpt')

#%%
print(model(_input))
# %%
