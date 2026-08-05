import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    # Calculate dense rank in descending order (highest score gets rank 1, no rank gaps)
    scores['rank'] = scores['score'].rank(method='dense', ascending=False)
    
    # Sort by score in descending order and select required columns
    return scores[['score', 'rank']].sort_values(by='score', ascending=False)