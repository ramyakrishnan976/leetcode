import pandas as pd

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    # 1. Merge tables to get department names
    df = employee.merge(department, left_on='departmentId', right_on='id', suffixes=('', '_dept'))
    
    # 2. Use 'dense' rank to handle ties in salaries correctly
    # ascending=False ensures the highest salaries get rank 1
    df['rnk'] = df.groupby('departmentId')['salary'].rank(method='dense', ascending=False)
    
    # 3. Filter for the top 3 unique salaries
    top_3_df = df[df['rnk'] <= 3]
    
    # 4. Select and rename columns for the final output
    result = top_3_df[['name_dept', 'name', 'salary']]
    result.columns = ['Department', 'Employee', 'Salary']
    
    return result
