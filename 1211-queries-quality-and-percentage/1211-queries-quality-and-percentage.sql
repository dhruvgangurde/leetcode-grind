# Write your MySQL query statement below
SELECT query_name ,
ROUND(AVG(RATING / POSITION), 2) AS quality  ,
 ROUND(SUM(rating < 3) * 100 / COUNT(*), 2) AS poor_query_percentage  
FROM QUERIES
GROUP BY QUERY_NAME;
