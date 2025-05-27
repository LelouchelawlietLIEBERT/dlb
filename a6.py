import pandas as pd
df = pd.read_csv("students.csv")
print(df.describe())
print(df[df['marks'] > 50])
print(df.groupby('dept')['marks'].mean())
print(df.sort_values('GPA', ascending=False))
df.fillna(0, inplace=True)
df['Grade'] = pd.cut(df['marks'], bins=[0,50,75,100], labels=['C','B','A'])
df.groupby('dept')['marks'].mean().plot(kind='bar')
