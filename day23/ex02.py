#%%
from xml.etree.ElementTree import parse

print(f'module load ok')
# %%
tree = parse('..\\res\\tanks\\sheet_tanks.xml')
rootNode = tree.getroot()
_node = rootNode.find('SubTexture')
print(_node)

# %%
print(_node.attrib)
# %%
print(_node.attrib['name'])
print(_node.attrib['x'])
# %%
_nodes = rootNode.findall('SubTexture')
print(_nodes)
# %%
for node in _nodes :
  print(node.attrib['name'])
# %%
from struct import *

_f = open('sheet.bin','wb')
for node in _nodes :
  # _f.write(node.attrib['name'])
  buf = pack('hhhh',
  int(node.attrib['x'])
  ,int(node.attrib['y'])
  ,int(node.attrib['width'])
  ,int(node.attrib['height'])
  )  
  _f.write(buf)
  # print(node.attrib['name'])
_f.close()
#%%

_str =_nodes[0].attrib['name']
_tmp = f'{_str:32}'
print(_tmp)
bytes(_tmp,'utf-8')



#%%
_f = open('sheet2.bin','wb')
for node in _nodes :
  # _f.write(node.attrib['name'])
  _str =node.attrib['name']
  _tmp = f'{_str:32}'
  # print(_tmp)  
  _f.write(bytes(_tmp,'utf-8'))
  
  buf = pack('hhhh',
  int(node.attrib['x'])
  ,int(node.attrib['y'])
  ,int(node.attrib['width'])
  ,int(node.attrib['height'])
  )  
  _f.write(buf)
  # print(node.attrib['name'])
_f.close()





# %%
