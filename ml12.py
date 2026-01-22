import numpy as np
import matplotlib.pyplot as plt
from statsmodels.nonparametric.smoothers_lowess import lowess
np.random.seed(0)
X = np.linspace(-3, 3, 100)
y = np.sin(X) + np.random.normal(0, 0.1, 100)
lowess_result = lowess(y, X, frac=0.25)
plt.figure(figsize=(8,5))
plt.scatter(X, y, color='blue', label='Original Data')
plt.plot(lowess_result[:,0], lowess_result[:,1],
         color='red', linewidth=2, label='LOWESS Fit')
plt.xlabel("X")
plt.ylabel("y")
plt.title("Locally Weighted Regression using In-built LOWESS")
plt.legend()
plt.grid(True)
plt.show()

# import pandas as pd
# import matplotlib.pyplot as plt
# from statsmodels.nonparametric.smoothers_lowess import lowess

# # 1. Load dataset (replace filename)
# data = pd.read_csv("dataset.csv")

# # 2. Select input and output columns
# X = data.iloc[:, 0]   # Independent variable
# y = data.iloc[:, 1]   # Dependent variable

# # 3. Apply Locally Weighted Regression (LOWESS - in built)
# # frac controls local neighborhood size
# lwr = lowess(y, X, frac=0.3)

# # 4. Visualization
# plt.figure(figsize=(8,5))
# plt.scatter(X, y, color='blue', label='Original Data')
# plt.plot(lwr[:, 0], lwr[:, 1], color='red', linewidth=2,
#          label='Locally Weighted Regression')
# plt.xlabel("X")
# plt.ylabel("y")
# plt.title("Locally Weighted Regression using In-built Function")
# plt.legend()
# plt.grid(True)
# plt.show()
