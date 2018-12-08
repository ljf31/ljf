s=(1,2,3,4)
f, s1, t, f = s
print f, s1

from collections import deque
t= deque(maxlen=3)
t.append(1)
t.append(2)
t.append(22)
t.append(222)
print t

import heapq
t=[3,2,1,4,2, -1]
heapq.heapify(t)
print t
print heapq.heappop(t)
print t

from collections import defaultdict
d = defaultdict(list)
d['a'].append(1)
d['a'].append(2)
d['a'].append(2)
d['b'].append(3)
print d
dd={'a': 1, 'b': 2}
print zip(dd.values(), dd.keys())
print dd.values(), dd.keys()

l1=['a', 'b']
l2=[1,2]
print zip(l1, l2)

s1=slice(2,5)
print s1
tt=[1,2,3,4,5,6]
print tt[s1]

from collections import Counter
test=['1', '2', '1', '3', '4', '3']
t = Counter(test)
print t, t.most_common(2)

import re
line = 'asdf fjdk; aded, fjek,asdf,   foo , fff ,rr'
t=re.split(r'[;,\s]\s*', line)
print t
t=re.split(r'(;|,|\s)\s*', line)
print t
t=re.split(r'(?:;|,|\s)\s*', line)
print t

from fnmatch import fnmatch, fnmatchcase
print fnmatch('foo.txt', '*.txt')

text ='today is 10/14/2018. my bd is 09/07/1990'
datepat = re.compile(r'(\d+)/(\d+)/(\d+)')
txt1='10/14/20'
tt = datepat.match(txt1)
print tt, tt.groups(), tt.group(1)
rt = datepat.findall(text)
print rt
rp = datepat.sub(r'\3-\1-\2', text)
print rp

lt = [1, 2, 3]
lt.extend([4, 5])
print lt

import hashlib
md5 = hashlib.md5()
md5.update('welcom to python hashlib'.encode('utf-8'))
print md5.hexdigest()
