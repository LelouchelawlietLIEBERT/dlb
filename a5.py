import numpy as np
t = np.random.randint(20, 40, 14)
t2d = t.reshape(2, 7)
print(t2d[1,:5])
print(np.sort(t2d, axis=None), np.sort(t2d, axis=1))
print(t2d.max(1), t2d.min(1), t2d.max(0), t2d.min(0), t2d.max(), t2d.min())
