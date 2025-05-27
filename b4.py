import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("TATASTEEL.csv")
df['Date'] = pd.to_datetime(df['Date'])

plt.figure(figsize=(12,6))
plt.plot(df['Date'], df['Close'], label='Close')
plt.scatter(df['Date'][::10], df['Close'][::10], color='r', s=10)
plt.xlabel("Date")
plt.ylabel("Price")
plt.title("TATASTEEL Closing Prices Over Time")
plt.grid(True)
plt.legend()
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()
