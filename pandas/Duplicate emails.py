import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    # Group by email and count occurrences
    counts = person.groupby('email').size().reset_index(name='count')
    
    # Filter for emails that appear more than once
    duplicate_emails_df = counts[counts['count'] > 1]
    
    # Return only the email column with the correct capitalization
    return duplicate_emails_df[['email']].rename(columns={'email': 'Email'})
