# -*- coding: utf-8 -*-
"""
Created on Mon Sep 24 18:25:14 2018

@author: ASUS
"""

from sklearn import datasets
from sklearn import neighbors

import pandas as pd
import numpy as np
import os

df = pd.read_csv('2010-capitalbikeshare-tripdata.csv')
def handle_non_numerical_data(df):
    columns = df.columns.values
    for column in columns:
        text_digit_vals = {}
        def convert_to_int(val):
            return text_digit_vals[val]

        if df[column].dtype != np.int64 and df[column].dtype != np.float64:
            column_contents = df[column].values.tolist() # 
            unique_elements = set(column_contents)
            x = 0
            for unique in unique_elements:
                if unique not in text_digit_vals:
                    text_digit_vals[unique] = x
                    x+=1

            df[column] = list(map(convert_to_int, df[column]))

    return df
df1 = handle_non_numerical_data(df)
print(df1.head(5))
x=df[['Duration','Start date','End date','Start station number','Start station','End station number','End station','Bike number']]
y=df[['Member type']]

knn = neighbors.KNeighborsClassifier()
knn.fit(x, y.values.ravel()) 
print(knn.predict([[1959, 58739, 11268, 31200,25,31108,4,495]]))

'''
root@comp423-desktop:/home/comp423/DA# python KNN.py 
   Duration  Start date  End date  Start station number  Start station  End station number  End station  Bike number  Member type
0      1012        1219     28370                 31208              8               31108           17          786            0
1        61        5650     16778                 31209            102               31209          103           45            0
2      2690       52098     41773                 31600             13               31100           93          566            0
3      1406        4606     19366                 31600             13               31602           81          307            0
4      1413       19000     23838                 31100             92               31201           36          640            0
[0]
root@comp423-desktop:/home/comp423/DA# 

'''
