#%%
print("숫자를 입력하세요")
a = input()

if int(a) > 0 :
  print('0 보다 커요.')
else :
  print('0 보다 작아요.')
# %%

print("요일을 입력하세요.")
strDay = input()

if strDay == '월' :
  print('monday')
  print('----------')
elif strDay == '화' :
  print('fire')
else :
  print('없는 요일입니다.')

print('********************')
# %%
## && , ||
a = 16
if a > 10 and a % 2 == 0 :
  print('bingo')

print('finish')

# %%
a=5
if a==3 or a==4 :
  print('3일수도있고 4일수도 있습니다.')
else :
  print('다른수입니다.')


# %%
bool('')
bool('aabb')
# %%
print(bool([]))
print(bool([1,2,4]))
# %%
