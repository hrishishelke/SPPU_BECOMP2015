import pandas as pd
import numpy as np
import csv

from sklearn.naive_bayes import BernoulliNB
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.pipeline import Pipeline


text_clf = Pipeline([
                ('vect', CountVectorizer()),
                ('tfidf', TfidfTransformer()),
                ('clf', BernoulliNB()),
])


training_data = pd.read_csv('train_tweets.csv')
testing_data  = pd.read_csv('test_tweets.csv')


features = training_data.values[:, 2]

labels   = training_data.values[:, 1].astype('int')


text_clf = text_clf.fit(features, labels)

testing_data = testing_data.values[:, 1]


predictions = text_clf.predict(testing_data)

hate = 0
non_hate = 0

for i in predictions:
    if i == 0:
        non_hate += 1
    else:
        hate += 1

print('Total Hate Tweets:', hate, ' Total Non-Hate Tweets:', non_hate)


with open('output.csv', 'w') as csvfile:
    fieldnames = ['label', 'tweet']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    for i in range(len(predictions)):
        writer.writerow({'label': predictions[i], 'tweet': testing_data[i]})




/*Output



		root@comp436-desktop:/home/comp436/Desktop# python pp.py 
Total Hate Tweets: 292  Total Non-Hate Tweets: 16905
root@comp436-desktop:/home/comp436/Desktop# 

*/
