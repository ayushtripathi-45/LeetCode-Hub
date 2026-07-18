import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)
    
    if N <= 0 or len(unique_salaries) < N:
        nth_salary = None
    else:
        nth_salary = unique_salaries.iloc[N - 1]
        
    column_name = f'getNthHighestSalary({N})'
    return pd.DataFrame({column_name: [nth_salary]})