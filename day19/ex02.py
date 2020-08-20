#%%
a=5
b=1
def scope_test():
  global a
  a=1
  b=7
  print(a,b)

scope_test()
print(a,b)
# %%
count = 5
def recur_test():
  global count
  if count > 0:
    count = count-1
    print(count)
    recur_test()
  

recur_test()
# %%
def hello():
  print('hello')

a=hello
a()

# %%
def say():
  def hello2():
    print('hello')
  hello2()

say()





# %%
