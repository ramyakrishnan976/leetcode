import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    # Use method='dense' to prevent gaps in ranking, and ascending=False for highest to lowest
    scores['rank'] = scores['score'].rank(method='dense', ascending=False).astype(int)
    
    # Sort the dataframe by score in descending order and select required columns
    return scores[['score', 'rank']].sort_values(by='score', ascending=False)
