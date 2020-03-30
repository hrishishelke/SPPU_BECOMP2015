
import numpy as np
from sklearn.cluster import KMeans
from sklearn import preprocessing, cross_validation
import pandas as pd

import os 
from sklearn import datasets
from sklearn.metrics import confusion_matrix
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
import pandas as pd

df = pd.read_csv('2010-capitalbikeshare-tripdata.csv')
print(df.head())
def handle_non_numerical_data(df):
    columns = df.columns.values
    for column in columns:
        text_digit_vals = {}
        def convert_to_int(val):
            return text_digit_vals[val]

        if df[column].dtype != np.int64 and df[column].dtype != np.float64:
            column_contents = df[column].values.tolist()
            unique_elements = set(column_contents)
            x = 0
            for unique in unique_elements:
                if unique not in text_digit_vals:
                    text_digit_vals[unique] = x
                    x+=1

            df[column] = list(map(convert_to_int, df[column]))

    return df
df = handle_non_numerical_data(df)
x=df[['Duration','Start date','End date','Start station number','Start station','End station number','End station','Bike number']]
y=df[['Member type']]
X_train, X_test, y_train, y_test = train_test_split(x, y, random_state = 0)
dtree_model = DecisionTreeClassifier(max_depth = 2).fit(X_train, y_train)
dtree_predictions = dtree_model.predict(X_test)
dtree_predictions.shape
df = pd.read_csv('Un.csv')
df2 = handle_non_numerical_data(df)
x1=df2[['Duration','Start date','End date','Start station number','Start station','End station number','End station','Bike number']]
print(df.head())
y1=df2[['Member type']]
dp = dtree_model.predict(x1)
print(dp)


'''

root@comp423-desktop:/home/comp423/DA# python Decision_Tree.py
/root/anaconda3/lib/python3.6/site-packages/sklearn/cross_validation.py:41: DeprecationWarning: This module was deprecated in version 0.18 in favor of the model_selection module into which all the refactored classes and functions are moved. Also note that the interface of the new CV iterators are different from that of this module. This module will be removed in 0.20.
  "This module will be removed in 0.20.", DeprecationWarning)
   Duration       Start date     ...      Bike number  Member type
0      1012  9/20/2010 11:27     ...           W00742       Member
1        61  9/20/2010 11:41     ...           W00032       Member
2      2690  9/20/2010 12:05     ...           W00993       Member
3      1406  9/20/2010 12:06     ...           W00344       Member
4      1413  9/20/2010 12:10     ...           W00883       Member

[5 rows x 9 columns]
   Duration  Start date     ...       Bike number  Member type
0       759           1     ...                 2            1
1       433           3     ...                 1            1
2       329           4     ...                 4            1
3       775           0     ...                 0            1
4      3044           2     ...                 3            0

[5 rows x 9 columns]
[1 1 1 1 0]
root@comp423-desktop:/home/comp423/DA# ^C


'''
