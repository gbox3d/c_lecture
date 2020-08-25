#%%
#import PIL.Image as Image
from PIL import Image,ImageDraw

from IPython.display import display

print('module ok ')
#%%
_img = Image.open('../res/tanks/sheet_tanks.png')
print(_img.size)
# %%
display(_img)
# %%
_img2 = Image.new('RGB',(800,600),(255,255,255))
display(_img2)

# %%
drawer = ImageDraw.Draw(_img2)
drawer.line([(0,0),(400,400)],width=8,fill="red")
_img_crop = _img.crop((0,0,128,128))
_img2.paste(_img_crop,(100,100))

display(_img2)

# %%
img_resize = _img.resize((200,100),Image.ANTIALIAS)
display(img_resize)
# %%
img_rotate = _img.rotate(90)
display(img_rotate)
# %%

_img_crop.save('test.png')

# %%
