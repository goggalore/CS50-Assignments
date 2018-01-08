import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positives = set()
        self.negatives = set()
        
        file = open(positives, "r")
        for line in file:
            if not line.startswith(';'):
                self.positives.add(line.strip(" \n"))
        file.close()
        
        file = open(negatives, "r")
        for line in file:
            if not line.startswith(';'):
                self.negatives.add(line.strip(" \n"))
        file.close()
        
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        
        score = 0.0 
        for token in tokens:
            if token.lower() in self.positives:
                score += 1 
            elif token.lower() in self.negatives:
                score -= 1 
                
        return score
