import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(department, left_on='departmentId', right_on='id', suffixes=('', '_dept'))
    max_salary_df = df[df['salary'] == df.groupby('departmentId')['salary'].transform('max')]
    result = max_salary_df[['name_dept', 'name', 'salary']].rename(columns={
        'name_dept': 'Department',
        'name': 'Employee',
        'salary': 'Salary'
    })
    return result