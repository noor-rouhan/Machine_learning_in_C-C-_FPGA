# -*- coding: utf-8 -*-
"""
Created on Fri Jan 25 00:47:02 2019

@author: auri
"""

import numpy as np
import matplotlib.pyplot as plt


X_train = []
Y_train = []
X_test = []
Y_test = []
num_iterations=2000
learning_rate=0.5  

#weight initialization
    
w = np.zeros(shape=(X_train.shape[0], 1))
b = 0
    
# Gradient descent and optimization
    
costs = []
    
for i in range(num_iterations):
        
        m = X_train.shape[1]
        
        z = np.dot(w.T, X_train) + b
        
        A= 1 / (1 + np.exp(-z))
    
        cost = (- 1 / m) * np.sum(Y_train * np.log(A) + (1 - Y_train) * (np.log(1 - A)))  # compute cost

        dw = (1 / m) * np.dot(X_train, (A - Y_train).T)
        db = (1 / m) * np.sum(A - Y_train)

        cost = np.squeeze(cost)
        
        w = w - learning_rate * dw  
        b = b - learning_rate * db
       
        if i % 100 == 0:
            costs.append(cost)
        
 