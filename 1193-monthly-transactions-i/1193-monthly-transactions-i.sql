# Write your MySQL query statement below
SELECT LEFT(TRANS_DATE, 7) AS month, country, count(id) as trans_count, SUM(state = 'approved') as approved_count,SUM(amount) as trans_total_amount,SUM(amount * (state = 'approved')) as approved_total_amount
FROM transactions
GROUP BY month, country;
