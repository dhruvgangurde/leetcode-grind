# Write your MySQL query statement below
-- for each product, check which price range the purchase date falls in (purchase_date BETWEEN start_date AND end_date)
-- accordingly get the price for that sale
-- calculate total revenue using (price * units)
-- sum all revenue and sum all units for each product
-- average selling price = total revenue / total units
-- round answer to 2 decimal places
SELECT p.product_id, ROUND(IFNULL(SUM(p.price * u.units) / SUM(u.units), 0), 2) as average_price
FROM Prices p
LEFT JOIN UnitsSold u 
ON p.product_id = u.product_id AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;