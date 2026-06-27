# Write your MySQL query statement below
SELECT customer_id,count(v.visit_id) as count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.amount is NULL
GROUP BY v.customer_id;