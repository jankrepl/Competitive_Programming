# Name: Correlation_and_Regression_Lines_A_Quick_Recap_1
# WWWW: https://www.hackerrank.com/challenges/correlation-and-regression-lines-6
# Author: Jan Krepl


from scipy.stats import pearsonr
p = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
h = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]
result = pearsonr(p, h)[0]
print("%.3f/n" % result) 
