# Write your MySQL query statement below
-- select round( count( case when order_date= customer_pref_delivery_date then 1 end)/ count(*)* 100 ,2) as immediate_percentage
select round( avg(  order_date= customer_pref_delivery_date )* 100 ,2) as immediate_percentage
from Delivery 
WHERE (customer_id, order_date) IN (
    SELECT customer_id, MIN(order_date)
    FROM Delivery
    GROUP BY customer_id
)
-- having order_date = min(order_date) group by customer_id this wrog cause we need to fiter row not group row 
--  not possible lke this 
-- where order_date = min(order_date) group by customer_id