from openpyxl import load_workbook
wb = load_workbook("sales.xlsx"); ws = wb.active
data = list(ws.iter_rows(values_only=True))[1:]
sales = [(r[0], r[1]*r[2]) for r in data]
print("Total Sales:", sum(x[1] for x in sales))
print("Total Qty:", sum(r[1] for r in data))
print("Avg Price:", sum(r[2] for r in data)/len(data))
print("Best:", max(sales, key=lambda x: x[1])[0])
print("Expensive:", max(data, key=lambda x: x[2])[0])
