#%%
import tensorflow as tf
import numpy as np

print(f'tf version {tf.__version__}')

#%%
#데이터셋 만들기 ...
_input = np.array([[0,0],[0,1],[1,0],[1,1]]).astype(np.float64)
_output = np.array([[0],[1],[1],[0]]).astype(np.float64)

train_dataset = tf.data.Dataset.from_tensor_slices((_input,_output))
test_dataset = tf.data.Dataset.from_tensor_slices((_input,_output))
BATCH_SIZE=1
SHUFFLE_BUFFER_SIZE = 4

train_dataset = train_dataset.shuffle(SHUFFLE_BUFFER_SIZE).batch(BATCH_SIZE)
test_dataset = test_dataset.batch(BATCH_SIZE)

#모델만들기 
def create_model() :
  layers = []
  layers.append(tf.keras.layers.Dense(2,activation=tf.nn.sigmoid))
  layers.append(tf.keras.layers.Dense(1,activation=tf.nn.sigmoid))
  model = tf.keras.Sequential(layers)
  print('layer setup')
  sgd = tf.keras.optimizers.SGD(lr=0.01,decay=0,momentum=0.99,nesterov=True)
  model.compile(optimizer=sgd,loss='mse',metrics=['mae','mse'])
  return model


#%%
if __name__ == "__main__":
  model = create_model()
#%%
  print(model(_input)) #훈련전
#%%
  model.fit(train_dataset,epochs=500, validation_data=test_dataset)
  print(model(_input)) # 훈련후 

# %%
