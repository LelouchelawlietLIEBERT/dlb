from sklearn.datasets import load_iris
import pandas as pd, matplotlib.pyplot as plt
d = load_iris(); df = pd.DataFrame(d.data, columns=d.feature_names)
df['species'] = d.target
plt.hist(df['petal length (cm)']); plt.show()
df.groupby('species')['petal length (cm)'].mean().plot(kind='bar'); plt.show()
