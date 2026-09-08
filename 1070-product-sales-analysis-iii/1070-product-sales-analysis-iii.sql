# Write your MySQL query statement below
select s.product_id,s.year as first_year,s.quantity,s.price
from Sales s
join
-- (select product_id,min(year) as year,quantity,price
(select product_id,min(year) as year
from Sales
group by product_id)f
ON s.product_id=f.product_id and s.year=f.year