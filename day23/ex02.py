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




# %%
