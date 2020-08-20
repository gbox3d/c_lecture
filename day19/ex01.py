#%% 
def print_hello() :
  print("say hello")

print_hello()


# %%
def sum(a,b):
  return a + b

c = sum(5,6)
print(c)

# %%
def sub(a,b=5):
  return a-b

print(sub(4,3))
print(sub(7))

# %%
def print_person(name="none",phone=1,age=30):
  print(f'{name},{phone},{age}')

print_person()
print_person(age=43,phone=303)

# %%
def merge_string(*list_str):
  result = ''
  for s in list_str:
    result = result + s
  return result


print(merge_string('아버지','가방에','들어가신다'))
print(merge_string('아버지가방에','들어가신다'))

# %%
def print_team(**players):
  for k in players:
    print(k,players[k])

print_team(honaldu=27,aloso=11,pepe=56)
print_team(honaldu=27,pepe=56)


# %%
